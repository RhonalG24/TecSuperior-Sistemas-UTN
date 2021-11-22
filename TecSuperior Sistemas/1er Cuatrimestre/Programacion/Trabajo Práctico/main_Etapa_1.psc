Algoritmo Etapa_1
	leer("Ingrese la cantidad de vueltas: ", cantVueltas);
	verificarCondicion(cantVueltas, 0, "La cantidad de vueltas tiene que ser mayor a 0.", "Ingrese la cantidad de vueltas: ");
	leer("Ingrese la distancia del circuito: ", distanciaVuelta);
	int contador = 0;
	Mientras contador < cantVueltas Hacer
		leer("Ingrese el numero de la vuelta: ", numeroDeVuelta);
		leer("Ingrese el tiempo de la vuelta (MMSS): ", tiempoVueltaMMSS);
		verificarCondicion(tiempoVueltaMMSS, 0, "El tiempo de las vueltas tiene que ser mayor a 0", "Ingrese el tiempo de la vuelta (MMSS): ");
		calcularVueltaMasRapida(tiempoVueltaMMSS, tiempoVueltaMasRapida, vueltaMasRapida, numeroDeVuelta);
		calcularVueltaMasLenta(tiempoVueltaMMSS, tiempoVueltaMasLenta, vueltaMasLenta, numeroDeVuelta);
		contador++;
	FinMientras
	Escribir "La vuelta más rapida fue la" << vueltaMasRapida << " con un tiempo de " << tiempoVueltaMasRapida;
	Escribir "La vuelta más lenta fue la " << vueltaMasLenta << " con un tiempo de " << tiempoVueltaMaslenta;
	Si tiempoVueltaMasRapida != 1 Entonces
		float porcentajeReduccionTiempo = calcularPorcentajeReduccionTiempo(tiempoVueltaMasLenta, tiempoVueltaMasRapida);
		Escribir "El porcentaje de reduccion de tiempo entre el peor y mejor tiempo es de " << porcentajeReduccionTiempo;
	SiNo
		Escribir "No se puede calcular el porcentaje de reduccion de tiempo.";
	FinSi
FinAlgoritmo
