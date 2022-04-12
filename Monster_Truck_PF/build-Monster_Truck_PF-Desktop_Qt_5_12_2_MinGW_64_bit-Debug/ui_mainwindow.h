/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QGraphicsView *escena;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *respuesta;
    QVBoxLayout *caja_ingreso_creacion;
    QFormLayout *name_password;
    QLabel *user_name;
    QLineEdit *username;
    QLabel *password;
    QLineEdit *pw;
    QHBoxLayout *botones_ingresar_crear;
    QPushButton *ingresar;
    QPushButton *crearU;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(529, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        escena = new QGraphicsView(widget_2);
        escena->setObjectName(QString::fromUtf8("escena"));

        gridLayout_3->addWidget(escena, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        respuesta = new QLabel(widget);
        respuesta->setObjectName(QString::fromUtf8("respuesta"));

        gridLayout->addWidget(respuesta, 1, 0, 1, 1);

        caja_ingreso_creacion = new QVBoxLayout();
        caja_ingreso_creacion->setObjectName(QString::fromUtf8("caja_ingreso_creacion"));
        name_password = new QFormLayout();
        name_password->setObjectName(QString::fromUtf8("name_password"));
        user_name = new QLabel(widget);
        user_name->setObjectName(QString::fromUtf8("user_name"));

        name_password->setWidget(0, QFormLayout::LabelRole, user_name);

        username = new QLineEdit(widget);
        username->setObjectName(QString::fromUtf8("username"));

        name_password->setWidget(0, QFormLayout::FieldRole, username);

        password = new QLabel(widget);
        password->setObjectName(QString::fromUtf8("password"));

        name_password->setWidget(1, QFormLayout::LabelRole, password);

        pw = new QLineEdit(widget);
        pw->setObjectName(QString::fromUtf8("pw"));

        name_password->setWidget(1, QFormLayout::FieldRole, pw);


        caja_ingreso_creacion->addLayout(name_password);

        botones_ingresar_crear = new QHBoxLayout();
        botones_ingresar_crear->setObjectName(QString::fromUtf8("botones_ingresar_crear"));
        ingresar = new QPushButton(widget);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));

        botones_ingresar_crear->addWidget(ingresar);

        crearU = new QPushButton(widget);
        crearU->setObjectName(QString::fromUtf8("crearU"));

        botones_ingresar_crear->addWidget(crearU);


        caja_ingreso_creacion->addLayout(botones_ingresar_crear);


        gridLayout->addLayout(caja_ingreso_creacion, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 529, 20));
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
        respuesta->setText(QString());
        user_name->setText(QApplication::translate("MainWindow", "User name", nullptr));
        password->setText(QApplication::translate("MainWindow", "Password", nullptr));
        ingresar->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        crearU->setText(QApplication::translate("MainWindow", "crear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
