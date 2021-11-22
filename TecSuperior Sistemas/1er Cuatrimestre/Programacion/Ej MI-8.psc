Algoritmo Ej_MI_8
	Definir lado1, lado2, lado3 Como Real;
	Definir mensaje como Cadena;
	
	Escribir "Ingrese el primer lado: ";
	Leer lado1;
	Escribir "Ingrese el segundo lado: ";
	Leer lado2;
	Escribir "Ingrese el tercer lado: ";
	Leer lado3;	
	
	Si (lado1+lado2 > lado3 Y lado1+lado3 > lado2 Y lado2+lado3 > lado1) Entonces
		Si (lado1==lado2 Y lado2==lado3 Y lado1==lado3) Entonces
			mensaje = "Es un triángulo equilátero:";
		sino 
			Si (lado1==lado2 Y lado1<>lado3 Y lado2<>lado3) O (lado1==lado3 Y lado1<>lado2 Y lado3<>lado2) O (lado2==lado3 Y lado2<>lado1 Y lado3<> lado1) entonces
				mensaje = "Es un triángulo isósceles.";
			sino 
				Si (lado1<>lado2 Y lado2<>lado3 Y lado1<>lado3) entonces
					mensaje = "Es un triángulo escaleno.";
				FinSi
			FinSi
		FinSI
	SiNo
		mensaje = "No es un triángulo.";
	FinSi
	
	Escribir mensaje;
FinAlgoritmo
