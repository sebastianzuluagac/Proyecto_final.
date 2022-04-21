#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "personaje.h"
#include <fstream>
#include <qstring.h>
#include <QDebug>

using namespace std;

bool GUARDAR_ESTADO(personaje *car);

bool CARGAR_ESTADO(personaje *car);

bool LOGIN(string nameU, string pass);

bool CREAR_USUARIO(string nameU, string pass);

bool in(string cadena,string palabra);

string FORMATOLINEA(personaje*car);

string Datos_nivel(string Ruta);

#endif // ARCHIVOS_H
