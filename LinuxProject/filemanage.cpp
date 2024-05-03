#include "filemanage.h"

FileManage::FileManage() {}

void FileManage::saveToFile(const QString &data){
    QFile plik(m_fileName);

    if (plik.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&plik);
        if (plik.pos() == 0) {
            stream << data;
        } else {
            stream << "\n" << data;
        }
        plik.close();
        qDebug() << "Dane zostały zapisane do pliku" << m_fileName;
    } else {
        qDebug() << "Nie można otworzyć pliku" << m_fileName << "do zapisu";
    }
}
