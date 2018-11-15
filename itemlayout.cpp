#include "itemlayout.h"
#include "mainwindow.h"
class MainWindow;
ItemLayout::ItemLayout(const QString& itemName, QWidget* parent) : // конструктор
    QHBoxLayout(parent), // дофига странная инициализация C++11
    ok(new QPushButton("Ok")),
    camera(new QLabel()),
    email(new QLineEdit()),
    cancel(new QPushButton("Cancel"))
{
    camera->setText(itemName);
    camera->font(); // добавляем свойство font к Label
    font.setPointSize(24); // устанавливаем размер шрифта
    camera->setFont(font); // задаем значение свойству Font

    email->setFont(font); // добавляем свойство Font в LineEdit
    email->setFixedSize(940, height);
    //email->setFixedHeight(height); // задаем фиксированную высоту
    email->setAlignment(Qt::AlignCenter); // выравниваем текст по центру

    font.setPointSize(13); // меняем размер шрифта
    ok->setFont(font); // добавляем свойство Font в кнопку
    ok->setFixedSize(QSize(width, height)); // задаем фиксированный размер кнопки
    ok->setDisabled(true); // сетим неактивность


    cancel->setFont(font); // добавляем свойство Font в кнопку cancel
    cancel->setFixedSize(QSize(width, height)); // задаем фиксированный размер

    addWidget(camera); // добавляем виджет camera
    addWidget(email); // добавляем виджет email
    addWidget(ok); // добавляем виджет ok
    addWidget(cancel); // добавляем виджет cancel
    connect(email, &QLineEdit::textChanged, this, &ItemLayout::blockButton); // вешаем коннект
    connect(cancel, &QPushButton::clicked, this, &ItemLayout::signalForDialog); // сигналит о нажатии Ok
    connect(ok, &QPushButton::clicked, this, &ItemLayout::signalForDialogOk); // сигналит о нажатии cancel

}

ItemLayout *ItemLayout::getInputElement() // возвращает сет элементов
{
    return this;
}

QWidget *ItemLayout::getCancel()
{
    return this->cancel;
}

QWidget *ItemLayout::getOk()
{
    return this->ok;
}

QWidget *ItemLayout::getCamera()
{
    return this->camera;
}

QWidget *ItemLayout::getEmail()
{
    return this->email;
}
void ItemLayout::blockButton(QString s) // сетит кнопку в enabled
{
    if(s.isEmpty()) // если поле пустое
        ok->setDisabled(true); // неактивная кнопка
    if(s.contains(QRegExp("[aA-zZ]{2,}@[aA-zZ]{2,}[.][aA-zZ]{2,}"))) // проверка содержания
    {
        ok->setDisabled(false); // сетит активную кнопку
    }
}

void ItemLayout::signalForDialog()
{
    emit signalToDeleteItem(this);
    qDebug() << "button cancel was pushed"; // заходим
}

void ItemLayout::signalForDialogOk()
{
    emit signalToSendReference(this);
    qDebug() << "button Ok was pressed";
}
