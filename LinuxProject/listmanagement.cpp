#include "listmanagement.h"

listManagement::listManagement()
{

}

void listManagement::addItem(QListWidget &widget, QString message){
    widget.addItem(message);
}

void listManagement::removeItem(QListWidget &widget, QListWidgetItem *item){
    widget.removeItemWidget(item);
}
