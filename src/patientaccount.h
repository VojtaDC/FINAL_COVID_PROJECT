#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

#include <QWidget>

namespace Ui {
class patientaccount;
}

class patientaccount : public QWidget
{
    Q_OBJECT

public:
    explicit patientaccount(QWidget *parent = nullptr);
    ~patientaccount();

private:
    Ui::patientaccount *ui;
};

#endif // PATIENTACCOUNT_H
