Algoritmo Condicionales13
	Definir horaActual, diaSemana Como Entero;
	Definir mensaje como cadena;
	
	Escribir "Ingrese el número correspondiente al día actual:";
	Escribir "1.- Lunes.";
	Escribir "2.- Martes.";
	Escribir "3.- Miércoles.";
	Escribir "4.- Jueves.";
	Escribir "5.- Viernes.";
	Escribir "6.- Sábado.";
	Escribir "7.- Domingo.";
	leer diaSemana;
	Escribir "Ingrese la hora actual (HHMM):";
	Leer horaActual;
	
	mensaje = "El banco está cerrado";
	
	//Horario de atención: de 10:00 a 15:00.
	si horaActual > 1000 Y horaActual < 1500 Entonces
		//Días de atención: de Lunes a Viernes.
		si diaSemana > 0 y diaSemana < 6 Entonces
			mensaje = "Puede ir al banco."
		FinSi
	FinSi
	
	Escribir mensaje;
	
	
FinAlgoritmo
