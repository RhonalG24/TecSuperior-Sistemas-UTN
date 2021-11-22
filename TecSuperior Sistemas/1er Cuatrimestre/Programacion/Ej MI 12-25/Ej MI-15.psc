Algoritmo Ej_MI_15
	Definir tipoInfraccion Como Entero;	
	Definir valorMulta Como Real;
	Definir multaTotalL, multaTotalM, multaTotalG Como Real
	Definir motivoInfraccion como Cadena;
	Definir cantInfraccionG Como Entero;
	Definir gravedadInfraccion Como Caracter;
	Definir totalL, totalM, totalG Como Entero;
	Definir CANTIDAD_FRACCIONES Como Entero;
	CANTIDAD_FRACCIONES = 20;
	
	multaTotalG = 0;
	multaTotalL = 0;
	multaTotalM = 0;
	totalG = 0;
	totalL = 0;
	totalM = 0;
	cantInfraccionG = 0;
	
	Para i = 0 hasta CANTIDAD_FRACCIONES-1 Con Paso 1 Hacer
		Escribir "Ingrese el tipo de infracción (1, 2, 3 o 4): ";
		leer tipoInfraccion;
		Escribir "Ingrese el motivo de la infracción: ";
		leer motivoInfraccion;
		Escribir "Ingrese el valor de la multa: ";
		Leer valorMulta;
		Escribir "Ingrese la gravedad de la infracción (L, M o G): ";
		Leer gravedadInfraccion;
			
		Segun gravedadInfraccion hacer
			'L':
				totalL = totalL + 1;
				multaTotalL = multaTotalL + valorMulta;
			'M':
				totalM = totalM + 1;
				multaTotalM = multaTotalM + valorMulta;
			'G':
				totalG = totalG + 1;
				multaTotalG = multaTotalG + valorMulta;
				Si (tipoInfraccion == 3 O tipoInfraccion == 4) entonces
					cantInfraccionG = cantInfraccionG + 1;
				FinSi
			De Otro Modo:
				Escribir "El valor de la gravedad no es correcta.";
		FinSegun
			
			
	FinPara
		
	Escribir "La fábrica tiene ", totalL, " infraciones de gravedad L lo cual suma una multa de $", multaTotalL, " ,";
	Escribir totalM, " infraciones de gravedad M lo cual suma una multa de $", multaTotalM;
	Escribir  "y ", totalG, " infraciones de gravedad G lo cual suma una multa de $", multaTotalG;
	
	si cantInfraccionG > 3 Entonces
		Escribir "Clausurar fábrica.";
	FinSi
	
	
//Ej. MI-15: Se realiza una inspección en una fábrica de pinturas, y se detectaron 20 infracciones. De cada infracción se tomó nota de los siguientes datos:
//		- Tipo de Infracción (1, 2, 3, ó 4)
//		- Motivo de la infracción
//		- Valor de la multa
//		- Gravedad de la infracción (‘L’,‘M’, ‘G’)
//	Se pide informar al final del proceso:
//		• Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
//		• La leyenda “Clausurar fábrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean mayor a 3.
	
FinAlgoritmo
