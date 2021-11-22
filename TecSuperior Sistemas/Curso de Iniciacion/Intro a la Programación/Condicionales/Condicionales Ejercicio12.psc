Algoritmo Condicionales12
	Definir sueldoNeto Como Real;
	Definir categoria, cantHijos, antiguedad Como Entero;
	
	Definir  bonoCategoria, BONO_FAMILIAR, salarioFamiliar, porcentajeAntiguedad Como Real;
	
	Definir sueldo Como Real;
	
	BONO_FAMILIAR = 350;
	
	Escribir "Ingrese el sueldo neto del empleado: ";
	Leer  sueldoNeto;
	Escribir "Ingrese el número de la categoría del empleado:";
	Escribir "1.- Cadete.";
	Escribir "2.- Administrativo.";
	Escribir "3.- Supervisor.";
	Escribir "4.- Gerente.";
	Leer categoria;
	Escribir "Ingrese cuántos hijos tiene el empleado:";
	Leer cantHijos;
	Escribir "Ingrese los años de antiguedad del empleado:";
	Leer antiguedad;
	
	
	salarioFamiliar = BONO_FAMILIAR * cantHijos;
	
	Segun categoria hacer
		2: 
			bonoCategoria = 3000;
		3: 
			bonoCategoria = 6000;
		4:
			bonoCategoria = 10000;
		de otro modo:
			bonoCategoria = 0;
	FinSegun
	
	si antiguedad < 2 Entonces
		porcentajeAntiguedad = 0;
	sino
		si antiguedad < 5 Entonces
			porcentajeAntiguedad = 0.25;
		SiNo
			si antiguedad < 10 Entonces
				porcentajeAntiguedad = 0.6;
			SiNo
				porcentajeAntiguedad = 1;
			FinSi
		FinSi
	FinSi
	
	sueldo = (sueldoNeto + bonoCategoria + salarioFamiliar) * (1 + porcentajeAntiguedad);
	
	Escribir "El sueldo del empleado es de ", sueldo;	
	
FinAlgoritmo
