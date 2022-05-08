/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *customplot;
    QPushButton *draw_button;
    QPushButton *pushButton_2;
    QLineEdit *exp_input;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *zoom_in_h_button;
    QPushButton *zoom_out_h_button;
    QPushButton *zoom_in_v_button;
    QPushButton *zoom_out_v_button;
    QLabel *label_4;
    QDoubleSpinBox *max_spin;
    QLabel *label_3;
    QDoubleSpinBox *min_spin;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 870);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customplot = new QCustomPlot(centralwidget);
        customplot->setObjectName(QString::fromUtf8("customplot"));
        customplot->setGeometry(QRect(20, 380, 1021, 481));
        draw_button = new QPushButton(centralwidget);
        draw_button->setObjectName(QString::fromUtf8("draw_button"));
        draw_button->setGeometry(QRect(20, 290, 131, 61));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 130, 81, 41));
        exp_input = new QLineEdit(centralwidget);
        exp_input->setObjectName(QString::fromUtf8("exp_input"));
        exp_input->setGeometry(QRect(20, 130, 531, 41));
        QFont font;
        font.setPointSize(12);
        exp_input->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(21, 91, 201, 27));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 191, 341, 27));
        label_2->setFont(font1);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1070, 400, 191, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        zoom_in_h_button = new QPushButton(layoutWidget);
        zoom_in_h_button->setObjectName(QString::fromUtf8("zoom_in_h_button"));

        verticalLayout->addWidget(zoom_in_h_button);

        zoom_out_h_button = new QPushButton(layoutWidget);
        zoom_out_h_button->setObjectName(QString::fromUtf8("zoom_out_h_button"));

        verticalLayout->addWidget(zoom_out_h_button);

        zoom_in_v_button = new QPushButton(layoutWidget);
        zoom_in_v_button->setObjectName(QString::fromUtf8("zoom_in_v_button"));

        verticalLayout->addWidget(zoom_in_v_button);

        zoom_out_v_button = new QPushButton(layoutWidget);
        zoom_out_v_button->setObjectName(QString::fromUtf8("zoom_out_v_button"));

        verticalLayout->addWidget(zoom_out_v_button);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(257, 230, 66, 21));
        max_spin = new QDoubleSpinBox(centralwidget);
        max_spin->setObjectName(QString::fromUtf8("max_spin"));
        max_spin->setGeometry(QRect(330, 230, 81, 29));
        max_spin->setMinimum(-100000.000000000000000);
        max_spin->setMaximum(100000.000000000000000);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 230, 63, 20));
        min_spin = new QDoubleSpinBox(centralwidget);
        min_spin->setObjectName(QString::fromUtf8("min_spin"));
        min_spin->setGeometry(QRect(90, 230, 81, 29));
        min_spin->setMinimum(-100000.000000000000000);
        min_spin->setMaximum(100000.000000000000000);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(490, 30, 381, 51));
        QFont font2;
        font2.setPointSize(24);
        font2.setBold(true);
        label_5->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(700, 130, 271, 41));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        label_6->setFont(font3);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(670, 120, 601, 231));
        QFont font4;
        font4.setPointSize(11);
        label_7->setFont(font4);
        label_7->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), exp_input, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        draw_button->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter function of x", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "select min & max values of x", nullptr));
        zoom_in_h_button->setText(QCoreApplication::translate("MainWindow", "Zoom In - horizontally", nullptr));
        zoom_out_h_button->setText(QCoreApplication::translate("MainWindow", "Zoom Out - horizontally", nullptr));
        zoom_in_v_button->setText(QCoreApplication::translate("MainWindow", "Zoom In - vertically", nullptr));
        zoom_out_v_button->setText(QCoreApplication::translate("MainWindow", "Zoom Out - vertically", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Maximum", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Minimum", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Function Plotter", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Functions supported:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<ul>\n"
"  <li>addition (+), subtraction/negation (-), multiplication (*), division (/), <br>exponentiation (^) and modulus (%)</li>\n"
"  <li>abs, acos, asin, atan, atan2, ceil, cos, cosh, exp, floor, ln, log, log10,<br> pow, sin, sinh, sqrt, tan, tanh, fac </li>\n"
"  <li>Constants: pi, e</li>\n"
"</ul><ui>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
