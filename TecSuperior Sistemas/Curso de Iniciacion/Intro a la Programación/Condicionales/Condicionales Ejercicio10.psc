Algoritmo Condicionales10
	Definir diaNaci, mesNaci, anioNaci, diaActual, mesActual, anioActual Como Entero;
	Definir mensaje como cadena;
	
	Escribir "Ingrese su d�a de nacimiento:";
	Leer diaNaci;
	Escribir "Ingrese su mes de nacimiento:";
	Leer mesNaci;
	Escribir "Ingrese su a�o de nacimiento:";
	Leer anioNaci;
	Escribir "Ingrese el d�a actual:";
	Leer diaActual;
	Escribir "Ingrese el mes actual:";
	Leer mesActual;
	Escribir "Ingrese el a�o actual:";
	Leer anioActual;
	
	si anioActual - anioNaci > 18 Entonces
		mensaje = "Es mayor de edad";
	SiNo
		si (anioActual) - anioNaci < 18 Entonces
			mensaje = "Es menor de edad.";
		SiNo
			si mesActual < mesNaci O mesActual = mesNaci Y diaActual < diaNaci Entonces
				mensaje = "Es menor de edad.";
			SiNo
				si mesActual > mesNaci O mesActual = mesNaci Y diaActual >= diaNaci Entonces
					mensaje = "Es mayor de edad.";
				FinSi
			FinSi
		FinSi
	FinSi
	
	
	Escribir mensaje;
	
FinAlgoritmo
