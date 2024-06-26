#include "filemanage.h"
#include "productdata.h"

FileManage::FileManage() {}


void FileManage::saveToFile(const QString &data, const char type){

    QFile file(type == 'b' ? m_fileNameProduction : m_fileNameReports);

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        if (file.pos() == 0) {
            stream << data;
        } else {
            stream << "\n" << data;
        }
        file.close();
        qDebug() << "Dane zostały zapisane do pliku " << (type == 'b' ? m_fileNameProduction : m_fileNameReports);
    } else {
        qDebug() << "Nie można otworzyć pliku" << (type == 'b' ? m_fileNameProduction : m_fileNameReports) << "do zapisu";
    }
}

QVector<QPair<QString,QString>> FileManage::getFromFile(const char type){
    QVector<QPair<QString, QString>> reportData;
    QFile file(type == 'b' ? m_fileNameProduction : m_fileNameReports);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while (!in.atEnd()){
            QString line = in.readLine();
            QStringList parts = line.split('\t');
            if(parts.size() == 2){
                QString reportDescription = parts[0];
                QString reportDate = parts[1];

                reportData.append(qMakePair(reportDescription,reportDate));
            }
            else{
                qDebug() << "Bledny format danych";
            }
        }

        file.close();
        return reportData;
    }
    else{
        qDebug() << "Nie udalo sie wczytac pliku";
        return reportData;
    }
}

void FileManage::removeFromFile(const QString &reportDescription, QString &reportDate, const char type){
    QFile file(type == 'b' ? m_fileNameProduction : m_fileNameReports);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QVector<QPair<QString, QString>> reportData;
        QTextStream in(&file);
        while (!in.atEnd()){
            QString line = in.readLine();
            QStringList parts = line.split('\t');
            if(parts.size() == 2){
                QString description = parts[0];
                QString date = parts[1];
                if(description !=  reportDescription || date != reportDate)
                {
                    reportData.append(qMakePair(description,date));
                }
            }
            else{
                qDebug() << "Bledny format danych";
            }
        }

        file.close();
        if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
            QTextStream out(&file);
            for(const auto &data:reportData){
                qDebug() << data.first << " " << data.second;
                out << data.first << "\t" << data.second << '\n';
            }
        }
    }
    else{
        qDebug() << "Nie udalo sie wczytac pliku";
    }
}

// Funkcja do przetwarzania danych z pliku
QVector<int> FileManage::getProductionFromFile(const char type) {
    QFile file(type == 'b' ? m_fileNameProduction : m_fileNameReports);
    QVector<int> itemCounts;
    QDate today = QDate::currentDate();

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split('\t');
            int id = parts[0].toInt();
            int quantity = parts[1].toInt();
            QDateTime dateTime = QDateTime::fromString(parts[2], "dd.MM.yyyy-hh:mm:ss");
            if (dateTime.date() == today) {
                if (id >= itemCounts.size()) {
                    itemCounts.resize(id);
                }
                itemCounts[id-1] += quantity;
            }
        }
    }
    else {
        qWarning() << "Nie można otworzyć pliku:";
        return itemCounts;
    }
    file.close();
    return itemCounts;
}

QVector<ProductData> FileManage::getAllProduction(const char type) {
    QVector<ProductData> data;

    QFile file(type == 'b' ? m_fileNameProduction : m_fileNameReports);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split('\t');
            if (parts.size() == 3) {
                ProductData product;
                product.id = parts[0].toInt();
                product.quantity = parts[1].toInt();
                product.date = QDateTime::fromString(parts[2], "dd.MM.yyyy-hh:mm:ss");
                if (product.date.isValid()) {
                    data.append(product);
                } else {
                    qWarning() << "Invalid date format in line:" << line;
                }
            } else {
                qWarning() << "Invalid line format:" << line;
            }
        }
    }
    else {
        qWarning() << "Nie można otworzyć pliku:";
        return data;
    }
    file.close();
    return data;
}

