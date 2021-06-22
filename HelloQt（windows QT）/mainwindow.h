#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTcpSocket>
#include <QTimer>
#include <QLabel>
#include <QPainter>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QNetworkAccessManager>
#include <QSerialPort>
#include <QTime>
#include <QTimer>
#include <QtCharts/QtCharts>

#include "verificationcodelabel.h"
#include "chart.h"
#include "con_sql.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void send_email();
    void draw_temp_chart();
    void draw_humidity_chart();

    void show_led_off(QLabel *led);
    void show_led_on(QLabel *led);
    void show_beep_off();
    void show_beep_on();
    void show_switch_off(QLabel *led);
    void show_switch_on(QLabel *led);
    void show_window_off(QLabel *led);
    void show_window_on(QLabel *led);

    chart *humidity_chart;
    chart *temp_chart;

public slots:
    // 自定义槽函数
    void onCancle();
    void onLogin();
    void onConnected();
    void myslot();
    void main_refresh();

private slots:
    void requestLoginFinished(QNetworkReply*s);
    void on_btn_register_clicked();
    void on_btn_return_clicked();
    void on_btn_ok_reg_clicked();
    void on_btn_send_code_clicked();
    void on_btn_login_close_clicked();
    void on_btn_register_close_clicked();
    void on_btn_main_close_clicked();

    void on_btn_temp_details_clicked();

    void on_btn_humidity_details_clicked();

    void on_btn_temp_return_clicked();

    void on_btn_humidity_return_clicked();

    void on_btn_main_return_clicked();

    void on_btn_led_details_clicked();

    void on_btn_household_details_clicked();

    void on_btn_led_return_clicked();

    void on_btn_household_return_clicked();

private:
    QPoint last;
    QTcpSocket *client;
    Ui::MainWindow *ui;
    qint16 package_size;
    QSerialPort global_port;
    VerificationCodeLabel *M_VerificationCodeLabel;

    con_sql sql_connect;
    int verificationcode;

    QTimer *timer;
    QTimer *main_timer;
    int count;          //倒计时

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

};

#endif // MAINWINDOW_H
