Algoritmo Ej_MI_20
	//Dados 10 valores informar el mayor
	Definir num Como Real;
	Definir numMayor Como Real;
	Definir CANT_VALORES Como Entero;
	
	CANT_VALORES = 5;
	
	Escribir "1) Ingrese un n�mero: ";
	leer num;
	
	numMayor = num;
	
	Para i = 1 Hasta CANT_VALORES - 1 Con Paso 1 Hacer
		Escribir i+1, ") Ingrese un n�mero: ";
		leer num;
		
		si num > numMayor Entonces
			numMayor = num;
		FinSi
	FinPara
	
	Escribir  "El mayor n�mero ingresado fue ", numMayor;
	
FinAlgoritmo
