#include "filter.h"

filter::filter(Dialog* dialog, QObject *parent) : QObject(parent), m_dialog(dialog)
{

}

bool filter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        qDebug("Ate key press %d", keyEvent->key());
        if (keyEvent->key() == Qt::Key_Alt) { // добавление полей по нажатию alt
            m_dialog->insertNewDevice();
        }
//        if(keyEvent->key() == Qt::Key_Escape) // отмена фокуса по нажатию esc
//        {
//            // тут меняем фокус итема

//            if(keyEvent->key() == Qt::Key_Escape) // по нажатию дважды esc выход из приложения
//            {
//                exit(0); // выходим из приложения
//            }
//        }
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
