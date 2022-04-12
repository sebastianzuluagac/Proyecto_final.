#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "personaje.h"
#include <fstream>
#include <qstring.h>
#include <QDebug>

using namespace std;

bool GUARDAR_ESTADO(personaje car);

bool CARGAR_ESTADO();

bool LOGIN(string nameU, string pass);

bool CREAR_USUARIO(QString nameU, QString pass);

bool in(string cadena,string palabra);

#endif // ARCHIVOS_H
