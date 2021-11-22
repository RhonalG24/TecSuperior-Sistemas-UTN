Algoritmo Ejercicio1
	Definir nota1,nota2,nota3 Como Entero;
	Definir promedio Como Real;
	Definir mensaje Como Caracter;
	
	Escribir 'Ingrese la primera nota:';
	Leer nota1;
	Escribir 'Ingrese la segunda nota:';
	Leer nota2;
	Escribir 'Ingrese la tercera nota:';
	Leer nota3;
	
	promedio <- (nota1+nota2+nota3)/3;
	
	Si promedio < 4 Entonces
		mensaje = "Insuficiente.";
	SiNo
		Si promedio < 6 Entonces
			mensaje = "Regular.";
		SiNo
			Si promedio <8 Entonces
				mensaje = "Bien.";
			SiNo
				Si promedio <9 Entonces
					mensaje = "Muy bien.";
				SiNo
					mensaje = "Sobresaliente.";
				FinSi
			FinSi
		FinSi
	FinSi
	
	Escribir mensaje;
	
FinAlgoritmo
