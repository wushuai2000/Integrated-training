#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort>
#include <QLabel>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QNetworkAccessManager>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void receive_data();
    void beep_flash();
    void on_btn_sitting_status_clicked();
    void on_btn_kitchen_status_clicked();
    void on_btn_bedroom_status_clicked();
    void on_btn_toilet_status_clicked();

    void checkW();
    void replyFinished(QNetworkReply *reply);

    void requestLoginFinished(QNetworkReply*s);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void set_temp(QString num);
    void set_humidity(QString num);
    void system_init();
    void decode_data();
    void show_beep_off();
    void show_beep_on();
    void show_led_off(QLabel *led);
    void show_led_on(QLabel *led);
    void show_switch_off(QLabel *led);
    void show_switch_on(QLabel *led);
    void show_window_off(QLabel *led);
    void show_window_on(QLabel *led);

private:
    QTimer *beep_timer;
    QSerialPort global_port;
    Ui::MainWindow *ui;
    QByteArray PasteData,ReadData;
    QString temperature,humidity,beep,relay,reverse,led1,led2,led3,warn;

    int beep_flag = 1;

    QNetworkAccessManager *manager;  //请求句柄
    QString fengli;       //风力
    QString wendu;        //温度
    QString weather_type;  //天气类型
};

#endif // MAINWINDOW_H
