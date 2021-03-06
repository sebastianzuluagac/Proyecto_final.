#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <string.h>
#include <QVector>
#include <QMap>
#include <QString>
#include <math.h>
#include <time.h>
#include <QTimer>
#include <QDebug>
#include "Macros.h"
#include "containers.h"
#include "objetos.h"
#define bloqueX 240
#define bloqueY 153
using namespace std;
class personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    personaje(QGraphicsScene *scene, float Pos_x, float Pos_y);
    personaje();
    void Iniciar_nivel(ima *fondo);
    void set_sprite(int posx, int posy);
    void set_sprite(int posx);
    void MOVER_ADELANTE();
    void MOVER_ATRAS();
    void Mover(float Aplicar_fuerza_x, float Aplicar_fuerza_y);
    float Datos(char Index);
    void Saltar();
    void Girar(float Fuerza_ang_x, float Fuerza_ang_y);
    bool Carro_apoyado();
    bool Colsionando(){return Colision;}
    void Carro_colisionando(bool Colision) {this->Colision = Colision;}
    void Inclinacion(int Grado);
    void Limite_inf(int Valor_limite);
    void Punto_colision(int Punto_colision, int Rango_colision);
    void Choque_frontal(int Punto_choque, int Rebote);
    void Danio_vehiculo(short int Danios);
    void Destruirse();
    void Ganar();

    //Gestion de los datos del jugador---------------------------------
    void USERNAME(QString name){username=name;}
    QString GET_NAME(){return username;}
    void UPDATE_DATA(char dat, char signo, int cant);
    int GET_DATA(char dat, char signo);
    void SETDATA(int monedas, std::string carrosD, int nivelesD);

    //-----------------------------------------------------------------

private slots:
    void Ciclo_automatico();
    void Animacion_destruccion();


private:
    float Aceleracion_x=0, Aceleracion_y=0, Velocidad_x=0, Velocidad_y=0, Posicion_x, Posicion_y, masa=200, Fuerza_x=0, Fuerza_y=0, T=100;
    float Fuerza_neta = 0, Friccion_x = 1, Gravedad = 0.9;
    float Aceleracion_ang_x=1, Aceleracion_ang_y=1, Velocidad_ang_x=1, Velocidad_ang_y=1, Grado = 0, Momento_inercia = 10, Fuerza_ang_x = 0, Fuerza_ang_y = 10;
    float Limite_inferior = 500, Punto_inicial_colision = 0, Rango_colision;
    int dinero=0,carroElegido=0,nivelesDes=1;
    short int Resistencia, Estado_vehiculo;
    bool Colision = false;
    QGraphicsScene *scene;
    QTimer *velocimetro;
    QTimer *Animacion;
    QPixmap imagen;
    QPixmap copia;
    QString username, carrosDes;
    ima *fondo;

};

#endif // PERSONAJE_H
