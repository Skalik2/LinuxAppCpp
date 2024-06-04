#ifndef FILEMANAGE_H
#define FILEMANAGE_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <QPair>
#include <QDateTime>

#include "productdata.h"

class FileManage
{
    QString m_fileNameProduction = QString("baza.data");
    QString m_fileNameReports = QString("reports.data");
public:
    FileManage();
    void saveToFile(const QString &data, const char type);
    QVector<QPair<QString,QString>> getFromFile(const char type);
    void removeFromFile(const QString &reportDescription, QString &reportDate, const char type);
    QVector<int> getProductionFromFile(const char type);
    QVector<ProductData> getAllProduction(const char type);
    void saveAllProduction(const char type);
};

#endif // FILEMANAGE_H
