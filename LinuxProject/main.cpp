#include "mainwindow.h"
#include "closehandler.h"

#include <QApplication>
#include <QWidget>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QEvent>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Qt::WindowFlags flags = w.windowFlags();
    CloseHandler h;
    w.setWindowFlags(flags | Qt::WindowStaysOnTopHint);
    w.installEventFilter(&h);
    w.showFullScreen();
    return a.exec();
}
