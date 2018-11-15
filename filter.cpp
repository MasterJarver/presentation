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
        if(keyEvent->key() == Qt::Key_Escape) // отмена фокуса по нажатию esc
        {
            // тут меняем фокус итема

            if(keyEvent->key() == Qt::Key_Escape) // по нажатию дважды esc выход из приложения
            {
                qApp->exit(0); // выходим из приложения
            }
        }
        if(keyEvent->key() == Qt::Key_Down) // если нажата кнопка стрелка вниз
        {
            int index = m_dialog->getInputs().indexOf(m_dialog->getFocusElement()); // нашли индекс элемента в фокусе
            qDebug() << "final index" << index;
            // тут меняем указатель на фокус
            if(index < m_dialog->getInputs().count() - 1)
            {
                m_dialog->getInputs().at(index + 1)->getEmail()->setFocus(Qt::FocusReason::ActiveWindowFocusReason); // сетит в фокус следующий элемент в UI
                m_dialog->setFocusElement(index + 1); // = m_dialog->getInputs().at(index + 1); // сетит указатель на фокус
            }
            qDebug() << "button Down was pushed";
        }
        if(keyEvent->key() == Qt::Key_Up)
        {
            int index = m_dialog->getInputs().indexOf(m_dialog->getFocusElement()); // нашли индекс элемента в фокусе
            if(index > 0)
            {
                m_dialog->getInputs().at(index - 1)->getEmail()->setFocus(Qt::FocusReason::ActiveWindowFocusReason); // сетит в фокус следующий элемент в UI
                m_dialog->setFocusElement(index - 1); // = m_dialog->getInputs().at(index + 1); // сетит указатель на фокус
            }
            qDebug() << "button Up was pushed";
        }
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
