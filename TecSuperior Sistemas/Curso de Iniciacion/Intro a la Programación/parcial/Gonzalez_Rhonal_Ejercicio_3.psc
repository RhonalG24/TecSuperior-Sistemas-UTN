Algoritmo Ejercicio_3
	Definir duracionNormal, horaSalida, diaSemana Como Entero;
	Definir horaLlegada Como Entero;
	Definir minutos, hora Como Entero;
	Definir mensaje como Cadena;
	
	Escribir "Ingrese cuantos minutos dura normalmente para llegar (HHMM):";
	Leer duracionNormal;
	Escribir "Ingrese la hora a la que está saliendo (HHMM):";
	Leer horaSalida;
	Escribir "Ingrese el número correspondiente al día de la semana:";
	Escribir "1.- Lunes.";
	Escribir "2.- Martes.";
	Escribir "3.- Miércoles.";
	Escribir "4.- Jueves.";
	Escribir "5.- Viernes.";
	Escribir "6.- Sábado.";
	Escribir "7.- Domingo.";
	Leer diaSemana;
	
	
	si horaSalida > 1730 y horaSalida < 1900 Entonces
		Segun diaSemana hacer
			1:
				duracionNormal = duracionNormal + 15;
				
			4:
				duracionNormal = duracionNormal + 25;
			De Otro Modo:
				duracionNormal = duracionNormal + 5;
				
		FinSegun
	FinSi
	
	
	horaLlegada = horaSalida + duracionNormal;
	minutos = horaLlegada % 100;
	horas = trunc(horaLlegada / 100);
	
	si minutos > 59 Entonces
		minutos = minutos - 60;
		horas = horas + 1;
	FinSi
	
	horaLlegada = (horas * 100) + minutos;
	
	Si horaLlegada > 1805 y horaLlegada < 1815 Entonces
		mensaje = "Estas llegando en horario.";
	SiNo
		Si horaLlegada > 1815 Entonces
			mensaje = "Estas llegando tarde.";
		SiNo
			mensaje = "Estas llegando temprano.";
		FinSi
	FinSi
	
	Escribir "Vas a llegar a las ", horaLlegada;
	Escribir mensaje;
FinAlgoritmo
