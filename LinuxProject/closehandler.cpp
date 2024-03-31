#include "closehandler.h"


bool CloseHandler::eventFilter(QObject* obj, QEvent* event)
{
    if(obj->isWidgetType()) {
        switch(event->type()) {
         case QEvent::Close: {
            if(m_flag){
                event->ignore();
                return true;
            }
            break;
        }
        case QEvent::KeyPress: {
            auto keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F4 && keyEvent->modifiers() == Qt::AltModifier) {
                m_flag = true;
            }
            break;
        }
        default:
            break;
        }
    }
    return QObject::eventFilter(obj,event);
}
