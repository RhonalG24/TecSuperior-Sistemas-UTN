Algoritmo Ej_MI_14_Random
	
	Definir num Como Entero;
	Definir promedioMayores Como Real;
	Definir numMayores Como Entero;
	Definir sumaMenores como Entero;
	
	numMayores = 0;
	
	Para i = 1 Hasta 50 Con Paso 1 Hacer
		
		num = Aleatorio(-999,999);
		Escribir i, ") ", num;
		
		Si (num > 100) Entonces
			promedioMayores = promedioMayores + num;
			numMayores = numMayores + 1;
		SiNo
			si num < -10 Entonces
				sumaMenores = sumaMenores + num;
			FinSi
			
		FINSI
		
	FinPara
	promedioMayores = promedioMayores / numMayores;
	
	Escribir "El promedio de números mayores que 100 es: ", promedioMayores;
	Escribir "La suma de los números menores que -10 es: ", sumaMenores;
	
FinAlgoritmo


