/********************************************************************************
** Form generated from reading UI file 'imageresolution.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGERESOLUTION_H
#define UI_IMAGERESOLUTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_imageResolution
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *imageResolution)
    {
        if (imageResolution->objectName().isEmpty())
            imageResolution->setObjectName(QStringLiteral("imageResolution"));
        imageResolution->resize(400, 300);
        buttonBox = new QDialogButtonBox(imageResolution);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(imageResolution);
        QObject::connect(buttonBox, SIGNAL(accepted()), imageResolution, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), imageResolution, SLOT(reject()));

        QMetaObject::connectSlotsByName(imageResolution);
    } // setupUi

    void retranslateUi(QDialog *imageResolution)
    {
        imageResolution->setWindowTitle(QApplication::translate("imageResolution", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class imageResolution: public Ui_imageResolution {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGERESOLUTION_H
