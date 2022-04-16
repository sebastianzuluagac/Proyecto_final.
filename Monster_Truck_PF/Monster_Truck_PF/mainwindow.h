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
#include <string>
using namespace std;
#include "nivel.h"
#include "personaje.h"
#include "archivos.h"
#include "Macros.h"

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
    void Juego_activo();

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

private:
    bool Colision = false;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    nivel *n1;
    personaje *carro;
    QVector <containers*> Contenedores;
    QKeyEvent *tecla;
    QTimer *timer;
};
#endif // MAINWINDOW_H
