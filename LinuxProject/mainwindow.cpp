#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "misc.h"
#include "filemanage.h"

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
    if(QString::fromUtf8(result).trimmed() == QString("admin")){
        ui->stackedWidget->setCurrentIndex(3);
        ui->labelUserNameAdmin->setText("User: " + QString::fromUtf8(result));
    }
    else{
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(1);

        ui->labelUserName->setText("User: " + QString::fromUtf8(result));
    }


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


    labels.append(ui->labelCount1);
    labels.append(ui->labelCount2);
    labels.append(ui->labelCount3);
    labels.append(ui->labelCount4);
    labels.append(ui->labelCount5);
    labels.append(ui->labelCount6);
    labels.append(ui->labelCount1_2);
    labels.append(ui->labelCount2_2);
    labels.append(ui->labelCount3_2);
    labels.append(ui->labelCount4_2);
    labels.append(ui->labelCount5_2);
    labels.append(ui->labelCount6_2);

    QMovie *movie = new QMovie(assetsDir.absolutePath()+"/loading.gif");
    ui->loadingLabel->setMovie(movie);
    ui->loadingLabel->show();
    movie->start();
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

    //Main page handling

void MainWindow::on_pushButtonProduction_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonToday_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButtonReport_clicked()
{
    //TODO: report page
}
    //End of main page handling


    //Handling production page

void MainWindow::buttonFunctions(){
    ui->listWidget->setEnabled(true);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButtonReturn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton1_clicked()
{
    if (ui->spinBox1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#1] "+ QString::fromStdString(std::to_string(ui->spinBox1->value())) + "x Armored steel channel 40x10x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton2_clicked()
{
    if (ui->spinBox2->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#2] "+ QString::fromStdString(std::to_string(ui->spinBox2->value())) + "x Steel profile H-type 30x20x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton3_clicked()
{
    if (ui->spinBox3->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#3] "+ QString::fromStdString(std::to_string(ui->spinBox3->value())) + "x Steel closed square profile 30x30x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton4_clicked()
{
    if (ui->spinBox4->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#4] "+ QString::fromStdString(std::to_string(ui->spinBox4->value())) + "x Steel pipe O-type 20x120cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton5_clicked()
{
    if (ui->spinBox5->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#5] "+ QString::fromStdString(std::to_string(ui->spinBox5->value())) + "x Steel rod O-type 1x200cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton6_clicked()
{
    if (ui->spinBox6->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#6] "+ QString::fromStdString(std::to_string(ui->spinBox6->value())) + "x Steel sheet 100x100x0.3cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton1_2_clicked()
{
    if (ui->spinBox1_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#7] "+ QString::fromStdString(std::to_string(ui->spinBox1_1->value())) + "x Steel pipe triangle-type 6x40cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton2_2_clicked()
{
    if (ui->spinBox2_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#8] "+ QString::fromStdString(std::to_string(ui->spinBox2_1->value())) + "x Steel pipe hexagon-type 2x20cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton3_2_clicked()
{
    if (ui->spinBox3_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#9] "+ QString::fromStdString(std::to_string(ui->spinBox3_1->value())) + "x Steel pipe hexagon-type 5x40cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton4_2_clicked()
{
    if (ui->spinBox4_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#10] "+ QString::fromStdString(std::to_string(ui->spinBox4_1->value())) + "x Steel soft U-bend circle profile 20cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton5_2_clicked()
{
    if (ui->spinBox5_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#11] "+ QString::fromStdString(std::to_string(ui->spinBox5_1->value())) + "x Steel soft U-bend square profile 30x30cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButton6_2_clicked()
{
    if (ui->spinBox6_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#12] "+ QString::fromStdString(std::to_string(ui->spinBox6_1->value())) + "x Steel rod rectangle-type 2x2x200cm |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
    }
}

void MainWindow::on_pushButtonCancel_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->listWidget->clear();
}

void MainWindow::on_pushButtonSubmit_2_clicked()
{
    if(ui->checkBox->isChecked()){
        ui->labelError->setText(QString("Sent succesfully"));
        ui->listWidget->setEnabled(false);
        //delay(1000);
        ui->stackedWidget_2->setCurrentIndex(1);
        FileManage f;
        for(int i = 0; i < ui->listWidget->count(); i++){
            QListWidgetItem *item = ui->listWidget->item(i);
            if (item->text().at(3).isNumber()){
                if (item->text().at(7).isNumber()){
                    f.saveToFile(item->text().mid(2,2) + "\t" + item->text().mid(6,2) + "\t" + item->text().mid(item->text().length() - 19,19));
                }else{
                    f.saveToFile(item->text().mid(2,2) + "\t" + item->text().mid(6,1) + "\t" + item->text().mid(item->text().length() - 19,19));
                }
            }
            else{
                if (item->text().at(6).isNumber()){
                    f.saveToFile(item->text().mid(2,1) + "\t" + item->text().mid(5,2) + "\t" + item->text().mid(item->text().length() - 19,19));
                }else{
                    f.saveToFile(item->text().mid(2,1) + "\t" + item->text().mid(5,1) + "\t" + item->text().mid(item->text().length() - 19,19));
                }
            }
        }
        ui->labelError->setText(QString(""));
        ui->listWidget->clear();
        ui->checkBox->setChecked(false);
    }
    else{
        ui->labelError->setText(QString("You need to accept first!"));
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    delete item;
    if(ui->listWidget->count() == 0){
        delay(500);
        ui->stackedWidget_2->setCurrentIndex(1);
    }
}

    //End of production handling


    //

void MainWindow::on_pushButtonReturn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButtonLogoutAdm_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QProcess process;
    QDir assetsDir(QCoreApplication::applicationDirPath() + "/Scripts/./logout.sh");
    process.start(assetsDir.absolutePath());
    process.waitForFinished(-1);
}


void MainWindow::on_pushButtonLogout_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QProcess process;
    QDir assetsDir(QCoreApplication::applicationDirPath() + "/Scripts/./logout.sh");
    process.start(assetsDir.absolutePath());
    process.waitForFinished(-1);
}

