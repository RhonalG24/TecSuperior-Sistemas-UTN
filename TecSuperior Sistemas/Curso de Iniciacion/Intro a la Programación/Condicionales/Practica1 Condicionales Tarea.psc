Algoritmo Tarea
	Definir fechaNac, fechaNacEnDias, dni, cuil Como Entero;
	Definir fechaAct, fechaActEnDias, adultoEnDias Como Entero;
	Definir dia, mes, anio Como Entero;
	adultoEnDias = 18 * 365; //un adulto ha vivido 18 años 
	
	Escribir "Ingrese la fecha actual en formato AAAAMMDD:";
	leer fechaAct;
	
	anio = TRUNC(fechaAct / 10000);
	mes = TRUNC((fechaAct % 10000)/100);
	dia = fechaAct % 100;
	
	//año tiene 365 días, no existe año 0
	//mes tiene 30 días, no existe mes 0
	fechaActEnDias = ((anio - 1) * 365) + ((mes - 1) * 30) + dia;
	
	Escribir "Ingrese su fecha de nacimiento en formato AAAAMMDD";
	leer fechaNac;
	Escribir  "Ingrese su DNI";
	Leer dni;
	
	//AAAAMMDD
	anio = TRUNC(fechaNac / 10000);
	mes = TRUNC((fechaNac % 10000)/100);
	dia = fechaNac % 100;
	
	fechaNacEnDias = ((anio - 1) * 365) + ((mes - 1) * 30) + dia;
	
	si (fechaActEnDias - fechaNacEnDias) < adultoEnDias Entonces
		Escribir "Naciste el ", dia, " del mes ", mes, " del año " anio;
		Escribir "Tu DNI es: ", dni;
	SiNo
		Escribir "Ingrese su CUIL:"
		leer cuil;
		
		Escribir "Naciste el ", dia, " del mes ", mes, " del año " anio;
		Escribir "Tu DNI es: ", dni;
		Escribir "Tu CUIL es: ", cuil;
	FinSi
	
FinAlgoritmo

//mesNacimiento = TRUNC((fechaNacimiento % 10000) / 100);
//diaNacimiento = (fechaNacimiento % 100;

//mesActual = TRUNC((fechaActual % 10000) / 100);
//diaActual = (fechaActual % 100;
//
//edad = TRUNC(fechaActual / 10000) - TRUNC(fechaNacimiento / 10000);

//Si mesNacimiento <= mesActual O mesNacimiento == mesActual Y diaNacimiento > diaActualEntonces
//	edad = edad - 1;
//FinSi
//

