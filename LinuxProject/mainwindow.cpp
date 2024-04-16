#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "misc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap zdjecieTest("/home/skalik/Dokumenty/GitHub/LinuxAppCpp/LinuxProject/tit.png");
    QPixmap imgPipeQ("/home/skalik/Dokumenty/GitHub/LinuxAppCpp/LinuxProject/pipe.png");
    QPixmap imgGussetQ("/home/skalik/Dokumenty/GitHub/LinuxAppCpp/LinuxProject/gusset.png");
    QPixmap imgHollowQ("/home/skalik/Dokumenty/GitHub/LinuxAppCpp/LinuxProject/hollow.png");
    QPixmap imgFilledQ("/home/skalik/Dokumenty/GitHub/LinuxAppCpp/LinuxProject/filled.png");
    // QString result = getConsoleOutput("whoami");
    // ui->labelUserName->setText(result);
    ui->zdjecie->setPixmap(zdjecieTest.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgPipe->setPixmap(imgPipeQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgGusset->setPixmap(imgGussetQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgHollow->setPixmap(imgHollowQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgFilled->setPixmap(imgFilledQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->stackedWidget->setCurrentIndex(0);

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

void MainWindow::closeEvent(QCloseEvent *event){
    event->ignore();
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton1_clicked()
{
    ui->labelCount1->setNum((ui->labelCount1->text()).toInt() + ui->spinBox1->value());
}

