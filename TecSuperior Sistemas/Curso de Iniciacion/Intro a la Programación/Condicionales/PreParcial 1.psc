//Objetivo: Dados tres numeros, informar si forman una escalera ascendente

//Datos de Entreda
//	num1: Variable tipo Entero.
//	num2: Variable tipo Entero.
//	num3: Variable tipo Entero.

//Precondiciones
//	No hay.

//Datos de Salida:
//	mensaje: Cadena.

//Lote de Prueba

Algoritmo Ej_1_Preparcial
	Definir num1, num2, num3 Como Entero;
	Definir mensaje Como Cadena;
	
	Escribir "Ingrese el primer numero:";
	Leer num1;
	Escribir "Ingrese el segundo numero:";
	Leer num2;
	Escribir "Ingrese el tercer numero:";
	Leer num3;
	
	si num1 + 1 == num2 y num2 + 1 == num3 Entonces
		mensaje = "Forman escalera ascendente.";
	sino
		mensaje = "No forman escalera ascendente.";
	FinSi
	
	Escribir mensaje; 
	
FinAlgoritmo
