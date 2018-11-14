#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include "dialog.h"

class filter : public QObject
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
