#ifndef ITEMLAYOUT_H
#define ITEMLAYOUT_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QRegExp>
#include <QDebug>
#include <QVector>
class ItemLayout : public QHBoxLayout // QWidget
{
Q_OBJECT
public:
    ItemLayout(const QString& itemName, QWidget* parent = nullptr);
    ItemLayout* getInputElement(); // возвращает сет элементов для ввода
    QWidget* getCancel(); // возвращает указатель на кнопку cancel
    QWidget* getOk();
    QWidget* getCamera();
    QWidget* getEmail();
private:
    const int height = 80;
    const int width = 200;
    QPushButton* ok;
    QLabel* camera;
    QLineEdit* email;
    QFont font;
    QPushButton* cancel;
signals:
    void signalToDeleteItem(ItemLayout* item); // синал о удалении инпута
    void signalToSendReference(ItemLayout* item); // сигнал о отправке ссылки
public slots:
    void blockButton(QString s);
    void signalForDialog(); // сигнал диалогу о удалении элемента
    void signalForDialogOk(); // сигнал диалогу об отправке ссылки
};
#endif // ITEMLAYOUT_H
