#include "containers.h"

containers::containers(int Pos_x, int Pos_y)
{
    imagen.load(":/SPRITES_GAME/objetos/containers/container_amarillo.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,602, 209).scaled(602*0.5,210*0.5);
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
    else return 0;
}
