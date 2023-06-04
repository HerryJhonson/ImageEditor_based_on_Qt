#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include <QDebug>
#include <QImage>
#include <QTransform>
#include <QMessageBox>
#include "sizemodifieddialog.h"
#include "imageresolution.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
       //创建菜单栏
        QMenuBar* menuBar = new QMenuBar(this);

        // 创建文件菜单
        QMenu* fileMenu = menuBar->addMenu(tr("图片"));

        // 创建打开菜单项
        QAction* openAction = new QAction(tr("打开"), this);
        fileMenu->addAction(openAction);

        // 设置菜单栏
        setMenuBar(menuBar);

        //点击 打开 上传图片
        connect(openAction, &QAction::triggered, this, [this]() {
            ui->fileName = QFileDialog::getOpenFileName(this, "选择图片", "");

        //显示图片到上传位置 同时显示图片的大小和分辨率和内存
            if (!ui->fileName.isEmpty()) {
                QPixmap pixmap(ui->fileName);

            // 设置要显示图片的 QLabel 控件
            QLabel* imageLabel = ui->imageLabel;
            imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            imageLabel->setAlignment(Qt::AlignCenter);

            //显示图片的大小和分辨率和内存
            QImage image(ui->fileName);

            if (!image.isNull()) {
                ui->imageLabel->setPixmap(QPixmap::fromImage(image).scaled(ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                ui->imageLabel->setAlignment(Qt::AlignCenter);

                // 获取图片的大小和分辨率和内存
                QString imageSizeStr = QString("%1 x %2").arg(image.width()).arg(image.height());
                QString imageResolutionStr = QString("%1 dpi").arg(image.dotsPerMeterX() * 0.0254);
               //  QString imageMemoryStr = QString("%1 KB").arg(image.byteCount() / 1024);

                // 获取图片文件的属性 int
                QFileInfo fileInfo(ui->fileName);
                qint64 fileSize = fileInfo.size();
                QString imageMemoryStr = QString("%1 KB").arg(fileSize / 1024);

                // 在界面上显示图片的大小和分辨率和内存
                ui->imageSizeLabel->setText(imageSizeStr);
                ui->imageResolutionLabel->setText( imageResolutionStr);
                ui->imageMemoryLabel->setText(imageMemoryStr);
            }
            }});

          //选择保存图片的目录
        connect(ui->saveBtn, &QPushButton::clicked, [this]() {
            QString saveDirectory = QFileDialog::getExistingDirectory(this, tr("选择保存目录"), "", QFileDialog::ShowDirsOnly);
            if (!saveDirectory.isEmpty()) {
            ui->lineEdit->setText(saveDirectory);
    }
});
//        //点击旋转按钮的响应  写错了复制的图片是size以后的大小变了
//        connect(ui->rotateBtn, &QPushButton::clicked, this, [this]() {
//            // 获取当前显示的图片
//            QPixmap currentPixmap = *ui->imageLabel->pixmap();

//            if (!currentPixmap.isNull()) {
//                // 旋转180度
//                QPixmap rotatedPixmap = currentPixmap.transformed(QTransform().rotate(180));//这个应该还可以再改成90或者更小吧
//                ui-> modifiedPixmap_ = rotatedPixmap;
//                // 在imageLabel_2中显示旋转后的图片
//                ui->imageLabel_2->setPixmap(rotatedPixmap.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
//                ui->imageLabel_2->setAlignment(Qt::AlignCenter);

//            }
//        });
        connect(ui->rotateBtn, &QPushButton::clicked, this, [this]() {
            if (!ui->fileName.isEmpty()) {
                QPixmap pixmap(ui->fileName);

                if (!pixmap.isNull()) {
                    // 旋转 180 度
                    QPixmap rotatedPixmap = pixmap.transformed(QTransform().rotate(180));

                    // 赋值给 modifiedPixmap_
                    ui->modifiedPixmap_ = rotatedPixmap;

                    // 在 imageLabel_2 中显示旋转后的图片
                    ui->imageLabel_2->setPixmap(ui->modifiedPixmap_.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    ui->imageLabel_2->setAlignment(Qt::AlignCenter);
                }
            }
        });

        //选择保存图片的目录 debug半天结果是modifiedPixmap_两个变量名字一样。。。。
        connect(ui->saveBtn2, &QPushButton::clicked,this, [this]() {
            QString saveDirectory = ui->lineEdit->text();  // 获取保存目录
            if (!saveDirectory.isEmpty() && !ui->modifiedPixmap_.isNull()) {
                QString savePath = saveDirectory + "/rotated_image.jpg"; // 拼接保存路径和文件名

                if (ui->modifiedPixmap_.save(savePath, "JPG")) {
                    QMessageBox::information(this, tr("保存成功"), tr("图片保存成功！"));
                } else {
                    QMessageBox::critical(this, tr("保存失败"), tr("图片保存失败，请检查保存目录！"));
                }
            }
        });

        //点击尺寸修改
        connect(ui->sizeModifiedBtn, &QPushButton::clicked, this, [this]() {
            sizeModifiedDialog* dialog = new sizeModifiedDialog(this);
            dialog->setModal(true); // 设置为模态对话框，阻塞其他窗口操作
            dialog->show();
        });

        //点击分辨率
        connect(ui->pushButton_3, &QPushButton::clicked, this, [this]() {
            imageResolution* dialog = new imageResolution(this);
            dialog->setModal(true); // 设置为模态对话框，阻塞其他窗口操作
            dialog->show();
        });


};


MainWindow::~MainWindow()
{
    delete ui;
}


