#include "chart.h"
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

chart::chart(QWidget *parent) : QWidget(parent)
{
//    series->append(-1,2);
//    series->append(QPointF(2,6));
//    series->append(3,8);
//    series->append(7,-9);
//    series->append(11,3);

//    *series << QPointF(11,2) << QPointF(15,5) << QPointF(18,4) << QPointF(19,2.5);

//    int time;
//    double c;
//    while(lt.size()>=10){
//        lt.pop_front();
//    }
//    lt.push_back({time,c});


}

void chart::draw_point(std::list<std::pair<int,int>> lt)
{
    series = new QLineSeries();
    for(auto it:lt){
        qDebug()<<it.first<<","<<it.second;
        series->append(it.first,it.second);
    }
    tchart = new QChart();
    // 将图例隐藏
    tchart->legend()->hide();
    // 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
    tchart->addSeries(series);
    // 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
    series->setUseOpenGL(true);
    // 创建默认的坐标系（笛卡尔坐标）
    tchart->createDefaultAxes();
    // 设置图表标题
    tchart->setTitle(QStringLiteral("温度折线图"));
}


