//Ej. MI-26: ​ Un buque de carga traslada 100 contenedores a tres diferentes puertos del país.
//	Los puertos se identifican con los números 1, 2 y 3.
//	De cada contenedor que el buque traslade se registran los siguientes datos:
//	- Identificación del contenedor
//	- Peso del contenedor en kg
//	- Puerto de arribo (un valor de 1 a 3).
//	Se pide calcular e informar:
//	1) El peso total que el buque debe trasladar
//	2) La identificación del contenedor de mayor peso
//	3) La cantidad de contenedores que debe trasladar a cada puerto
Algoritmo Ej_MI_26
	Definir CANT_CONTENEDORES, puerto Como Entero;
	Definir idContenedor como Cadena;
	Definir pesoContenedor, pesoTotalBuque, pesoMayor Como Real;
	Definir cantContenedoresP1, cantContenedoresP2, cantContenedoresP3 Como Entero;
	
	CANT_CONTENEDORES = 5;
	pesoMayor = 0;
	
	para i = 0 Hasta CANT_CONTENEDORES - 1 Con Paso 1 Hacer
		Escribir "Ingrese el identificador del contenedor:";
		Leer idContenedor;
		Escribir "Ingrese el peso del contenedor:";
		Leer pesoContenedor;
		Escribir "Ingrese el puerto de destino del contenedor (1, 2 o 3):";
		Leer puerto;
		
		pesoTotalBuque = pesoTotalBuque + pesoContenedor;
		
		si pesoContenedor > pesoMayor O pesoMayor == 0 Entonces
			pesoMayor = pesoContenedor;
			idContenedorPesado = idContenedor;
		FinSi
		
		Segun puerto hacer
			1:
				cantContenedoresP1 = cantContenedoresP1 + 1;
			2:
				cantContenedoresP2 = cantContenedoresP2 + 1;
			3:
				cantContenedoresP3 = cantContenedoresP3 + 1;
		FinSegun
		
	FinPara
	
	Escribir "El peso total en el buque es de KG ", pesoTotalBuque;
	Escribir "El contenedor más pesado es el ", idContenedorPesado, " con KG ", pesoMayor;
	
	Si cantContenedoresP1 > 0 Entonces
		Escribir "Al puerto 1 deben trasladarse ",cantContenedoresP1, " contenedores.";
	SiNo
		Escribir "Ninguno de los contenedores va al puerto 1";
	FinSi
	Si cantContenedoresP2> 0 Entonces
		Escribir "Al puerto 2 deben trasladarse ",cantContenedoresP2, " contenedores.";
	SiNo
		Escribir "Ninguno de los contenedores va al puerto 2";
	FinSi
	Si cantContenedoresP3 > 0 Entonces
		Escribir "Al puerto 3 deben trasladarse ",cantContenedoresP3, " contenedores.";
	SiNo
		Escribir "Ninguno de los contenedores va al puerto 3";
	FinSi
	
	
FinAlgoritmo
