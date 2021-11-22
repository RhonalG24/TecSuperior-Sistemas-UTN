Algoritmo Ej_MI_27
//En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de todos contra todos. 
//Por cada partido disputado por un equipo se dispone de la siguiente información:
//	a) Nro. de equipo,
//	b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado).
//	Se arma un lote de datos con todos los resultados del torneo, agrupados por Nro. de equipo.
//Desarrollar el programa que imprima:
	//	Por cada equipo, su número y el puntaje total que obtuvo (suma 3 si gana, y 1 si empata).
	
	Definir cantEquipos Como entero;
	Definir nroEquipo Como Entero;
	Definir resultado Como Caracter;
	Definir puntajeTotal Como Entero;
	
	Escribir "Ingrese la cantidad de equipos que participan en el torneo: ";
	Leer cantEquipos;
	
	Para  i = 1 Hasta cantEquipos Con Paso 1 Hacer
		Escribir "Para el equipo N° ", i, " ingrese:";
		Para j = 1 Hasta cantEquipos - 1 Con Paso 1 Hacer
			Escribir "N° del equipo rival:"
			leer nroEquipo;
			Escribir "Ingrese el resultado (P, E o G):";
			Leer resultado;
			
			segun resultado hacer
				'E':
					puntajeTotal = puntajeTotal + 1;
				'G':
					puntajeTotal = puntajeTotal + 3;
				De Otro Modo:
					
			FinSegun
			
			
		FinPara
		
		Escribir "El equipo ", i , " obtuvo ", puntajeTotal, " puntos."
		Escribir " ";
		puntajeTotal = 0;
	FinPara

FinAlgoritmo
