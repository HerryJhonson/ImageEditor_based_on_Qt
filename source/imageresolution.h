#ifndef IMAGERESOLUTION_H
#define IMAGERESOLUTION_H

#include <QDialog>

namespace Ui {
class imageResolution;
}

class imageResolution : public QDialog
{
    Q_OBJECT

public:
    explicit imageResolution(QWidget *parent = nullptr);
    ~imageResolution();

private:
    Ui::imageResolution *ui;
};

#endif // IMAGERESOLUTION_H
