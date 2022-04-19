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
    //Actualizar posicion en x, y actualizar focus.
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
    //Actualizar posicion en x, actualizar focus y establecer limite inicio de pista.
    if(Posicion_x < 0) Velocidad_x = 0, Fuerza_x = 0, Posicion_x = 0;
    this->setX(Posicion_x);
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
    else if(Index == 8) return Limite_inferior;
    else return 0;
}

void personaje::Saltar()
{
    //Actualizar posicion en y.
    this->setY(Posicion_y);
}

void personaje::Girar(float Fuerza_ang_x, float Fuerza_ang_y)
{
    //Recibir fuerza angular en sus componentes, estableciendo sus limites.
    this->Fuerza_ang_x = Fuerza_ang_x;
    this->Fuerza_ang_y = Fuerza_ang_y;
    if(this->Fuerza_ang_x > 0.548) this->Fuerza_ang_x = 0.548;
    if(this->Fuerza_ang_x < -0.548) this->Fuerza_ang_x = -0.548;
}

bool personaje::Carro_apoyado()
{
    //true si el carro esta sobre el piso o cerca de el a 5 pixeles, de lo contrario false.
    if(Posicion_y >= Limite_inferior-5) return true;
    else return false;
}


void personaje::Inclinacion(int Grado)
{
    //Establecer angulo de inclinacion.
    setRotation(Grado);
}

void personaje::Limite_inf(int Valor_limite)
{
    //Establecer limite inferior donde apoyarse.
    Limite_inferior = Valor_limite;
}

void personaje::Punto_colision(int Punto_colision, int Rango_colision)
{
    //Establecer punto y rango de colision con containers.
    Punto_inicial_colision = Punto_colision;
    this->Rango_colision = Rango_colision;
}

void personaje::Choque_frontal(int Punto_choque, int Rebote)
{
    if(Rebote > 0){
        Posicion_x = Punto_choque;
        Velocidad_x = 0;
        Fuerza_x = -Rebote;
        MOVER_ADELANTE();
    }
    else if(Rebote < 0){
        Posicion_x = Punto_choque;
        Velocidad_x = 0;
        Fuerza_x = -Rebote;
        MOVER_ATRAS();
    }

}

void personaje::Destruirse()
{
    //Crear animacion de destruccion.
    delete velocimetro;
    delete this;
}

void personaje::UPDATE_DATA(char dat,char signo, int cant)
{
    switch (dat) {
    case 'D':{
            if (signo=='+')dinero++;
            else if (signo=='-')dinero-=cant;
    }break;
    //-------------------------------------

    case 'C':{
        if (signo=='E')carroElegido=cant;
        else if (signo=='D') carrosDes++;
    }break;
    //-------------------------------------

    case 'N':{nivelesDes++;}break;
    //-------------------------------------

    case ' ':{}break;
    //-------------------------------------

    }
}

int personaje::GET_DATA(char dat, char signo)
{
    switch (dat) {
    case 'D':{return dinero;}break;
    //-------------------------------------

    case 'C':{
        if (signo=='E') return carroElegido;
        else if (signo=='D') return carrosDes;
    }break;
    //-------------------------------------

    case 'N':{return nivelesDes;}break;
    //-------------------------------------

    case ' ':{}break;
    //-------------------------------------

    }
    return -1;
}

void personaje::Ciclo_automatico()
{
    //Si no esta en rango de colision establecer el suelo como limite inferior(500).
    if((this->Datos(3)-Punto_inicial_colision) > Rango_colision || this->Datos(3)+120 < Punto_inicial_colision) Limite_inferior = 500;

    //Aplicar formulas de fuerza en x para determinar aceleracion, velocidad y actualizar posicion.
    Aceleracion_x = Fuerza_x/masa;
    Velocidad_x = Aceleracion_x*T;
    Posicion_x = Posicion_x + Velocidad_x;
    if(Velocidad_x>0)this->MOVER_ADELANTE();
    if(Velocidad_x<0)this->MOVER_ATRAS();
    if(Fuerza_x>0)Fuerza_x -= Friccion_x;
    if(Fuerza_x<0)Fuerza_x += Friccion_x;

    //Aplicar formulas de fuerza en y para determinar aceleracion, velocidad y actualizar posicion.
    Aceleracion_y = Fuerza_y/masa;
    Velocidad_y = Velocidad_y + Aceleracion_y*T;
    Posicion_y = Posicion_y + Velocidad_y;
    if(Posicion_y>Limite_inferior) Posicion_y = Limite_inferior, Velocidad_y = 0;
    this->Saltar();
    if(Posicion_y!=Limite_inferior)Fuerza_y += Gravedad;

    //Si el carro esta apoyado, velocidad menor de 20 e inclinacion < 60 enderezar automaticamente con angulo 0.
    if(this->Carro_apoyado()==true && this->Datos(2)<60 && this->Datos(2)>0 && Velocidad_x < 20 && Colision == false){
        Fuerza_ang_x = Fuerza_ang_x-0.02;
        if(this->Datos(2) < 5)Fuerza_ang_x = 0;
    }
    //Si el carro esta apoyado, velocidad menor de 20 e inclinacion > -60 enderezar automaticamente con angulo 0.
    if(this->Carro_apoyado()==true && this->Datos(2)>-60 && this->Datos(2)<0 && Velocidad_x < 20 && Colision == false){
        Fuerza_ang_x = Fuerza_ang_x+0.02;
        if(this->Datos(2) > -5)Fuerza_ang_x = 0;
    }

    //Aplicar formulas de movimiento rotacional basado en fuerzas para determinar
    //aceleracion angular, velocidad angular y asi actualizar angulo de inclinacion.
    Aceleracion_ang_x = Fuerza_ang_x/Momento_inercia;
    Velocidad_ang_x = Aceleracion_ang_x*T;
    Aceleracion_ang_y = Fuerza_ang_y/Momento_inercia;
    Velocidad_ang_y = Aceleracion_ang_y*T;
    Grado = atan(Velocidad_ang_x/Velocidad_ang_y);
    Grado = Grado*180/3.14159265;
    Grado = Grado*180/3.14159265;
    this->Inclinacion(Grado);

}


