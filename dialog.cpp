#include "dialog.h"
#include "ui_dialog.h"
#include "filter.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(this, &Dialog::insertDevice, this, &Dialog::addDevice);
    QWidget::setWindowState(Qt::WindowState::WindowFullScreen); // сетит окно в фуллскрин
    layout()->setAlignment(Qt::AlignVCenter);
    emit insertDevice();
    installEventFilter(new filter(this, this));
    focusElement = inputs.at(0); // сетим указатель на первый элемент в векторе
    inputs.at(0)->getEmail()->setStyleSheet("QLineEdit {background-color: #66A1D2; border-radius: 9px;}");
    inputs.at(0)->getOk()->setStyleSheet("QPushButton {background-color: #66A1D2; border-radius: 9px;}");
    inputs.at(0)->getCancel()->setStyleSheet("QPushButton {background-color: #66A1D2; border-radius: 9px;}");
    inputs.at(0)->getCamera()->setStyleSheet("QLabel {background-color: #66A1D2; border-radius: 9px; margin-left: 10px;}");
}

Dialog::~Dialog()
{
    delete ui;
}

QVector<ItemLayout *> Dialog::getInputs() // возвращает вектор инпутов
{
    return this->inputs;
}

ItemLayout *Dialog::getFocusElement()
{
    return this->focusElement;
}

void Dialog::setFocusElement(int index) // сетит фокус
{
    focusElement = inputs.at(index);
}

int Dialog::getCount()
{
    return this->count;
}

void Dialog::addDevice() // добавляет новый item в вектор и отрисовывает на view
{
    count = inputs.size();
    inputs.append(new ItemLayout(QString("Device %1").arg(QString::number(++count)))); // добавляем в конец
    ui->verticalLayout->addLayout(inputs.at(count - 1));
    ui->verticalLayout->setMargin(200);
    connect(inputs.at(count - 1), &ItemLayout::signalToDeleteItem, this, &Dialog::deleteDevice);
    connect(inputs.at(count - 1), &ItemLayout::signalToSendReference, this, &Dialog::sendReference);
    qDebug() << "add device method" << getInputs().at(inputs.size() - 1);
    qDebug() << "focus element: " << focusElement;
}

void Dialog::deleteDevice(ItemLayout* item) // выполняется по нажатию кнопки cancel
{
    qDebug() << "insert into deleteDevice()";
    int index = inputs.indexOf(item);
    qDebug() << "idex item in vector: " << index; // определили индекс объекта в векторе
    qDebug() << "ui->verticfalLayout: " << ui->verticalLayout;
    qDebug() << "item: " << item;
    layout()->removeWidget(item->getOk());
    delete item->getOk();
    layout()->removeWidget(item->getCancel());
    delete item->getCancel();
    layout()->removeWidget(item->getCamera());
    delete item->getCamera();
    layout()->removeWidget(item->getEmail());
    delete item->getEmail();
    inputs.removeAt(inputs.indexOf(item)); // удаляем объект из вектора, тут траблов нет
    if(inputs.count() == 0) // если инпутов нет
        qApp->exit(0); // выходим из приложения Qt с кодом 0
}

void Dialog::sendReference(ItemLayout *item) // выполняется по нажатию кнопки Ok
{
    qDebug() << "insert into sendReference()";
    //item->getCancel()->setFocus(Qt::FocusReason::ActiveWindowFocusReason); // работает корректно
    //inputs.at((inputs.indexOf(item)) + 1)->getEmail()->setFocus(Qt::FocusReason::ActiveWindowFocusReason); // смена фокуса на следующий итем
    layout()->removeWidget(item->getOk());
    delete item->getOk();
    layout()->removeWidget(item->getCancel());
    delete item->getCancel();
    layout()->removeWidget(item->getCamera());
    delete item->getCamera();
    layout()->removeWidget(item->getEmail());
    delete item->getEmail();
    inputs.removeAt(inputs.indexOf(item)); // удаляем объект из вектора, тут траблов нет
    if(inputs.count() == 0) // если инпутов нет
        qApp->exit(0); // выходим из приложения Qt с кодом 0
}

void Dialog::insertNewDevice()
{
    emit insertDevice();
}
