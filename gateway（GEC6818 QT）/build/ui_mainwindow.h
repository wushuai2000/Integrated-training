/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_title;
    QLabel *label_temp;
    QLabel *label_humidity;
    QLabel *label_temp_num_symbol;
    QLabel *label_temp_num;
    QLabel *label_humidity_num;
    QLabel *label_humidity_num_symbol;
    QLabel *label_beep;
    QLabel *label_beep_status;
    QLabel *label_sitting_led;
    QLabel *label_sitting;
    QLabel *label_kitchen;
    QLabel *label_bedroom;
    QLabel *label_toilet;
    QLabel *label_bedroom_led;
    QLabel *label_kitchen_led;
    QLabel *label_toilet_led;
    QPushButton *btn_sitting_status;
    QPushButton *btn_kitchen_status;
    QPushButton *btn_bedroom_status;
    QPushButton *btn_toilet_status;
    QLabel *label_air;
    QLabel *label_tv;
    QLabel *label_wash;
    QLabel *label_air_status;
    QLabel *label_tv_status;
    QLabel *label_wash_status;
    QLineEdit *lineEdit_weather;
    QLineEdit *lineEdit_temperature;
    QLineEdit *lineEdit_wind;
    QLabel *label_weather;
    QLabel *label_temperature;
    QLabel *label_wind;
    QLabel *label_prompt;
    QTextEdit *textEdit_prompt;
    QLabel *label_city;
    QLineEdit *lineEdit_city;
    QPushButton *btn_update_weather;
    QLabel *label_window;
    QLabel *label_window_status;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QLatin1String("QWidget#centralWidget\n"
"{\n"
"	border-image: url(:/new/prefix1/img/bg.png);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_title = new QLabel(centralWidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(190, 0, 451, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(25);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_title->setFont(font);
        label_title->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_title->setStyleSheet(QStringLiteral("color: #9E4F35;"));
        label_title->setAlignment(Qt::AlignCenter);
        label_temp = new QLabel(centralWidget);
        label_temp->setObjectName(QStringLiteral("label_temp"));
        label_temp->setGeometry(QRect(0, 60, 171, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_temp->setFont(font1);
        label_temp->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255)"));
        label_temp->setAlignment(Qt::AlignCenter);
        label_humidity = new QLabel(centralWidget);
        label_humidity->setObjectName(QStringLiteral("label_humidity"));
        label_humidity->setGeometry(QRect(0, 110, 171, 41));
        label_humidity->setFont(font1);
        label_humidity->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255)"));
        label_humidity->setAlignment(Qt::AlignCenter);
        label_temp_num_symbol = new QLabel(centralWidget);
        label_temp_num_symbol->setObjectName(QStringLiteral("label_temp_num_symbol"));
        label_temp_num_symbol->setGeometry(QRect(190, 60, 46, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_temp_num_symbol->setFont(font2);
        label_temp_num_symbol->setStyleSheet(QStringLiteral("color: rgb(255, 158, 0);"));
        label_temp_num = new QLabel(centralWidget);
        label_temp_num->setObjectName(QStringLiteral("label_temp_num"));
        label_temp_num->setGeometry(QRect(140, 60, 46, 41));
        label_temp_num->setFont(font2);
        label_temp_num->setStyleSheet(QStringLiteral("color: rgb(255, 158, 0);"));
        label_temp_num->setAlignment(Qt::AlignCenter);
        label_humidity_num = new QLabel(centralWidget);
        label_humidity_num->setObjectName(QStringLiteral("label_humidity_num"));
        label_humidity_num->setGeometry(QRect(140, 110, 46, 41));
        label_humidity_num->setFont(font2);
        label_humidity_num->setStyleSheet(QStringLiteral("color: rgb(255, 158, 0);"));
        label_humidity_num->setAlignment(Qt::AlignCenter);
        label_humidity_num_symbol = new QLabel(centralWidget);
        label_humidity_num_symbol->setObjectName(QStringLiteral("label_humidity_num_symbol"));
        label_humidity_num_symbol->setGeometry(QRect(190, 110, 61, 41));
        label_humidity_num_symbol->setFont(font2);
        label_humidity_num_symbol->setStyleSheet(QStringLiteral("color: rgb(255, 158, 0);"));
        label_beep = new QLabel(centralWidget);
        label_beep->setObjectName(QStringLiteral("label_beep"));
        label_beep->setGeometry(QRect(10, 180, 171, 41));
        label_beep->setFont(font1);
        label_beep->setStyleSheet(QStringLiteral("color:rgb(255, 133, 102)"));
        label_beep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_beep_status = new QLabel(centralWidget);
        label_beep_status->setObjectName(QStringLiteral("label_beep_status"));
        label_beep_status->setGeometry(QRect(180, 180, 50, 40));
        label_sitting_led = new QLabel(centralWidget);
        label_sitting_led->setObjectName(QStringLiteral("label_sitting_led"));
        label_sitting_led->setGeometry(QRect(730, 60, 32, 40));
        label_sitting = new QLabel(centralWidget);
        label_sitting->setObjectName(QStringLiteral("label_sitting"));
        label_sitting->setGeometry(QRect(569, 60, 131, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_sitting->setFont(font3);
        label_sitting->setStyleSheet(QStringLiteral(""));
        label_sitting->setAlignment(Qt::AlignCenter);
        label_kitchen = new QLabel(centralWidget);
        label_kitchen->setObjectName(QStringLiteral("label_kitchen"));
        label_kitchen->setGeometry(QRect(570, 100, 131, 41));
        label_kitchen->setFont(font3);
        label_kitchen->setStyleSheet(QStringLiteral(""));
        label_kitchen->setAlignment(Qt::AlignCenter);
        label_bedroom = new QLabel(centralWidget);
        label_bedroom->setObjectName(QStringLiteral("label_bedroom"));
        label_bedroom->setGeometry(QRect(570, 140, 131, 41));
        label_bedroom->setFont(font3);
        label_bedroom->setStyleSheet(QStringLiteral(""));
        label_bedroom->setAlignment(Qt::AlignCenter);
        label_toilet = new QLabel(centralWidget);
        label_toilet->setObjectName(QStringLiteral("label_toilet"));
        label_toilet->setGeometry(QRect(570, 180, 131, 41));
        label_toilet->setFont(font3);
        label_toilet->setStyleSheet(QStringLiteral(""));
        label_toilet->setAlignment(Qt::AlignCenter);
        label_bedroom_led = new QLabel(centralWidget);
        label_bedroom_led->setObjectName(QStringLiteral("label_bedroom_led"));
        label_bedroom_led->setGeometry(QRect(730, 140, 32, 40));
        label_kitchen_led = new QLabel(centralWidget);
        label_kitchen_led->setObjectName(QStringLiteral("label_kitchen_led"));
        label_kitchen_led->setGeometry(QRect(730, 100, 32, 40));
        label_toilet_led = new QLabel(centralWidget);
        label_toilet_led->setObjectName(QStringLiteral("label_toilet_led"));
        label_toilet_led->setGeometry(QRect(730, 180, 32, 40));
        btn_sitting_status = new QPushButton(centralWidget);
        btn_sitting_status->setObjectName(QStringLiteral("btn_sitting_status"));
        btn_sitting_status->setGeometry(QRect(700, 65, 30, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(16);
        btn_sitting_status->setFont(font4);
        btn_sitting_status->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok.png)\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(44 , 137 , 255);\n"
"	border-image: url(:/new/prefix1/img/ok.png);\n"
"}\n"
"QPushButton:pressed{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212"
                        "\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png);\n"
"}"));
        btn_kitchen_status = new QPushButton(centralWidget);
        btn_kitchen_status->setObjectName(QStringLiteral("btn_kitchen_status"));
        btn_kitchen_status->setGeometry(QRect(700, 105, 30, 30));
        btn_kitchen_status->setFont(font4);
        btn_kitchen_status->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok.png)\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(44 , 137 , 255);\n"
"	border-image: url(:/new/prefix1/img/ok.png);\n"
"}\n"
"QPushButton:pressed{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212"
                        "\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png);\n"
"}"));
        btn_bedroom_status = new QPushButton(centralWidget);
        btn_bedroom_status->setObjectName(QStringLiteral("btn_bedroom_status"));
        btn_bedroom_status->setGeometry(QRect(700, 145, 30, 30));
        btn_bedroom_status->setFont(font4);
        btn_bedroom_status->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok.png)\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(44 , 137 , 255);\n"
"	border-image: url(:/new/prefix1/img/ok.png);\n"
"}\n"
"QPushButton:pressed{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212"
                        "\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png);\n"
"}"));
        btn_toilet_status = new QPushButton(centralWidget);
        btn_toilet_status->setObjectName(QStringLiteral("btn_toilet_status"));
        btn_toilet_status->setGeometry(QRect(700, 185, 30, 30));
        btn_toilet_status->setFont(font4);
        btn_toilet_status->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok.png)\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(44 , 137 , 255);\n"
"	border-image: url(:/new/prefix1/img/ok.png);\n"
"}\n"
"QPushButton:pressed{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212"
                        "\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png);\n"
"}"));
        label_air = new QLabel(centralWidget);
        label_air->setObjectName(QStringLiteral("label_air"));
        label_air->setGeometry(QRect(10, 230, 171, 41));
        label_air->setFont(font1);
        label_air->setStyleSheet(QStringLiteral("color:rgb(255, 133, 102)"));
        label_air->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_tv = new QLabel(centralWidget);
        label_tv->setObjectName(QStringLiteral("label_tv"));
        label_tv->setGeometry(QRect(10, 280, 171, 41));
        label_tv->setFont(font1);
        label_tv->setStyleSheet(QStringLiteral("color:rgb(255, 133, 102)"));
        label_tv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_wash = new QLabel(centralWidget);
        label_wash->setObjectName(QStringLiteral("label_wash"));
        label_wash->setGeometry(QRect(10, 330, 171, 41));
        label_wash->setFont(font1);
        label_wash->setStyleSheet(QStringLiteral("color:rgb(255, 133, 102)"));
        label_wash->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_air_status = new QLabel(centralWidget);
        label_air_status->setObjectName(QStringLiteral("label_air_status"));
        label_air_status->setGeometry(QRect(180, 230, 40, 40));
        label_tv_status = new QLabel(centralWidget);
        label_tv_status->setObjectName(QStringLiteral("label_tv_status"));
        label_tv_status->setGeometry(QRect(180, 280, 40, 40));
        label_wash_status = new QLabel(centralWidget);
        label_wash_status->setObjectName(QStringLiteral("label_wash_status"));
        label_wash_status->setGeometry(QRect(180, 330, 40, 40));
        lineEdit_weather = new QLineEdit(centralWidget);
        lineEdit_weather->setObjectName(QStringLiteral("lineEdit_weather"));
        lineEdit_weather->setGeometry(QRect(390, 120, 151, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        lineEdit_weather->setFont(font5);
        lineEdit_weather->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_weather->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
""));
        lineEdit_weather->setClearButtonEnabled(false);
        lineEdit_temperature = new QLineEdit(centralWidget);
        lineEdit_temperature->setObjectName(QStringLiteral("lineEdit_temperature"));
        lineEdit_temperature->setGeometry(QRect(390, 170, 151, 30));
        lineEdit_temperature->setFont(font5);
        lineEdit_temperature->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_temperature->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
""));
        lineEdit_temperature->setClearButtonEnabled(false);
        lineEdit_wind = new QLineEdit(centralWidget);
        lineEdit_wind->setObjectName(QStringLiteral("lineEdit_wind"));
        lineEdit_wind->setGeometry(QRect(390, 220, 151, 30));
        lineEdit_wind->setFont(font5);
        lineEdit_wind->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_wind->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
""));
        lineEdit_wind->setClearButtonEnabled(false);
        label_weather = new QLabel(centralWidget);
        label_weather->setObjectName(QStringLiteral("label_weather"));
        label_weather->setGeometry(QRect(290, 120, 91, 30));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setWeight(75);
        label_weather->setFont(font6);
        label_weather->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    //background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png)\n"
"}"));
        label_weather->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_temperature = new QLabel(centralWidget);
        label_temperature->setObjectName(QStringLiteral("label_temperature"));
        label_temperature->setGeometry(QRect(290, 170, 91, 30));
        label_temperature->setFont(font6);
        label_temperature->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    //background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png)\n"
"}"));
        label_temperature->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_wind = new QLabel(centralWidget);
        label_wind->setObjectName(QStringLiteral("label_wind"));
        label_wind->setGeometry(QRect(290, 220, 91, 30));
        label_wind->setFont(font6);
        label_wind->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    //background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png)\n"
"}"));
        label_wind->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_prompt = new QLabel(centralWidget);
        label_prompt->setObjectName(QStringLiteral("label_prompt"));
        label_prompt->setGeometry(QRect(230, 270, 151, 30));
        label_prompt->setFont(font6);
        label_prompt->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    //background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png)\n"
"}"));
        label_prompt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        textEdit_prompt = new QTextEdit(centralWidget);
        textEdit_prompt->setObjectName(QStringLiteral("textEdit_prompt"));
        textEdit_prompt->setGeometry(QRect(390, 270, 341, 91));
        textEdit_prompt->setFont(font5);
        textEdit_prompt->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
""));
        label_city = new QLabel(centralWidget);
        label_city->setObjectName(QStringLiteral("label_city"));
        label_city->setGeometry(QRect(290, 70, 91, 30));
        label_city->setFont(font1);
        label_city->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:16pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:white;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    //background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png)\n"
"}"));
        label_city->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_city = new QLineEdit(centralWidget);
        lineEdit_city->setObjectName(QStringLiteral("lineEdit_city"));
        lineEdit_city->setGeometry(QRect(390, 70, 151, 30));
        lineEdit_city->setFont(font5);
        lineEdit_city->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_city->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
""));
        lineEdit_city->setClearButtonEnabled(false);
        btn_update_weather = new QPushButton(centralWidget);
        btn_update_weather->setObjectName(QStringLiteral("btn_update_weather"));
        btn_update_weather->setGeometry(QRect(390, 380, 211, 30));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font7.setPointSize(14);
        btn_update_weather->setFont(font7);
        btn_update_weather->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:14pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:red;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:8px;\n"
"	border-image: url(:/new/prefix1/img/ok.png)\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(44 , 137 , 255);\n"
"	border-image: url(:/new/prefix1/img/ok.png);\n"
"}\n"
"QPushButton:pressed{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212"
                        "\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"	border-image: url(:/new/prefix1/img/ok1.png);\n"
"}"));
        label_window = new QLabel(centralWidget);
        label_window->setObjectName(QStringLiteral("label_window"));
        label_window->setGeometry(QRect(10, 380, 171, 41));
        label_window->setFont(font1);
        label_window->setStyleSheet(QStringLiteral("color:rgb(255, 133, 102)"));
        label_window->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_window_status = new QLabel(centralWidget);
        label_window_status->setObjectName(QStringLiteral("label_window_status"));
        label_window_status->setGeometry(QRect(180, 380, 40, 40));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_title->setText(QApplication::translate("MainWindow", "\346\231\272\350\203\275\345\256\266\345\261\205\346\216\247\345\210\266\347\263\273\347\273\237", Q_NULLPTR));
        label_temp->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_humidity->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\271\277\345\272\246\357\274\232", Q_NULLPTR));
        label_temp_num_symbol->setText(QApplication::translate("MainWindow", "\342\204\203", Q_NULLPTR));
        label_temp_num->setText(QApplication::translate("MainWindow", "20", Q_NULLPTR));
        label_humidity_num->setText(QApplication::translate("MainWindow", "20", Q_NULLPTR));
        label_humidity_num_symbol->setText(QApplication::translate("MainWindow", "%rh", Q_NULLPTR));
        label_beep->setText(QApplication::translate("MainWindow", "Beep\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_beep_status->setText(QString());
        label_sitting_led->setText(QString());
        label_sitting->setText(QApplication::translate("MainWindow", "\345\256\242\345\216\205\347\201\257\357\274\232", Q_NULLPTR));
        label_kitchen->setText(QApplication::translate("MainWindow", "\345\216\250\346\210\277\347\201\257\357\274\232", Q_NULLPTR));
        label_bedroom->setText(QApplication::translate("MainWindow", "\345\215\247\345\256\244\347\201\257\357\274\232", Q_NULLPTR));
        label_toilet->setText(QApplication::translate("MainWindow", "\345\216\225\346\211\200\347\201\257\357\274\232", Q_NULLPTR));
        label_bedroom_led->setText(QString());
        label_kitchen_led->setText(QString());
        label_toilet_led->setText(QString());
        btn_sitting_status->setText(QString());
#ifndef QT_NO_SHORTCUT
        btn_sitting_status->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btn_kitchen_status->setText(QString());
#ifndef QT_NO_SHORTCUT
        btn_kitchen_status->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btn_bedroom_status->setText(QString());
#ifndef QT_NO_SHORTCUT
        btn_bedroom_status->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btn_toilet_status->setText(QString());
#ifndef QT_NO_SHORTCUT
        btn_toilet_status->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label_air->setText(QApplication::translate("MainWindow", "\347\251\272\350\260\203\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_tv->setText(QApplication::translate("MainWindow", "\347\224\265\350\247\206\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_wash->setText(QApplication::translate("MainWindow", "\346\264\227\350\241\243\346\234\272\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_air_status->setText(QString());
        label_tv_status->setText(QString());
        label_wash_status->setText(QString());
        lineEdit_weather->setText(QString());
        lineEdit_weather->setPlaceholderText(QString());
        lineEdit_temperature->setText(QString());
        lineEdit_temperature->setPlaceholderText(QString());
        lineEdit_wind->setText(QString());
        lineEdit_wind->setPlaceholderText(QString());
        label_weather->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224\357\274\232", Q_NULLPTR));
        label_temperature->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", Q_NULLPTR));
        label_wind->setText(QApplication::translate("MainWindow", "\351\243\216\345\212\233\357\274\232", Q_NULLPTR));
        label_prompt->setText(QApplication::translate("MainWindow", "\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232", Q_NULLPTR));
        label_city->setText(QApplication::translate("MainWindow", "\345\237\216\345\270\202\357\274\232", Q_NULLPTR));
        lineEdit_city->setText(QString());
        lineEdit_city->setPlaceholderText(QString());
        btn_update_weather->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\345\244\251\346\260\224\346\225\260\346\215\256", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btn_update_weather->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label_window->setText(QApplication::translate("MainWindow", "\347\252\227\346\210\267\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_window_status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
