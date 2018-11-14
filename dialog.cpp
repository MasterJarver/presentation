#include "dialog.h"
#include "ui_dialog.h"
#include "filter.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(this, &Dialog::insertDevice, this, &Dialog::addDevice);
    //QWidget::setWindowState(Qt::WindowState::WindowFullScreen); // сетит окно в фуллскрин
    layout()->setAlignment(Qt::AlignVCenter);
    emit insertDevice();
    //emit insertDevice();

    installEventFilter(new filter(this, this));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addDevice() // добавляет новый item в вектор и отрисовывает на view
{

    count = inputs.size();
    inputs.append(new ItemLayout(QString("Device %1").arg(QString::number(++count)))); // в конец
    ui->verticalLayout->addLayout(inputs.at(count - 1));
    ui->verticalLayout->setMargin(200);
    connect(inputs.at(count - 1), &ItemLayout::signalToDeleteItem, this, &Dialog::deleteDevice);
    connect(inputs.at(count - 1), &ItemLayout::signalToSendReference, this, &Dialog::sendReference);
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
}

void Dialog::sendReference(ItemLayout *item) // выполняется по нажатию кнопки Ok
{
    qDebug() << "insert into sendReference()";
    layout()->removeWidget(item->getOk());
    delete item->getOk();
    layout()->removeWidget(item->getCancel());
    delete item->getCancel();
    layout()->removeWidget(item->getCamera());
    delete item->getCamera();
    layout()->removeWidget(item->getEmail());
    delete item->getEmail();
    inputs.removeAt(inputs.indexOf(item)); // удаляем объект из вектора, тут траблов нет
}

void Dialog::insertNewDevice()
{
    emit insertDevice();
}
