// Ej. MI-34: ​ Desarrollar una función tal que dado un número entero positivo calcule y retorne su factorial.
Funcion factorial <- calcularFactorial ( num1 Por Valor )
	
	Definir factorial Como Entero
	factorial = 1;
	
	Para i = num1 Hasta 1 Con Paso -1	Hacer
		factorial = factorial * i;
		
	FinPara
	
FinFuncion

Algoritmo Ej_MI_34
	Definir num Como Entero
	
	Escribir "ingrese un número positivo";
	Leer num;
	
	Definir factorial Como Entero;
	factorial = calcularFactorial(num);
	
	Escribir 'El factorial de ',num,' es ',factorial;
	
FinAlgoritmo

