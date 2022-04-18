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

void nivel::CARGAR_MUNDO(char Nivel)
{
    level1->setBackgroundBrush(fondo);
    string Nombre_archivo = "../Monster_Truck_PF/Nivel";
    Nombre_archivo.push_back(Nivel);
    Nombre_archivo.append(".txt");
    string Linea, Pos_x, Pos_y, Inclinacion;
    fstream Archivo;
    Archivo.open(Nombre_archivo, fstream::in | fstream::binary);
    if(Archivo.is_open()){
        while (!Archivo.eof()) {
            getline(Archivo, Linea);
            //Composicion de la linea: a bbbbb cccc ddd e; a=Tipo, bbbb=Posicion en x, cccc=Posicion en y, ddd=inclinacion, e=Tipo especifico
            //Ampliacion tipo: 0=Container, 1=Bomba, 2=Vehiculo, 3=Pinchos, 4=Cajas, 5=Monedas.
            for(int i = 2; i < 16; i++){
                if(i <= 6) Pos_x.push_back(Linea[i]);
                else if(i > 7 && i <= 11) Pos_y.push_back(Linea[i]);
                else if(i > 12 && i <= 15) Inclinacion.push_back(Linea[i]);
            }
            Crear_objeto(Linea[0], atoi(Pos_x.c_str()), atoi(Pos_y.c_str()), atoi(Inclinacion.c_str()), Linea[17]);
            Pos_x.clear(), Pos_y.clear(), Inclinacion.clear();
        }
    }
    Archivo.close();
}

void nivel::Crear_objeto(int Tipo, int Pos_x, int Pos_y, int Grados, char Tipo_especial)
{
    switch (Tipo){

    case 48:{
    //Numero 0 correspondiente a tipo Container.
        static short int Contador_containers = 0;
        (*Contenedores).push_back(new containers(Pos_x, Pos_y, Tipo_especial));
        (*Contenedores)[Contador_containers]->Inclinacion(-Grados);
        (*Contenedores)[Contador_containers]->setPos(Pos_x, Pos_y);
        level1->addItem((*Contenedores)[Contador_containers]);
        Contador_containers+=1;
    }break;

    case 49:{
    //Numero 1 correspondiente a tipo Bomba.

    }break;

    case 50:{
    //Numero 2 correspondiente a tipo Vehiculos.

    }break;

    case 51:{
    //Numero 3 correspondiente a tipo Pinchos.
        static short int Contador_pinchos = 0;
        (*Pincho).push_back(new pinchos(Pos_x, Pos_y));
        level1->addItem((*Pincho)[Contador_pinchos]);
        Contador_pinchos+=1;
    }break;

    case 52:{
    //Numero 4 correspondiente a tipo Cajas.
        static short int Contador_cajas = 0;
        (*Box).push_back(new cajas(Pos_x, Pos_y));
        level1->addItem((*Box)[Contador_cajas]);
        Contador_cajas+=1;
    }break;

    case 53:{
    //Numero 5 correspondiente a tipo Monedas.
        static short int Contador_monedas = 0;
        (*Money).push_back(new monedas(Pos_x, Pos_y));
        level1->addItem((*Money)[Contador_monedas]);
        Contador_monedas+=1;
    }break;

    }
}

void nivel::Recibir_vectores(QVector <cajas*>* Box, QVector <pinchos*>* Pincho, QVector <monedas*>* Money, QVector <containers*>* Contenedores){
    this->Box = Box;
    this->Pincho = Pincho;
    this->Money = Money;
    this->Contenedores = Contenedores;
}

