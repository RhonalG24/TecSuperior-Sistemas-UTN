Algoritmo Condicionales6
	Definir anio Como Entero;
	Definir mensaje como cadena;
	
	Escribir "Ingrese un año:";
	Leer anio;
	
	si anio % 4 = 0 Y anio % 100 <> 0 O anio % 400 = 0 Entonces
		mensaje = "Es bisiesto."
	SiNo
		mensaje = "No es bisiesto."
	FinSi
	
	Escribir mensaje;
	
FinAlgoritmo
