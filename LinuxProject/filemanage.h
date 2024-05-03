#ifndef FILEMANAGE_H
#define FILEMANAGE_H

#include <QString>
#include <QFile>
#include <QDebug>

class FileManage
{
    QString m_fileName = QString("baza.data");
public:
    FileManage();
    void saveToFile(const QString &data);
};

#endif // FILEMANAGE_H
