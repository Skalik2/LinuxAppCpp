#ifndef CLOSEHANDLER_H
#define CLOSEHANDLER_H

#include <QEvent>
#include <QKeyEvent>

class CloseHandler: public QObject {
private:
    bool m_flag;
protected:
    bool eventFilter(QObject* obj, QEvent* event);
};

#endif // CLOSEHANDLER_H
