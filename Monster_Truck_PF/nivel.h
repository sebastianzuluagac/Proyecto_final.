#ifndef NIVEL_H
#define NIVEL_H
#include <QMainWindow>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QVector>
#include <QMap>
#include <QString>
#include <math.h>
#include <time.h>
#include "containers.h"

class nivel: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    nivel();
    void CARGAR_MUNDO();

private:
    QPixmap fondo;
    containers *container;
    QVector <containers*> contenedores;
};

#endif // NIVEL_H
