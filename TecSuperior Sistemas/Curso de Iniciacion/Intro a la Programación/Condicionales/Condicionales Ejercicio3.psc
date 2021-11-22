Algoritmo Condicionales3
	Definir hora, horas, minutos Como Entero;
	Definir mensaje Como Caracter;
	
	Escribir "Ingrese la hora en formato HHMM:";
	Leer hora;
	
	horas = TRUNC(hora / 100);
	minutos = hora % 100;
	
	Si horas > 12 Entonces
		horas = horas - 12;
		si minutos > 9 Entonces
			Escribir "La hora es ", horas, ":", minutos, " PM";
			
		sino 
			Escribir "La hora es ", horas, ":0", minutos, " PM";
		FinSi
		
	SiNo
		Si horas = 0 Entonces
			horas = 12;
		FinSi
		
		si minutos > 9 Entonces
			Escribir  "La hora es ", horas, ":", minutos, " AM";
			
		SiNo
			Escribir "La hora es ", horas, ":0", minutos, " AM";
			
		FinSi
	FinSi
	
	
	

FinAlgoritmo
