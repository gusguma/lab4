/*
Programa:		lab24_2.c
Objetivo:		Programa para la conversion de EUR en USD,JPY,
                GBP y CHF.
Resultados:     Se mostrará el resultado de la conversion en
                las monedas definidas anteriormente
Fecha:			Marzo 2021
Autor:			Gustavo Gutierrez Martin
Versión:		1.0.0
*/

#include<stdio.h>

/**
 * Obtiene los Dolares y los Centavos a partir de la entrada.
 * 
 * @param entrada Euros introducidos por el usuario
 * @param dolares Dolares obtenidos - por referencia
 * @param centavos Centavos obtenidos - por referencia
 * @return no devuelve nada
 */
int obtenerDolares(double entrada, int *dolares, int *centavos);

/**
 * Obtiene los Yenes a partir de la entrada.
 * 
 * @param entrada Euros introducidos por el usuario
 * @return no devuelve nada
 */
int obtenerYenes(double entrada);

/**
 * Obtiene las Libras y los Peniques a partir de la entrada.
 * 
 * @param entrada Euros introducidos por el usuario
 * @param libras Libras obtenidas - por referencia
 * @param peniques Peniques obtenidos - por referencia
 * @return no devuelve nada
 */
int obtenerLibras(double entrada, int *libras, int *peniques);

/**
 * Obtiene los Francos y los Rappen a partir de la entrada.
 * 
 * @param entrada Euros introducidos por el usuario
 * @param francos Francos obtenidos - por referencia
 * @param peniques Rappen obtenidos - por referencia
 * @return no devuelve nada
 */
int obtenerFrancos(double entrada, int *francos, int *rappen);

int main(){    

    double entrada;
    int dolares = 0;
    int centavos = 0;
    int yenes = 0;
    int libras = 0;
    int peniques = 0;
    int francos = 0;
    int rappen = 0;

    printf("\n---------------------------------------------------------------------\n");
    printf("Programa para conversion de EUR en USD,YEN,GBP y CHF\n");
    printf("---------------------------------------------------------------------");
    printf("\n\tA continuación deberá introducir una cantidad de euros con el");
    printf("\n\tformato siguiente: XXXXXXX.XX el numero de decimales será de 2");
    printf("\n\tIntroduzca los euros a convertir:");    
    scanf("%le", &entrada);
    obtenerDolares(entrada,&dolares,&centavos);
    yenes = obtenerYenes(entrada);
    obtenerLibras(entrada,&libras,&peniques);
    obtenerFrancos(entrada,&francos,&rappen);
    printf("\n\t%.2f Euros equivalen a:\n\n",entrada);
    printf("\t\t%d Dolares y %d Centavos.\n",dolares,centavos);
    printf("\t\t%d Yenes.\n", yenes);
    printf("\t\t%d Libras y %d Peniques.\n",libras,peniques);
    printf("\t\t%d Francos y %d Rappens.\n\n",francos,rappen);
    return 0;
}

int obtenerDolares(double entrada, int *dolares, int *centavos) {
    const int DIVISION = 100;
    const double EUR_USD = 1.1416;
    double dolaresDouble = entrada * EUR_USD;
    *dolares = (int) dolaresDouble;
    *centavos = (dolaresDouble - *dolares) * DIVISION;
    return 0;
}

int obtenerYenes(double entrada) {
    const double EUR_JPY = 124.34;
    return entrada * EUR_JPY;
}

int obtenerLibras(double entrada, int *libras, int *peniques) {
    const int DIVISION = 100;
    const double EUR_GBP = 0.8860;
    double librasDouble = entrada * EUR_GBP;
    *libras = (int) librasDouble;
    *peniques = (librasDouble - *libras) * DIVISION;
    return 0;
}

int obtenerFrancos(double entrada, int *francos, int *rappen) {
    const int DIVISION = 100;
    const double EUR_CHF = 1.1297;
    double francosDouble = entrada * EUR_CHF;
    *francos = (int) francosDouble;
    *rappen = (francosDouble - *francos) * DIVISION;
    return 0;
}