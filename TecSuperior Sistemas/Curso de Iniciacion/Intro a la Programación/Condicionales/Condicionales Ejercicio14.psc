Algoritmo Condicionales14
	Definir persona1, persona2, persona3 como cadena;
	Definir edad1, edad2, edad3 Como Entero;
	Definir personaMayor como cadena;
	Definir edadMayor Como Entero;
	
	Escribir "Ingrese el nombre de la primera persona:";
	Leer persona1;
	Escribir  "Ingrese la edad de la primera persona:"
	Leer edad1;
	Escribir "Ingrese el nombre de la segunda persona:";
	Leer persona2;
	Escribir  "Ingrese la edad de la segunda persona:"
	Leer edad2;
	Escribir "Ingrese el nombre de la tercera persona:";
	Leer persona3;
	Escribir  "Ingrese la edad de la tercera persona:"
	Leer edad3;
	
	edadMayor = 0;
	
	si edad1 > edad2 Y edad1 > edad3 Entonces
		edadMayor = edad1;
		personaMayor = persona1;
	SiNo
		si edad2 > edad1 Y edad2 > edad3 Entonces
			edadMayor = edad2;
			personaMayor = persona2;
		SiNo
			si edad3 > edad1 Y edad3 > edad2 Entonces
				edadMayor = edad3;
				personaMayor = persona3;
			FinSi
		FinSi
	FinSi
	
	si edadMayor = 0 Entonces
		Escribir "Datos insuficientes para determinar quien es mayor";
	SiNo
		Escribir "La persona mayor es ", personaMayor, " con ", edadMayor, " años de edad.";
	FinSi
	
	
	
FinAlgoritmo
