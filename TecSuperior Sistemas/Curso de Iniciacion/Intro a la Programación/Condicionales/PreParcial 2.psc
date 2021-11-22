//La posada cuenta con tres tipos de habitaciones:
//	● Cabañas, disponibles para grupos de 3 a 6 personas, con un mínimo de estadía de 6 noches. Precio de $1600 por persona la noche.
//	● Habitaciones privadas, para una o dos personas solamente, con un mínimo de estadía de 4 noches. Precio de $1200 por persona la noche.
//	● Habitaciones compartidas, para grupos de hasta 8 personas, sin mínimo de estadía. Precio de $950 por persona la noche.

//Objetivo: Determinar qué ofertas puede ofrecer una posada tomando en cuenta la cantidad de personas, 
//días de estadía y la fecha de ingreso para realizar un descuento si aplica. Informar también si no 
//se puede ofrecer nada.

//Datos de entrada:
//	cantPersonas: Variable tipo Entero.
// 	diasEstadia: Variable tipo Entero.
//	fechaIngreso: Variable tipo Entero.

//Precondiciones:
//	cantPersonas > 0.
// 	diasEstadia > 0.
//	fechaIngreso > 0000 Y fechaIngreso ≤ 1231. Fecha válida en formato MMDD.

//Datos de Salida:
//	mensaje: tipo Cadena.

//Flujo de Prueba:
// cantPersonas	diasEstadia	fechaIngreso	mensaje
//		1			7			0101		Habitación compartida: $6650
//										Habitación privada: $8400
//		3			10			0315		Habitación compartidad: $27075 - Descuento: $1425 (5%)
//										Cabaña

Algoritmo PreParcial_2
	Definir cantPersonas, diasEstadia, fechaIngreso Como Entero;
	Definir  cantSemanas, habitacion Como Entero
	Definir descuento Como Real;
	definir mensaje como cadena;
	
	Escribir "Ingrese la cantidad de personas:"
	leer cantPersonas;
	Escribir "Ingrese la cantidad de días:"
	leer diasEstadia;
	Escribir "Ingrese la fecha de ingreso (MMDD):"
	leer fechaIngreso;
	
	
	
	Si fechaIngreso >= 1210 O fechaIngreso <= 0310 Entonces
		descuento = 0;
	SiNo
		cantSemanas = trunc(diasEstadia / 7);
		Si cantSemanas > 5 Entonces
			descuento = 25/100;
		SiNo
			descuento = 5/100 * cantSemanas;
		FinSi
	FinSi
	
	si cantPersonas > 2 y cantPersonas < 7 y diasEstadia > 5 Entonces
		habitacion = 1600;
		precio = habitacion * cantPersonas * diasEstadia;
		Escribir  "Cabaña: $", precio-precio*descuento, " - Descuento: $", precio*descuento, " (",descuento*100,"%)";
	FinSi
	
	si cantPersonas < 3 y diasEstadia > 3  Entonces
		habitacion = 1200;
		precio = habitacion * cantPersonas * diasEstadia;
		Escribir  "Habitación Privada: $", precio-precio*descuento, " - Descuento: $", precio*descuento, " (",descuento*100,"%)";
	FinSi
	
	si cantPersonas < 9 Entonces
		habitacion = 950;
		precio = habitacion * cantPersonas * diasEstadia;
		Escribir  "Habitación compartida: $", precio-precio*descuento, " - Descuento: $", precio*descuento, " (",descuento*100,"%)";
	FinSi
	
	si cantPersonas > 8 Entonces
		mensaje = "No hay oferta disponible.";
		
		
	FinSi
	Escribir mensaje;
	
FinAlgoritmo
 