#ifndef PERSONAJE_H
#define PERSONAJE_H
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

class personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje();
    void set_sprite(int posx, int posy);
    void MOVER_ADELANTE();
    void MOVER_ATRAS();
    void GRAVEDAD();

    void USERNAME(QString name){username=name;}
    QString GET_NAME(){return username;}
    float getV(){return v;}

private slots:
    void velocidad();
private:
    float v=0;
    QTimer *velocimetro;
    QPixmap imagen;
    QPixmap copia;
    QString username;


};

#endif // PERSONAJE_H
