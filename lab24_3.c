/*
Programa:		lab24_3.c
Objetivo:		Algoritmo de Machine Learning para predecir,
                el riesgo cardiovascular(RC).
Resultados:     El resultado obtenido tendra dos partes, 
                Primera parte: que nos devolverá el Indice de
                masa corporal(IMC), para los distintos casos
                descritos.
                Segunda parte: Nos devolverá el riesgo cardiovascular
                de un caso en particular, denominado "caso Tesla", y
                nos devolverá un riesgo cardiovascular normalizado a
                una escala de [0,100].
Fecha:			Marzo 2021
Autor:			Gustavo Gutierrez Martin
Versión:		1.0.0
NOTA IMPORTANTE: incluir el parámetro -lm al final al compilar.
*/

#include<stdio.h>
#include<math.h>

const int CENTIMETROS = 100;
const int NORMALIZA = 100;

enum TIPO_PERSONA {JOVEN=1,ADULTO=2,MADURO=4,RESTO=3};
enum SEXO_PERSONA {MUJER=1,HOMBRE=2};

double talla,peso,imc,rcTeslaAbsoluto,rcTeslaNormalizado,rcMin,rcMax;
int edad,sexo;
enum SEXO_PERSONA riesgoSexo;
enum TIPO_PERSONA riesgoEdad;

/**
 * Calcula el IMC en funcion de los datos de entrada.
 * 
 * @return no devuelve nada
 */
int calculaIMC();

/**
 * Calcula el RC minimo del caso Tesla.
 * 
 * @return no devuelve nada
 */
int calculaRCMin();

/**
 * Calcula el RC maximo del caso Tesla.
 * 
 * @return no devuelve nada
 */
int calculaRCMax();

/**
 * Metodo que calcula el RC de Tesla en funcion del riesgo edad.
 * @param riesgoEdad valor entero con el riesgo en funcion de la edad.
 * @return no devuelve nada
 */
int calculoRCTesla(enum TIPO_PERSONA riesgoEdad);

/**
 * Muestra los datos del caso Tesla.
 * 
 * @return no devuelve nada
 */
int muestraDatosTesla();

int main(){
    printf("\n---------------------------------------------------------------------\n");
    printf("Algoritmo para el cálculo del IMC(Indice de Masa Corporal)\n");
    printf("---------------------------------------------------------------------");
    printf("\nA continuación se le solicitarán una serie de datos para el cálculo:\n");
    printf("\n\tIntroduzca la talla (en cm.): ");
    scanf("%le", &talla);
    printf("\n\tIntroduzca el peso (en kg.) maximo 1 decimal: ");
    scanf("%le", &peso);
    printf("\n\tIntroduzca la edad (en años): ");
    scanf("%i", &edad);
    printf("\n\tIntroduzca el sexo en número ([1] Mujer,[2] Hombre): ");
    scanf("%i", &sexo);
    calculaIMC();
    printf("\n\tEl IMC para una persona con una talla de %.0f cm.",talla);
    printf("\n\ty un peso de %.1f kg. es de %.1f \n\n",peso,imc);
    printf("\n\tA título informativo, puede consultar el estado segun su IMC: ");
    printf("\n\tValores de IMC entre 18.5 y 24.9 es NORMAL.");
    printf("\n\tValores de IMC entre 25.0 y 29.9 es SOBREPESO.");
    printf("\n\tValores de IMC es mas de 30.0 es OBESIDAD.\n");
    //Caso Tesla
    talla = 170.00;
    peso = 80.0; 
    riesgoSexo = MUJER;
    sexo = riesgoSexo;
    calculaRCMin();
    calculaRCMax();
    muestraDatosTesla();
    return 0;
}

int calculaIMC() {
    double tallaMetros = talla / CENTIMETROS;
    imc = (peso / pow(tallaMetros,2));
    return 0;
}

int calculaRCMin() {
    calculaIMC();
    riesgoEdad = JOVEN;
    riesgoSexo = MUJER;
    rcMin = imc * riesgoSexo * riesgoEdad;
    return 0;
}

int calculaRCMax() {
    riesgoEdad = MADURO;
    riesgoSexo = HOMBRE;
    rcMax = imc * riesgoSexo * riesgoEdad;
    return 0;
}

int calculoRCTesla(enum TIPO_PERSONA riesgo_edad){
    rcTeslaAbsoluto = imc * riesgoSexo * riesgo_edad;
    rcTeslaNormalizado = (rcTeslaAbsoluto - rcMin) / (rcMax - rcMin);
    rcTeslaNormalizado = rcTeslaNormalizado * NORMALIZA;
    return 0;
}

int muestraDatosTesla() {
    printf("\n---------------------------------------------------------------------\n\n");
    printf("El cálculo del IMC para el conocido caso Tesla para una persona de )\n");
    printf("%.0f cm. y %.1f kg. es de: %.1f\n\n",talla,peso,imc);
    riesgoSexo = MUJER;
    riesgoEdad = JOVEN;
    calculoRCTesla(riesgoEdad);
    printf("El valor absoluto de RC para Tesla menos de 25 años es de %.1f\n",rcTeslaAbsoluto);
    printf("El valor normalizado de RC para Tesla menos de 25 años es de %.1f\n",rcTeslaNormalizado);
    riesgoEdad = ADULTO;
    calculoRCTesla(riesgoEdad);
    printf("El valor absoluto de RC para Tesla entre 25 y 40 años es de %.1f\n",rcTeslaAbsoluto);
    printf("El valor normalizado de RC para Tesla entre 25 y 40 años es de %.1f\n",rcTeslaNormalizado);
    riesgoEdad = MADURO;
    calculoRCTesla(riesgoEdad);
    printf("El valor absoluto de RC para Tesla entre 41 y 55 años es de %.1f\n",rcTeslaAbsoluto);
    printf("El valor normalizado de RC para Tesla entre 41 y 55 años es de %.1f\n",rcTeslaNormalizado);
    riesgoEdad = RESTO;
    calculoRCTesla(riesgoEdad);
    printf("El valor absoluto de RC para Tesla mas de 55 años es de %.1f\n",rcTeslaAbsoluto);
    printf("El valor normalizado de RC para Tesla mas de 55 años es de %.1f\n\n",rcTeslaNormalizado);
    return 0;
}
