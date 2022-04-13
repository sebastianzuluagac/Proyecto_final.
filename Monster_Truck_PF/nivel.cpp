#include "nivel.h"

nivel::nivel()
{
    QPixmap imagen;
    imagen.load(":/SPRITES_GAME/niveles/nivel1.png");

    fondo=imagen.copy(0,0,6060, 780);//.scaled(100,10);
    setPixmap(fondo);
    level1 = new QGraphicsScene;
    level1->setSceneRect(0,0,tamnivelX, tamnivelY);
}

void nivel::CARGAR_MUNDO(int n)
{
    switch (n) {

        //-------------------------------------
        case 1:{
        level1->setBackgroundBrush(fondo);
        //for (int i=0;i<10;i++){
            container=new containers(0,0);
          //  contenedores.push_back(container);
        //}
        level1->addItem(container);
        container->INCLINACION(30);
        container->setPos(1000,500);
        }break;
        //-------------------------------------
        //-------------------------------------
        case 2:{

        }break;
        //-------------------------------------
        //-------------------------------------
        case 3:{

        }break;
        //-------------------------------------

    }

}

