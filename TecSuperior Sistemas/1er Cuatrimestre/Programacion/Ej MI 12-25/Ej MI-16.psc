Algoritmo Ej_MI_16
	//Ingresar e informar valores, mientras que el valor ingresado no sea negativo. Informar la cantidad de valores ingresados.
	Definir num Como Real;
	Definir cantValores Como Entero;
	
	Escribir "Ingrese un n�mero (O un n�mero negativo para salir): ";
	Leer num;
	
	Mientras num >= 0 Hacer
		cantValores = cantValores + 1;
		Escribir "El n�mero ingresado fue ", num;
		Escribir "Ingrese otro n�mero (O un n�mero negativo para salir): ";
		leer num;
	FinMientras
	
	Escribir "Ingres� un total de ", cantValores, " valores.";
	
FinAlgoritmo
