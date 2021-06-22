#ifndef REALTIMECURVEQCHARTWIDGET_H
#define REALTIMECURVEQCHARTWIDGET_H

#include <QWidget>
#include <QList>

#include <QSplineSeries>
#include <QScatterSeries>
#include <QChart>
#include <QChartView>

using namespace QtCharts;

class RealTimeCurveQChartWidget : public QWidget {
    Q_OBJECT

public:
    explicit RealTimeCurveQChartWidget(QWidget *parent = 0);
    ~RealTimeCurveQChartWidget();

    QChart *chart;
    int newData;

    void dataReceived(int value);

protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

private:
    /**
     * 接收到数据源发送来的数据，数据源可以下位机，采集卡，传感器等。
     */

    int timerId;
    int maxSize;  // data 最多存储 maxSize 个元素
    int maxX;
    int maxY;
    QList<double> data; // 存储业务数据的 list

    QSplineSeries *splineSeries;
    QScatterSeries *scatterSeries;
};

#endif // REALTIMECURVEQCHARTWIDGET_H
