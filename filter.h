#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include "dialog.h"
#include <QApplication>
class filter : public QObject // класс отслеживающий нажатия клавиш
{
    Q_OBJECT
public:
    explicit filter(Dialog* dialog, QObject* parent = nullptr);

signals:

public slots:
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    Dialog* m_dialog;
};

#endif // FILTER_H
