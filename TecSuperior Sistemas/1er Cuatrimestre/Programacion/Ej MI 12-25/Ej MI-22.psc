Algoritmo Ej_MI_22
	// Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un Nombre = ‘FIN’, 
	//informar el nombre de la persona con mayor edad y el de la más joven.

	Definir nombre como Cadena;
	Definir fechaNac Como Entero;
	Definir fechaMayor Como Entero;
	Definir fechaMenor Como Entero;
	Definir personaMayor Como Cadena;
	Definir personaMenor Como Cadena;
	
	fechaMayor = 0;
	fechaMenor = 0;
	
	Escribir "Ingrese el nombre de la persona (O FIN para salir); "
	Leer nombre;
	
	Mientras nombre != "FIN" Hacer
		Escribir "Ingrese la fecha de nacimiento en formato AAAAMMDD: ";
		Leer fechaNac;
		
		si fechaNac > fechaMenor O fechaMenor == 0 Entonces
			personaMenor = nombre;
			fechaMenor = fechaNac;
		FinSi
		
		Si fechaNac < fechaMayor O fechaMayor == 0 Entonces
			personaMayor = nombre;
			fechaMayor = fechaNac;
		FinSi
		
		Escribir "Ingrese el nombre de otras persona (O FIN para salir): ";
		Leer nombre;
	FinMientras
	
	si fechaMayor == 0 O fechaMenor == 0 Entonces
		Escribir "No se ingresaron personas.";
	SiNo
		Escribir "La persona con mayor edad es ", personaMayor;
		Escribir "La persona con menor edad es ", personaMenor;
	FinSi
FinAlgoritmo
