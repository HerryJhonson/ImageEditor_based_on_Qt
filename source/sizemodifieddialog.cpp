#include "sizemodifieddialog.h"
#include "ui_sizemodifieddialog.h"

sizeModifiedDialog::sizeModifiedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sizeModifiedDialog)
{
    ui->setupUi(this);
}

sizeModifiedDialog::~sizeModifiedDialog()
{
    delete ui;
}
