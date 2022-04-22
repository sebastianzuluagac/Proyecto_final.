#include "objetos.h"

//-------------------Monedas-------------------------
monedas::monedas(int pos_x, int pos_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/monedas/monedas.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,140, 150).scaled(42,45);
    setPixmap(copia);
    setPos(pos_x,pos_y);
    animacion = new QTimer(this);
    connect(animacion, SIGNAL(timeout()), this, SLOT(movimiento()));
    animacion->start(150);

}

monedas::monedas()
{

}

void monedas::set_sprite(int posx, int posy)
{
    //int dimensionbloquee=16;
    copia=imagen.copy(140*posx,150*posy,140, 150).scaled(42,45);
    setPixmap(copia);
}

void monedas::Destruir_moneda()
{
    Destruir = true;
}

bool monedas::Moneda_activa()
{
    if(Destruir == true) return false;
    else return true;
}

void monedas::movimiento()
{
    //ANIMACION_MOVIMIENTO
    static short int pos=0;
    set_sprite(pos,0);
    pos++;
    if (pos>10){
        pos=1;
    }
    if(Destruir == true){
        this->setY(this->y()-30);
    }
}

//----------------------------------------------------

//------------------Cajas------------------------------
cajas::cajas(int pos_x, int pos_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/cajas.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,110, 124).scaled(110*0.5,124*0.5);
    setPixmap(copia);
    setPos(pos_x,pos_y);
    animacion = new QTimer(this);
    connect(animacion, SIGNAL(timeout()), this, SLOT(destruccion()));
    animacion->start(100);

}

cajas::cajas()
{

}

void cajas::set_sprite(int posx, int posy)
{    
    copia=imagen.copy(110*posx,124*posy,110, 124);//.scaled(bloqueX*0.5,bloqueY*0.5);
    setPixmap(copia);
}

void cajas::destruccion()
{
    //ANIMACION_DESTRUCCION
    static short int pos=0;
    set_sprite(pos,0);
    pos++;
    if (pos>12){
        pos=0;
        animacion->stop();
    }
}

//----------------------------------------------------

//----------------PINCHOS---------------------------
pinchos::pinchos(int pos_x, int pos_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/pinchos.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,292, 237).scaled(80,60);
    setPixmap(copia);
    setPos(pos_x,pos_y);

}

pinchos::pinchos()
{

}

//----------------------------------------------------

//------------------Minas------------------------------
minas::minas(int pos_x, int pos_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/minas.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,130, 150).scaled(180, 150);
    setPixmap(copia);
    setPos(pos_x,pos_y);
    animacion = new QTimer(this);
    connect(animacion, SIGNAL(timeout()), this, SLOT(destruccion()));
}

minas::minas()
{

}

void minas::set_sprite(int posx, int posy)
{
    copia=imagen.copy(130*posx, 150*posy, 130, 150).scaled(180, 150);
    setPixmap(copia);
}

void minas::Destruir_mina()
{
    Destruir = true;
    animacion->start(100);
}

bool minas::Mina_activa()
{
    if(Destruir == true) return false;
    else return true;
}

void minas::destruccion()
{
    //ANIMACION_DESTRUCCION
    static short int pos=0;
    set_sprite(pos,0);
    pos++;
    if (pos>9){
        pos=0;
        animacion->stop();
    }
}

//----------------------------------------------------

//------------------MujerNPC------------------------------
mujer::mujer(int pos_x, int pos_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/mujer.png");
    setPixmap(imagen);
    copia=imagen.copy(0, 0, 110, 170).scaled(110*0.5, 170*0.5);
    setPixmap(copia);
    setPos(pos_x,pos_y);
    animacion = new QTimer(this);
    connect(animacion, SIGNAL(timeout()), this, SLOT(movimiento()));
    animacion->start(100);

}

mujer::mujer()
{
}

void mujer::set_sprite(int posx, int posy)
{
    copia=imagen.copy(110*posx,170*posy,110, 170).scaled(110*0.5, 170*0.5);
    setPixmap(copia);
}

void mujer::movimiento()
{//ANIMACION_DESTRUCCION
    static short int pos=0;
    set_sprite(pos,0);
    setX(x()+10);
    pos++;
    if (pos>18){
        pos=0;
    }
}

//----------------------------------------------------


//------------------MujerNPC------------------------------
pajaro::pajaro(int pos_x, int pos_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/pajaro.png");
    setPixmap(imagen);
    copia=imagen.copy(0, 0, 240, 280).scaled(240*0.5, 280*0.5);
    setPixmap(copia);
    setPos(pos_x,pos_y);
    animacion = new QTimer(this);
    connect(animacion, SIGNAL(timeout()), this, SLOT(movimiento()));
    animacion->start(100);

}

pajaro::pajaro()
{
}

void pajaro::set_sprite(int posx, int posy)
{
    copia=imagen.copy(240*posx, 280*posy, 240, 280).scaled(240*0.5, 280*0.5);
    setPixmap(copia);
}

void pajaro::Destruir_ave()
{
    Destruir = true;
}

bool pajaro::Ave_activa()
{
    if(Destruir == true) return false;
    else return true;
}

void pajaro::movimiento()
{//ANIMACION_DESTRUCCION
    static short int pos=0;
    set_sprite(pos,0);
    setX(x()+10);
    pos++;
    if (pos>8){
        pos=0;
    }
    if(Destruir == true){
        this->setY(this->y()+30);
    }
}

//----------------------------------------------------

//------------------Cierra------------------------------
cierra::cierra(int pos_x, int pos_y, int Velocidad, int Ancho_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/cierras.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,1024, 1024).scaled(100,100);
    setPixmap(copia);
    x=pos_x;y=pos_y;
    animacion = new QTimer(this);
    connect(animacion, SIGNAL(timeout()), this, SLOT(movimiento()));
    animacion->start(Velocidad);
    this->Ancho_y = Ancho_y;
    this->Velocidad = Velocidad;
}

cierra::cierra()
{
}

void cierra::set_sprite(int posx, int posy)
{
    copia=imagen.copy(1024*posx,1024*posy,1024, 1024).scaled(100,100);
    setPixmap(copia);
}

int cierra::Datos(int Indx)
{
    if(Indx == 0) return px;
    else if(Indx == 1) return 100;
    else if(Indx == 2) return Velocidad;
    else return 0;
}

void cierra::movimiento()
{//ANIMACION_DESTRUCCION
    static short int pos=0;
    set_sprite(pos,0);

    static float cont=0;
    px=x+300*qCos( qDegreesToRadians(cont) );
    cont+=5.0f;

    py=y+Ancho_y*qSin( qDegreesToRadians(cont) );
    cont+=5.0f;
    setPos(px,py);


    //setRotation(10*pos);
    pos++;
    if (pos>4){
        pos=0;
    }
}

//----------------------------------------------------


//----------------META---------------------------
meta::meta(int pos_x, int pos_y)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/meta.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,197, 169).scaled(197*1.5,169*1.5);
    setPixmap(copia);
    setPos(pos_x,pos_y);
    this->Pos_x = pos_x;

}

meta::meta()
{

}


//----------------RESORTES---------------------------
resorte::resorte(int pos_x, int pos_y, int Fuerza_resorte)
{
    imagen.load("../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/resortes.png");
    setPixmap(imagen);
    copia=imagen.copy(0, 0, 800, 511).scaled(200,100);
    setPixmap(copia);
    setPos(pos_x,pos_y);
    this->Pos_x = pos_x;
    this->Pos_y = pos_y;
    this->Fuerza_resorte = Fuerza_resorte;
}

resorte::resorte()
{

}

int resorte::Datos(int Indx)
{
    if(Indx == 0) return Pos_x;
    else if(Indx == 1) return Pos_y;
    else if(Indx == 2) return 200;
    else if(Indx == 3) return Fuerza_resorte;
    else return 0;
}

//----------------IMAGENES---------------------------
ima::ima(int pos_x, int pos_y, int tamx, int tamy, QString dire)
{
    imagen.load(dire);
    setPixmap(imagen);
    copia=imagen.copy(0,0,tamx, tamy);//.scaled(tamx*1.5,tamy*1.5);
    setPixmap(copia);
    setPos(pos_x,pos_y);

}

ima::ima(){

}

void ima::set_sprite(int posx, int posy,int tamx,int tamy)
{
    copia=imagen.copy(tamx*posx,tamy*posy,tamx, tamy);//.scaled(tamx*0.5,tamy*0.5);
    setPixmap(copia);
}

void ima::Escalar(int tamx, int tamy, float esc_x, float esc_y)
{
    copia=imagen.copy(0,0,tamx, tamy).scaled(tamx*esc_x, tamy*esc_y);
    setPixmap(copia);
}

//----------------------------------------------------



