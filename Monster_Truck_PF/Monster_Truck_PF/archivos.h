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

bool CREAR_USUARIO(string nameU, string pass);

bool in(string cadena,string palabra);

string Datos_nivel(string Ruta);

#endif // ARCHIVOS_H
