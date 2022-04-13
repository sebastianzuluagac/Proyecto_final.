#include "personaje.h"
using namespace std;



personaje::personaje(QGraphicsScene *scene, float Pos_x, float Pos_y)
{
    //setPixmap(QPixmap(nombre));
    imagen.load(":/SPRITES_GAME/personaje/carro1/carro_mounstro.png");
    setPixmap(imagen);
    velocimetro = new QTimer(this);
    connect(velocimetro, SIGNAL(timeout()), this, SLOT(Ciclo_automatico()));
    velocimetro->start(50);
    this->scene = scene;
    this->Posicion_x = Pos_x;
    this->Posicion_y = Pos_y;
    this->setPos(Pos_x, Pos_y);
}

personaje::personaje()
{}


void personaje::set_sprite(int posx, int posy)
{
    //int dimensionbloquee=16;
    copia=imagen.copy(bloqueX*posx,bloqueY*posy,bloqueX, bloqueY).scaled(bloqueX*0.5,bloqueY*0.5);
    setPixmap(copia);
}

void personaje::MOVER_ADELANTE()
{
    //ANIMACION_MOVIMIENTO
    static short int pos=8;
    set_sprite(pos,0);
    pos--;
    if (pos<0){
        pos=8;
    }
    this->setX(Posicion_x);
    this->x()>400? scene->setSceneRect(this->x()-400,0,tamnivelX, tamnivelY):scene->setSceneRect(0,0,tamnivelX, tamnivelY);
}

void personaje::MOVER_ATRAS()
{
    //ANIMACION_MOVIMIENTO
    static short int pos=0;
    set_sprite(pos,0);
    pos++;
    if (pos>8){
        pos=0;
    }
    this->setX(Posicion_x);
    if(Posicion_x < 0) Velocidad_x = 0, Fuerza_x = 0;
    this->x()>400? scene->setSceneRect(this->x()-400,0,tamnivelX, tamnivelY):scene->setSceneRect(0,0,tamnivelX, tamnivelY);
}

void personaje::Mover(float Aplicar_fuerza_x, float Aplicar_fuerza_y)
{
    Fuerza_x = Aplicar_fuerza_x;
    Fuerza_y = Aplicar_fuerza_y;
}

float personaje::Fuerza_actual(char Index)
{
    if(Index == 0) return Fuerza_x;
    else if(Index == 1) return Fuerza_y;
    else return 0;
}

void personaje::Saltar()
{
    this->setY(Posicion_y);
}

bool personaje::Carro_apoyado()
{
    if(Posicion_y == 500) return true;
    else return false;
}


void personaje::Ciclo_automatico()
{
    Aceleracion_x = Fuerza_x/masa;
    Velocidad_x = Aceleracion_x*T;
    Posicion_x = Posicion_x + Velocidad_x;
    if(Velocidad_x>0)this->MOVER_ADELANTE();
    if(Velocidad_x<0)this->MOVER_ATRAS();
    if(Fuerza_x>0)Fuerza_x -= Friccion_x;
    if(Fuerza_x<0)Fuerza_x += Friccion_x;

    Aceleracion_y = Fuerza_y/masa;
    Velocidad_y = Velocidad_y + Aceleracion_y*T;
    Posicion_y = Posicion_y + Velocidad_y;
    if(Posicion_y>500) Posicion_y = 500, Velocidad_y = 0, Fuerza_y = 0;
    this->Saltar();
    if(Posicion_y!=500)Fuerza_y += Gravedad;
}


