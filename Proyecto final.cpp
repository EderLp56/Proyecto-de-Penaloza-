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
