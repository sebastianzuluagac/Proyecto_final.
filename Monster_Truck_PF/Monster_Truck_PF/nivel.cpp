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

nivel::~nivel()
{
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
            //Ampliacion tipo: 0=Container, 1=Bomba, 2=Aves, 3=Pinchos, 4=Cajas, 5=Monedas, 6=Mujer.
            for(int i = 2; i < 16; i++){
                if(i <= 6) Pos_x.push_back(Linea[i]);
                else if(i > 7 && i <= 11) Pos_y.push_back(Linea[i]);
                else if(i > 12 && i <= 15) Inclinacion.push_back(Linea[i]);
            }
            //Crear objeto de acuerdo a los datos obtenidos en la linea.
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
        (*Contenedores).push_back(new containers(Pos_x, Pos_y, Tipo_especial));
        (*Contenedores)[Contador_containers]->Inclinacion(-Grados);
        (*Contenedores)[Contador_containers]->setPos(Pos_x, Pos_y);
        level1->addItem((*Contenedores)[Contador_containers]);
        Contador_containers+=1;
    }break;

    case 49:{
    //Numero 1 correspondiente a tipo Minas.
        (*Mina).push_back(new minas(Pos_x, Pos_y));
        level1->addItem((*Mina)[Contador_minas]);
        Contador_minas+=1;
    }break;

    case 50:{
    //Numero 2 correspondiente a tipo aves.
        (*Aves).push_back(new pajaro(Pos_x, Pos_y));
        level1->addItem((*Aves)[Contador_aves]);
        Contador_aves+=1;
    }break;

    case 51:{
    //Numero 3 correspondiente a tipo Pinchos.
        (*Pincho).push_back(new pinchos(Pos_x, Pos_y));
        level1->addItem((*Pincho)[Contador_pinchos]);
        Contador_pinchos+=1;
    }break;

    case 52:{
    //Numero 4 correspondiente a tipo Cajas.
        (*Box).push_back(new cajas(Pos_x, Pos_y));
        level1->addItem((*Box)[Contador_cajas]);
        Contador_cajas+=1;
    }break;

    case 53:{
    //Numero 5 correspondiente a tipo Monedas.
        (*Money).push_back(new monedas(Pos_x, Pos_y));
        level1->addItem((*Money)[Contador_monedas]);
        Contador_monedas+=1;
    }break;

    case 54:{
    //Numero 6 correspondiente a tipo Dama.
        (*Dama).push_back(new mujer(Pos_x, Pos_y));
        level1->addItem((*Dama)[Contador_damas]);
        Contador_damas+=1;
    }break;

    case 55:{
    //Numero 7 correspondiente a tipo Cierra.
        (*Cierras).push_back(new cierra(Pos_x, Pos_y, (Tipo_especial-48)*100, Grados));
        level1->addItem((*Cierras)[Contador_cierras]);
        Contador_cierras+=1;
    }break;

    case 56:{
    //Numero 8 correspondiente a tipo Resorte.
        (*Resortes).push_back(new resorte(Pos_x, Pos_y));
        level1->addItem((*Resortes)[Contador_resortes]);
        Contador_resortes+=1;
    }break;

    case 57:{
    //Numero 9 correspondiente a tipo Meta.
        Finish = new meta(Pos_x, Pos_y);
        level1->addItem(Finish);
    }break;

    }
}

void nivel::Recibir_vectores(QVector <cajas*>* Box, QVector <pinchos*>* Pincho, QVector <monedas*>* Money,
                             QVector <containers*>* Contenedores, QVector <minas*>* Mina, QVector <mujer*>* Dama,
                             QVector <pajaro*>* Aves, QVector <cierra*>* Cierras, QVector <resorte*>* Resortes, meta *Finish){
    this->Box = Box;
    this->Pincho = Pincho;
    this->Money = Money;
    this->Contenedores = Contenedores;
    this->Mina = Mina;
    this->Dama = Dama;
    this->Aves = Aves;
    this->Cierras = Cierras;
    this->Resortes = Resortes;
    this->Finish = Finish;
}

void nivel::Eliminar_memoria_vectores()
{
    //Liberar memoria de contenedores y eliminarlos de la escena level1.
    for(int i = 0; i < (*Contenedores).size(); i++){
        level1->removeItem((*Contenedores)[i]);
        delete (*Contenedores)[i];
    }
    (*Contenedores).clear();
    Contador_containers = 0;

    //Liberar memoria de pinchos y eliminarlos de la escena level1.
    for(int i = 0; i < (*Pincho).size(); i++){
        level1->removeItem((*Pincho)[i]);
        delete (*Pincho)[i];
    }
    (*Pincho).clear();
    Contador_pinchos = 0;

    //Liberar memoria de cajas y eliminarlos de la escena level1.
    for(int i = 0; i < (*Box).size(); i++){
        level1->removeItem((*Box)[i]);
        delete (*Box)[i];
    }
    (*Box).clear();
    Contador_cajas = 0;

    //Liberar memoria de monedas y eliminarlos de la escena level1.
    for(int i = 0; i < (*Money).size(); i++){
        level1->removeItem((*Money)[i]);
        delete (*Money)[i];
    }
    (*Money).clear();
    Contador_monedas = 0;

    //Liberar memoria de aves y eliminarlos de la escena level1.
    for(int i = 0; i < (*Aves).size(); i++){
        level1->removeItem((*Aves)[i]);
        delete (*Aves)[i];
    }
    (*Aves).clear();
    Contador_aves = 0;

    //Liberar memoria de minas y eliminarlos de la escena level1.
    for(int i = 0; i < (*Mina).size(); i++){
        level1->removeItem((*Mina)[i]);
        delete (*Mina)[i];
    }
    (*Mina).clear();
    Contador_minas = 0;

    //Liberar memoria de damas y eliminarlos de la escena level1.
    for(int i = 0; i < (*Dama).size(); i++){
        level1->removeItem((*Dama)[i]);
        delete (*Dama)[i];
    }
    (*Dama).clear();
    Contador_damas = 0;

    //Liberar memoria de cierras y eliminarlos de la escena level1.
    for(int i = 0; i < (*Cierras).size(); i++){
        level1->removeItem((*Cierras)[i]);
        delete (*Cierras)[i];
    }
    (*Cierras).clear();
    Contador_cierras = 0;

    //Liberar memoria de damas y eliminarlos de la escena level1.
    for(int i = 0; i < (*Resortes).size(); i++){
        level1->removeItem((*Resortes)[i]);
        delete (*Resortes)[i];
    }
    (*Resortes).clear();
    Contador_resortes = 0;

    //Liberar memorita de meta y eliminarla de la escena level1.
    level1->removeItem(Finish);
    delete Finish;
}



