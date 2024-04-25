#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "misc.h"

#include <QDebug>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir assetsDir(QCoreApplication::applicationDirPath() + "/Assets");
    QPixmap zdjecieTest(assetsDir.absolutePath() + "/tit.png");
    QPixmap imgPipeQ(assetsDir.absolutePath() + "/pipe.png");
    QPixmap imgGussetQ(assetsDir.absolutePath() + "/gusset.png");
    QPixmap imgHollowQ(assetsDir.absolutePath() + "/hollow.png");
    QPixmap imgFilledQ(assetsDir.absolutePath() + "/filled.png");
    QPixmap imgSheetQ(assetsDir.absolutePath() + "/sheet.png");
    QPixmap imgTriangleQ(assetsDir.absolutePath() + "/triangle.png");
    QPixmap imgHexQ(assetsDir.absolutePath() + "/hex.png");
    QPixmap imgPentaQ(assetsDir.absolutePath() + "/penta.png");
    QPixmap imgBendUQ(assetsDir.absolutePath() + "/bendU.png");
    QPixmap imgSquareBendQ(assetsDir.absolutePath() + "/squareBend.png");
    QPixmap imgSquareFilledQ(assetsDir.absolutePath() + "/squareFilled.png");
    // QString result = getConsoleOutput("whoami");
    // ui->labelUserName->setText(result);
    ui->zdjecie->setPixmap(zdjecieTest.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgPipe->setPixmap(imgPipeQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgGusset->setPixmap(imgGussetQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgHollow->setPixmap(imgHollowQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgFilled->setPixmap(imgFilledQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgSheet->setPixmap(imgSheetQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgTriangle->setPixmap(imgTriangleQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgHex->setPixmap(imgHexQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgPenta->setPixmap(imgPentaQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgBendU->setPixmap(imgBendUQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgSquareBend->setPixmap(imgSquareBendQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->imgSquareFilled->setPixmap(imgSquareFilledQ.scaled(100,100, Qt::KeepAspectRatio));
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonClose_clicked()
{
    std::system("shutdown now");
}


void MainWindow::closeEvent(QCloseEvent *event){
    //event->ignore();
}


void MainWindow::on_pushButton_clicked()
{

}

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(4);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_pushButton1_clicked()
{
    if (ui->spinBox1->value()!= 0){
        ui->listWidget->addItem( "[#1] "+ QString::fromStdString(std::to_string(ui->spinBox1->value())) + "x Armored steel channel 40x10x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}


void MainWindow::on_pushButton2_clicked()
{
    if (ui->spinBox2->value()!= 0){
        ui->listWidget->addItem( "[#2] "+ QString::fromStdString(std::to_string(ui->spinBox2->value())) + "x Steel profile H-type 30x20x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton3_clicked()
{
    if (ui->spinBox3->value()!= 0){
        ui->listWidget->addItem( "[#3] "+ QString::fromStdString(std::to_string(ui->spinBox3->value())) + "x Steel closed square profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton4_clicked()
{
    if (ui->spinBox4->value()!= 0){
        ui->listWidget->addItem( "[#4] "+ QString::fromStdString(std::to_string(ui->spinBox4->value())) + "x Steel profile O-type 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}


void MainWindow::on_pushButton5_clicked()
{
    if (ui->spinBox5->value()!= 0){
        ui->listWidget->addItem( "[#5] "+ QString::fromStdString(std::to_string(ui->spinBox5->value())) + "x Steel profile O-type 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton6_clicked()
{
    if (ui->spinBox6->value()!= 0){
        ui->listWidget->addItem( "[#6] "+ QString::fromStdString(std::to_string(ui->spinBox6->value())) + "x Steel profile O-type 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton1_3_clicked()
{
    if (ui->spinBox1_1->value()!= 0){
        ui->listWidget->addItem( "[#7] "+ QString::fromStdString(std::to_string(ui->spinBox1_1->value())) + "x Steel profile O-type 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton2_2_clicked()
{
    if (ui->spinBox2_1->value()!= 0){
        ui->listWidget->addItem( "[#8] "+ QString::fromStdString(std::to_string(ui->spinBox2_1->value())) + "x Steel profile O-type 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton3_2_clicked()
{
    if (ui->spinBox3_1->value()!= 0){
        ui->listWidget->addItem( "[#9] "+ QString::fromStdString(std::to_string(ui->spinBox3_1->value())) + "x Steel profile O-type 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}


void MainWindow::on_pushButton4_2_clicked()
{
    if (ui->spinBox4_1->value()!= 0){
        ui->listWidget->addItem( "[#10] "+ QString::fromStdString(std::to_string(ui->spinBox4_1->value())) + "x Steel soft U-bend circle profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton5_2_clicked()
{
    if (ui->spinBox5_1->value()!= 0){
        ui->listWidget->addItem( "[#11] "+ QString::fromStdString(std::to_string(ui->spinBox5_1->value())) + "x Steel soft U-bend circle profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton6_2_clicked()
{
    if (ui->spinBox6_1->value()!= 0){
        ui->listWidget->addItem( "[#12] "+ QString::fromStdString(std::to_string(ui->spinBox6_1->value())) + "x Steel soft U-bend circle profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    delete item;
}


void MainWindow::on_pushButtonCancel_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->listWidget->clear();
}


void MainWindow::on_pushButtonProduction_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


