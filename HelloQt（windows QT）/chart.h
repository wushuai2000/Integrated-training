#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <QApplication>
#include <QChartView>
#include <QLineSeries>
#include <QLabel>
QT_CHARTS_USE_NAMESPACE


class chart : public QWidget
{
    Q_OBJECT
public:
    explicit chart(QWidget *parent = nullptr);
    QLineSeries *series;
    QChart *tchart;

    void draw_point(std::list<std::pair<int,int>> lt);
signals:

public slots:

};

#endif // CHART_H
