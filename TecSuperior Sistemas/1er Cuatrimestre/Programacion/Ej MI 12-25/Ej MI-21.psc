// Dados N valores informar el mayor, el menor y en qu� posici�n del conjunto fueron ingresados.
Algoritmo Ej_MI_21
	Definir cantValores Como Entero;
	Definir num, num1 como real;
	Definir ingresoMayor Como Real;
	Definir ingresoMenor Como Real;
	Definir numMayor Como Real;
	Definir numMenor Como Real;
	
	numMayor =  0;
	numMenor = 0;
	
	Escribir "�Cu�ntos valores ingresar�s?";
	Leer cantValores;
	Escribir "Ingrese un n�mero";
	Leer num1;
	
	numMayor = num1;
	numMenor = num1;
	ingresoMenor = 1;
	ingresoMayor = 1;
	
	Definir i Como Entero;
	
	Para i = 2 Hasta cantValores Con Paso 1 Hacer
		Escribir "Ingrese otro n�mero: ";
		Leer num;
		Si num > numMayor Entonces
			numMayor = num;
			ingresoMayor = i;
		SiNo
			Si num < numMenor Entonces
				numMenor = num;
				ingresoMenor = i;
			FinSi
		FinSi
	FinPara
	
	Escribir "El mayor n�mero fue ", numMayor, " y fue introducido en la posicion ", ingresoMayor;
	Escribir "El menor n�mero fue ", numMenor, " y fue ingresado en la posici�n ", ingresoMenor;
	
FinAlgoritmo
