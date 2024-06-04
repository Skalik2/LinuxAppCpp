#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "qlistwidget.h"
#include "usermanipulation.h"

#include <QMainWindow>
#include <QCloseEvent>
#include <QDir>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QProcess>
#include <QMovie>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

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
    void setLabelText(int labelId, int amountToAdd);
    void buttonFunctions();
private slots:
    void loadReports();
    void setProductionTable();
    void loadProduction();
    void loadAllProduction();
    void saveAllProduction();
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
    void on_pushButtonReturn_clicked();
    void on_pushButtonReturn_2_clicked();
    void on_pushButtonReport_clicked();
    void on_pushButtonLogoutAdm_clicked();
    void on_pushButtonLogout_clicked();
    void on_pushButton_2_clicked();
    void on_pushButtonReturn_3_clicked();
    void on_pushButton_clicked();
    void on_pushButtonReport_2_clicked();
    void on_listWidget_2_itemClicked(QListWidgetItem *item);
    void on_pushButtonReturn_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButtonToday_2_clicked();
    void on_pushButtonReturn_6_clicked();
    void on_pushButtonReturn_7_clicked();
    void on_pushButtonReport_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButtonReturn_8_clicked();
    void on_pushButtonClearAddUser_clicked();
    void on_pushButtonClearDelUser_clicked();
};
#endif // MAINWINDOW_H
