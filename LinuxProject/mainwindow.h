#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "qlistwidget.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QDir>
#include <QDateTime>
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;
    QDateTime m_currentDate;
public:
    QVector<QLabel*> labels;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event) override;
    void buttonFunctions();
private slots:
    void on_pushButtonClose_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButton3_clicked();
    void on_pushButton4_2_clicked();
    void on_pushButtonCancel_clicked();
    void on_pushButtonProduction_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton2_2_clicked();
    void on_pushButton3_2_clicked();
    void on_pushButton5_2_clicked();
    void on_pushButton6_2_clicked();
    void on_pushButtonSubmit_2_clicked();
    void on_pushButtonToday_clicked();
    void on_pushButton1_2_clicked();
};
#endif // MAINWINDOW_H
