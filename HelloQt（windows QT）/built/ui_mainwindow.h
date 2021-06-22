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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_close;
    QStackedWidget *stackedWidget;
    QWidget *page_login;
    QLabel *label_title_log;
    QLineEdit *lineEdit_password_log;
    QLabel *label_username_log;
    QLabel *label_password_log;
    QLineEdit *lineEdit_username_log;
    QPushButton *btn_cancle;
    QPushButton *btn_ok;
    QPushButton *btn_register;
    QLabel *label;
    QLineEdit *lineEdit_captcha;
    QLabel *label_captcha;
    QWidget *page_register;
    QLabel *label_title_reg;
    QLabel *label_username_reg;
    QPushButton *btn_return;
    QLineEdit *lineEdit_password_reg_2;
    QLineEdit *lineEdit_username_reg;
    QPushButton *btn_ok_reg;
    QLabel *label_password_reg_2;
    QLabel *label_password_reg_1;
    QLineEdit *lineEdit_password_reg_1;
    QWidget *page_main;
    QLabel *label_title_reg_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(500, 400);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("QLabel#label_title\n"
"{\n"
"	color: rgb(255, 85, 0);\n"
"}\n"
"\n"
"QWidget#centralWidget\n"
"{\n"
"	border-image: url(:/new/prefix1/img/kali.png);\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_close = new QPushButton(centralWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setGeometry(QRect(480, 0, 21, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font1.setPointSize(20);
        btn_close->setFont(font1);
        btn_close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:red;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 150 , 254);\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:10px;\n"
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
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 20, 480, 380));
        page_login = new QWidget();
        page_login->setObjectName(QStringLiteral("page_login"));
        label_title_log = new QLabel(page_login);
        label_title_log->setObjectName(QStringLiteral("label_title_log"));
        label_title_log->setGeometry(QRect(160, 20, 261, 80));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label_title_log->setFont(font2);
        label_title_log->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_title_log->setStyleSheet(QStringLiteral("color:#FF5500"));
        label_title_log->setAlignment(Qt::AlignCenter);
        lineEdit_password_log = new QLineEdit(page_login);
        lineEdit_password_log->setObjectName(QStringLiteral("lineEdit_password_log"));
        lineEdit_password_log->setGeometry(QRect(180, 160, 220, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Comic Sans MS"));
        font3.setPointSize(15);
        lineEdit_password_log->setFont(font3);
        lineEdit_password_log->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
"border:3px solid #00ff00;"));
        lineEdit_password_log->setEchoMode(QLineEdit::Password);
        lineEdit_password_log->setClearButtonEnabled(true);
        label_username_log = new QLabel(page_login);
        label_username_log->setObjectName(QStringLiteral("label_username_log"));
        label_username_log->setGeometry(QRect(90, 110, 60, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        label_username_log->setFont(font4);
        label_username_log->setStyleSheet(QStringLiteral("color:rgb(80, 80, 80)"));
        label_username_log->setAlignment(Qt::AlignCenter);
        label_password_log = new QLabel(page_login);
        label_password_log->setObjectName(QStringLiteral("label_password_log"));
        label_password_log->setGeometry(QRect(90, 160, 60, 30));
        label_password_log->setFont(font4);
        label_password_log->setStyleSheet(QStringLiteral("color:rgb(80, 80, 80)"));
        label_password_log->setAlignment(Qt::AlignCenter);
        lineEdit_username_log = new QLineEdit(page_login);
        lineEdit_username_log->setObjectName(QStringLiteral("lineEdit_username_log"));
        lineEdit_username_log->setGeometry(QRect(180, 110, 220, 30));
        QFont font5;
        font5.setFamily(QStringLiteral("Comic Sans MS"));
        font5.setPointSize(16);
        lineEdit_username_log->setFont(font5);
        lineEdit_username_log->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_username_log->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
"border:3px solid #00ff00;\n"
""));
        lineEdit_username_log->setClearButtonEnabled(true);
        btn_cancle = new QPushButton(page_login);
        btn_cancle->setObjectName(QStringLiteral("btn_cancle"));
        btn_cancle->setGeometry(QRect(280, 270, 80, 41));
        btn_cancle->setFont(font1);
        btn_cancle->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
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
        btn_ok = new QPushButton(page_login);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(120, 270, 80, 40));
        btn_ok->setFont(font1);
        btn_ok->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
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
        btn_register = new QPushButton(page_login);
        btn_register->setObjectName(QStringLiteral("btn_register"));
        btn_register->setEnabled(true);
        btn_register->setGeometry(QRect(360, 250, 40, 20));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font6.setPointSize(9);
        font6.setUnderline(true);
        btn_register->setFont(font6);
        btn_register->setAutoFillBackground(false);
        btn_register->setStyleSheet(QStringLiteral("color:rgb(80, 80, 80)"));
        btn_register->setFlat(true);
        label = new QLabel(page_login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 30, 61, 61));
        label->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/img/react.png);"));
        lineEdit_captcha = new QLineEdit(page_login);
        lineEdit_captcha->setObjectName(QStringLiteral("lineEdit_captcha"));
        lineEdit_captcha->setGeometry(QRect(180, 210, 110, 30));
        lineEdit_captcha->setFont(font3);
        lineEdit_captcha->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
"border:3px solid #00ff00;"));
        lineEdit_captcha->setEchoMode(QLineEdit::Normal);
        lineEdit_captcha->setClearButtonEnabled(true);
        label_captcha = new QLabel(page_login);
        label_captcha->setObjectName(QStringLiteral("label_captcha"));
        label_captcha->setGeometry(QRect(59, 210, 91, 30));
        label_captcha->setFont(font4);
        label_captcha->setStyleSheet(QStringLiteral("color:rgb(80, 80, 80)"));
        label_captcha->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_login);
        lineEdit_password_log->raise();
        label_title_log->raise();
        label_username_log->raise();
        label_password_log->raise();
        lineEdit_username_log->raise();
        btn_cancle->raise();
        btn_ok->raise();
        btn_register->raise();
        label->raise();
        lineEdit_captcha->raise();
        label_captcha->raise();
        btn_close->raise();
        page_register = new QWidget();
        page_register->setObjectName(QStringLiteral("page_register"));
        label_title_reg = new QLabel(page_register);
        label_title_reg->setObjectName(QStringLiteral("label_title_reg"));
        label_title_reg->setGeometry(QRect(150, 20, 200, 80));
        QFont font7;
        font7.setFamily(QStringLiteral("Comic Sans MS"));
        font7.setPointSize(20);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        label_title_reg->setFont(font7);
        label_title_reg->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_title_reg->setStyleSheet(QStringLiteral("color:#FF5500"));
        label_title_reg->setAlignment(Qt::AlignCenter);
        label_username_reg = new QLabel(page_register);
        label_username_reg->setObjectName(QStringLiteral("label_username_reg"));
        label_username_reg->setGeometry(QRect(90, 110, 60, 30));
        label_username_reg->setFont(font4);
        label_username_reg->setStyleSheet(QStringLiteral("color:rgb(80, 80, 80)"));
        label_username_reg->setAlignment(Qt::AlignCenter);
        btn_return = new QPushButton(page_register);
        btn_return->setObjectName(QStringLiteral("btn_return"));
        btn_return->setGeometry(QRect(280, 270, 80, 41));
        btn_return->setFont(font1);
        btn_return->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
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
        lineEdit_password_reg_2 = new QLineEdit(page_register);
        lineEdit_password_reg_2->setObjectName(QStringLiteral("lineEdit_password_reg_2"));
        lineEdit_password_reg_2->setGeometry(QRect(180, 210, 220, 30));
        lineEdit_password_reg_2->setFont(font3);
        lineEdit_password_reg_2->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
"border:3px solid #00ff00;"));
        lineEdit_password_reg_2->setEchoMode(QLineEdit::Password);
        lineEdit_password_reg_2->setClearButtonEnabled(true);
        lineEdit_username_reg = new QLineEdit(page_register);
        lineEdit_username_reg->setObjectName(QStringLiteral("lineEdit_username_reg"));
        lineEdit_username_reg->setGeometry(QRect(180, 110, 220, 30));
        lineEdit_username_reg->setFont(font3);
        lineEdit_username_reg->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_username_reg->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
"border:3px solid #00ff00;\n"
""));
        lineEdit_username_reg->setClearButtonEnabled(true);
        btn_ok_reg = new QPushButton(page_register);
        btn_ok_reg->setObjectName(QStringLiteral("btn_ok_reg"));
        btn_ok_reg->setGeometry(QRect(120, 270, 80, 40));
        btn_ok_reg->setFont(font1);
        btn_ok_reg->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:20pt;\n"
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
        label_password_reg_2 = new QLabel(page_register);
        label_password_reg_2->setObjectName(QStringLiteral("label_password_reg_2"));
        label_password_reg_2->setGeometry(QRect(90, 210, 60, 30));
        label_password_reg_2->setFont(font4);
        label_password_reg_2->setStyleSheet(QStringLiteral("color:rgb(80, 80, 80)"));
        label_password_reg_2->setAlignment(Qt::AlignCenter);
        label_password_reg_1 = new QLabel(page_register);
        label_password_reg_1->setObjectName(QStringLiteral("label_password_reg_1"));
        label_password_reg_1->setGeometry(QRect(90, 160, 60, 30));
        label_password_reg_1->setFont(font4);
        label_password_reg_1->setStyleSheet(QStringLiteral("color:rgb(80, 80, 80)"));
        label_password_reg_1->setAlignment(Qt::AlignCenter);
        lineEdit_password_reg_1 = new QLineEdit(page_register);
        lineEdit_password_reg_1->setObjectName(QStringLiteral("lineEdit_password_reg_1"));
        lineEdit_password_reg_1->setGeometry(QRect(180, 160, 220, 30));
        lineEdit_password_reg_1->setFont(font3);
        lineEdit_password_reg_1->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"color:#000000;\n"
"background-color: rgba(255, 255, 255, 0%);\n"
"border:3px solid #00ff00;"));
        lineEdit_password_reg_1->setEchoMode(QLineEdit::Password);
        lineEdit_password_reg_1->setClearButtonEnabled(true);
        stackedWidget->addWidget(page_register);
        page_main = new QWidget();
        page_main->setObjectName(QStringLiteral("page_main"));
        label_title_reg_2 = new QLabel(page_main);
        label_title_reg_2->setObjectName(QStringLiteral("label_title_reg_2"));
        label_title_reg_2->setGeometry(QRect(60, -10, 271, 80));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font8.setPointSize(20);
        font8.setBold(true);
        font8.setItalic(false);
        font8.setWeight(75);
        label_title_reg_2->setFont(font8);
        label_title_reg_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_title_reg_2->setStyleSheet(QStringLiteral("color:#FF5500"));
        label_title_reg_2->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(page_main);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 210, 41, 41));
        pushButton_2 = new QPushButton(page_main);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 210, 41, 41));
        stackedWidget->addWidget(page_main);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(lineEdit_username_log, lineEdit_password_log);
        QWidget::setTabOrder(lineEdit_password_log, btn_register);
        QWidget::setTabOrder(btn_register, btn_ok);
        QWidget::setTabOrder(btn_ok, btn_cancle);
        QWidget::setTabOrder(btn_cancle, lineEdit_username_reg);
        QWidget::setTabOrder(lineEdit_username_reg, lineEdit_password_reg_1);
        QWidget::setTabOrder(lineEdit_password_reg_1, lineEdit_password_reg_2);
        QWidget::setTabOrder(lineEdit_password_reg_2, btn_ok_reg);
        QWidget::setTabOrder(btn_ok_reg, btn_return);
        QWidget::setTabOrder(btn_return, btn_close);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_close->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        label_title_log->setText(QApplication::translate("MainWindow", "\346\231\272\350\203\275\345\256\266\345\261\205\346\216\247\345\210\266\347\263\273\347\273\237", Q_NULLPTR));
        lineEdit_password_log->setPlaceholderText(QApplication::translate("MainWindow", "password", Q_NULLPTR));
        label_username_log->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267", Q_NULLPTR));
        label_password_log->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        lineEdit_username_log->setText(QString());
        lineEdit_username_log->setPlaceholderText(QApplication::translate("MainWindow", "username", Q_NULLPTR));
        btn_cancle->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btn_ok->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btn_register->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        label->setText(QString());
        lineEdit_captcha->setPlaceholderText(QApplication::translate("MainWindow", "Captcha", Q_NULLPTR));
        label_captcha->setText(QApplication::translate("MainWindow", "\351\252\214\350\257\201\347\240\201", Q_NULLPTR));
        label_title_reg->setText(QApplication::translate("MainWindow", "Register", Q_NULLPTR));
        label_username_reg->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267", Q_NULLPTR));
        btn_return->setText(QApplication::translate("MainWindow", "\350\277\224\345\233\236", Q_NULLPTR));
        lineEdit_password_reg_2->setPlaceholderText(QApplication::translate("MainWindow", "password", Q_NULLPTR));
        lineEdit_username_reg->setText(QString());
        lineEdit_username_reg->setPlaceholderText(QApplication::translate("MainWindow", "username", Q_NULLPTR));
        btn_ok_reg->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btn_ok_reg->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label_password_reg_2->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        label_password_reg_1->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        lineEdit_password_reg_1->setPlaceholderText(QApplication::translate("MainWindow", "password", Q_NULLPTR));
        label_title_reg_2->setText(QApplication::translate("MainWindow", "\346\231\272\350\203\275\345\256\266\345\261\205\346\216\247\345\210\266\347\263\273\347\273\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\345\274\200", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\205\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
