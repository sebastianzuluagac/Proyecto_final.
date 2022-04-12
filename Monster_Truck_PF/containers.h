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
#define bloqueX 240
#define bloqueY 153

class containers: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    containers(QString name);
    containers();
    void CHOOSE_IMAGE();
private:

    QPixmap imagen;
    QPixmap copia;
};

#endif // CONTAINERS_H
