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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QPushButton *L;
    QPushButton *home;
    QProgressBar *vidaP;
    QPushButton *icon_money;
    QLCDNumber *cant_money;
    QPushButton *R;
    QLabel *precio;
    QWidget *layoutWidget;
    QHBoxLayout *comprar_seleccionar;
    QPushButton *seleccionar;
    QPushButton *buy;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(787, 415);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(740, 20, 274, 210));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        escena = new QGraphicsView(widget_2);
        escena->setObjectName(QString::fromUtf8("escena"));

        gridLayout_3->addWidget(escena, 0, 0, 1, 1);

        inicio = new QWidget(centralwidget);
        inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->setGeometry(QRect(390, 0, 188, 120));
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
        niveles->setGeometry(QRect(150, 320, 441, 80));
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
        tienda->setGeometry(QRect(720, 330, 51, 41));
        tienda->setCursor(QCursor(Qt::OpenHandCursor));
        tienda->setMouseTracking(false);
        tienda->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SPRITES_GAME/botones/compras1.webp"), QSize(), QIcon::Normal, QIcon::On);
        tienda->setIcon(icon);
        tienda->setIconSize(QSize(51, 100));
        jugar = new QPushButton(centralwidget);
        jugar->setObjectName(QString::fromUtf8("jugar"));
        jugar->setGeometry(QRect(570, 160, 80, 61));
        L = new QPushButton(centralwidget);
        L->setObjectName(QString::fromUtf8("L"));
        L->setGeometry(QRect(79, 160, 51, 51));
        QFont font;
        font.setPointSize(25);
        L->setFont(font);
        L->setAutoFillBackground(true);
        home = new QPushButton(centralwidget);
        home->setObjectName(QString::fromUtf8("home"));
        home->setGeometry(QRect(20, 10, 41, 41));
        home->setFont(font);
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("\360\237\224\231");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        home->setIcon(icon1);
        home->setIconSize(QSize(16, 16));
        vidaP = new QProgressBar(centralwidget);
        vidaP->setObjectName(QString::fromUtf8("vidaP"));
        vidaP->setGeometry(QRect(200, 10, 181, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        QBrush brush1(QColor(0, 120, 215, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        vidaP->setPalette(palette);
        vidaP->setMaximum(1000);
        vidaP->setValue(24);
        vidaP->setTextVisible(false);
        icon_money = new QPushButton(centralwidget);
        icon_money->setObjectName(QString::fromUtf8("icon_money"));
        icon_money->setGeometry(QRect(90, 10, 41, 41));
        icon_money->setCursor(QCursor(Qt::OpenHandCursor));
        icon_money->setMouseTracking(false);
        icon_money->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/SPRITES_GAME/monedas/20220329_092624.png"), QSize(), QIcon::Normal, QIcon::On);
        icon_money->setIcon(icon2);
        icon_money->setIconSize(QSize(50, 50));
        cant_money = new QLCDNumber(centralwidget);
        cant_money->setObjectName(QString::fromUtf8("cant_money"));
        cant_money->setGeometry(QRect(130, 10, 51, 41));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        cant_money->setPalette(palette1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(15);
        cant_money->setFont(font1);
        R = new QPushButton(centralwidget);
        R->setObjectName(QString::fromUtf8("R"));
        R->setGeometry(QRect(670, 160, 51, 51));
        R->setFont(font);
        R->setAutoFillBackground(true);
        precio = new QLabel(centralwidget);
        precio->setObjectName(QString::fromUtf8("precio"));
        precio->setGeometry(QRect(270, 280, 170, 13));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 300, 168, 25));
        comprar_seleccionar = new QHBoxLayout(layoutWidget);
        comprar_seleccionar->setObjectName(QString::fromUtf8("comprar_seleccionar"));
        comprar_seleccionar->setContentsMargins(0, 0, 0, 0);
        seleccionar = new QPushButton(layoutWidget);
        seleccionar->setObjectName(QString::fromUtf8("seleccionar"));

        comprar_seleccionar->addWidget(seleccionar);

        buy = new QPushButton(layoutWidget);
        buy->setObjectName(QString::fromUtf8("buy"));

        comprar_seleccionar->addWidget(buy);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 787, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(pw, ingresar);
        QWidget::setTabOrder(ingresar, crearU);
        QWidget::setTabOrder(crearU, nivel4);
        QWidget::setTabOrder(nivel4, nivel1);
        QWidget::setTabOrder(nivel1, nivel2);
        QWidget::setTabOrder(nivel2, nivel3);
        QWidget::setTabOrder(nivel3, tienda);
        QWidget::setTabOrder(tienda, jugar);
        QWidget::setTabOrder(jugar, L);
        QWidget::setTabOrder(L, escena);
        QWidget::setTabOrder(escena, home);
        QWidget::setTabOrder(home, icon_money);
        QWidget::setTabOrder(icon_money, R);
        QWidget::setTabOrder(R, username);
        QWidget::setTabOrder(username, buy);

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
        nivel1->setText(QApplication::translate("MainWindow", "1\357\270\217\342\203\243", nullptr));
        nivel2->setText(QApplication::translate("MainWindow", "2", nullptr));
        nivel3->setText(QApplication::translate("MainWindow", "3", nullptr));
        tienda->setText(QString());
        jugar->setText(QApplication::translate("MainWindow", "jugar", nullptr));
        L->setText(QApplication::translate("MainWindow", "\360\237\221\210", nullptr));
        home->setText(QApplication::translate("MainWindow", "\360\237\224\231", nullptr));
        icon_money->setText(QString());
        R->setText(QApplication::translate("MainWindow", "\360\237\221\211", nullptr));
        precio->setText(QString());
        seleccionar->setText(QApplication::translate("MainWindow", "seleccionar", nullptr));
        buy->setText(QApplication::translate("MainWindow", "comprar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
