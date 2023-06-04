#ifndef SIZEMODIFIEDDIALOG_H
#define SIZEMODIFIEDDIALOG_H

#include <QDialog>

namespace Ui {
class sizeModifiedDialog;
}

class sizeModifiedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sizeModifiedDialog(QWidget *parent = nullptr);
    ~sizeModifiedDialog();

private:
    Ui::sizeModifiedDialog *ui;
};

#endif // SIZEMODIFIEDDIALOG_H
