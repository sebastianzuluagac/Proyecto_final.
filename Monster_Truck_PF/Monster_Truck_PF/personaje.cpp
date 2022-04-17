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
{

}

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

float personaje::Datos(char Index)
{
    if(Index == 0) return Fuerza_x;
    else if(Index == 1) return Fuerza_y;
    else if(Index == 2) return Grado;
    else if(Index == 3) return Posicion_x;
    else if(Index == 4) return Posicion_y;
    else if(Index == 5) return Fuerza_ang_x;
    else if(Index == 6) return Fuerza_ang_y;
    else if(Index == 7) return Punto_inicial_colision;

    else return 0;
}

void personaje::Saltar()
{
    this->setY(Posicion_y);
}

void personaje::Girar(float Fuerza_ang_x, float Fuerza_ang_y)
{
    this->Fuerza_ang_x = Fuerza_ang_x;
    this->Fuerza_ang_y = Fuerza_ang_y;
}

bool personaje::Carro_apoyado()
{
    if(Posicion_y == Limite_inferior) return true;
    else return false;
}

void personaje::Inclinacion(int Grado)
{
    setRotation(Grado);
    //this->Grado = Grado;
}

void personaje::Limite_inf(int Valor_limite)
{
    Limite_inferior = Valor_limite;
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
    if(Posicion_y>Limite_inferior) Posicion_y = Limite_inferior, Velocidad_y = 0, Fuerza_y = 0;
    this->Saltar();
    if(Posicion_y!=Limite_inferior)Fuerza_y += Gravedad;

    if(this->Carro_apoyado()==true && this->Datos(2)>0 && Fuerza_x == 0)Fuerza_ang_x = Fuerza_ang_x-0.5;
    if(this->Carro_apoyado()==true && this->Datos(2)<0 && Fuerza_x == 0)Fuerza_ang_x = Fuerza_ang_x+0.5;
    Aceleracion_ang_x = Fuerza_ang_x/Momento_inercia;
    Velocidad_ang_x = Aceleracion_ang_x*T;
    Aceleracion_ang_y = Fuerza_ang_y/Momento_inercia;
    Velocidad_ang_y = Aceleracion_ang_y*T;
    Grado = (atan(Velocidad_ang_x/Velocidad_ang_y))*180/3.14159265;
    this->Inclinacion(Grado);

}


