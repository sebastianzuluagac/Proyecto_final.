#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <time.h>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <portabledeviceconnectapi.h>
#include <QVector>
#include <QKeyEvent>
#include <fstream>
#include <string>
using namespace std;
#include "nivel.h"
#include "personaje.h"

#define tamnivelX 1380//6061
#define tamnivelY 800

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *tecla);

private slots:
    void animacion_ruedo ();


    void on_ingresar_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene,*inicio;
    nivel *n1;
    personaje *carro;
    QKeyEvent *tecla;
    QTimer *timer;
};
#endif // MAINWINDOW_H
