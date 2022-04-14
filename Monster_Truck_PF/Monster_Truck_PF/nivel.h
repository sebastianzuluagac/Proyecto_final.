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

class nivel: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    nivel();
    void CARGAR_MUNDO(char Nivel);
    void Crear_objeto(int Tipo, int Pos_x, int Pos_y, int Inclinacion, int Tipo_especial);

    QGraphicsScene* getlevel(){return level1;}

private:
    QGraphicsScene *level1;
    QPixmap fondo;
    containers *container;
    QVector <containers*> Contenedores;
};

#endif // NIVEL_H
