Algoritmo sin_titulo
	Definir coeficienteA, coeficienteB, coeficienteC, bCuadrado, parteRaíz, raiz1, raiz2 Como Real;
	
	Escribir  "Ingrese el primer coeficiente:";
	leer coeficienteA;
	Escribir  "Ingrese el segundo coeficiente:";
	leer coeficienteB;
	Escribir  "Ingrese el tercer coeficiente:";
	leer coeficienteC;
	
	bCuadrado = coeficienteB * coeficienteB;
	parteRaíz = RC( bCuadrado - (4 * coeficienteA * coeficienteC));
	
	raiz1 = ((-coeficienteB) + parteRaíz )/( 2 * coeficienteA);
	raiz2 = ((-coeficienteB) - parteRaíz )/( 2 * coeficienteA);
	
	Escribir  "Las raíces son:";
	Escribir "x1= " raiz1;
	Escribir "x2= " raiz2;
	
	FinAlgoritmo
