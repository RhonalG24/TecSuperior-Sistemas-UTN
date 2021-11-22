Algoritmo Condicionales2
	Definir lado1, lado2, lado3 Como Real;
	Definir mensaje como cadena;
	
	Escribir "Ingrese el primer lado:"
	Leer lado1;
	Escribir "Ingrese el segundo lado:"
	Leer lado2;
	Escribir "Ingrese el tercer lado:"
	Leer lado3;
	
	si (lado1 + lado2 > lado3) Y (lado2 + lado3 > lado1) Y (lado1 + lado3 > lado2) Entonces
		mensaje = "Forman triángulo."
	SiNo
		mensaje = "No forman triángulo."
	FinSi
	
	Escribir mensaje;
	
FinAlgoritmo
