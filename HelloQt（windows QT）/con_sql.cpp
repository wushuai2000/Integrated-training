#include "con_sql.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

con_sql::con_sql(QObject *parent) : QObject(parent)
{

}

// 连接数据库
void con_sql::get_sql_con()
{
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection))
    {
        dbconn = QSqlDatabase::database(QSqlDatabase::defaultConnection);
    }
    else
    {
        dbconn = QSqlDatabase::addDatabase("QMYSQL");
    }
    dbconn.setHostName("47.100.56.86");//主机名字
    dbconn.setDatabaseName("GEC6818");//数据库名字
    dbconn.open("user", "123321"); //第一个参数写用户名，这里我们就写root就可以，第二个参数密码是mysql的登陆密码。
    //可以使用如下语句判断是否连接成功
    if(dbconn.open("user", "123321"))
    {
        qDebug() << "mysql connect success!!!";
    }
    query = (QSqlQuery)dbconn; //进行绑定 此后可以使用query对象对数据库进行操作。
}

// 关闭数据库连接
void con_sql::db_close()
{
    dbconn.close();
}

// 查询所有数据
void con_sql::select_all_data()
{
    /*
    SELECT * from
    (SELECT temp,beep FROM data
    WHERE time >= STR_TO_DATE('2021-06-16 00:00:00','%Y-%m-%d %H:%i:%s')
    order by  time desc)  as total limit 0,10;
    */

    temp_data.clear();
    humidity_data.clear();
    beep_data.clear();
    relay_data.clear();
    reverse_data.clear();
    led1_data.clear();
    led2_data.clear();
    led3_data.clear();
    warn_data.clear();
    time_data.clear();
    query.exec("SELECT * from (SELECT temp,humidity,beep,relay,reverse,led1,led2,led3,warn,date_format(time,'%Y-%m-%d %H:%i:%s') as time FROM data WHERE time >= STR_TO_DATE('2021-06-16 00:00:00','%Y-%m-%d %H:%i:%s') order by time desc)  as total limit 0,10;");
    while(query.next())
    {
        //将所有账户进行保存
        temp_data<<query.value(0).toString();
        humidity_data<<query.value(1).toString();
        beep_data<<query.value(2).toString();
        relay_data<<query.value(3).toString();
        reverse_data<<query.value(4).toString();
        led1_data<<query.value(5).toString();
        led2_data<<query.value(6).toString();
        led3_data<<query.value(7).toString();
        warn_data<<query.value(8).toString();
        time_data<<query.value(9).toString();
    }
    query.clear();
    query.exec("SELECT * FROM room_led where id = 1;");
    while(query.next())
    {
        sitting_led_status = query.value(0).toString();
        kitchen_led_status = query.value(1).toString();
        bedroom_led_status = query.value(2).toString();
        toilet_led_status = query.value(3).toString();
    }
    qDebug() << temp_data;
    qDebug() << humidity_data;
//    qDebug() << beep_data;
//    qDebug() << relay_data;
//    qDebug() << reverse_data;
//    qDebug() << led1_data;
//    qDebug() << led2_data;
//    qDebug() << led3_data;
//    qDebug() << warn_data;
//    qDebug() << time_data;
//    qDebug() << sitting_led_status;
//    qDebug() << kitchen_led_status;
//    qDebug() << bedroom_led_status;
//    qDebug() << toilet_led_status;
    query.clear();
}
