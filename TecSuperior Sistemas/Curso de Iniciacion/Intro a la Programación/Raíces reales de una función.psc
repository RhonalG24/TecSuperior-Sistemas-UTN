Algoritmo sin_titulo
	Definir coeficienteA, coeficienteB, coeficienteC, bCuadrado, parteRa�z, raiz1, raiz2 Como Real;
	
	Escribir  "Ingrese el primer coeficiente:";
	leer coeficienteA;
	Escribir  "Ingrese el segundo coeficiente:";
	leer coeficienteB;
	Escribir  "Ingrese el tercer coeficiente:";
	leer coeficienteC;
	
	bCuadrado = coeficienteB * coeficienteB;
	parteRa�z = RC( bCuadrado - (4 * coeficienteA * coeficienteC));
	
	raiz1 = ((-coeficienteB) + parteRa�z )/( 2 * coeficienteA);
	raiz2 = ((-coeficienteB) - parteRa�z )/( 2 * coeficienteA);
	
	Escribir  "Las ra�ces son:";
	Escribir "x1= " raiz1;
	Escribir "x2= " raiz2;
	
	FinAlgoritmo
