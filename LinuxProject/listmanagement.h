#ifndef LISTMANAGEMENT_H
#define LISTMANAGEMENT_H

#include "qlistwidget.h"
#include <QWidget>
#include <QString>

class listManagement
{
public:
    void addItem(QListWidget &widget, QString message);
    void removeItem(QListWidget &widget, QListWidgetItem *item);
    listManagement();
};

#endif // LISTMANAGEMENT_H
