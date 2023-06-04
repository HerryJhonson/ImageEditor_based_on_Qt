#include "imageresolution.h"
#include "ui_imageresolution.h"

imageResolution::imageResolution(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::imageResolution)
{
    ui->setupUi(this);
}

imageResolution::~imageResolution()
{
    delete ui;
}
