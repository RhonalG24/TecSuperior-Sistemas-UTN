Algoritmo Ejercicio9
	
	Definir hours Como Real;
	Definir seconds, minutes Como Real;
	Definir miliseconds como Real;
	
	Escribir "Ingrese las horas:"; 
	Leer hours;
	
	
	minutes = hours * 60;
	seconds = minutes * 60;
	miliseconds = seconds * 1000;
	
	Escribir hours, "  horas son: ", miliseconds, " milisegundos.";
	
FinAlgoritmo