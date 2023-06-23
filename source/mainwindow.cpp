#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include <QDebug>
#include <QImage>
#include <QTransform>
#include <QMessageBox>
#include "sizemodifieddialog.h"
#include "imageresolution.h"
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    //setMouseTracking(true);
    ui->setupUi(this);
       //创建菜单栏
        QMenuBar* menuBar = new QMenuBar(this);

        // 创建文件菜单
        QMenu* fileMenu = menuBar->addMenu(tr("选择图片"));

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
            }
        }
                );

          //选择保存图片的目录
        connect(ui->saveBtn, &QPushButton::clicked, [this]() {
            QString saveDirectory = QFileDialog::getExistingDirectory(this, tr("选择保存目录"), "", QFileDialog::ShowDirsOnly);
            if (!saveDirectory.isEmpty()) {
            ui->lineEdit->setText(saveDirectory);
            }
        });
        //旋转图片
        connect(ui->rotateBtn, &QPushButton::clicked, this, [this]() {
            if (!ui->fileName.isEmpty()) {
                QPixmap pixmap(ui->fileName);

                if (!pixmap.isNull()) {
                    // 旋转 180 度
                    //弹出对话框输入旋转的度数？
                    bool ok;
                    // 获取浮点数
                    double value2 = QInputDialog::getDouble(this, tr("旋转角度"), tr("请输入-180到180之间的数值"), 0.00, -180, 180, 2, &ok);
                    if(ok) qDebug() << "value2:" << value2;
                    QPixmap rotatedPixmap = pixmap.transformed(QTransform().rotate(value2));
                    // 赋值给 modifiedPixmap_
                    ui->modifiedPixmap_ = rotatedPixmap;
                    // 在 imageLabel_2 中显示旋转后的图片
                    ui->imageLabel_2->setPixmap(ui->modifiedPixmap_.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    ui->imageLabel_2->setAlignment(Qt::AlignCenter);
                }
            }
        }
                );

        //选择保存图片的目录 debug半天结果是modifiedPixmap_两个变量名字一样。。。。
        connect(ui->saveBtn2, &QPushButton::clicked,this, [this]() {
            QString saveDirectory = ui->lineEdit->text();  // 获取保存目录
            if (!saveDirectory.isEmpty() && !ui->modifiedPixmap_.isNull()) {
                QString savePath = saveDirectory + "/changed_image.jpg"; // 拼接保存路径和文件名

                if (ui->modifiedPixmap_.save(savePath, "JPG")) {
                    QMessageBox::information(this, tr("保存成功"), tr("图片保存成功！"));
                } else {
                    QMessageBox::critical(this, tr("保存失败"), tr("图片保存失败，请检查保存目录！"));
                }
            }
        }
                );

        //点击裁剪
        connect(ui->pushButton_2, &QPushButton::clicked, this, [this]() {
            if (!ui->fileName.isEmpty()) {
                QPixmap pixmap(ui->fileName);
                if (!pixmap.isNull()) {
                    //获取裁剪范围的两个角
                    bool ok1;
                    int cut_x1 = QInputDialog::getInt(this, tr("请输入坐标"), tr("裁剪起点横坐标"), 0.00, 0, pixmap.width(), 2, &ok1);
                    if(ok1) qDebug() << "cut_x1:" << cut_x1;
                    bool ok2;
                    int cut_y1 = QInputDialog::getInt(this, tr("请输入坐标"), tr("裁剪起点纵坐标"), 0.00, 0, pixmap.height(), 2, &ok2);
                    if(ok2) qDebug() << "cut_y1:" << cut_y1;
                    bool ok3;
                    int cut_x2 = QInputDialog::getInt(this, tr("请输入坐标"), tr("裁剪终点横坐标"), 0.00, 0, pixmap.width(), 2, &ok3);
                    if(ok3) qDebug() << "cut_x2:" << cut_x2;
                    bool ok4;
                    int cut_y2 = QInputDialog::getInt(this, tr("请输入坐标"), tr("裁剪终点点纵坐标"), 0.00, 0, pixmap.height(), 2, &ok4);
                    if(ok4) qDebug() << "cut_y2:" << cut_y2;

                    QPixmap cuttedPixmap = pixmap.copy(cut_x1,cut_y1,cut_x2,cut_y2);
                    // 赋值给 modifiedPixmap_
                    ui->modifiedPixmap_ = cuttedPixmap;
                    // 在 imageLabel_2 中显示裁剪后的图片
                    ui->imageLabel_2->setPixmap(ui->modifiedPixmap_.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    ui->imageLabel_2->setAlignment(Qt::AlignCenter);
                }
            }

        }
                );
        //点击尺寸修改
        connect(ui->sizeModifiedBtn, &QPushButton::clicked, this, [this]() {
            if (!ui->fileName.isEmpty()) {
                QPixmap pixmap(ui->fileName);
                if (!pixmap.isNull()) {
                    // 尺寸修改，这里仅限分辨率的缩放
                    bool ok;
                    double zoomRate = QInputDialog::getDouble(this, tr("缩放比例%"), tr("请输入缩放比例%(1-100)"), 50, 0, 100, 2, &ok);
                    if(ok) qDebug() << "zoomRate:" << zoomRate;

                    QPixmap sizemodifiedPixmap = pixmap.scaled(pixmap.width()*zoomRate/100, pixmap.height()*zoomRate/100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    // 赋值给 modifiedPixmap_
                    ui->modifiedPixmap_ = sizemodifiedPixmap;
                    // 在 imageLabel_2 中显示缩放后的图片
                    ui->imageLabel_2->setPixmap(ui->modifiedPixmap_.scaled(ui->imageLabel_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    ui->imageLabel_2->setAlignment(Qt::AlignCenter);
                }
            }

        }
                );

        connect(ui->pushButton_3, &QPushButton::clicked, this, [this]() {
            imageResolution* dialog = new imageResolution(this);
            dialog->setModal(true); // 设置为模态对话框，阻塞其他窗口操作
            dialog->show();
        });





};

//鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
        QString str="("+QString::number(event->x())+","+QString::number(event->y())+")";
        // ui->lineEdit->setText(tr("鼠标按下")+str);
        if(event->button()==Qt::LeftButton)
        {
            ui->lineEdit->setText(tr("鼠标左键按下:")+str);

        }else if(event->button()==Qt::RightButton)
        {
            ui->lineEdit->setText(tr("鼠标右键按下:")+str);
        }else if(event->button()==Qt::MidButton)
        {
            ui->lineEdit->setText(tr("鼠标中键按下:")+str);
        }
}


MainWindow::~MainWindow()
{
    delete ui;
}


