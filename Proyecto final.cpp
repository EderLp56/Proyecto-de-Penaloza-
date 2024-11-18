//Proyecto de pe¤aloza 
#include "corrector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para cargar el diccionario desde el archivo
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
        // Eliminar paréntesis si están presentes
        if (palabra[0] == '(' && palabra[strlen(palabra) - 1] == ')') {
            // Copiar la palabra sin los paréntesis
            memmove(palabra, palabra + 1, strlen(palabra) - 1);
            palabra[strlen(palabra) - 1] = '\0';
        }
        //agrega codigo 2 
        int encontrado = 0;  // Inicializamos la bandera
        for (int i = 0; i < *iNumElementos && !encontrado; i++) {  // Mientras no se haya encontrado, seguimos iterando
            if (strcmp(szPalabras[i], palabra) == 0) {
                iEstadisticas[i]++;
                encontrado = 1;  // Activamos la bandera si se encuentra la palabra
            }
        }

