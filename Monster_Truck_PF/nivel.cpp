#include "nivel.h"

nivel::nivel()
{
    QPixmap imagen;
    imagen.load(":/SPRITES_GAME/niveles/nivel1.png");

    fondo=imagen.copy(0,0,6060, 780);//.scaled(100,10);
    setPixmap(fondo);
}

void nivel::CARGAR_MUNDO()
{
    for (int i=0;i<10;i++){
        container=new containers(":/SPRITES_GAME/objetos/containers/container_amarillo.png");
        contenedores.push_back(container);
    }


}

