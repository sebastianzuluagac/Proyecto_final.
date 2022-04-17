#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QVector>
#include <QMap>
#include <QString>
#include <math.h>
#include <time.h>
#include <QTimer>
#include <QDebug>
#include "Macros.h"
#include "containers.h"
#define bloqueX 240
#define bloqueY 153

class personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    personaje(QGraphicsScene *scene, float Pos_x, float Pos_y);
    personaje();
    void set_sprite(int posx, int posy);
    void MOVER_ADELANTE();
    void MOVER_ATRAS();
    void Mover(float Aplicar_fuerza_x, float Aplicar_fuerza_y);
    float Datos(char Index);
    void Saltar();
    void Girar(float Fuerza_ang_x, float Fuerza_ang_y);
    bool Carro_apoyado();
    void Inclinacion(int Grado);
    void Limite_inf(int Valor_limite);
    void Punto_colision(int Punto_colision){Punto_inicial_colision = Punto_colision;}

    void USERNAME(QString name){username=name;}
    QString GET_NAME(){return username;}
    float getV(){return v;}


private slots:
    void Ciclo_automatico();


private:
    float Aceleracion_x=0, Aceleracion_y=0, Velocidad_x=0, Velocidad_y=0, Posicion_x, Posicion_y, masa=200, Fuerza_x=0, Fuerza_y=0, T=100;
    float Fuerza_neta = 0, Friccion_x = 1, Gravedad = 1;
    float Aceleracion_ang_x=1, Aceleracion_ang_y=1, Velocidad_ang_x=1, Velocidad_ang_y=1, Grado = 0, Momento_inercia = 10, Fuerza_ang_x = 0, Fuerza_ang_y = 10;
    int Limite_inferior = 500, Punto_inicial_colision = 0;
    QGraphicsScene *scene;
    float v=0;
    QTimer *velocimetro;
    QPixmap imagen;
    QPixmap copia;
    QString username;

};

#endif // PERSONAJE_H
