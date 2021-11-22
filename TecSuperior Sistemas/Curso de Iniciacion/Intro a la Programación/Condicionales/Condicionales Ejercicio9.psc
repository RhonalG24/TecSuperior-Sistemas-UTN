//Sagitario 		23 nov. – 20 dic. 	
//Capricornio 	21 dic. – 19 enero 	
//Acuario 		20 enero – 18 febrero 	
//Piscis 		19 febrero – 20 marzo 	
//Aries 			21 marzo – 20 abril
//Tauro 			21 abril – 20 mayo 	
//Géminis	 	21 mayo – 20 junio 	
//Cáncer 		21 junio – 20 julio 	
//Leo 			21 julio – 21 agosto 	
//Virgo 			22 agosto – 22 sept. 	
//Libra 			23 sept. – 22 oct. 	
//Escorpio 		23 oct. – 22 nov. 	

Algoritmo Condicionales9
	Definir dia, mes Como Entero;
	Definir signo como Cadena;
	
	Escribir "Ingrese su dia de nacimiento:";
	leer dia;
	Escribir "Ingrese su mes de nacimiento:";
	leer mes;
	
	Segun mes hacer
		1:
			si dia <= 19 Entonces
				signo = "Capricornio";
			SiNo
				signo = "Acuario";
			FinSi
		2:
			si dia <= 18 Entonces
				signo = "Acuario";
			SiNo
				signo = "Piscis";
			FinSi
		3:
			si dia <= 20 Entonces
				signo = "Piscis";
			SiNo
				signo = "Aries";
			FinSi
		4:
			si dia <= 20 Entonces
				signo = "Aries";
			SiNo
				signo = "Tauro";
			FinSi
		5:
			si dia <= 20 Entonces
				signo = "Tauro";
			SiNo
				signo = "Géminis";
			FinSi
		6:
			si dia <= 20 Entonces
				signo = "Géminis";
			SiNo
				signo = "Cáncer";
			FinSi
		7:
			si dia <= 20 Entonces
				signo = "Cáncer";
			SiNo
				signo = "Leo";
			FinSi
		8:
			si dia <= 21 Entonces
				signo = "Leo";
			SiNo
				signo = "Virgo";
			FinSi
		9:
			si dia <= 22 Entonces
				signo = "Virgo";
			SiNo
				signo = "Libra";
			FinSi
		10:
			si dia <= 22 Entonces
				signo = "Libra";
			SiNo
				signo = "Escorpio";
			FinSi
		11:
			si dia <= 22 Entonces
				signo = "Escorpio";
			SiNo
				signo = "Sagitario";
			FinSi
		12:
			si dia <= 20 Entonces
				signo = "Sagitario";
			SiNo
				signo = "Capricornio";
			FinSi
	FinSegun
	
	Escribir "Su signo zodiacal es ", signo;
FinAlgoritmo
