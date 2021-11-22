Algoritmo Ej_MI_14
	
	Definir num Como Entero;
	Definir promedioMayores Como Real;
	Definir numMayores Como Entero;
	Definir sumaMenores como Entero;
	
	numMayores = 0;
	
	Para i = 1 Hasta 50 Con Paso 1 Hacer
		
		Escribir i,") Ingrese un número:";
		Leer num;
				
		Si (num > 100) Entonces
			promedioMayores = promedioMayores + num;
			numMayores = numMayores + 1;
		SiNo
			si num < -10 Entonces
				sumaMenores = sumaMenores + num;
			FinSi
			
		FINSI
		
	FinPara

	Si (numMayores > 0) Entonces
		promedioMayores = promedioMayores / numMayores;
		Escribir "El promedio de números mayores que 100 es: ", promedioMayores;
	SiNo
		Escribir "No hay números mayores a 100."
	FinSi

	
	Escribir "La suma de los números menores que -10 es: ", sumaMenores;
	
FinAlgoritmo
