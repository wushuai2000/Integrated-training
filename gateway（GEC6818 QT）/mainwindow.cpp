#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qjsondocument.h>
#include<qjsonarray.h>
#include<qjsonobject.h>
#include<qjsonvalue.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_temp("00");
    set_humidity("00");
    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));//关联信号和槽
    connect(ui->btn_update_weather, SIGNAL(clicked()), this, SLOT(checkW()));//关联信号和槽

    //串口初始化
    system_init();
    connect(&global_port,&QSerialPort::readyRead,this,&MainWindow::receive_data);   //建立接收信号

    show_beep_off();
    beep_timer = new QTimer();
    connect(beep_timer,SIGNAL(timeout()),this,SLOT(beep_flash()));

    ui->btn_sitting_status->setText("开");
    show_led_off(ui->label_sitting_led);
    ui->btn_kitchen_status->setText("开");
    show_led_off(ui->label_kitchen_led);
    ui->btn_bedroom_status->setText("开");
    show_led_off(ui->label_bedroom_led);
    ui->btn_toilet_status->setText("开");
    show_led_off(ui->label_toilet_led);

    show_switch_off(ui->label_air_status);
    show_switch_off(ui->label_tv_status);
    show_switch_off(ui->label_wash_status);
    show_window_off(ui->label_window_status);

    ui->btn_update_weather->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_temp(QString num)
{
    ui->label_temp_num->setText(num);
}

void MainWindow::set_humidity(QString num)
{
    ui->label_humidity_num->setText(num);
}

//串口接收函数
void MainWindow::receive_data()
{
    QByteArray BufferData = global_port.readAll();
    //异常类：无头且变量为空，已丢失头部，数据不可靠，直接返回
    if ((!BufferData.contains("{"))&(PasteData.isNull()))
    {
        return;
    }
    //第一种：有头无尾，先清空原有内容，再附加
    if ((BufferData.contains("{"))&(!BufferData.contains("}")))
    {
        PasteData.clear();
        PasteData.append(BufferData);
    }
    //第二种：无头无尾且变量已有内容，数据中段部分，继续附加即可
    if ((!BufferData.contains("{"))&(!BufferData.contains("}"))&(!PasteData.isNull()))
    {
        PasteData.append(BufferData);
    }
    //第三种：无头有尾且变量已有内容，已完整读取，附加后输出数据，并清空变量
    if ((!BufferData.contains("{"))&(BufferData.contains("}"))&(!PasteData.isNull()))
    {
        PasteData.append(BufferData);
        ReadData = PasteData;
        PasteData.clear();
        decode_data();
    }
    //第四种：有头有尾（一段完整的内容），先清空原有内容，再附加，然后输出，最后清空变量
    if ((BufferData.contains("{"))&(BufferData.contains("}")))
    {
        PasteData.clear();
        PasteData.append(BufferData);
        ReadData = PasteData;
        PasteData.clear();
    }
    qDebug() << ReadData;
}

//串口初始化函数
void MainWindow::system_init()
{
    // This is available in all editors.
    global_port.setParity(QSerialPort::NoParity);   //设置奇偶校验
    global_port.setDataBits(QSerialPort::Data8);    //设置数据位
    global_port.setStopBits(QSerialPort::OneStop);  //设置停止位

    //connect(ui->btn_open, &QPushButton::clicked, this, &Serial::on_pushButton_clicked);
    //ttyUSB0
    global_port.setPortName("ttyUSB0");    //设置端口号
    global_port.setBaudRate(QSerialPort::Baud9600);//设置波特率
    global_port.open(QIODevice::ReadWrite);

    //global_port.write("1111111");   //写数据
}

void MainWindow::requestLoginFinished(QNetworkReply *s)//API请求返回数据
{
    QString ok = s->readAll();
    if(ok == '1')
    {
        qDebug() << "数据插入成功！";
    }
    else if(ok == '0')
    {
        qDebug() << "数据插入失败！";
    }
    else
    {
        qDebug() << "数据更新成功";
    }
}

void MainWindow::decode_data(){//解析收到的json
    // {"temperature":20,"humidity":20,"beep":1,"relay":1,"reverse":1,"led1":1,"led2":1,"led3":1,"warn":1}
    QString simpjson_str = ReadData;
    //简单的QT解析JSON
    QJsonParseError simp_json_error;
    //QTJSON所有的元素
    QJsonDocument simp_parse_doucment = QJsonDocument::fromJson(simpjson_str.toUtf8(), &simp_json_error);
    //检查json是否有错误
    if (simp_json_error.error == QJsonParseError::NoError)
    {
        if (simp_parse_doucment.isObject())
        {
            //开始解析json对象
            QJsonObject obj = simp_parse_doucment.object();
            //如果包含temperature
            if (obj.contains("temperature"))
            {
                //得到temperature
                QJsonValue temperature_value = obj.take("temperature");
                if (temperature_value.isDouble())
                {
                    //转换temperature
                    temperature = temperature_value.toVariant().toString();
                }
            }
            if (obj.contains("humidity"))
            {
                QJsonValue humidity_value = obj.take("humidity");
                if (humidity_value.isDouble())
                {
                    humidity = humidity_value.toVariant().toString();
                }
            }
            if (obj.contains("beep"))
            {
                QJsonValue beep_value = obj.take("beep");
                if (beep_value.isDouble())
                {
                    beep = beep_value.toVariant().toString();
                }
            }
            if (obj.contains("relay"))
            {
                QJsonValue relay_value = obj.take("relay");
                if (relay_value.isDouble())
                {
                    relay = relay_value.toVariant().toString();
                }
            }
            if (obj.contains("reverse"))
            {
                QJsonValue reverse_value = obj.take("reverse");
                if (reverse_value.isDouble())
                {
                    reverse = reverse_value.toVariant().toString();
                }
            }
            if (obj.contains("led1"))
            {
                QJsonValue led1_value = obj.take("led1");
                if (led1_value.isDouble())
                {
                    led1 = led1_value.toVariant().toString();
                }
            }
            if (obj.contains("led2"))
            {
                QJsonValue led2_value = obj.take("led2");
                if (led2_value.isDouble())
                {
                    led2 = led2_value.toVariant().toString();
                }
            }
            if (obj.contains("led3"))
            {
                QJsonValue led3_value = obj.take("led3");
                if (led3_value.isDouble())
                {
                    led3 = led3_value.toVariant().toString();
                }
            }
            if (obj.contains("warn"))
            {
                QJsonValue warn_value = obj.take("warn");
                if (warn_value.isDouble())
                {
                    warn = warn_value.toVariant().toString();
                }
            }
        }
    }
    qDebug() << "QT解析出来的数据：" << "temperature:" << temperature << "," << "humidity:" << humidity << "," << "beep:" << beep<< "," << "relay:" << relay<< "," << "reverse:" << reverse<< "," << "led1:" << led1<< "," << "led2:" << led2<< "," << "led3:" << led3<< "," << "warn:" << warn;

    QNetworkRequest request;
    QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
    QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
    Q_ASSERT(connRet);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setUrl(QUrl("http://47.100.56.86/gec/sql.php"));
    QString testData = QString("&temp=%1&humidity=%2&beep=%3&relay=%4&reverse=%5&led1=%6&led2=%7&led3=%8&warn=%9").arg(temperature).arg(humidity).arg(beep).arg(relay).arg(reverse).arg(led1).arg(led2).arg(led3).arg(warn);
    naManager->post(request, testData.toUtf8());

    set_temp(temperature);
    set_humidity(humidity);
    if(beep == "1"){
        beep_timer->start(100);
    }else{
        beep_timer->stop();
    }

    if(led1 == "1"){
       show_switch_on(ui->label_air_status);
    }else if(led1 == "0"){
       show_switch_off(ui->label_air_status);
    }
    if(led2 == "1"){
       show_switch_on(ui->label_tv_status);
    }else if(led2 == "0"){
       show_switch_off(ui->label_tv_status);
    }
    if(led3 == "1"){
       show_switch_on(ui->label_wash_status);
    }else if(led3 == "0"){
       show_switch_off(ui->label_wash_status);
    }

    if(reverse == "0"){
        show_window_on(ui->label_window_status);
    }else if(reverse == "1"){
        show_window_off(ui->label_window_status);
    }
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
        QPixmap pix = QPixmap::fromImage(image.scaled(32,40,Qt::KeepAspectRatio));
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
        QPixmap pix = QPixmap::fromImage(image.scaled(32,40,Qt::KeepAspectRatio));
        led->setPixmap(pix);
        inserts.close();
    }
    else
        qDebug() <<"文件打开失败"<<inserts.errorString();
}

// beep闪烁
void MainWindow::beep_flash()
{
    if(beep_flag == 1){
        show_beep_on();
        beep_flag = 0;
    }else{
        show_beep_off();
        beep_flag = 1;
    }
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


void MainWindow::on_btn_sitting_status_clicked()
{
    QString status = ui->btn_sitting_status->text();
    QString on = QString("1");
    QString off = QString("0");
    if(status == "关"){
        ui->btn_sitting_status->setText("开");
        show_led_off(ui->label_sitting_led);
        system("/home/led/d7_off");
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(off).arg(off).arg(off).arg(off);
        naManager->post(request, testData.toUtf8());
    }else if(status == "开"){
        ui->btn_sitting_status->setText("关");
        show_led_on(ui->label_sitting_led);
        system("/home/led/d7_on");

        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(on).arg(off).arg(off).arg(off);
        naManager->post(request, testData.toUtf8());
    }

}

void MainWindow::on_btn_kitchen_status_clicked()
{
    QString status = ui->btn_kitchen_status->text();
    QString on = QString("1");
    QString off = QString("0");
    if(status == "关"){
        ui->btn_kitchen_status->setText("开");
        show_led_off(ui->label_kitchen_led);
        system("/home/led/d8_off");
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(off).arg(off).arg(off).arg(off);
        naManager->post(request, testData.toUtf8());
    }else if(status == "开"){
        ui->btn_kitchen_status->setText("关");
        show_led_on(ui->label_kitchen_led);
        system("/home/led/d8_on");
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(off).arg(on).arg(off).arg(off);
        naManager->post(request, testData.toUtf8());
    }
}

void MainWindow::on_btn_bedroom_status_clicked()
{
    QString status = ui->btn_bedroom_status->text();
    QString on = QString("1");
    QString off = QString("0");
    if(status == "关"){
        ui->btn_bedroom_status->setText("开");
        show_led_off(ui->label_bedroom_led);
        system("/home/led/d9_off");
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(off).arg(off).arg(off).arg(off);
        naManager->post(request, testData.toUtf8());
    }else if(status == "开"){
        ui->btn_bedroom_status->setText("关");
        show_led_on(ui->label_bedroom_led);
        system("/home/led/d9_on");
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(off).arg(off).arg(on).arg(off);
        naManager->post(request, testData.toUtf8());
    }
}

void MainWindow::on_btn_toilet_status_clicked()
{
    QString status = ui->btn_toilet_status->text();
    QString on = QString("1");
    QString off = QString("0");
    if(status == "关"){
        ui->btn_toilet_status->setText("开");
        show_led_off(ui->label_toilet_led);
        system("/home/led/d10_off");
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(off).arg(off).arg(off).arg(off);
        naManager->post(request, testData.toUtf8());
    }else if(status == "开"){
        ui->btn_toilet_status->setText("关");
        show_led_on(ui->label_toilet_led);
        system("/home/led/d10_on");
        QNetworkRequest request;
        QNetworkAccessManager* naManager = new QNetworkAccessManager(this);
        QMetaObject::Connection connRet = QObject::connect(naManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(requestLoginFinished(QNetworkReply*)));
        Q_ASSERT(connRet);
        // 将账号和密码作为参数进行url的构造
        request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        request.setUrl(QUrl("http://47.100.56.86/gec/update.php"));
        QString testData = QString("&sitting=%1&kitchen=%2&bedroom=%3&toilet=%4").arg(off).arg(off).arg(off).arg(on);
        naManager->post(request, testData.toUtf8());
    }
}

void MainWindow::checkW() //点击查询请求天气数据
{
    ui->lineEdit_city->setText("开福区");
    QString local_city = ui->lineEdit_city->text().trimmed(); //获得需要查询天气的城市名称
    char quest_array[256] = "http://wthrcdn.etouch.cn/weather_mini?city=";
    QNetworkRequest quest;
    sprintf(quest_array, "%s%s", quest_array, local_city.toUtf8().data());
    quest.setUrl(QUrl(quest_array));
    quest.setHeader(QNetworkRequest::UserAgentHeader, "RT-Thread ART");
    /*发送get网络请求*/
    manager->get(quest);
}

void MainWindow::replyFinished(QNetworkReply *reply)  //天气数据处理槽函数
{
    qDebug() << "recv weather data!!";
    QString all = reply->readAll();

    //ui->textBrowser->setText(all); //将接收到的数据显示出来

    QJsonParseError err;
    QJsonDocument json_recv = QJsonDocument::fromJson(all.toUtf8(), &err);//解析json对象
    if (!json_recv.isNull())
    {
        QJsonObject object = json_recv.object();

        if (object.contains("data"))
        {
            QJsonValue value = object.value("data");  // 获取指定 key 对应的 value
            if (value.isObject())
            {
                QJsonObject object_data = value.toObject();
                if (object_data.contains("forecast"))
                {
                    QJsonValue value = object_data.value("forecast");
                    if (value.isArray())
                    {
                        QJsonObject today_weather = value.toArray().at(0).toObject();
                        weather_type = today_weather.value("type").toString();

                        QString tuijian = object.value("data").toObject().value("ganmao").toString();
                        QString low = today_weather.value("low").toString();
                        QString high = today_weather.value("high").toString();
                        wendu = low.mid(low.length() - 3, 4) + "~" + high.mid(high.length() - 3, 4);
                        QString strength = today_weather.value("fengli").toString();
                        strength.remove(0, 8);
                        strength.remove(strength.length() - 2, 2);
                        fengli = today_weather.value("fengxiang").toString() + strength;
                        qDebug() << weather_type;
                        qDebug() << wendu;
                        qDebug() << fengli;
                        qDebug() << tuijian;
                        ui->lineEdit_weather->setText(weather_type);//显示天气类型
                        ui->lineEdit_temperature->setText(wendu);//显示温度
                        ui->lineEdit_wind->setText(fengli);//显示风力
                        ui->textEdit_prompt->setText(tuijian);
                    }
                }
            }
        }

    }
    else
    {
        qDebug() << "json_recv is NULL or is not a object !!";
    }
    reply->deleteLater(); //销毁请求对象
}

