/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *ProgressTime;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QComboBox *TimeRange;
    QLabel *label_3;
    QLabel *label_8;
    QPushButton *Start;
    QLabel *label_9;
    QFrame *line;
    QFrame *line_2;
    QPushButton *PushUp;
    QPushButton *PushRight;
    QPushButton *PushLeft;
    QPushButton *PushDown;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QPushButton *PushCloser;
    QPushButton *PushFurther;
    QLabel *label_10;
    QPushButton *PushLightCloser;
    QPushButton *PushLightFurther;
    QPushButton *PushLightUp;
    QPushButton *PushLightRight;
    QPushButton *PushLightLeft;
    QPushButton *PushLightDown;
    QLabel *label_11;
    QPushButton *RotateLeft;
    QPushButton *RotateRight;
    QPushButton *RotateDown;
    QPushButton *RotateUp;
    QFrame *line_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(910, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ProgressTime = new QProgressBar(centralwidget);
        ProgressTime->setObjectName(QString::fromUtf8("ProgressTime"));
        ProgressTime->setGeometry(QRect(10, 600, 611, 23));
        ProgressTime->setValue(0);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 611, 581));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(680, 10, 141, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(630, 50, 61, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        TimeRange = new QComboBox(centralwidget);
        TimeRange->addItem(QString());
        TimeRange->addItem(QString());
        TimeRange->addItem(QString());
        TimeRange->setObjectName(QString::fromUtf8("TimeRange"));
        TimeRange->setGeometry(QRect(690, 50, 181, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        TimeRange->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 80, 71, 21));
        label_3->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(630, 350, 131, 21));
        label_8->setFont(font1);
        Start = new QPushButton(centralwidget);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(630, 560, 271, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        Start->setFont(font3);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(650, 100, 91, 21));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        label_9->setFont(font4);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(700, 80, 201, 16));
        QFont font5;
        font5.setPointSize(9);
        line->setFont(font5);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(620, 100, 20, 231));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);
        PushUp = new QPushButton(centralwidget);
        PushUp->setObjectName(QString::fromUtf8("PushUp"));
        PushUp->setGeometry(QRect(730, 120, 61, 23));
        PushUp->setFont(font4);
        PushRight = new QPushButton(centralwidget);
        PushRight->setObjectName(QString::fromUtf8("PushRight"));
        PushRight->setGeometry(QRect(800, 160, 61, 23));
        PushRight->setFont(font4);
        PushLeft = new QPushButton(centralwidget);
        PushLeft->setObjectName(QString::fromUtf8("PushLeft"));
        PushLeft->setGeometry(QRect(660, 160, 61, 23));
        PushLeft->setFont(font4);
        PushDown = new QPushButton(centralwidget);
        PushDown->setObjectName(QString::fromUtf8("PushDown"));
        PushDown->setGeometry(QRect(730, 200, 61, 23));
        PushDown->setFont(font4);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(630, 320, 271, 16));
        line_3->setFont(font5);
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(1);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(890, 90, 20, 241));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::VLine);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(760, 350, 141, 20));
        line_5->setFont(font5);
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(1);
        line_5->setFrameShape(QFrame::HLine);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(630, 520, 271, 16));
        line_6->setFont(font5);
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(1);
        line_6->setFrameShape(QFrame::HLine);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(620, 370, 20, 161));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setFrameShape(QFrame::VLine);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(890, 360, 20, 171));
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setFrameShape(QFrame::VLine);
        PushCloser = new QPushButton(centralwidget);
        PushCloser->setObjectName(QString::fromUtf8("PushCloser"));
        PushCloser->setGeometry(QRect(730, 150, 61, 23));
        PushCloser->setFont(font4);
        PushFurther = new QPushButton(centralwidget);
        PushFurther->setObjectName(QString::fromUtf8("PushFurther"));
        PushFurther->setGeometry(QRect(730, 170, 61, 23));
        PushFurther->setFont(font4);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(650, 380, 91, 21));
        label_10->setFont(font4);
        PushLightCloser = new QPushButton(centralwidget);
        PushLightCloser->setObjectName(QString::fromUtf8("PushLightCloser"));
        PushLightCloser->setGeometry(QRect(730, 430, 61, 23));
        PushLightCloser->setFont(font4);
        PushLightFurther = new QPushButton(centralwidget);
        PushLightFurther->setObjectName(QString::fromUtf8("PushLightFurther"));
        PushLightFurther->setGeometry(QRect(730, 450, 61, 23));
        PushLightFurther->setFont(font4);
        PushLightUp = new QPushButton(centralwidget);
        PushLightUp->setObjectName(QString::fromUtf8("PushLightUp"));
        PushLightUp->setGeometry(QRect(730, 400, 61, 23));
        PushLightUp->setFont(font4);
        PushLightRight = new QPushButton(centralwidget);
        PushLightRight->setObjectName(QString::fromUtf8("PushLightRight"));
        PushLightRight->setGeometry(QRect(800, 440, 61, 23));
        PushLightRight->setFont(font4);
        PushLightLeft = new QPushButton(centralwidget);
        PushLightLeft->setObjectName(QString::fromUtf8("PushLightLeft"));
        PushLightLeft->setGeometry(QRect(660, 440, 61, 23));
        PushLightLeft->setFont(font4);
        PushLightDown = new QPushButton(centralwidget);
        PushLightDown->setObjectName(QString::fromUtf8("PushLightDown"));
        PushLightDown->setGeometry(QRect(730, 480, 61, 23));
        PushLightDown->setFont(font4);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(650, 230, 91, 21));
        label_11->setFont(font4);
        RotateLeft = new QPushButton(centralwidget);
        RotateLeft->setObjectName(QString::fromUtf8("RotateLeft"));
        RotateLeft->setGeometry(QRect(660, 270, 61, 23));
        RotateLeft->setFont(font4);
        RotateRight = new QPushButton(centralwidget);
        RotateRight->setObjectName(QString::fromUtf8("RotateRight"));
        RotateRight->setGeometry(QRect(800, 270, 61, 23));
        RotateRight->setFont(font4);
        RotateDown = new QPushButton(centralwidget);
        RotateDown->setObjectName(QString::fromUtf8("RotateDown"));
        RotateDown->setGeometry(QRect(730, 290, 61, 23));
        RotateDown->setFont(font4);
        RotateUp = new QPushButton(centralwidget);
        RotateUp->setObjectName(QString::fromUtf8("RotateUp"));
        RotateUp->setGeometry(QRect(730, 250, 61, 23));
        RotateUp->setFont(font4);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(630, 220, 271, 16));
        line_9->setFont(font5);
        line_9->setFrameShadow(QFrame::Plain);
        line_9->setLineWidth(1);
        line_9->setFrameShape(QFrame::HLine);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 910, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        TimeRange->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\225\320\241\320\236\320\247\320\235\320\253\320\225 \320\247\320\220\320\241\320\253", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217:", nullptr));
        TimeRange->setItemText(0, QCoreApplication::translate("MainWindow", "1 \320\274\320\270\320\275\321\203\321\202\320\260", nullptr));
        TimeRange->setItemText(1, QCoreApplication::translate("MainWindow", "1.5 \320\274\320\270\320\275\321\203\321\202\321\213", nullptr));
        TimeRange->setItemText(2, QCoreApplication::translate("MainWindow", "2 \320\274\320\270\320\275\321\203\321\202\321\213", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260:", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202!", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214:", nullptr));
        PushUp->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        PushRight->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        PushLeft->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        PushDown->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        PushCloser->setText(QCoreApplication::translate("MainWindow", "\320\221\320\273\320\270\320\266\320\265", nullptr));
        PushFurther->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\321\214\321\210\320\265", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214:", nullptr));
        PushLightCloser->setText(QCoreApplication::translate("MainWindow", "\320\221\320\273\320\270\320\266\320\265", nullptr));
        PushLightFurther->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\321\214\321\210\320\265", nullptr));
        PushLightUp->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        PushLightRight->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        PushLightLeft->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        PushLightDown->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214:", nullptr));
        RotateLeft->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        RotateRight->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        RotateDown->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        RotateUp->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
