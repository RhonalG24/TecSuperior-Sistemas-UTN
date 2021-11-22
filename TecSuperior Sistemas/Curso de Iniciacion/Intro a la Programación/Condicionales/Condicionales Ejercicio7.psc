Algoritmo Condicionales7
	Definir  mes, anio Como Entero;
	Definir dias Como Entero;
	
	Escribir "Ingrese el mes en número: ";
	Leer mes;
	Escribir "ingrese el año: ";
	Leer  anio;
	
	Segun mes hacer
		1, 3, 5, 7, 8, 10, 12:
			dias = 31;
		4, 6, 9, 11:
			dias = 30;
		2:
			si (anio % 4 = 0) Y (anio % 100 <> 0 O anio % 400 = 0) Entonces
				dias = 29;
			SiNo
				dias = 28;
			FinSi
	FinSegun
	
	Escribir  "El mes ", mes, " del año ", anio, " tuvo ",dias, " días.";
FinAlgoritmo
