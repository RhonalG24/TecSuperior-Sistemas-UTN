Algoritmo Ej_Clase2
	Definir num como entero;
	Definir mayor1, mayor2, mayor3 Como Entero;
	Definir CANT_NUMEROS Como Entero;
	CANT_NUMEROS = 4;
	
	Escribir "Ingrese un número: ";
	Leer num;
	
	mayor1 = num;
	mayor2 = 0;
	mayor3 = 0;
	
	
	Para i = 0 Hasta CANT_NUMEROS-2 Con Paso 1 Hacer
		Escribir "Ingrese un número: ";
		Leer num;
		
		
		Si num > mayor1 Entonces
			mayor3 = mayor2;
			mayor2 = mayor1;
			mayor1 = num;
			
		sino si num > mayor2 O mayor2 == 0 Entonces
				mayor3 = mayor2;
				mayor2 = num;
			SiNo
				si num > mayor3 O mayor3 == 0 Entonces
					mayor3 = num;
				FinSi
			FinSi
			
		FinSi
		
	FinPara
	
	Escribir "El primero en el ranking es: ", mayor1;
	Escribir "El segundo en el ranking es: ", mayor2;
	Escribir "El tercero en el ranking es: ", mayor3;
	
FinAlgoritmo
