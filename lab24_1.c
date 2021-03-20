/*
Programa:		lab24_1.c
Objetivo:		Programa para la conversion de segundos en dias,
                horas, minutos y segundos.
Resultados:     Se mostrará el resultado en Días, Horas, 
                Minutos y Segundos
Fecha:			Marzo 2021
Autor:			Gustavo Gutierrez Martin
Versión:		1.0.0
*/

#include<stdio.h>

const int DIA = 86400;
const int HORA = 3600;
const int MINUTO = 60;

int entrada;
int dias = 0;
int horas = 0;
int minutos = 0;
int segundos = 0;
int diasResto, horasResto;

/**
 * Metodo que obtiene los datos desglosados.
 * 
 * @return no devuelve nada
 */
int obtenerDatos();

int main(){
    printf("\n---------------------------------------------------------------------\n");
    printf("Programa para conversion de segundos en Dias,Horas,Minutos y Segundos\n");
    printf("---------------------------------------------------------------------");
    printf("\n\tIntroduzca el número de segundos:");
    scanf("%d", &entrada);
    obtenerDatos();
    printf("\n\tLos segundos introducido son:\n");
    printf("\t\t%i Días\n", dias);
    printf("\t\t%i Horas\n", horas);
    printf("\t\t%i Minutos\n", minutos);
    printf("\t\t%i Segundos\n", segundos);
    return 0;
}

int obtenerDatos() {
    dias = entrada / DIA;
    diasResto = entrada % DIA;
    horas = diasResto / HORA;
    horasResto = diasResto % HORA;
    minutos = horasResto / MINUTO;
    segundos = horasResto % MINUTO;    
    return 0;
}