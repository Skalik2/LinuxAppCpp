#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
