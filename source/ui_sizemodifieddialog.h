/********************************************************************************
** Form generated from reading UI file 'sizemodifieddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZEMODIFIEDDIALOG_H
#define UI_SIZEMODIFIEDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_sizeModifiedDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *sizeModifiedDialog)
    {
        if (sizeModifiedDialog->objectName().isEmpty())
            sizeModifiedDialog->setObjectName(QStringLiteral("sizeModifiedDialog"));
        sizeModifiedDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(sizeModifiedDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(sizeModifiedDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), sizeModifiedDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), sizeModifiedDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(sizeModifiedDialog);
    } // setupUi

    void retranslateUi(QDialog *sizeModifiedDialog)
    {
        sizeModifiedDialog->setWindowTitle(QApplication::translate("sizeModifiedDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sizeModifiedDialog: public Ui_sizeModifiedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZEMODIFIEDDIALOG_H
