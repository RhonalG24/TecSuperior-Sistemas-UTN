Algoritmo Condicionales4
	Definir num Como Entero;
	Definir digito1, digito2, digito3, digito4, digito5 Como Entero;
	Definir mensaje como cadena;
	
	Escribir "Ingrese un n�mero de 5 d�gitos:";
	Leer num;
	
	digito1 = trunc(num / 10000);
	digito2 = trunc(num / 1000) % 10;
	digito3 = trunc(num / 100) % 10; 
	digito4 = trunc(num / 10) % 10;
	digito5 = num % 10;
	
	si digito1 = digito5 Y digito2 = digito4 Entonces
		mensaje = "Es capic�a.";
	SiNo
		mensaje = "No es capic�a."
	FinSi
	
	
	Escribir mensaje;
	
FinAlgoritmo
