Algoritmo Ej_MI_16
	//Ingresar e informar valores, mientras que el valor ingresado no sea negativo. Informar la cantidad de valores ingresados.
	Definir num Como Real;
	Definir cantValores Como Entero;
	
	Escribir "Ingrese un número (O un número negativo para salir): ";
	Leer num;
	
	Mientras num >= 0 Hacer
		cantValores = cantValores + 1;
		Escribir "El número ingresado fue ", num;
		Escribir "Ingrese otro número (O un número negativo para salir): ";
		leer num;
	FinMientras
	
	Escribir "Ingresó un total de ", cantValores, " valores.";
	
FinAlgoritmo
