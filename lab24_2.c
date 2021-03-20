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

const double EUR_USD = 1.1416;
const double EUR_JPY = 124.34;
const double EUR_GBP = 0.8860;
const double EUR_CHF = 1.1297;
const int DIVISION = 100;

double entrada;
int dolares = 0;
int centavos = 0;
int yenes = 0;
int libras = 0;
int peniques = 0;
int francos = 0;
int rappen = 0;

/**
 * Obtiene los Dolares y los Centavos a partir de la entrada.
 * 
 * @return no devuelve nada
 */
int obtenerDolares();

/**
 * Obtiene los Yenes a partir de la entrada.
 * 
 * @return no devuelve nada
 */
int obtenerYenes();

/**
 * Obtiene las Libras y los Peniques a partir de la entrada.
 * 
 * @return no devuelve nada
 */
int obtenerLibras();

/**
 * Obtiene las Francos y los Rappen a partir de la entrada.
 * 
 * @return no devuelve nada
 */
int obtenerFrancos();

int main(){
    printf("\n---------------------------------------------------------------------\n");
    printf("Programa para conversion de EUR en USD,YEN,GBP y CHF\n");
    printf("---------------------------------------------------------------------");
    printf("\n\tA continuación deberá introducir una cantidad de euros con el");
    printf("\n\tformato siguiente: XXXXXXX.XX el numero de decimales será de 2");
    printf("\n\tIntroduzca los euros a convertir:");    
    scanf("%le", &entrada);
    obtenerDolares();
    obtenerYenes();
    obtenerLibras();
    obtenerFrancos();
    printf("\n\t%.2f Euros equivalen a:\n\n",entrada);
    printf("\t\t%d Dolares y %d Centavos.\n", dolares,centavos);
    printf("\t\t%d Yenes.\n", yenes);
    printf("\t\t%d Libras y %d Peniques.\n", libras,peniques);
    printf("\t\t%d Francos y %d Rappens.\n\n", francos,rappen);
    return 0;
}

int obtenerDolares() {
    double dolaresDouble = entrada * EUR_USD;
    dolares = (int) dolaresDouble;
    centavos = (dolaresDouble - dolares) * DIVISION;
    return 0;
}

int obtenerYenes() {
    yenes = entrada * EUR_JPY;
    return 0;
}

int obtenerLibras() {
    double librasDouble = entrada * EUR_GBP;
    libras = (int) librasDouble;
    peniques = (librasDouble - libras) * DIVISION;
    return 0;
}

int obtenerFrancos() {
    double francosDouble = entrada * EUR_CHF;
    francos = (int) francosDouble;
    rappen = (francosDouble - francos) * DIVISION;
    return 0;
}