#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "misc.h"
#include "filemanage.h"
#include "productdata.h"

QVector<QString> productNames = {
    "Armored steel channel 40x10x120cm",
    "Steel profile H-type 30x20x120cm",
    "Steel closed square profile 30x30x120cm",
    "Steel pipe O-type 20x120cm",
    "Steel rod O-type 1.50x200cm",
    "Steel sheet 100x100x0.30cm",
    "Steel pipe triangle-type 6x40cm",
    "Steel pipe hexagon-type 2x20cm",
    "Steel pipe hexagon-type 5x40cm",
    "Steel soft U-bend circle profile 20cm",
    "Steel soft U-bend square profile 30x30cm",
    "Steel rod rectangle-type 2x2x200cm"
};

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
    if(true){//QString::fromUtf8(result).trimmed() == QString("admin")){
        ui->stackedWidget->setCurrentIndex(3);
        ui->labelUserNameAdmin->setText("Admin: " + QString::fromUtf8(result));
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

    /*ui->stackedWidget->setCurrentIndex(0); - menu
     *ui->stackedWidget->setCurrentIndex(1); - production
     *ui->stackedWidget->setCurrentIndex(2); - today's manifacture
     *ui->stackedWidget->setCurrentIndex(3); - admin menu
     *ui->stackedWidget->setCurrentIndex(4); - loading
     *ui->stackedWidget->setCurrentIndex(5); - report
     *ui->stackedWidget->setCurrentIndex(6); - admin reports
     *ui->stackedWidget->setCurrentIndex(7); - admin production
    */


}

void MainWindow::loadReports(){
    FileManage f;
    QVector<QPair<QString,QString>> data = f.getFromFile('r');
    int i = 1;
    ui->listWidget_2->clear();
    ui->textEdit_2->clear();
    for(const auto &elements: data)
    {
        QString itemText = QString("Report[%1]:\n%2\nDate\n%3\n").arg(QString::number(i),elements.first, elements.second);
        ui->listWidget_2->addItem(itemText);
        i+=1;
    }
    if (ui->textEdit_2->toPlainText().isEmpty()){
        ui->textEdit_2->setText(QString("No reports found!"));
    }
}


void MainWindow::setProductionTable(){
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    QStringList headers;
    headers << "ID" << "Name" << "Quantity";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::loadProduction(){
    FileManage f;

    // Ustalenie liczby wierszy
    QVector<int> production = f.getProductionFromFile('b');
    if (ui->tableWidget->rowCount() < productNames.size()) {
        ui->tableWidget->setRowCount(productNames.size());
    }

    setProductionTable();

    // Wypełnienie wierszy danymi
    for (int i = 0; i < productNames.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
        QString productName = (i < productNames.size()) ? productNames[i] : "Unknown Product";
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(productName));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(0)));
    }
    for (int i = 0; i < production.size(); ++i){
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(production[i])));
    }
}

void MainWindow::loadAllProduction(){
    FileManage f;
    QVector<ProductData> data = f.getAllProduction('b');
    // Odwrócenie kolejności elementów w wektorze
    std::reverse(data.begin(), data.end());
    ui->listWidget_3->clear();
    for(const auto &product: data)
    {
        QString itemText = QString("ID: %1\t Quantity: %3\t Date Added: %4\t Product name: %2")
                               .arg(product.id)
                               .arg(productNames[product.id-1])
                               .arg(product.quantity)
                               .arg(product.date.toString("dd.MM.yyyy-hh:mm:ss"));
        qDebug() << itemText;
        ui->listWidget_3->addItem(itemText);
    }
}

void MainWindow::saveAllProduction()
{
    QFile file("baza.data");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    for (int i = ui->listWidget_3->count() - 1; i >= 0 ; i--) {
        QListWidgetItem *item = ui->listWidget_3->item(i);
        QString itemText = item->text();

        QStringList parts = itemText.split("\t");
        if (parts.size() >= 4) {
            QString id = parts[0].split(": ")[1];
            QString quantity = parts[2].split(": ")[1];
            QString dateAdded = parts[3].split(": ")[1];
            out << id << "\t" << quantity << "\t" << dateAdded;
        }
        if (i > 0) {
            out << "\n";
        }
    }

    file.close();
    }
    else {
    qWarning() << "Cannot open file for writing:" << file.errorString();
    return;
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

    //Main page handling

void MainWindow::on_pushButtonProduction_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonToday_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    loadProduction();
}

void MainWindow::on_pushButtonReport_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
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

void MainWindow::setLabelText(int labelId, int amountToAdd){
    QString labelText = labels[labelId]->text();
    int currentValue = labelText.toInt();
    int newValue = currentValue + amountToAdd;
    labels[labelId]->setText(QString::number(newValue));
}

void MainWindow::on_pushButton1_clicked()
{
    if (ui->spinBox1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#1] "+ QString::fromStdString(std::to_string(ui->spinBox1->value())) + "x "+ productNames[0] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(0,ui->spinBox1->value());
        ui->spinBox1->setValue(0);
    }
}

void MainWindow::on_pushButton2_clicked()
{
    if (ui->spinBox2->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#2] "+ QString::fromStdString(std::to_string(ui->spinBox2->value())) + "x "+ productNames[1] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(1,ui->spinBox2->value());
        ui->spinBox2->setValue(0);
    }
}

void MainWindow::on_pushButton3_clicked()
{
    if (ui->spinBox3->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#3] "+ QString::fromStdString(std::to_string(ui->spinBox3->value())) + "x "+ productNames[2] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(2,ui->spinBox3->value());
        ui->spinBox3->setValue(0);
    }
}

void MainWindow::on_pushButton4_clicked()
{
    if (ui->spinBox4->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#4] "+ QString::fromStdString(std::to_string(ui->spinBox4->value())) + "x "+ productNames[3] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(3,ui->spinBox4->value());
        ui->spinBox4->setValue(0);
    }
}

void MainWindow::on_pushButton5_clicked()
{
    if (ui->spinBox5->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#5] "+ QString::fromStdString(std::to_string(ui->spinBox5->value())) + "x "+ productNames[4] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(4,ui->spinBox5->value());
        ui->spinBox5->setValue(0);
    }
}

void MainWindow::on_pushButton6_clicked()
{
    if (ui->spinBox6->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#6] "+ QString::fromStdString(std::to_string(ui->spinBox6->value())) + "x "+ productNames[5] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(5,ui->spinBox6->value());
        ui->spinBox6->setValue(0);
    }
}

void MainWindow::on_pushButton1_2_clicked()
{
    if (ui->spinBox1_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#7] "+ QString::fromStdString(std::to_string(ui->spinBox1_1->value())) + "x "+ productNames[6] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(6,ui->spinBox1_1->value());
        ui->spinBox1_1->setValue(0);
    }
}

void MainWindow::on_pushButton2_2_clicked()
{
    if (ui->spinBox2_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#8] "+ QString::fromStdString(std::to_string(ui->spinBox2_1->value())) + "x "+ productNames[7] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(7,ui->spinBox2_1->value());
        ui->spinBox2_1->setValue(0);
    }
}

void MainWindow::on_pushButton3_2_clicked()
{
    if (ui->spinBox3_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#9] "+ QString::fromStdString(std::to_string(ui->spinBox3_1->value())) + "x "+ productNames[8] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(8,ui->spinBox3_1->value());
        ui->spinBox3_1->setValue(0);
    }
}

void MainWindow::on_pushButton4_2_clicked()
{
    if (ui->spinBox4_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#10] "+ QString::fromStdString(std::to_string(ui->spinBox4_1->value())) + "x "+ productNames[9] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(9,ui->spinBox4_1->value());
        ui->spinBox4_1->setValue(0);
    }
}

void MainWindow::on_pushButton5_2_clicked()
{
    if (ui->spinBox5_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#11] "+ QString::fromStdString(std::to_string(ui->spinBox5_1->value())) + "x "+ productNames[10] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(10,ui->spinBox5_1->value());
        ui->spinBox5_1->setValue(0);
    }
}

void MainWindow::on_pushButton6_2_clicked()
{
    if (ui->spinBox6_1->value()!= 0){
        buttonFunctions();
        ui->listWidget->addItem( "[#12] "+ QString::fromStdString(std::to_string(ui->spinBox6_1->value())) + "x "+ productNames[11] +" |" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm:ss"));
        setLabelText(11,ui->spinBox6_1->value());
        ui->spinBox6_1->setValue(0);
    }
}

void MainWindow::on_pushButtonCancel_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->listWidget->clear();
    for (auto i:labels)
    {
        i->setText("0");
    }
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
                    f.saveToFile(item->text().mid(2,2) + "\t" + item->text().mid(6,2) + "\t" + item->text().mid(item->text().length() - 19,19), 'b');
                }else{
                    f.saveToFile(item->text().mid(2,2) + "\t" + item->text().mid(6,1) + "\t" + item->text().mid(item->text().length() - 19,19), 'b');
                }
            }
            else{
                if (item->text().at(6).isNumber()){
                    f.saveToFile(item->text().mid(2,1) + "\t" + item->text().mid(5,2) + "\t" + item->text().mid(item->text().length() - 19,19), 'b');
                }else{
                    f.saveToFile(item->text().mid(2,1) + "\t" + item->text().mid(5,1) + "\t" + item->text().mid(item->text().length() - 19,19), 'b');
                }
            }
        }
        for (auto i:labels)
        {
            i->setText("0");
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
    int id, amount;
    QStringList parts = item->text().split(" ");
    QRegularExpression re("\\d+");
    QRegularExpressionMatch idExpression = re.match(parts[0]);
    QRegularExpressionMatch amountExpression = re.match(parts[1]);

    QString numberString = idExpression.captured(0);
    id = numberString.toInt();
    numberString = amountExpression.captured(0);
    amount = numberString.toInt();

    QString labelText = labels[id-1]->text();
    int currentValue = labelText.toInt();
    int newValue = currentValue - amount;
    labels[id-1]->setText(QString::number(newValue));
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


void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}


void MainWindow::on_pushButtonReturn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_clicked()
{
    FileManage f;
    f.saveToFile(ui->textEdit->toPlainText() + "\t" + m_currentDate.currentDateTimeUtc().toLocalTime().toString("dd.MM.yyyy-hh:mm"),'r');
    ui->textEdit->clear();
    delay(500);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonReport_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    loadReports();
}


void MainWindow::on_listWidget_2_itemClicked(QListWidgetItem *item)
{
    ui->textEdit_2->setText(item->text());
}


void MainWindow::on_pushButtonReturn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_3_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidget_2->currentItem();
    if (selectedItem){
        FileManage f;
        QStringList parts = selectedItem->text().split('\n');
        f.removeFromFile(parts[1],parts[3],'r');
        loadReports();
    }
}


void MainWindow::on_pushButtonToday_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    loadAllProduction();
}


void MainWindow::on_pushButtonReturn_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButtonReturn_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButtonReport_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_pushButton_5_clicked()
{
    QString username = ui->lineEditLogin->text();
    QString password = ui->lineEditPassword->text();
    QString sudoPassword = ui->lineEditAdminPassword->text();

    userManipulation userManipul;
    userManipul.addUser(username, sudoPassword);
    userManipul.addPassword(username, password);

    ui->lineEditAdminPassword->clear();
    ui->lineEditLogin->clear();
    ui->lineEditPassword->clear();

    ui->labelErrorAdd->setText("User " + username + "added successfully");
    delay(500);
    ui->labelErrorAdd->setText("");
}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->checkBoxDelUser->isChecked()){
        QString username = ui->lineEditUserDel->text();
        QString sudoPassword = ui->lineEditAdminPassForDel->text();
        userManipulation userManipul;
        userManipul.userDel(username,sudoPassword);

        ui->lineEditAdminPassForDel->clear();
        ui->lineEditUserDel->clear();
        ui->labelErrorDel->setText("User " + username + "deleted successfully");
        delay(500);
        ui->labelErrorDel->setText("");
    }
    else{
        ui->labelErrorDel->setText("Confirm to proceed");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidget_3->currentItem();
    if (selectedItem) {
        delete ui->listWidget_3->takeItem(ui->listWidget_3->row(selectedItem));
    }
    saveAllProduction();
}


void MainWindow::on_pushButtonReturn_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButtonClearAddUser_clicked()
{
    ui->lineEditAdminPassword->clear();
    ui->lineEditLogin->clear();
    ui->lineEditPassword->clear();
}


void MainWindow::on_pushButtonClearDelUser_clicked()
{
    ui->lineEditAdminPassForDel->clear();
    ui->lineEditUserDel->clear();
}

