int encontrado = 0; // Bandera para controlar si la palabra fue encontrada
for (int i = 0; i < *iNumElementos; i++) {
    if (strcmp(szPalabras[i], palabra) == 0) {
        iEstadisticas[i]++;
        encontrado = 1;  // Marcamos que se encontró la palabra
    }
}

// Código 2 - Aquí puedes verificar si la palabra fue encontrada o no
if (encontrado == 0) {
    // Lógica si la palabra no fue encontrada
    // Por ejemplo, agregar la palabra al arreglo
    // ...
} else {
    // Lógica si la palabra fue encontrada
    // ...
}
