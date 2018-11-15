#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include "itemlayout.h"
class ItemLayout;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QVector<ItemLayout*> getInputs(); // возвращает вектор инпутов
    ItemLayout* getFocusElement(); // возвращает указатель на элемент в фокусе
    void setFocusElement(int index); // сетит фокус
    int getCount(); // возвращает количество элементов в векторе
private:    
    ItemLayout* focusElement = nullptr; // указатель на элемент в фокусе
    QVector<ItemLayout*> inputs; // вектор для хранения inputs
    int count = 0; // счетчик девайсов
    Ui::Dialog *ui;
signals:
    void insertDevice(); // сигнал имитирующий подключение флешки
public slots:
    void addDevice(); // отрисовывает новую строку для ввода
    void deleteDevice(ItemLayout* item); // слот удаляющий поле ввода
    void sendReference(ItemLayout* item); // слот отправляющий ссылку на почту(Ok)
    void insertNewDevice();
};

#endif // DIALOG_H
