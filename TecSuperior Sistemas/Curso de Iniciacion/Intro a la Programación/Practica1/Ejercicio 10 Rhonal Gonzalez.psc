Algoritmo Ejercicio10
	
	Definir sueldoNeto,montoXHijo,montoXAnio Como Real;
	Definir numHijos, aniosTrabajados Como Entero;
	Definir salarioFamiliar, antiguedad como Real; 
	Definir sueldoMensual Como Real;
	
	Escribir "Ingrese el sueldo neto:";
	Leer sueldoNeto;
	
	Escribir "Ingrese el número de hijos:";
	Leer numHijos;
	
	Escribir "Ingrese el monto por cada hijo:";
	Leer montoXHijo;
	
	Escribir "Ingrese los años trabajados:";
	Leer aniosTrabajados;
	
	Escribir "Ingrese el monto por cada año trabajado:";
	Leer montoXAnio;
	
	salarioFamiliar = numHijos * montoXHijo;
	antiguedad = aniosTrabajados * montoXAnio;
	sueldoMensual = sueldoNeto + salarioFamiliar + antiguedad;
	
	Escribir "El sueldo mensual es:", sueldoMensual;
	
FinAlgoritmo
