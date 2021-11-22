Algoritmo Ej_18
	//Dado un valor M determinar y emitir un listado con los M primeros múltiplos de 3 que no lo sean de 5, 
	//dentro del conjunto de los números naturales.
	
	Definir nMultiplos Como Entero;
	Definir multiploDe3 Como Entero;
	Definir i Como Entero;
	
	multiploDe3 = 3;
	i = 0;
	
	Escribir "Ingrese cuántos multiplos quiere mostrar";
	Leer nMultiplos;
	
	Mientras i < nMultiplos Hacer
		
		si (multiploDe3 % 5 != 0) Entonces
			i = i + 1;
			Escribir multiploDe3;
		FinSi
		
		multiploDe3 = multiploDe3 + 3;

	FinMientras
	
	
	
FinAlgoritmo
