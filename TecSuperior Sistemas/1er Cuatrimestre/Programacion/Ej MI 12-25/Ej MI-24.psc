Algoritmo Ej_MI_24
//Ej. MI-24: Se dispone de un lote de valores enteros positivos que finaliza con un numero negativo.
//El lote esta dividido en sublotes por medio de valores cero. Desarrollar un programa que determine e informe:
//	a) por cada sublote el promedio de valores
//	b) el total de sublotes procesados
//	c) el valor maximo del conjunto, indicando en que sublote se encontro y la posicion relativa del mismo dentro
//	del sublote
//	d) valor minimo de cada sublote
//Nota: el lote puede estar vacio (primer valor negativo), o puede haber uno, varios o todos los sublotes vacios (ceros
	//	consecutivos)
	
	Definir num Como Real;
	
	Definir cantSublotes como Entero;
	cantSublotes = 0;
	//Variable para controlar el paso al siguiente lote
	Definir sumarSublote Como Logico; 
	sumarSublote = Verdadero;
	
	//Variables para el promedio por sublote
	Definir promedioValSublote como Real;
	Definir valoresEnSublote Como Real;
	promedioValSublote = 0;
	valoresEnSublote = 0;
	
	
	//Variables para el valor maximo
	Definir valorMaxDelLote como Real;
	Definir numSublote como Entero; //Para el mayor del lote
	Definir posicionEnSublote como Entero; //Para el mayor del lote
	valorMaxDelLote = 0;
	numSublote = 0;
	posicionEnSublote = 0;
	
	//Variables para el valor minimo del sublote
	Definir valorMinDelSublote como Real;
	valorMinDelSublote = 0;
	
	Escribir "Ingrese el primer número del lote, 0 para terminar el sublote o un número negativo para salir: ";
	leer num;
	
	Mientras num >= 0 Hacer
		si sumarSublote == Verdadero Entonces
			cantSublotes = cantSublotes + 1;
			sumarSublote = Falso			
		FinSi
		
		Si num = 0 Entonces
			Escribir "Haz terminado el sublote ", cantSublotes;
			sumarSublote = Verdadero;
			Escribir " ";
			Escribir "Ingrese el siguiente número, 0 para terminar el sublote o un número negativo para salir: ";
			leer num;
			
		sino 
			
			Mientras num > 0 Hacer
				valoresEnSublote = valoresEnSublote + 1;
				promedioValSublote = promedioValSublote + num;
				
				si num > valorMaxDelLote O valorMaxDelLote = 0 Entonces
					valorMaxDelLote = num;
					posicionEnSublote = valoresEnSublote;
					numSublote = cantSublotes;
				FinSi
				
				si num < valorMinDelSublote o valorMinDelSublote = 0 Entonces
					valorMinDelSublote = num;
				FinSi
				
				Escribir "Ingrese el siguiente número, 0 para terminar el sublote o un número negativo para salir: ";
				leer num;
				
			FinMientras
			
			
			promedioValSublote = promedioValSublote / valoresEnSublote;
			Escribir "El promedio de los valores del sublote ", cantSublotes, " es: ", promedioValSublote;
			Escribir "El valor mínimo ingresado en este sublote fue: ", valorMinDelSublote;
			Escribir " ";
			
			promedioValSublote = 0;
			valoresEnSublote = 0;
			valorMinDelSublote = 0;
		FinSi
		
		
		
	FinMientras
	
	si cantSublotes = 0 Entonces
		Escribir "No se creó el lote.";
	SiNo
		Escribir "Se procesaron en total ", cantSublotes, " sublotes.";
		si valorMaxDelLote > 0 Entonces
			Escribir "El valor máximo del lote es ", valorMaxDelLote, ". Se encontró en el sublote ", numSublote, ", en la posición ", posicionEnSublote;
		FinSi
	FinSi
	
FinAlgoritmo
