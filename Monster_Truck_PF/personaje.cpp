#include "personaje.h"
using namespace std;
personaje::personaje()
{
    //setPixmap(QPixmap(nombre));
    imagen.load(":/SPRITES_GAME/personaje/carro1/carro_mounstro.png");
    setPixmap(imagen);
    velocimetro = new QTimer(this);
    connect(velocimetro, SIGNAL(timeout()), this, SLOT(velocidad()));
    velocimetro->start(500);
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
    set_sprite(pos,4);
    pos--;
    if (pos<0){
        pos=8;
    }

    setX(x()+10);
}

void personaje::MOVER_ATRAS()
{
    //ANIMACION_MOVIMIENTO
    static short int pos=0;
    set_sprite(pos,4);
    pos++;
    if (pos>8){
        pos=0;
    }
    //setX(x()-10);
    x()>0? setX(x()-10): setX(x());
}

void personaje::GRAVEDAD()
{
    y()<505? setY(y()+100): setY(y());
}



void personaje::velocidad()
{
    GRAVEDAD();
static int xx=0,vf=0,a=0;
    v=x()-xx;
   qDebug() <<"la velocidad es: "<<v<<endl;
   if (v!=vf){
   a=vf-v;
   }
    xx=x();
    vf=v;
    //v=v+a;
    //setX(v);
    qDebug() <<"la aceleracion es: "<<a<<endl;
}


