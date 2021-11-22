Algoritmo Condicionales11
	Definir genero Como Entero;
	Definir edad, aniosDeAporte Como Entero;
	Definir mensaje como cadena;
	
	//constantes
	Definir EDAD_MINIMA_HOMBRE, EDAD_MINIMA_MUJER, ANIOS_APORTE_MINIMOS Como Entero;
	EDAD_MINIMA_MUJER = 60;
	EDAD_MINIMA_HOMBRE = 65;
	ANIOS_APORTE_MINIMOS = 30;
	
	
	Escribir "Ingrese el número correspondiente al genero:";
	Escribir "Ingrese el genero:";
	Escribir "1.- Mujer.";
	Escribir "2.- Hombre.";
	Leer genero;
	Escribir "Ingrese la edad:";
	Leer edad;
	Escribir "Ingrese los años de aporte:";
	Leer aniosDeAporte;
	
	Si aniosDeAporte < ANIOS_APORTE_MINIMOS Entonces
		mensaje = "Aún no puede jubilarse.";
	SiNo
		Segun genero hacer
			1:
				si edad < EDAD_MINIMA_MUJER Entonces
					mensaje = "Aún no puede jubilarse.";
				SiNo
					mensaje = "Puede jubilarse.";
				FinSi
			2:
				si edad < EDAD_MINIMA_HOMBRE Entonces
					mensaje = "Aún no puede jubilarse.";
				SiNo
					mensaje = "Puede jubilarse.";
				FinSi
		FinSegun
	FinSi
	
	Escribir mensaje;
	
FinAlgoritmo
