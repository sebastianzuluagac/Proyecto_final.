#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <QMainWindow>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QVector>
#include <QMap>
#include <QString>
#include <math.h>
#include <time.h>
#include <QTimer>
#include <QDebug>
#include <QMatrix>
#define bloqueX 240
#define bloqueY 153

class containers: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    containers(int fila, int col);
    containers();
    void Inclinacion(float grado);
    int Datos(int Indx);


private:
    int Pos_x, Pos_y, Grados;
    QPixmap imagen;
    QPixmap copia;
};

#endif // CONTAINERS_H
