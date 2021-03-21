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

//declaracion de tipos enumerados
enum TIPO_PERSONA {JOVEN=1,ADULTO=2,MADURO=4,RESTO=3};
enum SEXO_PERSONA {MUJER=1,HOMBRE=2};

/**
 * Calcula el IMC de la persona a partir de la talla y el peso.
 * 
 * @param talla talla de la persona
 * @param peso  peso de la persona      
 * @return devuelve el valor del imc
 */
double calculaIMC(double talla, double peso);

/**
 * Calcula el RC, a partir de IMC y riesgo edad y sexo.
 * 
 * @param imc imc del caso tesla.
 * @param riesgoEdad riesgo edad minimo posible.
 * @param riesgoSexo riesgo sexo minimo posible.
 * @return devuelve el RC minimo posible para el imc dado.
 */
double calculaRC(double imc, enum TIPO_PERSONA riesgo_Edad, enum SEXO_PERSONA riesgo_Sexo);

/**
 * Calcula el RC normalizado, en un rango de 0 a 100.
 * 
 * @param rcAbs RC en valor absoluto
 * @param rcMin RC minimo posible del caso
 * @param rcMax RC maximo posible del caso
 * @return devuelve el RC normalizado en escala de 0 a 100.
 */
double calculaRCNormalizado(double rcAbs, double rcMin, double rcMax);

/**
 * Muestra los datos de cabecera del caso Tesla.
 * 
 * @param talla talla del caso tesla
 * @param peso  peso del caso tesla
 * @param imc  imc del caso tesla
 * @return no devuelve nada
 */
int muestraTeslaCabecera(double talla, double peso, double imc);

/**
 * Muestra los datos de caso Tesla siendo JOVEN.
 * 
 * @param absoluto valor absoluto del RC
 * @param normalizado  valor relativo del RC
 * @return no devuelve nada
 */
int muestraTeslaJoven(double absoluto, double normalizado);

/**
 * Muestra los datos de caso Tesla siendo ADULTO.
 * 
 * @param absoluto valor absoluto del RC
 * @param normalizado  valor relativo del RC
 * @return no devuelve nada
 */
int muestraTeslaAdulto(double absoluto, double normalizado);

/**
 * Muestra los datos de caso Tesla siendo MADURO.
 * 
 * @param absoluto valor absoluto del RC
 * @param normalizado  valor relativo del RC
 * @return no devuelve nada
 */
int muestraTeslaMaduro(double absoluto, double normalizado);

/**
 * Muestra los datos de caso Tesla siendo RESTO de edades.
 * 
 * @param absoluto valor absoluto del RC
 * @param normalizado  valor relativo del RC
 * @return no devuelve nada
 */
int muestraTeslaResto(double absoluto, double normalizado);

//Funcion principal
int main(){

    double talla,peso,imc,rcTeslaAbsoluto,rcTeslaNormalizado,rcMin,rcMax;
    int edad,sexo;
    enum SEXO_PERSONA riesgoSexo;
    enum TIPO_PERSONA riesgoEdad;

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
    imc = calculaIMC(talla,peso);
    printf("\n\tEl IMC para una persona con una talla de %.0f cm.",talla);
    printf("\n\ty un peso de %.1f kg. es de %.1f \n\n",peso,imc);
    printf("\n\tA título informativo, puede consultar el estado segun su IMC: ");
    printf("\n\tValores de IMC entre 18.5 y 24.9 es NORMAL.");
    printf("\n\tValores de IMC entre 25.0 y 29.9 es SOBREPESO.");
    printf("\n\tValores de IMC es mas de 30.0 es OBESIDAD.\n");
    //Caso Tesla asignacion de variables.
    talla = 170.00;
    peso = 80.0;
    imc = calculaIMC(talla,peso);
    //Caso Tesla calculo de RC min a partir de IMC:
    riesgoEdad = JOVEN; //el riesgo mas bajo en funcion de la edad
    riesgoSexo = MUJER; //el riesgo mas bajo en funcion del sexo
    rcMin = calculaRC(imc,riesgoEdad,riesgoSexo);
    //Caso Tesla calculo de RC min a partir de IMC:
    riesgoEdad = MADURO; //el riesgo mas alto en funcion de la edad
    riesgoSexo = HOMBRE; //el riesgo mas alto en funcion del sexo
    rcMax = calculaRC(imc,riesgoEdad,riesgoSexo);
    //Caso Tesla calculo de RC en funcion de la edad
    muestraTeslaCabecera(talla,peso,imc);
    riesgoSexo = MUJER;
    //Mostramos el RC si es una persona JOVEN
    riesgoEdad = JOVEN;
    rcTeslaAbsoluto = calculaRC(imc,riesgoEdad,riesgoSexo);
    rcTeslaNormalizado = calculaRCNormalizado(rcTeslaAbsoluto,rcMin,rcMax);
    muestraTeslaJoven(rcTeslaAbsoluto,rcTeslaNormalizado);
    //Mostramos el RC si es una persona ADULTO
    riesgoEdad = ADULTO;
    rcTeslaAbsoluto = calculaRC(imc,riesgoEdad,riesgoSexo);
    rcTeslaNormalizado = calculaRCNormalizado(rcTeslaAbsoluto,rcMin,rcMax);
    muestraTeslaAdulto(rcTeslaAbsoluto,rcTeslaNormalizado);
    //Mostramos el RC si es una persona MADURO
    riesgoEdad = MADURO;
    rcTeslaAbsoluto = calculaRC(imc,riesgoEdad,riesgoSexo);
    rcTeslaNormalizado = calculaRCNormalizado(rcTeslaAbsoluto,rcMin,rcMax);
    muestraTeslaMaduro(rcTeslaAbsoluto,rcTeslaNormalizado);
    //Mostramos el RC si es una persona RESTO
    riesgoEdad = RESTO;
    rcTeslaAbsoluto = calculaRC(imc,riesgoEdad,riesgoSexo);
    rcTeslaNormalizado = calculaRCNormalizado(rcTeslaAbsoluto,rcMin,rcMax);
    muestraTeslaResto(rcTeslaAbsoluto,rcTeslaNormalizado);    
    return 0;
}

double calculaIMC(double talla, double peso) {
    const int CENTIMETROS = 100;
    double tallaMetros = talla / CENTIMETROS;
    return (peso / pow(tallaMetros,2));
}

double calculaRC(double imc, enum TIPO_PERSONA riesgo_Edad, enum SEXO_PERSONA riesgo_Sexo) {
    return imc * riesgo_Sexo * riesgo_Edad;
}

double calculaRCNormalizado(double rcAbs, double rcMin, double rcMax) {
    const int NORMALIZA = 100;
    return ((rcAbs - rcMin) / (rcMax - rcMin)) * NORMALIZA;
}

int muestraTeslaCabecera(double talla, double peso, double imc){
    printf("\n---------------------------------------------------------------------\n\n");
    printf("El cálculo del IMC para el conocido caso Tesla para una persona de )\n");
    printf("%.0f cm. y %.1f kg. es de: %.1f\n\n",talla,peso,imc);
    return 0;
}

int muestraTeslaJoven(double absoluto, double normalizado) {
    printf("El valor absoluto de RC para Tesla menos de 25 años es de %.1f\n",absoluto);
    printf("El valor normalizado de RC para Tesla menos de 25 años es de %.1f\n",normalizado);
    return 0;
}

int muestraTeslaAdulto(double absoluto, double normalizado) {
    printf("El valor absoluto de RC para Tesla entre 25 y 40 años es de %.1f\n",absoluto);
    printf("El valor normalizado de RC para Tesla entre 25 y 40 años es de %.1f\n",normalizado);
    return 0;
}

int muestraTeslaMaduro(double absoluto, double normalizado) {
    printf("El valor absoluto de RC para Tesla entre 41 y 55 años es de %.1f\n",absoluto);
    printf("El valor normalizado de RC para Tesla entre 41 y 55 años es de %.1f\n",normalizado);
    return 0;
}

int muestraTeslaResto(double absoluto, double normalizado) {
    printf("El valor absoluto de RC para Tesla mas de 55 años es de %.1f\n",absoluto);
    printf("El valor normalizado de RC para Tesla mas de 55 años es de %.1f\n\n",normalizado);
    return 0;
}