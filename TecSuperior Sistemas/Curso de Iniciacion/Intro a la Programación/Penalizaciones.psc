Algoritmo Penalizaciones
	Definir nroSocio, cantDias, diasPenalizacion como real;
	Definir finSemana, socio Como Caracter;
	
	Escribir "Ingrese su n�mero de socio (Si no es socio, ingrese 0)";
	Leer nroSocio;
	Escribir "Ingrese la cantidad de d�as que han pasado desde que retir� el libro";
	Leer  cantDias;
	Escribir "Retir� el libro un fin de semana? (s/n)"
	Leer  finSemana;
	
	Si ( finSemana == "s" ) Entonces
		diasPenalizacion = cantDias - 32;
	SiNo
		diasPenalizacion = cantDias - 30;
	FinSi
	
	Si ( diasPenalizacion <= 0) Entonces
		diasPenalizacion = 0;
		
	SiNo
		si (nroSocio > 0 Y nroSocio <= 16) Entonces
			socio = "historico";
		FinSi
		
		Si (nroSocio >= 100 y nroSocio <= 200)
				socio = "patrocinadores";
		FinSi
		
		Si (nroSocio > 200) entonces
			socio = "normal";
		FinSi
		
		Si (nroSocio = 0) entonces
			socio = "NoSocio";
		FinSi
		
		Segun socio hacer
			"historico":
				diasPenalizacion = 0;
				
			"patrocinadores":
				si (diasPenalizacion >= 20) Entonces
					diasPenalizacion = 20;
					diasPenalizacion = diasPenalizacion * 2;
				SiNo
					diasPenalizacion = diasPenalizacion * 2;
				FinSi
				
			"normal":
				diasPenalizacion = diasPenalizacion * 2;
				
			"NoSocio":
				diasPenalizacion = diasPenalizacion * 5;
		FinSegun
	FinSi
	
	si (diasPenalizacion = 0) Entonces
		Escribir "No hay penalizaci�n.";
	SiNo
		Escribir "La penalizaci�n es de ", diasPenalizacion, " d�as.";
	FinSi
	
	
FinAlgoritmo
