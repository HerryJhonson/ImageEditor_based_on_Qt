/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *imageLabel;
    QLabel *imageLabel_2;
    QPushButton *saveBtn;
    QLineEdit *lineEdit;
    QPushButton *saveBtn2;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *imageSizeLabel;
    QLabel *imageResolutionLabel;
    QLabel *label_3;
    QLabel *imageMemoryLabel;
    QGroupBox *groupBox_2;
    QPushButton *sizeModifiedBtn;
    QPushButton *pushButton_3;
    QPushButton *rotateBtn;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
     QPixmap modifiedPixmap_;
    QString fileName;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1466, 906);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setEnabled(true);
        imageLabel->setGeometry(QRect(0, 0, 700, 600));
        imageLabel->setTabletTracking(true);
        imageLabel->setAutoFillBackground(true);
        imageLabel->setStyleSheet(QStringLiteral(""));
        imageLabel_2 = new QLabel(centralWidget);
        imageLabel_2->setObjectName(QStringLiteral("imageLabel_2"));
        imageLabel_2->setEnabled(true);
        imageLabel_2->setGeometry(QRect(700, 0, 700, 600));
        imageLabel_2->setTabletTracking(true);
        imageLabel_2->setAutoFillBackground(true);
        imageLabel_2->setStyleSheet(QStringLiteral(""));
        saveBtn = new QPushButton(centralWidget);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setGeometry(QRect(0, 730, 111, 51));
        saveBtn->setStyleSheet(QStringLiteral(""));
        saveBtn->setCheckable(false);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 730, 701, 51));
        saveBtn2 = new QPushButton(centralWidget);
        saveBtn2->setObjectName(QStringLiteral("saveBtn2"));
        saveBtn2->setGeometry(QRect(840, 730, 111, 51));
        saveBtn2->setStyleSheet(QStringLiteral(""));
        saveBtn2->setCheckable(false);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 620, 431, 101));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 161, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 60, 180, 31));
        label_2->setFont(font);
        imageSizeLabel = new QLabel(groupBox);
        imageSizeLabel->setObjectName(QStringLiteral("imageSizeLabel"));
        imageSizeLabel->setGeometry(QRect(120, 20, 160, 31));
        imageResolutionLabel = new QLabel(groupBox);
        imageResolutionLabel->setObjectName(QStringLiteral("imageResolutionLabel"));
        imageResolutionLabel->setGeometry(QRect(140, 60, 160, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 20, 161, 31));
        label_3->setFont(font);
        imageMemoryLabel = new QLabel(centralWidget);
        imageMemoryLabel->setObjectName(QStringLiteral("imageMemoryLabel"));
        imageMemoryLabel->setGeometry(QRect(310, 640, 160, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(520, 620, 431, 101));
        sizeModifiedBtn = new QPushButton(groupBox_2);
        sizeModifiedBtn->setObjectName(QStringLiteral("sizeModifiedBtn"));
        sizeModifiedBtn->setGeometry(QRect(0, 20, 100, 35));
        sizeModifiedBtn->setStyleSheet(QStringLiteral(""));
        sizeModifiedBtn->setCheckable(false);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 60, 100, 35));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        pushButton_3->setCheckable(false);
        rotateBtn = new QPushButton(groupBox_2);
        rotateBtn->setObjectName(QStringLiteral("rotateBtn"));
        rotateBtn->setGeometry(QRect(110, 20, 100, 35));
        rotateBtn->setStyleSheet(QStringLiteral(""));
        rotateBtn->setCheckable(false);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 60, 100, 35));
        pushButton_2->setStyleSheet(QStringLiteral(""));
        pushButton_2->setCheckable(false);
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(220, 20, 100, 35));
        pushButton_6->setStyleSheet(QStringLiteral(""));
        pushButton_6->setCheckable(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1466, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        imageLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; vertical-align:super;\">\344\270\212\344\274\240\345\233\276\347\211\207\351\242\204\350\247\210</span></p></body></html>", nullptr));
        imageLabel_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; vertical-align:super;\">\345\244\204\347\220\206\345\220\216</span></p></body></html>", nullptr));
        saveBtn->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\234\260\345\235\200", nullptr));
        saveBtn2->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\344\277\235\345\255\230", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\212\344\274\240\345\233\276\347\211\207\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\345\244\247\345\260\217\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\345\233\276\347\211\207\345\210\206\350\276\250\347\216\207\357\274\232</p></body></html>", nullptr));
        imageSizeLabel->setText(QString());
        imageResolutionLabel->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\345\206\205\345\255\230\357\274\232", nullptr));
        imageMemoryLabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        sizeModifiedBtn->setText(QApplication::translate("MainWindow", "\345\260\272\345\257\270\344\277\256\346\224\271", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\210\206\350\276\250\347\216\207\345\244\204\347\220\206", nullptr));
        rotateBtn->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\243\201\345\211\252", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\346\213\274\346\216\245", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\234\250\350\277\231\351\207\214\350\276\223\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
