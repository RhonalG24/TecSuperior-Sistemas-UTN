Algoritmo Condicionales5
	Definir  lado1, lado2, lado3 Como Real;
	Definir  mensaje como cadena;
	
	Escribir "Ingrese L1:";
	Leer  lado1;
	Escribir "Ingrese L2:";
	Leer  lado2;
	Escribir "Ingrese L3:";
	Leer  lado3;	
	
	si lado1*lado1 + lado2*lado2 = lado3*lado3 Entonces
		mensaje = "Es tri�ngulo rect�ngulo."
		
	SiNo
		mensaje = "No es tri�ngulo rect�ngulo."
	FinSi
	
	Escribir mensaje;
	
FinAlgoritmo
