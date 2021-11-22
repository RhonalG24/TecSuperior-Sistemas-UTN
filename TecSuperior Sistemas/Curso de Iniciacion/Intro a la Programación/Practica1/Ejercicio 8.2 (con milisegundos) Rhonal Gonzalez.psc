Algoritmo Ejercicio8
	
	Definir miliseconds Como Real;
	Definir seconds, minutes Como Real;
	Definir hours como Real;
	
	Escribir "Ingrese los milisegundos:"; 
	Leer miliseconds;
	
	seconds = miliseconds / 1000;
	minutes = seconds / 60;
	hours = minutes / 60;
	
	Escribir miliseconds, " milisegundos en horas es: ", hours, " horas.";
	
	
	
FinAlgoritmo