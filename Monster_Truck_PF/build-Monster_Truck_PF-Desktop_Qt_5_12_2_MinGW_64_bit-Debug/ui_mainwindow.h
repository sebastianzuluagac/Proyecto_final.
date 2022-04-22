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
    QVBoxLayout *caja_ingreso_creacion;
    QFormLayout *name_password;
    QLabel *user_name;
    QLineEdit *username;
    QLabel *password;
    QLineEdit *pw;
    QHBoxLayout *botones_ingresar_crear;
    QPushButton *ingresar;
    QPushButton *crearU;
    QLabel *respuesta;
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
    QPushButton *buy;
    QPushButton *seleccionar;
    QPushButton *jugar_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(777, 426);
        QFont font;
        font.setKerning(false);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
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
        inicio->setGeometry(QRect(530, 250, 241, 151));
        gridLayout = new QGridLayout(inicio);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        respuesta = new QLabel(inicio);
        respuesta->setObjectName(QString::fromUtf8("respuesta"));

        gridLayout->addWidget(respuesta, 1, 0, 1, 1);

        niveles = new QWidget(centralwidget);
        niveles->setObjectName(QString::fromUtf8("niveles"));
        niveles->setGeometry(QRect(150, 140, 461, 101));
        nivel4 = new QPushButton(niveles);
        nivel4->setObjectName(QString::fromUtf8("nivel4"));
        nivel4->setGeometry(QRect(350, 0, 101, 101));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/N4.jpg"), QSize(), QIcon::Normal, QIcon::On);
        nivel4->setIcon(icon);
        nivel4->setIconSize(QSize(100, 100));
        nivel1 = new QPushButton(niveles);
        nivel1->setObjectName(QString::fromUtf8("nivel1"));
        nivel1->setGeometry(QRect(20, 0, 101, 101));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/N1.jpg"), QSize(), QIcon::Normal, QIcon::On);
        nivel1->setIcon(icon1);
        nivel1->setIconSize(QSize(100, 100));
        nivel2 = new QPushButton(niveles);
        nivel2->setObjectName(QString::fromUtf8("nivel2"));
        nivel2->setGeometry(QRect(130, 0, 101, 101));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/N2.jpg"), QSize(), QIcon::Normal, QIcon::On);
        nivel2->setIcon(icon2);
        nivel2->setIconSize(QSize(100, 100));
        nivel3 = new QPushButton(niveles);
        nivel3->setObjectName(QString::fromUtf8("nivel3"));
        nivel3->setGeometry(QRect(240, 0, 101, 101));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/N3.jpg"), QSize(), QIcon::Normal, QIcon::On);
        nivel3->setIcon(icon3);
        nivel3->setIconSize(QSize(100, 100));
        tienda = new QPushButton(centralwidget);
        tienda->setObjectName(QString::fromUtf8("tienda"));
        tienda->setGeometry(QRect(540, 290, 81, 71));
        QFont font1;
        font1.setPointSize(1);
        font1.setKerning(false);
        tienda->setFont(font1);
        tienda->setCursor(QCursor(Qt::OpenHandCursor));
        tienda->setMouseTracking(false);
        tienda->setAutoFillBackground(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/decoracion/tienda.png"), QSize(), QIcon::Normal, QIcon::On);
        tienda->setIcon(icon4);
        tienda->setIconSize(QSize(120, 110));
        jugar = new QPushButton(centralwidget);
        jugar->setObjectName(QString::fromUtf8("jugar"));
        jugar->setGeometry(QRect(630, 250, 121, 101));
        jugar->setMaximumSize(QSize(16777215, 16777215));
        jugar->setSizeIncrement(QSize(0, 0));
        jugar->setFont(font1);
        jugar->setAutoFillBackground(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/decoracion/jugar.png"), QSize(), QIcon::Normal, QIcon::On);
        jugar->setIcon(icon5);
        jugar->setIconSize(QSize(160, 100));
        jugar->setCheckable(false);
        L = new QPushButton(centralwidget);
        L->setObjectName(QString::fromUtf8("L"));
        L->setGeometry(QRect(59, 160, 71, 61));
        QFont font2;
        font2.setPointSize(25);
        font2.setKerning(false);
        L->setFont(font2);
        L->setAutoFillBackground(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/decoracion/izquierda.png"), QSize(), QIcon::Normal, QIcon::On);
        L->setIcon(icon6);
        L->setIconSize(QSize(70, 80));
        home = new QPushButton(centralwidget);
        home->setObjectName(QString::fromUtf8("home"));
        home->setGeometry(QRect(20, 10, 41, 41));
        home->setFont(font2);
        QIcon icon7;
        QString iconThemeName = QString::fromUtf8("\360\237\224\231");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        home->setIcon(icon7);
        home->setIconSize(QSize(16, 16));
        vidaP = new QProgressBar(centralwidget);
        vidaP->setObjectName(QString::fromUtf8("vidaP"));
        vidaP->setGeometry(QRect(200, 10, 181, 31));
        vidaP->setMaximumSize(QSize(16777215, 16777215));
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/SPRITES_GAME/monedas/20220329_092624.png"), QSize(), QIcon::Normal, QIcon::On);
        icon_money->setIcon(icon8);
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
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(15);
        font3.setKerning(false);
        cant_money->setFont(font3);
        R = new QPushButton(centralwidget);
        R->setObjectName(QString::fromUtf8("R"));
        R->setGeometry(QRect(640, 160, 71, 61));
        R->setFont(font2);
        R->setAutoFillBackground(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/SPRITES_GAME/objetos/decoracion/derecha.PNG"), QSize(), QIcon::Normal, QIcon::On);
        R->setIcon(icon9);
        R->setIconSize(QSize(70, 70));
        precio = new QLabel(centralwidget);
        precio->setObjectName(QString::fromUtf8("precio"));
        precio->setGeometry(QRect(280, 310, 170, 21));
        QFont font4;
        font4.setPointSize(14);
        font4.setKerning(false);
        precio->setFont(font4);
        buy = new QPushButton(centralwidget);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setGeometry(QRect(370, 340, 96, 41));
        seleccionar = new QPushButton(centralwidget);
        seleccionar->setObjectName(QString::fromUtf8("seleccionar"));
        seleccionar->setGeometry(QRect(250, 340, 97, 41));
        jugar_2 = new QPushButton(centralwidget);
        jugar_2->setObjectName(QString::fromUtf8("jugar_2"));
        jugar_2->setGeometry(QRect(680, 0, 71, 61));
        jugar_2->setMaximumSize(QSize(16777215, 16777215));
        jugar_2->setSizeIncrement(QSize(0, 0));
        jugar_2->setFont(font1);
        jugar_2->setAutoFillBackground(false);
        jugar_2->setIcon(icon5);
        jugar_2->setIconSize(QSize(73, 80));
        jugar_2->setCheckable(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 777, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(username, pw);
        QWidget::setTabOrder(pw, ingresar);
        QWidget::setTabOrder(ingresar, nivel4);
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
        QWidget::setTabOrder(R, crearU);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        user_name->setText(QApplication::translate("MainWindow", "User name", nullptr));
        password->setText(QApplication::translate("MainWindow", "Password", nullptr));
        ingresar->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        crearU->setText(QApplication::translate("MainWindow", "crear", nullptr));
        respuesta->setText(QString());
        nivel4->setText(QString());
        nivel1->setText(QString());
        nivel2->setText(QString());
        nivel3->setText(QString());
        tienda->setText(QString());
        jugar->setText(QString());
#ifndef QT_NO_TOOLTIP
        L->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/SPRITES_GAME/objetos/decoracion/izquierda.png\"/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        L->setText(QString());
        home->setText(QApplication::translate("MainWindow", "\360\237\224\231", nullptr));
        icon_money->setText(QString());
        R->setText(QString());
        precio->setText(QString());
        buy->setText(QApplication::translate("MainWindow", "comprar", nullptr));
        seleccionar->setText(QApplication::translate("MainWindow", "seleccionar", nullptr));
        jugar_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
