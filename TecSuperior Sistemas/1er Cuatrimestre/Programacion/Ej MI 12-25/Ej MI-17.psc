//	a) Cu�ntos empleados ganan menos $1.520.
//	b) Cu�ntos ganan $1.520 o m�s pero menos de $2.780.
//	c) Cu�ntos ganan $2.780 o m�s pero menos de $5.999.
//	d) Cu�ntos ganan $5.999 o m�s.

Algoritmo Ej_MI_17

	
	Definir sueldo Como Real;
	Definir sueldo1 Como Entero; //menos $1.520.
	Definir sueldo2 Como Entero; //entre $1.520 y $2.780
	Definir sueldo3 Como Entero; //entre $2.780 y $5.999
	Definir sueldo4 Como Entero; //$5.999 o m�s.
	
	Escribir "Ingrese el sueldo (0 para salir): ";
	Leer sueldo;
	
	Mientras sueldo > 0 Hacer
		Si sueldo >= 5999 Entonces
			sueldo4 = sueldo4 + 1;
		SiNo
			Si sueldo >= 2780 Entonces
				sueldo3 = sueldo3 + 1;
			SiNo
				Si sueldo >= 1520 Entonces
					sueldo2 = sueldo1 + 1;
				SiNo
					sueldo1 = sueldo1 + 1;
				FinSi
			FinSi
		FinSi
		
		Escribir "Ingrese el siguiente sueldo � 0 para salir: ";
		Leer sueldo;
	FinMientras
	
	Escribir sueldo1, " empleados ganan menos de $1.520.";
	Escribir sueldo2, " empleados ganan entre $1.520 y $2.780.";
	Escribir sueldo3, " empleados ganan entre $2.780 y $5.999.";
	Escribir sueldo4, " empleados ganan $5.999 o m�s.";
	
FinAlgoritmo
