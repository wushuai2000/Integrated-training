#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smtp.h"
#include "chart.h"
#include "con_sql.h"

#include <QDebug>
#include <QHostAddress>
#include <QDateTime>
#include <QMessageBox>
#include <QDataStream>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QEvent>
#include <regex>
#include <qinputdialog.h>
#include <QChartView>
#include <QLineSeries>
#include <QGridLayout>

QT_CHARTS_USE_NAMESPACE

using namespace std;

using namespace QtCharts;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->page_login);
    package_size = 0;
    M_VerificationCodeLabel = new VerificationCodeLabel(this);
    M_VerificationCodeLabel->move(300,230);
    M_VerificationCodeLabel->show();

    sql_connect.get_sql_con();
    sql_connect.select_all_data();


    this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    client = new QTcpSocket(this);
    connect(client, SIGNAL(connected()), this, SLOT(onConnected()));

    connect(ui->btn_cancle,SIGNAL(clicked(bool)),this,SLOT(onCancle()));
    connect(ui->btn_ok,SIGNAL(clicked(bool)),this,SLOT(onLogin()));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(myslot()));

    main_timer = new QTimer();
    connect(main_timer,SIGNAL(timeout()),this,SLOT(main_refresh()));
}

MainWindow::~MainWindow()
{
    delete ui;
    sql_connect.db_close();
}

// 点击确认登录
void MainWindow::onLogin()
{
    QString name = ui->lineEdit_username_log->text();
    QString pwd = ui->lineEdit_password_log->text();
    QString captcha = ui->lineEdit_captcha->text();

    if(captcha.isEmpty()){
        QMessageBox::warning(this,"警告","验证码为空，请输入验证码！！！");
        client->close();
        return;
    }

    QChar *c_captcha = new QChar[5];
    c_captcha = captcha.data();
    for (int i = 0; i < M_VerificationCodeLabel->letter_number; ++i)
    {
        if(M_VerificationCodeLabel->verificationCode[i].toLower() != c_captcha[i]){
            QMessageBox::warning(this,"警告","验证码不正确，请重新输入！！！");
            client->close();
            return;
        }
    }
    if(name.isEmpty() or pwd.isEmpty()){
        QMessageBox::warning(this,"警告","用户名或密码不能为空！");
        client->close();
        return;
    }

    if(!regex_match(name.toStdString(), regex("^[0-9]+@[0-9a-zA-Z]+\.com$")) or !regex_match(pwd.toStdString(), regex("^[0-9a-zA-Z]+$"))){
        QMessageBox::warning(this,"警告","请勿输入非法字符！");
        client->close();
        return;
    }

//    // 打包数据，发送[长度，类型，用户，密码] 类型1表示登录
//    QByteArray buf;
//    QDataStream out(&buf, QIODevice::WriteOnly);
//    out << qint16(0) << qint8(1) << name << pwd;
//    qint16 len = buf.size() - sizeof(qint16);
//    out.device()->seek(0);
//    out << len;
//    client->write(buf);

    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
    Q_ASSERT(connRet);

    // 将账号和密码作为参数进行url的构造
    request.setUrl(QUrl("http://47.100.56.86/gec/index.php?model=1"));
    QString testData = QString("&name=%1&passwd=%2").arg(name).arg(pwd);
    naManager->post(request, testData.toUtf8());
}

// 点击确认注册
void MainWindow::on_btn_ok_reg_clicked()
{
//    client->connectToHost("172.16.47.121",12345);
    QString name = ui->lineEdit_username_reg->text();
    QString pwd1 = ui->lineEdit_password_reg_1->text();
    QString pwd2 = ui->lineEdit_password_reg_2->text();
    bool ok;

    if(name.isEmpty() or pwd1.isEmpty() or pwd2.isEmpty()){
        QMessageBox::warning(this,"警告","用户名或密码不能为空！");
        return;
    }

    if(pwd1 != pwd2){
        QMessageBox::warning(this,"警告","两次密码不一致！请重试！");
        return;
    }

    if(!regex_match(name.toStdString(), regex("^[0-9]+@[0-9a-zA-Z]+\.com$"))){
        QMessageBox::warning(this,"警告","请输入正确的邮箱号码！");
        return;
    }

    if(!regex_match(pwd1.toStdString(), regex("^[0-9a-zA-Z]+$"))){
        QMessageBox::warning(this,"警告","密码只能由字母和数字组成");
        return;
    }

//    // 打包数据，发送[长度，类型，用户，密码] 类型2表示注册
//    QByteArray buf;
//    QDataStream out(&buf, QIODevice::WriteOnly);
//    out << qint16(0) << qint8(2) << name << pwd1;
//    qint16 len = buf.size() - sizeof(qint16);
//    out.device()->seek(0);
//    out << len;
//    client->write(buf);

    QString text = QInputDialog::getText(this, tr("注册验证"),tr("请输入您收到的邮箱验证码"), QLineEdit::Normal,0, &ok);
    if (ok && !text.isEmpty() && text == QString::number(verificationcode))
    {
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);

        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/index.php?model=2"));
        QString testData = QString("&name=%1&passwd=%2").arg(name).arg(pwd1);
        naManager->post(request, testData.toUtf8());
    }else{
        QMessageBox::warning(this,"警告","验证码错误！请重试！");
    }
}

//post请求返回数据接收函数
void MainWindow::requestLoginFinished(QNetworkReply *s)
{
    QString ok = s->readAll();
    qDebug() << ok;

    if(!ok.compare("11"))
    {
        qDebug() << "账号密码正确";
        QMessageBox::information(this,"提示","登录成功！！！");
        ui->stackedWidget->setCurrentWidget(ui->page_main);
        M_VerificationCodeLabel->hide();
        main_timer->start(2000);
        main_refresh();
    }
    if(!ok.compare("-11"))
    {
        qDebug() << "账号密码错误，请重新输入！";
        QMessageBox::critical(this,"错误","用户名或密码错误！！！");
    }

    if(!ok.compare("21"))
    {
        qDebug() << "注册成功！";
        QMessageBox::information(this,"提示","注册成功！！！");
        timer->stop();
        ui->btn_send_code->setEnabled(true);
        ui->stackedWidget->setCurrentWidget(ui->page_login);
        M_VerificationCodeLabel->show();
    }

    if(!ok.compare("-21"))
    {
        qDebug() << "注册失败！";
        QMessageBox::critical(this,"错误","注册失败！！！请重试！");
    }
}

// 注册发送邮件
void MainWindow::send_email()
{
    //邮箱地址
    QString mailaddress_qstr = ui->lineEdit_username_reg->text(); //获取用户输入的邮箱地址
    std::string mailaddress_str = mailaddress_qstr.toStdString();
    const char * mailaddress_c = mailaddress_str.c_str();
    //这里因为抄下来的代码是char * 类型的，所以我们需要转换一下
    //随机生成验证码
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    verificationcode = qrand()%(99999 - 10000) + 10000;//产生一个5位数的随机数
    //将验证码加入字符串
    qDebug() << verificationcode;
    QString verificationcode_qstr = QString("注册验证码为%1，若非本人操作，请勿告诉他人。——————信息来自Extrader").arg(verificationcode);
    std::string verificationcode_str = verificationcode_qstr.toStdString();
    const char * verificationcode_c = verificationcode_str.c_str();
    //登录邮箱
    Smtp smtp("710712799@qq.com","tjydutioylbxbejg");  //第一个参数是发送者邮箱，第二个授权码，并不是邮箱密码
    //发送邮件
    smtp.send(mailaddress_c,"验证信息",verificationcode_c);
}

void MainWindow::draw_temp_chart()
{
    std::list<std::pair<int,int>> lt;
    for(int i = 0; i < 10;i++){
        lt.push_back({i,sql_connect.temp_data[9-i].toInt()});
    }
    temp_chart->draw_point(lt);
    lt.clear();
}

void MainWindow::draw_humidity_chart()
{
    std::list<std::pair<int,int>> lt;
    for(int i = 0; i < 10;i++){
        lt.push_back({i,sql_connect.humidity_data[9-i].toInt()});
    }
    humidity_chart->draw_point(lt);
    lt.clear();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
    if((e->x() < 310 && e->x() > 300) || (e->y() < 260 && e->y() > 230)){
        if(e->button() == Qt::LeftButton){
            M_VerificationCodeLabel->slt_reflushVerification();
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void MainWindow::onConnected()
{
    qDebug() << "connect server ok ";
//    ui->btn_close->setEnabled(false);  // 禁用按钮
}

// 点击取消
void MainWindow::onCancle()
{
    ui->lineEdit_username_log->clear();
    ui->lineEdit_password_log->clear();
    ui->lineEdit_captcha->clear();
}

// 跳转到注册界面
void MainWindow::on_btn_register_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_register);
    M_VerificationCodeLabel->hide();
}

// 跳转到登录界面
void MainWindow::on_btn_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
    M_VerificationCodeLabel->show();
    ui->lineEdit_username_reg->clear();
    ui->lineEdit_password_reg_1->clear();
    ui->lineEdit_password_reg_2->clear();
}

// 点击发送验证码
void MainWindow::on_btn_send_code_clicked()
{
    //这行代码也是写在上一个函数中的，只不过我拆下来方便理解
    //间隔1秒触发myslot() 来显示剩余秒数
    count = 60;
    QString name = ui->lineEdit_username_reg->text();
    if(!regex_match(name.toStdString(), regex("^[0-9]+@[0-9a-zA-Z]+\.com$"))){
        QMessageBox::warning(this,"警告","请输入正确的邮箱号码！");
        return;
    }
    timer->start(1000);
    send_email();
    ui->btn_send_code->setEnabled(false);
}

//显示倒计时
void MainWindow::myslot()
{
    QString count_qstr = QString("剩余%1秒").arg(count--);
//    qDebug() << count_qstr;
    ui->label_send_time->setText(count_qstr);//将剩余秒数写在标签上
    if(count == -1)
    {
     //如果用户没有返回登陆，倒计时结束应停止计时
        timer->stop();
        ui->btn_send_code->setEnabled(true);
    }
}

// 关闭窗口
void MainWindow::on_btn_login_close_clicked()
{
    this->close();
}

void MainWindow::on_btn_register_close_clicked()
{
    this->close();
}

void MainWindow::on_btn_main_close_clicked()
{
    this->close();
}

void MainWindow::main_refresh()
{
    sql_connect.select_all_data();

    temp_chart = new chart();
    draw_temp_chart();
    ui->temp_graphicsView->setChart(temp_chart->tchart);
    ui->temp_graphicsView->setRenderHint(QPainter::Antialiasing);

    humidity_chart = new chart();
    draw_humidity_chart();
    ui->humidity_graphicsView->setChart(humidity_chart->tchart);
    ui->humidity_graphicsView->setRenderHint(QPainter::Antialiasing);

    ui->label_temp_num->setText(sql_connect.temp_data[0]);
    ui->label_humidity_num->setText(sql_connect.humidity_data[0]);

    if(sql_connect.sitting_led_status == "1"){
        show_led_on(ui->label_sitting_led);
    }else {
        show_led_off(ui->label_sitting_led);
    }

    if(sql_connect.kitchen_led_status == "1"){
        show_led_on(ui->label_kitchen_led);
    }else {
        show_led_off(ui->label_kitchen_led);
    }

    if(sql_connect.bedroom_led_status == "1"){
        show_led_on(ui->label_bedroom_led);
    }else {
        show_led_off(ui->label_bedroom_led);
    }

    if(sql_connect.toilet_led_status == "1"){
        show_led_on(ui->label_toilet_led);
    }else {
        show_led_off(ui->label_toilet_led);
    }

    if(sql_connect.beep_data[0] == "1"){
        show_beep_on();
    }else{
        show_beep_off();
    }

    if(sql_connect.led1_data[0] == "1"){
        show_switch_on(ui->label_air_status);
    }else{
        show_switch_off(ui->label_air_status);
    }

    if(sql_connect.led2_data[0] == "1"){
        show_switch_on(ui->label_tv_status);
    }else{
        show_switch_off(ui->label_tv_status);
    }

    if(sql_connect.led3_data[0] == "1"){
        show_switch_on(ui->label_wash_status);
    }else{
        show_switch_off(ui->label_wash_status);
    }

    if(sql_connect.reverse_data[0] == "0"){
        show_window_on(ui->label_window_status);
    }else{
        show_window_off(ui->label_window_status);
    }

    sql_connect.beep_data.clear();
    sql_connect.relay_data.clear();
    sql_connect.reverse_data.clear();
    sql_connect.led1_data.clear();
    sql_connect.led2_data.clear();
    sql_connect.led3_data.clear();
    sql_connect.warn_data.clear();
    sql_connect.time_data.clear();
}

// 关灯
void MainWindow::show_led_off(QLabel *led)
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/led_off.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(70,75,Qt::KeepAspectRatio));
        led->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 开灯
void MainWindow::show_led_on(QLabel *led)
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/led_on.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(70,75,Qt::KeepAspectRatio));
        led->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 关beep
void MainWindow::show_beep_off()
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/beep_off.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(50,40,Qt::KeepAspectRatio));
        ui->label_beep_status->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 开beep
void MainWindow::show_beep_on()
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/beep_on.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(50,40,Qt::KeepAspectRatio));
        ui->label_beep_status->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 电器关状态
void MainWindow::show_switch_off(QLabel *led)
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/off.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(40,40,Qt::KeepAspectRatio));
        led->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 电器开状态
void MainWindow::show_switch_on(QLabel *led)
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/on.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(40,40,Qt::KeepAspectRatio));
        led->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 窗户关状态
void MainWindow::show_window_off(QLabel *led)
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/window_off.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(40,40,Qt::KeepAspectRatio));
        led->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 窗户开状态
void MainWindow::show_window_on(QLabel *led)
{
    //从普通文件加载图片，并设置在QLabel标签中
    QImage image;
    QFile inserts(":/new/prefix1/img/window_on.png");
    if(inserts.open(QIODevice::ReadOnly))
    {
        //加载文件
        image.load(&inserts,0);
        QPixmap pix = QPixmap::fromImage(image.scaled(40,40,Qt::KeepAspectRatio));
        led->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// 跳转到温度折线图
void MainWindow::on_btn_temp_details_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_temp_chart);
//    temp_chart = new chart();
//    draw_temp_chart();
//    ui->temp_graphicsView->setChart(temp_chart->tchart);
//    ui->temp_graphicsView->setRenderHint(QPainter::Antialiasing);
}

// 跳转到湿度折线图
void MainWindow::on_btn_humidity_details_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_humidity_chart);
//    humidity_chart = new chart();
//    draw_humidity_chart();
//    ui->humidity_graphicsView->setChart(humidity_chart->tchart);
//    ui->humidity_graphicsView->setRenderHint(QPainter::Antialiasing);
}

// 温度折线图跳转到主界面
void MainWindow::on_btn_temp_return_clicked()
{

    temp_chart->tchart->close();
    ui->stackedWidget->setCurrentWidget(ui->page_main);
}

// 湿度折线图跳转到主界面
void MainWindow::on_btn_humidity_return_clicked()
{
    humidity_chart->tchart->close();
    ui->stackedWidget->setCurrentWidget(ui->page_main);
}

// 跳转灯光详情
void MainWindow::on_btn_led_details_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_led_status);
}

// 跳转家电详情
void MainWindow::on_btn_household_details_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_household_status);
}

// 登出
void MainWindow::on_btn_main_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_login);
    main_timer->stop();
    M_VerificationCodeLabel->show();
}

// 灯光详情跳转到主界面
void MainWindow::on_btn_led_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_main);
}

// 家电详情跳转到主界面
void MainWindow::on_btn_household_return_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_main);
}
