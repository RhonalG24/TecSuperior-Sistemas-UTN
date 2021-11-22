Algoritmo Ej_MI_5
	Definir num1, num2 Como Entero;
	
	Escribir "Ingrese el primer n�mero: ";
	Leer num1;
	Escribir  "Ingrese el segundo n�mero: ";
	Leer num2;
	
	si num1 > num2 Entonces
		Escribir num1, " es mayor que ", num2;
	SiNo
		Escribir num2, " es mayor que ", num1;
	FinSi
	
FinAlgoritmo
	Definir edad Como Entero;
	Definir mensaje como cadena;
	
	Escribir "Ingrese la edad del socio:";
	Leer edad;
	si edad <= 12 Entonces
		mensaje = "El socio es menor.";
	SiNo
		si edad <= 18 Entonces
			mensaje = "El socio es cadete.";
		SiNo
			si edad <= 26 Entonces
				mensaje = "El socio es juvenil.";
			SiNo
				mensaje = "El socio es mayor.";
			FinSi
		FinSi
	FinSi
	
	Escribir mensaje;