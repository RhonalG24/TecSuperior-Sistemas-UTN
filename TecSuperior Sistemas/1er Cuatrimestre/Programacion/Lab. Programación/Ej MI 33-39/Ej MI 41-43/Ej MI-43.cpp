/*
Ej. MI-43: ​ Desarrollar:
a) Una función que reciba un número natural de 4 dígitos en formato de HHMM que corresponde a un tiempo
determinado en horas y minutos, retorne ese tiempo en minutos.

b) Un procedimiento que reciba el costo en pesos de un abono telefónico, la cantidad de minutos libres que incluye
el abono, el cargo en pesos por minuto excedente y la cantidad de minutos utilizados por un abonado, retorne la
cantidad de minutos excedidos y el monto en pesos a abonar (costo del abono más minutos excedidos por el
costo de minutos excedidos) más el 21% del valor del IVA

Desarrolle un algoritmo que resuelva la siguiente situación problemática: Todos los fines de mes, una
empresa de telefonía celular debe confeccionar las facturas con los consumos de todos sus abonados, que se
realizan en tres turnos de trabajo: Mañana, Tarde y Noche.

Para ello se ingresará por teclado la siguiente información de cada celular:

- Número de celular 9 dígitos ( 0 indica cambio de turno)
- Nombre del abonado 20 caracteres
- Dirección del abonado 25 caracteres
- Tiempo utilizado 4 dígitos en formato HHMM
- Tipo de abono (carácter, A, B, C, D o E)

Dependiendo del tipo de abono que se tenga, el usuario tiene cierta cantidad de minutos libres, por los cuales no abona
cargo extra, pero por cada minuto que se exceda debe abonar una suma extra según la siguiente tabla:
Emitir el siguiente listado por cada turno:

Informar por cada turno de trabajo:
- El nombre del abonado que debe abonar la factura más costosa y el monto de ésta.
- El nombre y el número de celular de la persona que realizó la mayor cantidad de minutos excedentes, indicando cuántos
fueron.

Al final del día informar:
- El monto total facturado
- En que turno y en qué orden dentro del turno apareció el abonado que utilizó la menor cantidad de minutos en el mes.

Utilice los subprogramas a) y b).

Analisis:

Entradas:
    int numeroCel
    string nombre
    string direccion
    int tiempo (HHMM)
    char tipoAbono [A,B,C,D,E]

Salidas:
    float facturaMasCostosa 
    int mayorMinutosExcedentesDelTurno
    float totalFacturado
    int menorCantidadMinutosDelMes

TOP-DOWN

- Pedir los datos
- Obtener datos del plan
- Calcular monto de la factura
- Imprimir los datos de la factura 

Estrategia:

Pedir numero
Para i = 1 hasta 3 con paso 1 //3 turnos [Mañana, Tarde, Noche]
    switch(i)
        case 1:
            cout << Turno Mañana
        case 2:
            cout << Turno Tarde
        case 3:
            cout << Turno Noche
    FinSwitch
    
    mientras numero != 0
        pedir resto de datos

        Obtener datos del plan por tipo de abono()

        calcular monto de la factura del cliente()
    
        pedir numero
    FinMientras
    
    factura más costosa? Nombre y monto
    mayor cantidad de minutos excedidos? Nombre, numeroTelefono y cuantos minutos fueron


    acumular Monto total
    Menor cantidad de minutos? Turno y orden

FinPara
mostrar monto total
mostrar menor cantidad minutos
*/

#include <iostream>
using namespace std;

int pedirNumeros(string mensaje);
string pedirCadena(string mensaje);
char pedirCaracter(string mensaje);

int tiempoAMinutos(int tiempo);
void calcularFactura(float costoAbono, int minutosLibresDelAbono, float cargoPorMinutoExcedido, int minutosUtilizados, int &minutosExcedidos, float &montoAAbonar);

void obtenerDatosPlan(char tipoAbono, float &costoAbono, int &minutosLibresDelAbono, float &cargoPorMinutoExcedido);

int main()
{
    //Entradas
    int numeroCel;
    string nombre;
    string direccion;
    int tiempo; //HHMM
    char tipoAbono;

    float costoAbono;
    int minutosLibresDelAbono;
    float cargoPorMinutoExcedido;

    int minutosUtilizados;
    int minutosExcedidos;
    float montoAAbonar;

    //Salidas
    float facturaMasCostosa = 0;
    string nombreFacturaMasCostosa = " ";

    int mayorMinutosExcedentesDelTurno = 0;
    string nombreMayorMinExcedidos;
    int numCelMayorMinExcedidos;

    float totalFacturado = 0;
    int menorCantidadMinutosDelMes;

    string turno;
    string turnoMenorCantMinutos;
    int posicion = 0;
    int posicionMenorCantMinutos = 0;

    numeroCel = pedirNumeros("Ingrese el numero de celular (0 para cambiar de turno):");
    for (int i = 1; i <= 3; i++)
    {
        switch (i)
        {
        case 1:
            turno = "Turno Mañana";
            cout << turno << endl
                 << endl;
            break;
        case 2:
            turno = "Turno Tarde";
            cout << turno << endl
                 << endl;
            break;
        default:
            turno = "Turno Noche";
            cout << turno << endl
                 << endl;
            break;
        }
        while (numeroCel != 0)
        {
            nombre = pedirCadena("Ingrese el nombre del cliente: ");
            direccion = pedirCadena("Ingrese la direccion del cliente: ");
            tiempo = pedirNumeros("Ingrese el tiempo utilizado en formato HHMM: ");
            tipoAbono = pedirCaracter("Ingrese el tipo de abono (A, B, C, D o E): ");

            posicion++;

            obtenerDatosPlan(tipoAbono, costoAbono, minutosLibresDelAbono, cargoPorMinutoExcedido);

            minutosUtilizados = tiempoAMinutos(tiempo);
            calcularFactura(costoAbono, minutosLibresDelAbono, cargoPorMinutoExcedido, minutosUtilizados, minutosExcedidos, montoAAbonar);

            if (montoAAbonar > facturaMasCostosa || facturaMasCostosa == 0)
            {
                facturaMasCostosa = montoAAbonar;
                nombreFacturaMasCostosa = nombre;
            }
            if (minutosExcedidos > mayorMinutosExcedentesDelTurno || mayorMinutosExcedentesDelTurno == 0)
            {
                nombreMayorMinExcedidos = nombre;
                numCelMayorMinExcedidos = numeroCel;
                mayorMinutosExcedentesDelTurno = minutosExcedidos;
            }
            if (minutosUtilizados < menorCantidadMinutosDelMes || menorCantidadMinutosDelMes == 0)
            {
                menorCantidadMinutosDelMes = minutosUtilizados;
                turnoMenorCantMinutos = turno;
                posicionMenorCantMinutos = posicion;
            }

            totalFacturado += montoAAbonar;

            numeroCel = pedirNumeros("Ingrese el siguiente numero de celular (0 para cambiar de turno):");
        }

        cout << "La factura más costosa de este turno fue la del cliente " << nombreFacturaMasCostosa << endl;
        cout << "con un monto de " << facturaMasCostosa << endl;
        cout << "El cliente con más minutos excedidos fue " << nombreMayorMinExcedidos << ", portador del numero " << numCelMayorMinExcedidos << endl;
        cout << "con un total de " << mayorMinutosExcedentesDelTurno << " minutos." << endl;
        cout << endl;

        posicion = 0;
        facturaMasCostosa = 0;
        nombreFacturaMasCostosa = " ";
        nombreMayorMinExcedidos = " ";
        numCelMayorMinExcedidos = 0;
        mayorMinutosExcedentesDelTurno = 0;
    }
    cout << "El monto total facturado fue: " << totalFacturado << endl;
    cout << "El abonado que usó la menor cantidad de minutos fue ingresado en el turno " << turnoMenorCantMinutos << " en la posición " << posicionMenorCantMinutos << endl
         << endl;

    return 0;
}

/*
a) Una función que reciba un número natural de 4 dígitos en formato de HHMM que corresponde a un tiempo
determinado en horas y minutos, retorne ese tiempo en minutos.
*/

int tiempoAMinutos(int tiempo)
{
    int minutos;
    int horas;

    horas = (tiempo / 100) * 60;
    minutos = (tiempo % 100) + horas;

    return minutos;
}

/*
b) Un procedimiento que reciba el costo en pesos de un abono telefónico, la cantidad de minutos libres que incluye
el abono, el cargo en pesos por minuto excedente y la cantidad de minutos utilizados por un abonado, retorne la
cantidad de minutos excedidos y el monto en pesos a abonar (costo del abono más minutos excedidos por el
costo de minutos excedidos) más el 21% del valor del IVA
*/

void calcularFactura(float costoAbono, int minutosLibresDelAbono, float cargoPorMinutoExcedido, int minutosUtilizados, int &minutosExcedidos, float &montoAAbonar)
{
    const int IVA = 0.21;
    minutosExcedidos = minutosUtilizados - minutosLibresDelAbono;
    if (minutosExcedidos <= 0)
    {
        minutosExcedidos = 0;
    }
    montoAAbonar = costoAbono + (minutosExcedidos * cargoPorMinutoExcedido);
    montoAAbonar += montoAAbonar * IVA; // monto a abonar más el IVA.
    return;
}

int pedirNumeros(string mensaje)
{
    int num;
    cout << mensaje << endl;
    cin >> num;
    return num;
}

string pedirCadena(string mensaje)
{
    string cadena;
    cout << mensaje << endl;
    cin >> cadena;
    cout << endl;

    return cadena;
}

char pedirCaracter(string mensaje)
{
    char caracter;
    cout << mensaje << endl;
    cin >> caracter;
    cout << endl;
    return caracter;
}

void obtenerDatosPlan(char tipoAbono, float &costoAbono, int &minutosLibresDelAbono, float &cargoPorMinutoExcedido)
{
    if (tipoAbono == 'A')
    {
        costoAbono = 70;
        minutosLibresDelAbono = 300;
        cargoPorMinutoExcedido = 0.09;
    }
    else
    {
        if (tipoAbono == 'B')
        {
            costoAbono = 55;
            minutosLibresDelAbono = 200;
            cargoPorMinutoExcedido = 0.15;
        }
        else
        {
            if (tipoAbono == 'C')
            {
                costoAbono = 40;
                minutosLibresDelAbono = 100;
                cargoPorMinutoExcedido = 0.21;
            }
            else
            {
                if (tipoAbono == 'D')
                {
                    costoAbono = 28;
                    minutosLibresDelAbono = 60;
                    cargoPorMinutoExcedido = 0.29;
                }
                else
                {
                    costoAbono = 19;
                    minutosLibresDelAbono = 40;
                    cargoPorMinutoExcedido = 0.37;
                }
            }
        }
    }
    return;
}
