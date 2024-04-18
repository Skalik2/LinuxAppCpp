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

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton1_clicked()
{
    if (ui->spinBox1->value()!= 0){
        ui->labelCount1->setNum((ui->labelCount1->text()).toInt() + ui->spinBox1->value());
        ui->listWidget->addItem( QString::fromStdString(std::to_string(ui->spinBox1->value())) + "x Armored steel channel 30x10x120cm |");
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}


void MainWindow::on_pushButton2_clicked()
{
    if (ui->spinBox2->value()!= 0){
        ui->labelCount2->setNum((ui->labelCount2->text()).toInt() + ui->spinBox2->value());
        ui->listWidget->addItem( QString::fromStdString(std::to_string(ui->spinBox2->value())) + "x Steel profile H-type 30x20x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton3_clicked()
{
    if (ui->spinBox3->value()!= 0){
        ui->labelCount3->setNum((ui->labelCount3->text()).toInt() + ui->spinBox3->value());
        ui->listWidget->addItem( QString::fromStdString(std::to_string(ui->spinBox3->value())) + "x Steel closed square profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton4_2_clicked()
{
    if (ui->spinBox4_2->value()!= 0){
        ui->labelCount4_2->setNum((ui->labelCount4_2->text()).toInt() + ui->spinBox4_2->value());
        ui->listWidget->addItem( QString::fromStdString(std::to_string(ui->spinBox4_2->value())) + "x Steel soft U-bend circle profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toString("dd.MM.yyyy-hh:mm:ss"));
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

