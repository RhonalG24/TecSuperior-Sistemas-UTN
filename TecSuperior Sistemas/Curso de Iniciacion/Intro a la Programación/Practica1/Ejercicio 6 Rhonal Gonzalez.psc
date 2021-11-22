Algoritmo Ejercicio6
	
	Definir fecha, anioAAAAMMDD, mesAAAAMMDD, diaAAAAMMDD Como Entero;
	Definir dia, mes, anio Como Entero;
	
	Escribir "Introduzca una fecha en formato AAAAMMDD:";
	Leer fecha;
	
	anio = REDON(fecha / 10000); // AAAA
	anioAAAAMMDD = (anio * 10000); // AAAA0000
	
	mes = REDON( (fecha - anioAAAAMMDD) / 100 ); // MM
	mesAAAAMMDD = mes * 100; // 0000MM00
	
	dia = (fecha - anioAAAAMMDD - mesAAAAMMDD); // 000000DD
	
	Escribir "día: ", dia;
	Escribir "mes: ", mes;
	Escribir "año: ", anio;
	
FinAlgoritmo
