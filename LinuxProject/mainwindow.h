#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlistwidget.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QDir>
#include <QDateTime>

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonSubmit_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButton3_clicked();
    void on_pushButton4_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButtonCancel_clicked();
};
#endif // MAINWINDOW_H
