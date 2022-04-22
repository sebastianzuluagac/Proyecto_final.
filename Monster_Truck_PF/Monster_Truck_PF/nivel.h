 #ifndef NIVEL_H
#define NIVEL_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QVector>
#include <QMap>
#include <QString>
#include <math.h>
#include <time.h>
#include <fstream>
#include <qstring.h>
#include <QDebug>
#include "personaje.h"
#include "containers.h"
#include "Macros.h"
#include "archivos.h"
#include "objetos.h"

class nivel: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    nivel();
    ~nivel();
    void CARGAR_MUNDO(char Nivel);
    void Crear_objeto(int Tipo, int Pos_x, int Pos_y, int Grados, char Tipo_especial);
    void Recibir_vectores(QVector <cajas*>* Box, QVector <pinchos*>* Pincho, QVector <monedas*>* Money,
                          QVector <containers*>* Contenedores, QVector <minas*>* Mina, QVector <mujer*>* Dama,
                          QVector <pajaro*>* Aves, QVector <cierra*>* Cierras, QVector <resorte*>* Resortes, meta *(*Finish));
    void Eliminar_memoria_vectores();
    QGraphicsScene* getlevel(){return level1;}

private:
    short int Contador_containers=0, Contador_pinchos=0, Contador_cajas=0, Contador_monedas=0,
                Contador_minas=0, Contador_aves=0, Contador_damas=0, Contador_cierras=0, Contador_resortes=0;
    QGraphicsScene *level1;
    QPixmap fondo;
    containers *container;
    meta *(*Finish);
    QVector <cajas*>* Box;
    QVector <pinchos*>* Pincho;
    QVector <monedas*>* Money;
    QVector <containers*>* Contenedores;
    QVector <minas*>* Mina;
    QVector <mujer*>* Dama;
    QVector <pajaro*>* Aves;
    QVector <cierra*>* Cierras;
    QVector <resorte*>* Resortes;
    ima *paisaje;
};

#endif // NIVEL_H
