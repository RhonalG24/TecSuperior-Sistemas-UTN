Algoritmo Condicionales8
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
FinAlgoritmo
