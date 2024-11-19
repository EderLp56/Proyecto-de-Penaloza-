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
     
    for (int i = 0; i < iNumSugeridas; i++) {
        int encontrado = 0;  // Inicializamos la bandera a 0 antes de cada iteración del primer bucle

        for (int j = 0; j < iNumElementos && !encontrado; j++) {  // Continuamos mientras no se haya encontrado
            if (strcmp(szPalabrasSugeridas[i], szPalabras[j]) == 0) {
                strcpy(szListaFinal[*iNumLista], szPalabras[j]);
                iPeso[*iNumLista] = iEstadisticas[j];
                (*iNumLista)++;
                encontrado = 1;  // Activamos la bandera cuando encontramos una coincidencia
            }
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

// Función para clonar palabras a partir de una palabra dada
void ClonaPalabras(char* szPalabraLeida, char szPalabrasSugeridas[][TAMTOKEN], int* iNumSugeridas) {
    *iNumSugeridas = 0;

    // Supresión
    for (int i = 0; szPalabraLeida[i] != '\0'; i++) {
        char clon[TAMTOKEN];
        strcpy(clon, szPalabraLeida);
        memmove(&clon[i], &clon[i + 1], strlen(clon) - i);
        strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
    }
    // Sustitución
    for (int i = 0; szPalabraLeida[i] != '\0'; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (szPalabraLeida[i] != c) {
                char clon[TAMTOKEN];
                strcpy(clon, szPalabraLeida);
                clon[i] = c;  // Sustituir carácter
                strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
            }
        }
    }
    // Trasposición
    for (int i = 0; szPalabraLeida[i + 1] != '\0'; i++) {
        char clon[TAMTOKEN];
        strcpy(clon, szPalabraLeida);
        char temp = clon[i];
        clon[i] = clon[i + 1];
        clon[i + 1] = temp;
        strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
    }

    // Inserción
    for (int i = 0; szPalabraLeida[i] != '\0'; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            char clon[TAMTOKEN];
            strcpy(clon, szPalabraLeida);
            memmove(&clon[i + 1], &clon[i], strlen(clon) - i + 1);
            clon[i] = c;  // Insertar carácter
            strcpy(szPalabrasSugeridas[(*iNumSugeridas)++], clon);
        }
    }
    // Ordenar las palabras clonadas
    qsort(szPalabrasSugeridas, *iNumSugeridas, TAMTOKEN, (int (*)(const void*, const void*))strcmp);
}
// Función para obtener la lista de palabras candidatas
void ListaCandidatas(char szPalabrasSugeridas[][TAMTOKEN], int iNumSugeridas, char szPalabras[][TAMTOKEN],
    int iEstadisticas[], int iNumElementos, char szListaFinal[][TAMTOKEN], int iPeso[], int* iNumLista) {
    *iNumLista = 0;

   
    for (int i = 0; i < iNumSugeridas; i++) {
        int encontrado = 0;  // Inicializamos la bandera a 0 antes de cada iteración del primer bucle

        for (int j = 0; j < iNumElementos && !encontrado; j++) {  // Continuamos mientras no se haya encontrado
            if (strcmp(szPalabrasSugeridas[i], szPalabras[j]) == 0) {
                strcpy(szListaFinal[*iNumLista], szPalabras[j]);
                iPeso[*iNumLista] = iEstadisticas[j];
                (*iNumLista)++;
                encontrado = 1;  // Activamos la bandera cuando encontramos una coincidencia
            }
        }
    }
