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
			mensaje = "Es un tri�ngulo equil�tero:";
		sino 
			Si (lado1==lado2 Y lado1<>lado3 Y lado2<>lado3) O (lado1==lado3 Y lado1<>lado2 Y lado3<>lado2) O (lado2==lado3 Y lado2<>lado1 Y lado3<> lado1) entonces
				mensaje = "Es un tri�ngulo is�sceles.";
			sino 
				Si (lado1<>lado2 Y lado2<>lado3 Y lado1<>lado3) entonces
					mensaje = "Es un tri�ngulo escaleno.";
				FinSi
			FinSi
		FinSI
	SiNo
		mensaje = "No es un tri�ngulo.";
	FinSi
	
	Escribir mensaje;
FinAlgoritmo
