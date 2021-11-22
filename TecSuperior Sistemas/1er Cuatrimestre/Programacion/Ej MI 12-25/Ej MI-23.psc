Algoritmo Ej_MI_23
	Definir num Como Real;
	Definir cantNumeros Como Entero;
	Definir valorMaximoNeg Como Real;
	Definir valorMinimoPos Como Real;
	Definir minDelRango Como Real;
	Definir promedio Como Real;
	Definir posicionMayor Como Entero;
	Definir posicionMenor Como Entero;
	
	cantNumeros = 0;
	promedio = 0;
	valorMaximoNeg = 0;
	valorMinimoPos = 0;
	minDelRango = 0;
	
	Escribir "Ingrese un n�mero (0 para salir): ";
	leer num;
	
	Mientras num > 0 O num < 0 Hacer
		cantNumeros = cantNumeros + 1;
		promedio = promedio + num;
		
		si num < 0 Entonces
			si num > valorMaximoNeg O valorMaximoNeg == 0 Entonces
				valorMaximoNeg = num;
				posicionMenor = cantNumeros;
				
			FinSi
			
			
		SiNo
			si num > 0 Entonces
				si num < valorMinimoPos O valorMinimoPos == 0 Entonces
					valorMinimoPos = num;
					posicionMayor = cantNumeros;
				FinSi
				
			FinSi
		FinSi
		
		si num >= -17.3 Y num <= 26.9 Entonces
			si num < minDelRango O minDelRango == 0 Entonces
				minDelRango = num;
			FinSi
		FinSi
		
		
		Escribir "Ingrese otro n�mero (0 para salir): ";
		leer num;
		
	FinMientras
	
	si cantNumeros = 0 Entonces
		Escribir "No se ingresaron valores.";
	SiNo
		promedio = promedio / cantNumeros;
		
		Escribir "El valor m�ximo entre los negativos fue: ", valorMaximoNeg, " y fue ingresado en la posici�n ", posicionMenor;
		Escribir "El valor m�nimo entre los positivos fue: ", valorMinimoPos, " y fue ingresado en la posici�n ", posicionMayor;
		si minDelRango = 0 Entonces
			Escribir "No se ingresaron valores entre -17.3 y 26.9. ";
		SiNo
			Escribir "El valor m�nimo dentro del rango -17.3 y 26.9 fue: ", minDelRango;
		FinSi
		Escribir "El promedio es: ", promedio;
	FinSi
FinAlgoritmo
//a) El valor m�ximo negativo
//b) El valor m�nimo positivo
//c) El valor m�nimo dentro del rango -17.3 y 26.9
//d) El promedio de todos los valores.
//
//e)EN QUE POSICI�N SE ENCONTR� EL MAYOR Y EL MENOR?