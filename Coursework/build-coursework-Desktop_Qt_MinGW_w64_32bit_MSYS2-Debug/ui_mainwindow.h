/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
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
#include <QtWidgets/QLineEdit>
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
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_9;
    QFrame *line;
    QFrame *line_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
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
        label_2->setGeometry(QRect(630, 60, 61, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(690, 60, 181, 22));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        comboBox->setFont(font2);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 100, 71, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(640, 130, 16, 31));
        QFont font3;
        font3.setPointSize(15);
        label_4->setFont(font3);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(660, 140, 41, 20));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        lineEdit->setFont(font4);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(720, 140, 41, 20));
        lineEdit_2->setFont(font4);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(780, 140, 41, 20));
        lineEdit_3->setFont(font4);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(830, 130, 16, 31));
        label_5->setFont(font3);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(710, 130, 16, 31));
        label_6->setFont(font3);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(770, 130, 20, 31));
        label_7->setFont(font3);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(630, 290, 131, 21));
        label_8->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 320, 51, 23));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        pushButton->setFont(font5);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(700, 320, 51, 23));
        pushButton_2->setFont(font5);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(760, 320, 51, 23));
        pushButton_3->setFont(font5);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(820, 320, 51, 23));
        pushButton_4->setFont(font5);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(800, 400, 61, 31));
        pushButton_5->setFont(font5);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(640, 400, 141, 31));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        font6.setWeight(50);
        pushButton_6->setFont(font6);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(640, 170, 91, 21));
        label_9->setFont(font6);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(700, 100, 201, 16));
        QFont font7;
        font7.setPointSize(9);
        line->setFont(font7);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(620, 120, 20, 161));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(720, 200, 51, 23));
        pushButton_7->setFont(font6);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(770, 220, 51, 23));
        pushButton_8->setFont(font6);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(670, 220, 51, 23));
        pushButton_9->setFont(font6);
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(720, 240, 51, 23));
        pushButton_10->setFont(font6);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(630, 270, 271, 16));
        line_3->setFont(font7);
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(1);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(890, 110, 20, 171));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::VLine);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(760, 290, 141, 20));
        line_5->setFont(font7);
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(1);
        line_5->setFrameShape(QFrame::HLine);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(630, 350, 271, 16));
        line_6->setFont(font7);
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(1);
        line_6->setFrameShape(QFrame::HLine);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(620, 310, 20, 51));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setFrameShape(QFrame::VLine);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(890, 300, 20, 61));
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setFrameShape(QFrame::VLine);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 910, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\225\320\241\320\236\320\247\320\235\320\253\320\225 \320\247\320\220\320\241\320\253", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217:", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "1 \320\274\320\270\320\275\321\203\321\202\320\260", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "1.5 \320\274\320\270\320\275\321\203\321\202\321\213", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "2 \320\274\320\270\320\275\321\203\321\202\321\213", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "[", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "500", nullptr));
        lineEdit_2->setText(QApplication::translate("MainWindow", "500", nullptr));
        lineEdit_3->setText(QApplication::translate("MainWindow", "500", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "]", nullptr));
        label_6->setText(QApplication::translate("MainWindow", ";", nullptr));
        label_7->setText(QApplication::translate("MainWindow", ";", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "+", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202!", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\265", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214:", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
