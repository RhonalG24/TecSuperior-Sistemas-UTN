Algoritmo Ejercicio2
	Definir lado1, lado2, lado3 Como Real;
	definir mensaje como cadena;
	
	Escribir  "Ingrese lado 1";
	Leer lado1;
	Escribir  "Ingrese lado 2";
	Leer lado2;
	Escribir  "Ingrese lado 3";
	Leer lado3;
	
	si (lado1+lado2) > lado3 Y (lado1+lado3) > lado2 Y (lado3+lado2) > lado1 Entonces
		mensaje = "Forman triangulo";
	SiNo
		mensaje = "No forman triangulo";
	FinSi
	
	Escribir  mensaje;
FinAlgoritmo
