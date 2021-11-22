Algoritmo Ej_MI_25
	Definir CANT_PARES como Entero;
	Definir color como Cadena;
	Definir num como Entero;
	
	Definir numAnterior como Entero;
	numAnterior = 0;
	Definir colorAnterior como Cadena;
	colorAnterior = "";
	
	Definir cantCeros como Entero;
	cantCeros = 0;
	Definir valoresAntesCero como Cadena;
	valoresAntesCero = "";
	Definir anteriorAlCero como Entero;
	
	Definir cantRepNegro como Entero;
	cantRepNegro = 0;
	
	Definir numRepetido como Entero;
	Definir cantRepNumero como Entero;
	cantRepNumero = 0;
	Definir mayorNumRepetido Como Entero;
	mayorNumRepetido = -1;
	Definir cantRepMayorNumero Como Entero;
	cantRepMayorNumero = 0;
	
	Definir mayorRepColorAlt como Entero;
	mayorRepColorAlt = 0;
	
	Definir mayorRepNeg2daDocena como Entero;
	mayorRepNeg2daDocena = 0;
	
	Escribir "Ingrese la cantidad de registros que hará: "
	Leer CANT_PARES;
	
	Para i<-1 Hasta CANT_PARES Hacer
		
		Escribir "Ingrese el color (rojo/negro):";
		Leer color;
		Escribir "Ingrese el número: "
		Leer num
		
		Si num == 0 Entonces
			cantCeros = cantCeros + 1;
			numAnteriorCero = numAnterior;
			valoresAntesCero = valoresAntesCero + "; " +  ConvertirATexto(numAnteriorCero);
		FinSi
		
		Si colorAnterior == color Y color == "negro" Entonces
			cantRepNegro = cantRepNegro + 1;
		FinSi
		
		Si numAnterior == num Entonces
			numRepetido = num;
			cantRepNumero = cantRepNumero +1;
			
			si cantRepNumero > cantRepMayorNumero O mayorNumRepetido == -1 Entonces
				mayorNumRepetido = numRepetido;
				cantRepMayorNumero = cantRepNumero;
			FinSi
		SiNo
			cantRepNumero = 0;
		FinSi
		
		Si color <> colorAnterior Entonces
			repColorAlt = repColorAlt + 1;
			
			Si mayorRepColorAlt == 0 Entonces
				mayorRepColorAlt = repColorAlt;
			FinSi
			
			Si repColorAlt > mayorRepColorAlt Entonces
				mayorRepColorAlt = repColorAlt;
			FinSi
			
		SiNo
			repColorAlt = 0;
		FinSi
		
		si num > 11 Y num < 25 Entonces
			cantNeg2daDocena = 0;
		SiNo
			cantNeg2daDocena = cantNeg2daDocena + 1;
			
			si cantNeg2daDocena > mayorRepNeg2daDocena Entonces
				mayorRepNeg2daDocena = cantNeg2daDocena;
			FinSi
		FinSi
		
		colorAnterior = color;
		numAnterior = num;
		
	FinPara
	
	Escribir "La cantidad de veces que salío el número 0 fue ", cantCeros;
	Escribir "y los valores antes de cada cero fueron: ", valoresAntesCero;
	Escribir "Las ocasiones en las que el color negro se repitio fue de ", cantRepNegro, " veces."; 
	Escribir "El número ", mayorNumRepetido, " salió de manera seguida ", cantRepMayorNumero , " veces.";
	Escribir "La cantidad de veces en las que se negó la segunda docena fue: ", mayorRepNeg2daDocena;
FinAlgoritmo
