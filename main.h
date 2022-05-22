#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINEA 500
#define ES_LETRA(x) ( (x>='a' && x<='z') || (x>='A' && x<='Z'))


char *voltear (char *ini, char *fin);
char *desofuscar (char *linea, const char *correcion, int offset);

#endif // MAIN_H_INCLUDED
