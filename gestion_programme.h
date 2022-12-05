#ifndef GESTION_PROGRAMME_H
#define GESTION_PROGRAMME_H

#include <QMainWindow>
#include "emission.h"
#include <QTextStream>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPlainTextEdit>
#include <QPrinter>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include "arduino.h"
#include "incendie.h"
#include <QtCharts/QPieSlice>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <arduino.h>
QT_BEGIN_NAMESPACE
namespace Ui { class gestion_programme; }
QT_END_NAMESPACE

class gestion_programme : public QMainWindow
{
    Q_OBJECT

public:
    gestion_programme(QWidget *parent = nullptr);
    ~gestion_programme();
private slots:
    void on_pB_ajouter_clicked();
    void on_detett_clicked();
    void on_modifer_clicked();
    void on_pdf_clicked();
    void on_recherche_clicked();
    void on_actionplay_clicked();
    void on_actionstop_clicked();

    void on_Lid_clicked();

    void on_lduree1_clicked();

    void on_ltriidinvite_clicked();

    void on_satistique_clicked();

    void on_afficher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Excel_clicked();

private:
    Ui::gestion_programme *ui;
    Emission Em;
     arduino A ;
     QByteArray data;
    QMediaPlayer* player;
    QVideoWidget* vw;
};
#endif // GESTION_PROGRAMME_H
