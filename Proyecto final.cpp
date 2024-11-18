//Proyecto de pe�aloza 
#include "corrector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funci�n para cargar el diccionario desde el archivo
void Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int* iNumElementos) {
    FILE* archivo = fopen(szNombre, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }
    //se agrega codigo
    char palabra[TAMTOKEN];
    *iNumElementos = 0;
    while (fscanf(archivo, "%s", palabra) != EOF && *iNumElementos < MAXPALABRAS) {
        // Eliminar par�ntesis si est�n presentes
        if (palabra[0] == '(' && palabra[strlen(palabra) - 1] == ')') {
            // Copiar la palabra sin los par�ntesis
            memmove(palabra, palabra + 1, strlen(palabra) - 1);
            palabra[strlen(palabra) - 1] = '\0';
        }
        //agrega codigo 2 
        int encontrado = 0;
        for (int i = 0; i < *iNumElementos; i++) {
            if (strcmp(szPalabras[i], palabra) == 0) {
                iEstadisticas[i]++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            strcpy(szPalabras[*iNumElementos], palabra);
            iEstadisticas[*iNumElementos] = 1;
            (*iNumElementos)++;
        }
    }

    fclose(archivo);
