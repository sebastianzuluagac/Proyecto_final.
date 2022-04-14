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
#include <QtGui/QIcon>
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
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QGraphicsView *escena;
    QWidget *inicio;
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
    QWidget *niveles;
    QPushButton *nivel4;
    QPushButton *nivel1;
    QPushButton *nivel2;
    QPushButton *nivel3;
    QPushButton *tienda;
    QPushButton *jugar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(753, 383);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(9, 9, 274, 210));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        escena = new QGraphicsView(widget_2);
        escena->setObjectName(QString::fromUtf8("escena"));

        gridLayout_3->addWidget(escena, 0, 0, 1, 1);

        inicio = new QWidget(centralwidget);
        inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->setGeometry(QRect(289, 9, 188, 120));
        gridLayout = new QGridLayout(inicio);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        respuesta = new QLabel(inicio);
        respuesta->setObjectName(QString::fromUtf8("respuesta"));

        gridLayout->addWidget(respuesta, 1, 0, 1, 1);

        caja_ingreso_creacion = new QVBoxLayout();
        caja_ingreso_creacion->setObjectName(QString::fromUtf8("caja_ingreso_creacion"));
        name_password = new QFormLayout();
        name_password->setObjectName(QString::fromUtf8("name_password"));
        user_name = new QLabel(inicio);
        user_name->setObjectName(QString::fromUtf8("user_name"));

        name_password->setWidget(0, QFormLayout::LabelRole, user_name);

        username = new QLineEdit(inicio);
        username->setObjectName(QString::fromUtf8("username"));

        name_password->setWidget(0, QFormLayout::FieldRole, username);

        password = new QLabel(inicio);
        password->setObjectName(QString::fromUtf8("password"));

        name_password->setWidget(1, QFormLayout::LabelRole, password);

        pw = new QLineEdit(inicio);
        pw->setObjectName(QString::fromUtf8("pw"));

        name_password->setWidget(1, QFormLayout::FieldRole, pw);


        caja_ingreso_creacion->addLayout(name_password);

        botones_ingresar_crear = new QHBoxLayout();
        botones_ingresar_crear->setObjectName(QString::fromUtf8("botones_ingresar_crear"));
        ingresar = new QPushButton(inicio);
        ingresar->setObjectName(QString::fromUtf8("ingresar"));

        botones_ingresar_crear->addWidget(ingresar);

        crearU = new QPushButton(inicio);
        crearU->setObjectName(QString::fromUtf8("crearU"));

        botones_ingresar_crear->addWidget(crearU);


        caja_ingreso_creacion->addLayout(botones_ingresar_crear);


        gridLayout->addLayout(caja_ingreso_creacion, 0, 0, 1, 1);

        niveles = new QWidget(centralwidget);
        niveles->setObjectName(QString::fromUtf8("niveles"));
        niveles->setGeometry(QRect(120, 240, 441, 80));
        nivel4 = new QPushButton(niveles);
        nivel4->setObjectName(QString::fromUtf8("nivel4"));
        nivel4->setGeometry(QRect(330, 10, 91, 61));
        nivel1 = new QPushButton(niveles);
        nivel1->setObjectName(QString::fromUtf8("nivel1"));
        nivel1->setGeometry(QRect(21, 10, 101, 61));
        nivel2 = new QPushButton(niveles);
        nivel2->setObjectName(QString::fromUtf8("nivel2"));
        nivel2->setGeometry(QRect(131, 10, 91, 61));
        nivel3 = new QPushButton(niveles);
        nivel3->setObjectName(QString::fromUtf8("nivel3"));
        nivel3->setGeometry(QRect(231, 10, 91, 61));
        tienda = new QPushButton(centralwidget);
        tienda->setObjectName(QString::fromUtf8("tienda"));
        tienda->setGeometry(QRect(690, 290, 51, 41));
        tienda->setCursor(QCursor(Qt::OpenHandCursor));
        tienda->setMouseTracking(false);
        tienda->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SPRITES_GAME/botones/compras1.webp"), QSize(), QIcon::Normal, QIcon::On);
        tienda->setIcon(icon);
        tienda->setIconSize(QSize(51, 100));
        jugar = new QPushButton(centralwidget);
        jugar->setObjectName(QString::fromUtf8("jugar"));
        jugar->setGeometry(QRect(540, 120, 80, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 753, 20));
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
        nivel4->setText(QApplication::translate("MainWindow", "4", nullptr));
        nivel1->setText(QApplication::translate("MainWindow", "1", nullptr));
        nivel2->setText(QApplication::translate("MainWindow", "2", nullptr));
        nivel3->setText(QApplication::translate("MainWindow", "3", nullptr));
        tienda->setText(QString());
        jugar->setText(QApplication::translate("MainWindow", "jugar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
