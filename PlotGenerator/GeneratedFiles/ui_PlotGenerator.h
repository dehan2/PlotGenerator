/********************************************************************************
** Form generated from reading UI file 'PlotGenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTGENERATOR_H
#define UI_PLOTGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "RenderArea.h"

QT_BEGIN_NAMESPACE

class Ui_PlotGeneratorClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    RenderArea *renderArea;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_load_bcf;
    QPushButton *pushButton_save_plot;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_screen_width;
    QLabel *label_2;
    QLineEdit *lineEdit_screen_height;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_num_entities;
    QLabel *label_4;
    QLabel *label_plot_width;
    QLabel *label_5;
    QLabel *label_plot_height;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_dx;
    QLabel *label_7;
    QLineEdit *lineEdit_dy;
    QLabel *label_8;
    QLineEdit *lineEdit_theta;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlotGeneratorClass)
    {
        if (PlotGeneratorClass->objectName().isEmpty())
            PlotGeneratorClass->setObjectName(QStringLiteral("PlotGeneratorClass"));
        PlotGeneratorClass->resize(1118, 643);
        centralWidget = new QWidget(PlotGeneratorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        renderArea = new RenderArea(centralWidget);
        renderArea->setObjectName(QStringLiteral("renderArea"));

        horizontalLayout->addWidget(renderArea);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMaximumSize(QSize(200, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_load_bcf = new QPushButton(tab);
        pushButton_load_bcf->setObjectName(QStringLiteral("pushButton_load_bcf"));

        verticalLayout->addWidget(pushButton_load_bcf);

        pushButton_save_plot = new QPushButton(tab);
        pushButton_save_plot->setObjectName(QStringLiteral("pushButton_save_plot"));

        verticalLayout->addWidget(pushButton_save_plot);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_screen_width = new QLineEdit(groupBox);
        lineEdit_screen_width->setObjectName(QStringLiteral("lineEdit_screen_width"));

        horizontalLayout_2->addWidget(lineEdit_screen_width);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_screen_height = new QLineEdit(groupBox);
        lineEdit_screen_height->setObjectName(QStringLiteral("lineEdit_screen_height"));

        horizontalLayout_2->addWidget(lineEdit_screen_height);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_num_entities = new QLabel(groupBox_2);
        label_num_entities->setObjectName(QStringLiteral("label_num_entities"));
        label_num_entities->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_num_entities, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_plot_width = new QLabel(groupBox_2);
        label_plot_width->setObjectName(QStringLiteral("label_plot_width"));
        label_plot_width->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_plot_width, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_plot_height = new QLabel(groupBox_2);
        label_plot_height->setObjectName(QStringLiteral("label_plot_height"));
        label_plot_height->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_plot_height, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_dx = new QLineEdit(groupBox_3);
        lineEdit_dx->setObjectName(QStringLiteral("lineEdit_dx"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_dx->sizePolicy().hasHeightForWidth());
        lineEdit_dx->setSizePolicy(sizePolicy1);
        lineEdit_dx->setMaximumSize(QSize(100, 16777215));
        lineEdit_dx->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_dx, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_dy = new QLineEdit(groupBox_3);
        lineEdit_dy->setObjectName(QStringLiteral("lineEdit_dy"));
        lineEdit_dy->setMaximumSize(QSize(100, 16777215));
        lineEdit_dy->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_dy, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_theta = new QLineEdit(groupBox_3);
        lineEdit_theta->setObjectName(QStringLiteral("lineEdit_theta"));
        lineEdit_theta->setMaximumSize(QSize(100, 16777215));
        lineEdit_theta->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_theta, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        PlotGeneratorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PlotGeneratorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1118, 21));
        PlotGeneratorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlotGeneratorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PlotGeneratorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlotGeneratorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PlotGeneratorClass->setStatusBar(statusBar);

        retranslateUi(PlotGeneratorClass);
        QObject::connect(pushButton_load_bcf, SIGNAL(clicked()), PlotGeneratorClass, SLOT(load_bcf_file()));
        QObject::connect(lineEdit_screen_width, SIGNAL(returnPressed()), PlotGeneratorClass, SLOT(update_screen()));
        QObject::connect(lineEdit_screen_height, SIGNAL(returnPressed()), PlotGeneratorClass, SLOT(update_screen()));
        QObject::connect(lineEdit_dx, SIGNAL(returnPressed()), PlotGeneratorClass, SLOT(plot_edited()));
        QObject::connect(lineEdit_dy, SIGNAL(returnPressed()), PlotGeneratorClass, SLOT(plot_edited()));
        QObject::connect(pushButton_save_plot, SIGNAL(clicked()), PlotGeneratorClass, SLOT(save_plot_file()));
        QObject::connect(lineEdit_theta, SIGNAL(returnPressed()), PlotGeneratorClass, SLOT(plot_edited()));

        QMetaObject::connectSlotsByName(PlotGeneratorClass);
    } // setupUi

    void retranslateUi(QMainWindow *PlotGeneratorClass)
    {
        PlotGeneratorClass->setWindowTitle(QApplication::translate("PlotGeneratorClass", "PlotGenerator", 0));
        pushButton_load_bcf->setText(QApplication::translate("PlotGeneratorClass", "Load BCF file", 0));
        pushButton_save_plot->setText(QApplication::translate("PlotGeneratorClass", "Save plot file", 0));
        groupBox->setTitle(QApplication::translate("PlotGeneratorClass", "Screen", 0));
        label->setText(QApplication::translate("PlotGeneratorClass", "W", 0));
        lineEdit_screen_width->setText(QApplication::translate("PlotGeneratorClass", "100", 0));
        label_2->setText(QApplication::translate("PlotGeneratorClass", "H", 0));
        lineEdit_screen_height->setText(QApplication::translate("PlotGeneratorClass", "100", 0));
        groupBox_2->setTitle(QApplication::translate("PlotGeneratorClass", "Plot Info", 0));
        label_3->setText(QApplication::translate("PlotGeneratorClass", "# Entities", 0));
        label_num_entities->setText(QApplication::translate("PlotGeneratorClass", "0", 0));
        label_4->setText(QApplication::translate("PlotGeneratorClass", "Width", 0));
        label_plot_width->setText(QApplication::translate("PlotGeneratorClass", "0", 0));
        label_5->setText(QApplication::translate("PlotGeneratorClass", "Height", 0));
        label_plot_height->setText(QApplication::translate("PlotGeneratorClass", "0", 0));
        groupBox_3->setTitle(QApplication::translate("PlotGeneratorClass", "Plot Control", 0));
        label_6->setText(QApplication::translate("PlotGeneratorClass", "dX", 0));
        lineEdit_dx->setText(QApplication::translate("PlotGeneratorClass", "0", 0));
        label_7->setText(QApplication::translate("PlotGeneratorClass", "dY", 0));
        lineEdit_dy->setText(QApplication::translate("PlotGeneratorClass", "0", 0));
        label_8->setText(QApplication::translate("PlotGeneratorClass", "Theta", 0));
        lineEdit_theta->setText(QApplication::translate("PlotGeneratorClass", "0", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PlotGeneratorClass", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PlotGeneratorClass", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotGeneratorClass: public Ui_PlotGeneratorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTGENERATOR_H
