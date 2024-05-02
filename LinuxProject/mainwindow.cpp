#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "misc.h"

#include <QDebug>
#include <QMessageBox>
#include <QFile>

#include <QProcess>

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

    //Displaying user name
    QProcess process;
    process.start("whoami");
    process.waitForFinished();
    QByteArray result = process.readAllStandardOutput();
    ui->labelUserName->setText("User: " + QString::fromUtf8(result));

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

    if(!QDir("productions").exists()){
        QDir().mkdir("productions");
    }
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

void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(4);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_pushButton1_clicked()
{
    if (ui->spinBox1->value()!= 0){
        ui->listWidget->addItem( "[#1] "+ QString::fromStdString(std::to_string(ui->spinBox1->value())) + "x Armored steel channel 40x10x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton2_clicked()
{
    if (ui->spinBox2->value()!= 0){
        ui->listWidget->addItem( "[#2] "+ QString::fromStdString(std::to_string(ui->spinBox2->value())) + "x Steel profile H-type 30x20x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton3_clicked()
{
    if (ui->spinBox3->value()!= 0){
        ui->listWidget->addItem( "[#3] "+ QString::fromStdString(std::to_string(ui->spinBox3->value())) + "x Steel closed square profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton4_clicked()
{
    if (ui->spinBox4->value()!= 0){
        ui->listWidget->addItem( "[#4] "+ QString::fromStdString(std::to_string(ui->spinBox4->value())) + "x Steel pipe O-type 20x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton5_clicked()
{
    if (ui->spinBox5->value()!= 0){
        ui->listWidget->addItem( "[#5] "+ QString::fromStdString(std::to_string(ui->spinBox5->value())) + "x Steel rod O-type 1x200cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton6_clicked()
{
    if (ui->spinBox6->value()!= 0){
        ui->listWidget->addItem( "[#6] "+ QString::fromStdString(std::to_string(ui->spinBox6->value())) + "x Steel sheet 100x100x0.3cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton1_2_clicked()
{
    if (ui->spinBox1_1->value()!= 0){
        ui->listWidget->addItem( "[#7] "+ QString::fromStdString(std::to_string(ui->spinBox1_1->value())) + "x Steel pipe triangle-type 6x40cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton2_2_clicked()
{
    if (ui->spinBox2_1->value()!= 0){
        ui->listWidget->addItem( "[#8] "+ QString::fromStdString(std::to_string(ui->spinBox2_1->value())) + "x Steel pipe hexagon-type 2x20cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton3_2_clicked()
{
    if (ui->spinBox3_1->value()!= 0){
        ui->listWidget->addItem( "[#9] "+ QString::fromStdString(std::to_string(ui->spinBox3_1->value())) + "x Steel pipe hexagon-type 5x40cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton4_2_clicked()
{
    if (ui->spinBox4_1->value()!= 0){
        ui->listWidget->addItem( "[#10] "+ QString::fromStdString(std::to_string(ui->spinBox4_1->value())) + "x Steel soft U-bend circle profile 20cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton5_2_clicked()
{
    if (ui->spinBox5_1->value()!= 0){
        ui->listWidget->addItem( "[#11] "+ QString::fromStdString(std::to_string(ui->spinBox5_1->value())) + "x Steel soft U-bend square profile 30x30cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton6_2_clicked()
{
    if (ui->spinBox6_1->value()!= 0){
        ui->listWidget->addItem( "[#12] "+ QString::fromStdString(std::to_string(ui->spinBox6_1->value())) + "x Steel rod rectangle-type 2x2x200cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    delete item;
    if(ui->listWidget->count() == 0){
        ui->stackedWidget_2->setCurrentIndex(1);
    }
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


void MainWindow::on_pushButtonToday_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButtonSubmit_2_clicked()
{
    if(ui->acceptCheckBox->isChecked()){
        QString today = m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy");
        QFile file("productions/production " + today + ".txt");
        QTextStream out(&file);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            qDebug() << "Could not open file for writing";
            return;
        }
        else{
        for(int i = 0 ; i < ui->listWidget->count(); i++){      //Save lines to file
            QListWidgetItem *item = ui->listWidget->item(i);
                if (item) {
                    QString text = item->text();
                    out << text << '\n';
                }
            }
        }
        file.close();
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->acceptCheckBox->setChecked(false);
        ui->listWidget->clear();
    }
    else {
        QMessageBox::warning(nullptr, "Warning", "Please check the confirmation box");
    }
}



