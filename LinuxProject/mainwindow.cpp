#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "misc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QString result = getConsoleOutput("whoami");
    // ui->labelUserName->setText(result);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonClose_clicked()
{
    std::system("shutdown now");
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEditLogin->clear();
    ui->lineEditPassword->clear();
    ui->labelInfo->clear();
}

void MainWindow::on_pushButtonSubmit_clicked()
{
    QString number = ui->lineEditLogin->text();
    try {
        if(number.contains("20")){
            ui->labelInfo->setText("Super");
        }
        else{
            throw(number);
        }
    } catch (QString num) {
        ui->labelInfo->setText("No match: "+num);
    }
}


