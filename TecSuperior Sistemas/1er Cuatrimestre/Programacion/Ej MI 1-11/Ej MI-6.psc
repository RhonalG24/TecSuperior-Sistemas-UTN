Algoritmo Ej_MI_6
	Definir fechaActual, fechaA, fechaB Como Entero;
	
	Escribir "Ingrese la fecha actual: ";
	Leer fechaActual;
	Escribir "Ingrese la primera fecha: ";
	Leer fechaA;
	Escribir "Ingrese la segunda fecha: ";
	Leer fechaB;
	
	si fechaActual - fechaA < fechaActual - fechaB Entonces
		Escribir "La fecha más reciente es ", fechaA;
	sino 
		Escribir "La fecha más reciente es ", fechaB;
	FinSi
	
FinAlgoritmo
