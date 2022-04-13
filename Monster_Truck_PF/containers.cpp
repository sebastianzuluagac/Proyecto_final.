#include "containers.h"

containers::containers(int fila , int col)
{
    imagen.load(":/SPRITES_GAME/objetos/containers/container_amarillo.png");
    setPixmap(imagen);
    copia=imagen.copy(0,0,602, 209).scaled(602*0.5,209*0.5);
    setPixmap(copia);
    //setPos(Pos_x,Pos_y);

}

containers::containers()
{

}

void containers::INCLINACION(float grado)
{
    QMatrix matrix;
    matrix.rotate(grado);
    copia = copia.transformed(matrix, Qt::SmoothTransformation);
}
