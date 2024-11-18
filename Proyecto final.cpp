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
    // Ordenar diccionario
    qsort(szPalabras, *iNumElementos, TAMTOKEN, (int (*)(const void*, const void*))strcmp);
}

// Funci�n para clonar palabras a partir de una palabra dada
void ClonaPalabras(char* szPalabraLeida, char szPalabrasSugeridas[][TAMTOKEN], int* iNumSugeridas) {
    *iNumSugeridas = 0;

    // Supresi�n
    for (int i = 0; szPalabraLeida[i] != '\0'; i++) {
        char clon[TAMTOKEN];
        strcpy(clon, szPalabraLeida);
        memmove(&clon[i], &clon[i + 1], strlen(clon) - i);
        strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
    }
    // Sustituci�n
    for (int i = 0; szPalabraLeida[i] != '\0'; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (szPalabraLeida[i] != c) {
                char clon[TAMTOKEN];
                strcpy(clon, szPalabraLeida);
                clon[i] = c;  // Sustituir car�cter
                strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
            }
        }
    }
    // Trasposici�n
    for (int i = 0; szPalabraLeida[i + 1] != '\0'; i++) {
        char clon[TAMTOKEN];
        strcpy(clon, szPalabraLeida);
        char temp = clon[i];
        clon[i] = clon[i + 1];
        clon[i + 1] = temp;
        strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
    }

    // Inserci�n
    for (int i = 0; szPalabraLeida[i] != '\0'; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            char clon[TAMTOKEN];
            strcpy(clon, szPalabraLeida);
            memmove(&clon[i + 1], &clon[i], strlen(clon) - i + 1);
            clon[i] = c;  // Insertar car�cter
            strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
        }
    }

