#ifndef OBJETOS_H
#define OBJETOS_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>
#include <QVector>
#include <qmath.h>

//------------------MONEDAS--------------------------------------
class monedas: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    monedas(int pos_x, int pos_y);
    monedas();
    void set_sprite(int posx, int posy);
    void start(){animacion->start(100);}
    void Destruir_moneda();
    bool Moneda_activa();

private slots:
    void movimiento();

private:
    bool Destruir = false;
    QPixmap imagen;
    QPixmap copia;
    QTimer *animacion;
    QVector <monedas*>* Money;
};

//---------------------CAJAS-------------------------------------------
class cajas: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cajas(int pos_x, int pos_y);
    cajas();
    void set_sprite(int posx, int posy);
    void startd(){animacion->start(100);}

private slots:
    void destruccion();

private:
    QPixmap imagen;
    QPixmap copia;
    QTimer *animacion;

};

//----------------------------PINCHOS--------------------------------
class pinchos: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pinchos(int pos_x, int pos_y);
    pinchos();

private:
    QPixmap imagen;
    QPixmap copia;
};


//---------------------MINAS-------------------------------------------
class minas: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    minas(int pos_x, int pos_y);
    minas();
    void set_sprite(int posx, int posy);
    void stard(){animacion->start(100);}
    void Destruir_mina();
    bool Mina_activa();

private slots:
    void destruccion();

private:    
    bool Destruir = false;
    QPixmap imagen;
    QPixmap copia;
    QTimer *animacion;

};

//---------------------MujerNPC-------------------------------------------
class mujer: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    mujer(int pos_x, int pos_y);
    mujer();
    void set_sprite(int posx, int posy);
    void stard(){animacion->start(100);}

private slots:
    void movimiento();

private:
    QPixmap imagen;
    QPixmap copia;
    QTimer *animacion;

};

//---------------------PAJARO-------------------------------------------
class pajaro: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pajaro(int pos_x, int pos_y);
    pajaro();
    void set_sprite(int posx, int posy);
    void stard(){animacion->start(100);}
    void Destruir_ave();
    bool Ave_activa();

private slots:
    void movimiento();

private:
    bool Destruir = false;
    QPixmap imagen;
    QPixmap copia;
    QTimer *animacion;

};

//---------------------CIERRA-------------------------------------------
class cierra: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cierra(int pos_x, int pos_y, int Velocidad, int Ancho_y);
    cierra();
    void set_sprite(int posx, int posy);
    int Datos(int Indx);

private slots:
    void movimiento();

private:
    float px, py;
    int x, y, Ancho_y, Velocidad;
    QPixmap imagen;
    QPixmap copia;
    QTimer *animacion;

};

//----------------------------META--------------------------------
class meta: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    meta(int pos_x, int pos_y);
    meta();
    int Datos(){return Pos_x;}

private:
    int Pos_x;
    QPixmap imagen;
    QPixmap copia;
};

//----------------------------RESORTES--------------------------------
class resorte: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    resorte(int pos_x, int pos_y, int Fuerza_resorte);
    resorte();
    int Datos(int Indx);

private:
    int Pos_x, Pos_y, Fuerza_resorte;
    QPixmap imagen;
    QPixmap copia;
};

//----------------------------IMAGENES--------------------------------
class ima: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ima(int pos_x, int pos_y,int tamx,int tamy,QString dire);
    ima();
    void set_sprite(int posx, int posy,int tamx,int tamy);
    void Escalar(int tamx, int tamy, float esc_x, float esc_y);

private:
    QPixmap imagen;
    QPixmap copia;
};



#endif // OBJETOS_H


