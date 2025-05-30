#include "patientaccount.h"
#include "ui_patientaccount.h"

patientaccount::patientaccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patientaccount)
{
    ui->setupUi(this);
}

patientaccount::~patientaccount()
{
    delete ui;
}
