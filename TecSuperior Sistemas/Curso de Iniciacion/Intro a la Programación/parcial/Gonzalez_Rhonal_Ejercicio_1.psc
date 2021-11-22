Algoritmo Ejercicio_1
	Definir valor1,valor2,valor3 Como Real
	Definir distancia1,distancia2,distancia3 Como Real
	Escribir 'Ingrese el primer valor:'
	Leer valor1
	Escribir 'Ingrese el segundo valor:'
	Leer valor2
	Escribir 'Ingrese el tercer valor:'
	Leer valor3
	distancia1 <- valor1-valor2
	Si distancia1<0 Entonces
		distancia1 <- distancia1*(-1)
	FinSi
	distancia2 <- valor1-valor3
	Si distancia2<0 Entonces
		distancia2 <- distancia2*(-1)
	FinSi
	distancia3 <- valor2-valor3
	Si distancia3<0 Entonces
		distancia3 <- distancia3*(-1)
	FinSi
	Si distancia1>distancia2 Y distancia1>distancia3 Entonces
		Escribir 'La maxima distancia es ',distancia1
	SiNo
		Si distancia2>distancia1 Y distancia2>distancia3 Entonces
			Escribir 'La maxima distancia es ',distancia2
		SiNo
			Si distancia3>distancia1 Y distancia3>distancia2 Entonces
				Escribir 'La maxima distancia es ',distancia3
			FinSi
		FinSi
	FinSi
FinAlgoritmo
