#include "containers.h"

containers::containers(int Pos_x, int Pos_y, char Tipo)
{
    QString direccion="../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/containers/";
    int tamy=0;
    switch (Tipo) {
        case 'a':{direccion.append("container_amarillo.png");tamx=602;tamy=209;}break;//a=amarillo
        case 'A':{direccion.append("C_Amarillo_F.png");tamx=200;tamy=216;}break;//A=C_Amarillo_F
        case 'b':{direccion.append("container_azul.png");tamx=602;tamy=209;}break;//b=blue
        case 'B':{direccion.append("C_Azul_F.png");tamx=200;tamy=216;}break; //B=C_Blue_F
        case 'r':{direccion.append("container_rojo.png");tamx=602;tamy=209;}break; //r=rojo
        case 'R':{direccion.append("C_Rojo_F.png");tamx=200;tamy=216;}break; //R=C_Rojo_F
    }
    imagen.load(direccion);
    setPixmap(imagen);
    copia=imagen.copy(0,0,tamx, tamy).scaled(tamx*0.5,tamy*0.5);
    setPixmap(copia);
    this->Pos_x = Pos_x;
    this->Pos_y = Pos_y;
    setPos(Pos_x,Pos_y);
}


containers::containers()
{

}

void containers::Inclinacion(float grado)
{
    setRotation(grado);
    Grados = grado;
}

int containers::Datos(int Indx)
{
    if(Indx == 0) return Pos_x;
    else if(Indx == 1) return Pos_y;
    else if(Indx == 2) return Grados;
    else if(Indx == 3) return tamx*0.5;
    else return 0;
}
