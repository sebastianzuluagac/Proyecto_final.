#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <time.h>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <portabledeviceconnectapi.h>
#include <QVector>
#include <QKeyEvent>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;
#include "nivel.h"
#include "personaje.h"
#include "archivos.h"
#include "Macros.h"
#include "objetos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void decorar();
    void Juego_activo();
    void Detener_juego();

protected:
    void keyPressEvent(QKeyEvent *tecla);

private slots:

    void on_ingresar_clicked();

    void on_crearU_clicked();

    void on_jugar_clicked();

    void on_nivel1_clicked();

    void on_nivel2_clicked();

    void on_nivel3_clicked();

    void on_nivel4_clicked();

    void on_tienda_clicked();

    void on_home_clicked();

    void on_R_clicked();

    void on_L_clicked();

    void on_seleccionar_clicked();

    void on_buy_clicked();

    void on_jugar_2_clicked();

private:
    bool Colision = false;
    bool Jugando = false;
    bool Ganastes = false;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    nivel *Niveles;
    personaje *carro;
    meta *Finish;
    QMap <char, ima*> Imagenes;
    QVector <cajas*> Box;
    QVector <pinchos*> Pincho;
    QVector <monedas*> Money;
    QVector <containers*> Contenedores;
    QVector <minas*> Mina;
    QVector <mujer*> Dama;
    QVector <pajaro*> Aves;
    QVector <cierra*> Cierras;
    QVector <resorte*> Resortes;
    QKeyEvent *tecla;
    QTimer *timer;

    //Tienda
    QGraphicsScene *tienda,*inicio;
    ima *modelo;
    int nLR=0;

};
#endif // MAINWINDOW_H
