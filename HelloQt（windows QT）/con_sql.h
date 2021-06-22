#ifndef CON_SQL_H
#define CON_SQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class con_sql : public QObject
{
    Q_OBJECT
public:
    QSqlDatabase    dbconn;
    QSqlQuery       query;
    QStringList temp_data;
    QStringList humidity_data;
    QStringList beep_data;
    QStringList relay_data;
    QStringList reverse_data;
    QStringList led1_data;
    QStringList led2_data;
    QStringList led3_data;
    QStringList warn_data;
    QStringList time_data;
    QString sitting_led_status;
    QString kitchen_led_status;
    QString bedroom_led_status;
    QString toilet_led_status;

    explicit con_sql(QObject *parent = nullptr);
    void get_sql_con();
    void db_close();
    void select_all_data();
signals:

public slots:
};

#endif // CON_SQL_H
