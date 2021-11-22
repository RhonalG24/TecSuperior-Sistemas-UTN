Algoritmo Ej_13
	Definir num1, num2 Como Entero;
	Definir producto Como Entero;
	
	producto = 0;
	
	Escribir "Ingrese el primer número:";
	Leer num1;
	Escribir "Ingrese el segundo número:";
	Leer num2;
	
	Para i = 0 Hasta num2-1 Con Paso 1 Hacer
		producto = producto + num1;
	FinPara
	
	Escribir "El producto es: ", producto;
FinAlgoritmo
