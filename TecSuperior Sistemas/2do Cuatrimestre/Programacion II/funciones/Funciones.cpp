#include <iostream>
using namespace std;
/*
AÑO BISIESTO
*/
//  if ((anio % 4 == 0) && (anio % 100 != 0 || anio % 400 == 0))
//         {
//             dias = 29;
//         }
//         else
//         {
//             dias = 28;
//         }
//DIAS DEL MES: [1,3,5,7,8,10,12] = 31, [4,6,9,11] = 30.

/*
OBTENER DATOS
*/
void leerInt(string mensaje, int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void leerShortInt(string mensaje, short int &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void leerString(string mensaje, string &valor)
{
    cout << mensaje;
    cin >> valor;
    cout << endl;
    return;
}

void leer(string mensaje, int &numero)
{
    cout << mensaje;
    cin >> numero;
    cout << endl;
    return;
}

/*
HORAS Y FECHAS
*/

/**
 * Horas (HHMMSS) a horas, minutos y segundos
 */
void descomponerTiempo(int tiempo, int &hora, int &minutos, int &segundos)
{
    hora = tiempo / 10000; //hhmmss
    minutos = (tiempo / 100) % 100;
    segundos = tiempo % 100;
    return;
}

/**
 * Pasa de horas, minutos y segundos a una hora en formato HHMMSS
 */
int componerTiempo(int horas, int minutos, int segundos)
{
    return horas * 10000 + minutos * 100 + segundos;
}

/**
 * Suma un tiempo a una hora previa.
 * Además, devuelve si pasó un día.
 */
void sumarTiempo(int horaInicial, int tiempo, int &suma, bool &nuevoDia)
{
    int horasIniciales, horasASumar;
    int minutosIniciales, minutosASumar;
    int segundosIniciales, segundosASumar;

    descomponerTiempo(horaInicial, horasIniciales, minutosIniciales, segundosIniciales);
    descomponerTiempo(tiempo, horasASumar, minutosASumar, segundosASumar);

    int horasTotales = horasIniciales + horasASumar;
    int minutosTotales = minutosIniciales + minutosASumar;
    int segundosTotales = segundosIniciales + segundosASumar;

    if (segundosTotales >= 60)
    {
        segundosTotales -= 60;
        minutosTotales++;
    }
    if (minutosTotales >= 60)
    {
        minutosTotales -= 60;
        horasTotales++;
    }
    if (horasTotales >= 24)
    {
        horasTotales -= 24;
        nuevoDia = true;
    }

    suma = componerTiempo(horasTotales, minutosTotales, segundosTotales);
    return;
}

/**
 * Recibe una hora (HHMM) y devuelve el relativo en minutos
 */
int tiempoAMinutos(int tiempo)
{
    int minutos;
    int horas;

    horas = (tiempo / 100) * 60;
    minutos = (tiempo % 100) + horas;

    return minutos;
}

/**
 * Recibe una fecha AAAAMMDD y devuelve el año, mes y día
 */
void convertirFecha(int fecha, int &anio, int &mes, int &dia)
{
    anio = fecha / 10000;
    mes = (fecha % 10000) / 100;
    dia = fecha % 100;
    return;
}

/**
 * Calcula la edad de una persona a partir de la fechaNaci y la fecha actual
 * Utiliza la funcion convertirFecha()
 */
void calcularEdad(int fechaActual, int fechaNacimiento, int &edad)
{
    int diaActual, mesActual, anioActual;
    int diaNac, mesNac, anioNac;

    convertirFecha(fechaActual, anioActual, mesActual, diaActual);
    convertirFecha(fechaNacimiento, anioNac, mesNac, diaNac);

    edad = anioActual - anioNac;

    if (mesActual < mesNac)
    {
        edad--;
    }
    else
    {
        if (mesActual == mesNac)
        {
            if (diaActual < diaNac)
            {
                edad--;
            }
        }
    }

    return;
}

/*TRIANGULOS*/

/**
 * Retorna true cuando los 3 lados forman un triangulo 
 * retorna un booleano
*/
bool esTriangulo(int lado1, int lado2, int lado3)
{
    return lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1;
}

string obtenerTipoTriangulo(int lado1, int lado2, int lado3)
{
    string tipoTriangulo = "";
    if (lado1 == lado2 && lado2 == lado3)
    {
        tipoTriangulo = "Equilatero";
    }
    else
    {
        if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3)
        {
            tipoTriangulo = "Escaleno";
        }
        else
        {
            tipoTriangulo = "Isosceles";
        }
    }
    return tipoTriangulo;
}

int areaTriaguloRectangulo(int base, int altura)
{
    return base * altura / 2;
}

void obtenerCatetos(int lado1, int lado2, int lado3, int &catetoA, int &catetoB, int &hipotenusa)
{
    if (lado1 > lado2 && lado1 > lado3)
    {
        hipotenusa = lado1;
        catetoA = lado2;
        catetoB = lado3;
    }

    if (lado2 > lado1 && lado2 > lado3)
    {
        hipotenusa = lado2;
        catetoA = lado1;
        catetoB = lado3;
    }

    if (lado3 > lado2 && lado3 > lado1)
    {
        hipotenusa = lado3;
        catetoA = lado2;
        catetoB = lado1;
    }
    return;
}

/**
 * Obtiene el área a partir de los lados del triángulo
 */
int areaTriaguloRectangulo(int lado1, int lado2, int lado3)
{
    int catetoA, catetoB, hipotenusa;
    obtenerCatetos(lado1, lado2, lado3, catetoA, catetoB, hipotenusa);
    return areaTriaguloRectangulo(catetoA, catetoB);
}

/*
MATEMATICOS
*/

/**
 * Multiplica usando sumatorias
 */
int multiplicacion(int num1, int num2)
{
    int producto = 0;

    for (int i = 0; i < num2; i++)
    {
        producto = producto + num1;
    }

    return producto;
}

int potencia(int base, int exponente)
{
    int potencia = base;
    for (int i = 1; i < exponente; i++)
    {
        potencia *= base;
    }
    return potencia;
}

/**
 * Calcula el factorial de un número
 */
int factorial(int numero)
{
    int factorial = 1;

    for (int i = numero; i >= 1; i--)
    {
        factorial *= i;
    }

    return factorial;
}

/**
 * Calcula es Maximo común divisor entre dos números
 */
int calcularMCD(int valorA, int valorB)
{
    int resto = valorA % valorB;

    while (resto > 0)
    {
        valorA = valorB;
        valorB = resto;
        resto = valorA % valorB;
    }

    return valorB;
}

/**
 * Evalúa si un número es primo o no
 */
bool esNumeroPrimo(int numero)
{
    bool primo = true;

    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            primo = false;
            return primo;
        }
    }
    return primo;
}

/**
 * Evalua número a número una secuencia para determinar si están ordenados
 * Debe recibir la variable string orden = "sinOrden" al comenzar el proceso.
 */
void definirOrden(int numero, int numeroAnterior, string &orden)
{
    string ordenActual;
    if (orden != "desordenado")
    {

        if (numero >= numeroAnterior)
        {
            ordenActual = "ascendente";
        }
        if (numero < numeroAnterior)
        {
            ordenActual = "descendente";
        }
        if (orden == "sinOrden")
        {
            orden = ordenActual;
        }
        if (orden != ordenActual)
        {
            orden = "desordenado";
        }
    }
}

/*
RECURSIVIDAD
*/
int multiplicacionRecursiva(int num1, int num2)
{
    int producto = 0;
    if (num2 <= 1)
    {
        return num1;
    }
    else
    {
        producto = num1 + multiplicacionRecursiva(num1, num2 - 1);
    }
}

int calcularFibonacci(int cantValores)
{
    if (cantValores < 3)
    {
        return 1;
    }
    else
    {
        int resultado = 1;

        resultado = calcularFibonacci(cantValores - 1) + calcularFibonacci(cantValores - 2);

        return resultado;
    }
}

/* IMPRESION */

// - VECTORES

/**
 *Imprime los valores contenidos en un vector junto a su índice.
 *Se especifica cúantos valores se desea imprimir por línea
 *Argumentos: el vector, la dimension del vector, la cantidad de valores por línea.
 */
void imprimirLimiteXLineaConID(int vector[], int dimension, int limiteXLinea)
{
    int cantLineas = dimension / limiteXLinea;
    int pos = 0;
    for (int l = 0; l <= cantLineas; l++)
    {
        if (pos + limiteXLinea >= dimension)
        {
            for (int i = pos; i < dimension; i++)
            {
                cout << "[" << i << "] = " << vector[i] << ". ";
            }
        }
        else
        {
            for (int i = pos; i < pos + limiteXLinea; i++)
            {
                cout << "[" << i << "] = " << vector[i] << ", ";
            }
        }
        pos += limiteXLinea;
        cout << endl;
    };
    return;
}

/**
 *Imprime de manera inversa los valores contenidos en un vector junto a su índice.
 *Se especifica cúantos valores se desea imprimir por línea
 *Argumentos: el vector, la dimension del vector, la cantidad de valores por línea.
 */
void imprimirInversoLimiteXLineaConID(int vector[], int dimension, int limiteXLinea)
{
    int cantLineas = dimension / limiteXLinea;
    for (int l = 0; l <= cantLineas; l++)
    {
        if (dimension < limiteXLinea)
        {
            for (int i = dimension - 1; i >= 0; i--)
            {
                cout << "[" << i << "] = " << vector[i] << ". ";
            }
            cout << endl;
        }
        else
        {
            for (int i = dimension - 1; i >= dimension - limiteXLinea; i--)
            {
                cout << "[" << i << "] = " << vector[i] << ", ";
            }
            cout << endl;
        }
        dimension -= limiteXLinea;
    }
    cout << endl;
    return;
}

//OTROS*************

void obtenerMayores(ProductoFinal arrA[], int cantA, ProductoFinal mayores[])
{
    mayores->precioContado = 0;
    for (int i = 0; i < cantA; i++)
    {
        if (arrA[i].precioContado > mayores[0].precioContado)
        {
            mayores[2] = mayores[1];
            mayores[1] = mayores[0];
            mayores[0] = arrA[i];
        }
        else
        {
            if (arrA[i].precioContado > mayores[1].precioContado)
            {
                mayores[2] = mayores[1];
                mayores[1] = arrA[i];
            }
            else
            {
                if (arrA[i].precioContado > mayores[2].precioContado)
                {
                    mayores[2] = arrA[i];
                }
            }
        }
    }
    return;
}

//TRABAJO PRACTICO PARA ETAPA 3

// typedef struct{
//     int fecha;
//     ST_Vuelta vueltas;
//     int distanciaCircuito; //km
//     float velocidadMedia;
// } Entrenamiento;

/**
 * Procedimiento para cargar todas las vueltas de un entrenamiento
 * Retorna a su vez la velocidad media de dicho entrenamiento
 * Parámetros:
 * - Vector de las vueltas
 * - Cantidad de vueltas a cargar
 * - Distancia del circuito
 * - Variable para cargar la velocidad media del entrenamiento
 * - Variable para cargar el tiempo de la vuelta más rápida
 * - Variable para cargar el número de la vuelta más rápida
 * - Variable para cargar el tiempo de la vuelta más lenta 
 * - Variable para cargar el número de la vuelta más lenta 

 */
void cargarVueltasDelEntrenamiento(ST_Vuelta vueltas[], int cantidad, int distancia, float &velocidadMediaEntrenamiento, int &tiempoVueltaMasRapida, int &vueltaMasRapida, int &tiempoVueltaMasLenta, int &vueltaMasLenta)
{
    int i = 0;     //contador del while
    int nroVuelta; //variable para cargar el vector de vueltas según el número de la vuelta

    vueltaMasRapida = 0; //
    tiempoVueltaMasRapida = 0;
    vueltaMasLenta = 0;
    tiempoVueltaMasLenta = 0;

    ST_Vuelta vuelta; //variable auxiliar para cargar el vector de las vueltas

    //Carga de la fecha del entrenamiento
    leer("Ingrese la fecha del entrenamiento (Formato AAAAMMDD): ", vuelta.fecha); //se carga en todas las vueltas del vector

    while (i < cantidad)
    {
        cout << "Registro N° " << i + 1 << "/" << cantidad << endl
             << endl; //Muestra la cantidad de vueltas registradas
        leer("Ingrese el número de la vuelta a cargar: ", nroVuelta);
        leer("Ingrese el tiempo de la vuelta (MMSS): ", vuelta.tiempoMMSS);
        vuelta.velocidadMedia = calcularlVelocidadMedia(distancia, vuelta.tiempoMMSS); //Carga la velicidad media de la vuelta
        cout << endl;

        calcularVueltaMasRapida(vuelta.tiempoMMSS, tiempoVueltaMasRapida, vueltaMasRapida, nroVuelta);
        calcularVueltaMasLenta(vuelta.tiempoMMSS, tiempoVueltaMasLenta, vueltaMasLenta, nroVuelta);

        //carga del vector con método PUP
        vueltas[nroVuelta - 1] = vuelta;

        velocidadMediaEntrenamiento += vuelta.velocidadMedia;
        i++;
    }

    cout << "La vuelta mas rapida fue la " << vueltaMasRapida << " con un tiempo de " << tiempoVueltaMasRapida << endl;
    cout << "La vuelta mas lenta fue la " << vueltaMasLenta << " con un tiempo de " << tiempoVueltaMasLenta << endl;

    if (tiempoVueltaMasRapida != 0)
    {
        float porcentajeReduccionTiempo = calcularPorcentajeReduccionTiempo(tiempoVueltaMasLenta, tiempoVueltaMasRapida);
        cout << "El porcentaje de reduccion de tiempo entre el peor y mejor tiempo es de " << porcentajeReduccionTiempo << endl;
    }
    else
    {
        cout << "No se puede calcular el porcentaje." << endl;
    }
    cout << endl;

    velocidadMediaEntrenamiento /= cantidad;

    cout << "La velocidad media del entrenamiento fue de " << velocidadMediaEntrenamiento << " m/s." << endl
         << endl;

    return;
}
