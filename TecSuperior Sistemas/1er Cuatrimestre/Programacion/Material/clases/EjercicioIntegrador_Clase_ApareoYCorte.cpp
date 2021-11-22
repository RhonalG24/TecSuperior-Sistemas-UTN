/*
//
typedef struct {
    string nombre;
    int cantidadDeHoras;
} ST_CURSO;


typedef struct {
    int dni;
    string nombre;
    int edad;
    string email;
    string telefono;
    int curso; // 1,2,...M
} ST_ALUMNE;


Un establecimiento educativo que se encuentra lanzando una serie de cursos,
requiere de una aplicación que le permita inscribir a los participantes.

Para ello cuenta con una cantidad M de cursos a brindar a la comunidad.

Desarrollar una aplicación que permita:
    a. Registrar una cantidad M de cursos. El código de curso, deberá asignarse de manera automática y debe ser un número entero en el rango [1, M].
    b. Registrar una cantidad de N alumnos/as. Un alumnoTurnoDia/a sólo puede inscribirse en un curso.
    c. Imprimir los datos de un alumnoTurnoDia/a y el curso al que se inscribió. Para obtener los datos, se ingresará el dni de la persona.
    d. Dados 2 vectores de alumnos, ordenados por código de curso y dni, uno con los datos de los alumnos del turno mañana y otro con los datos del turno tarde,
    imprimir por pantalla un listado con las siguientes características:
      
Curso: Programación 1
Alumno  Edad    Email   Teléfono
...
...
__________________________________
Total de alumnos del curso: 999
Promedio de edad del curso: 999

Curso: Programación 2
Alumno  Edad    Email   Teléfono
...
...
__________________________________
Total de alumnos del curso: 999
Promedio de edad del curso: 999



__________________________________
Total General de alumnos: 999
Promedio General de edades: 999

Restricciones:
    * El conjunto de cursos no puede ser recorrido secuencialmente.
    * Para los puntos a, b y c, el conjunto de alumnos/as sólo puede ser recorrido secuencialmente 1 vez.
*/

#include <iostream>
using namespace std;

typedef struct
{
    string nombre;
    int cantidadDeHoras;
} ST_CURSO;

typedef struct
{
    int dni;
    string nombre;
    int edad;
    string email;
    int telefono;
    int curso; // 1,2,...M
} ST_ALUMNO;

int busquedaBinaria(ST_ALUMNO alumno[], int n, int valorBuscado);
void burbujeo(ST_ALUMNO arr[], int n);
void cargarCurso(ST_CURSO array[], int cant);
void cargarAlumnos(ST_ALUMNO array[], int cant);
void imprimirResultado(ST_ALUMNO array[], ST_CURSO array2[], int posicion);

//Parte d)
void ordenarPorCurso(ST_ALUMNO arr[], int n);
void apareo(ST_ALUMNO vecA[], int n, ST_ALUMNO vecB[], int m, ST_ALUMNO vecC[], int &k);
void corteDeControl(ST_ALUMNO vector[], int cantidadDeElementos, ST_CURSO cursos[]);

int main()
{
    int cantAlumTurnoDia = 3, cantAlumTurnoTarde = 2, cantCursos = 3;

    // cout << "Ingrese la cantidad de cursos a lanzar: ";
    // cin >> cantCursos;
    ST_CURSO curso[cantCursos] = {
        {"Prog1", 2},
        {"Prog2", 3},
        {"Prog3", 4}};

    // cout << "Ingresar cantidad de alumnos a inscribir en el turno de la mañana: ";
    // cin >> cantAlumTurnoDia;
    ST_ALUMNO alumnoTurnoDia[cantAlumTurnoDia] = {
        {20123456, "Juanito", 22, "juanx", 1245647894, 2},
        {22456123, "Marta", 24, "marti", 1345612345, 3},
        {24592293, "Rhonal", 26, "rhonalgnzl", 1162104565, 1},
    };

    // cout << "Ingresar cantidad de alumnos a inscribir en el turno de la tarde: ";
    // cin >> cantAlumTurnoTarde;

    ST_ALUMNO alumnoTurnoTarde[cantAlumTurnoTarde] = {
        {96084802, "Andres", 22, "andrew", 1287451234, 3},
        {95456123, "Bella", 21, "bell", 1245698523, 1},
    };

    cout << endl;

    // // Funcion para cargar cursos
    // cargarCurso(curso, cantCursos);

    // // Ciclo para cargar alumnos
    // cout << "***********************************" << endl;
    // cout << "Carga de alumnos turno mañana: " << endl;

    // cargarAlumnos(alumnoTurnoDia, cantAlumTurnoDia);

    // cout << "***********************************" << endl;
    // cout << "Carga de alumnos turno tarde: " << endl;

    // cargarAlumnos(alumnoTurnoTarde, cantAlumTurnoTarde);

    // Ordenamiento
    burbujeo(alumnoTurnoDia, cantAlumTurnoDia);
    burbujeo(alumnoTurnoTarde, cantAlumTurnoTarde);

    cout << "***********************************" << endl;
    // Busqueda alumno por DNI
    int valorBuscado;
    cout << "Ingrese DNI para buscar alumno: ";
    cin >> valorBuscado;
    cout << endl
         << endl;

    int posicion = busquedaBinaria(alumnoTurnoDia, cantAlumTurnoDia, valorBuscado);

    // Impresión
    if (posicion >= 0)
    {
        imprimirResultado(alumnoTurnoDia, curso, posicion);
    }
    else
    {
        cout << "El DNI ingresado no corresponde a un alumno registrado" << endl;
    }

    //Imprimir listado
    int cantTotalAlumnos = cantAlumTurnoDia + cantAlumTurnoTarde;
    ST_ALUMNO alumnosTotal[cantTotalAlumnos] = {0};

    ordenarPorCurso(alumnoTurnoDia, cantAlumTurnoDia);
    ordenarPorCurso(alumnoTurnoTarde, cantAlumTurnoTarde);

    apareo(alumnoTurnoDia, cantAlumTurnoDia, alumnoTurnoTarde, cantAlumTurnoTarde, alumnosTotal, cantTotalAlumnos);

    cout << "******** Listado ********" << endl;

    corteDeControl(alumnosTotal, cantTotalAlumnos, curso);

    system("pause");

    return 0;
}

void cargarCurso(ST_CURSO array[], int cant)
{
    int codigoCurso;
    for (int i = 0; i < cant; i++)
    {
        cout << "******* Datos del curso a cargar *******" << endl;
        cout << "Ingrese el codigo del curso: ";
        cin >> codigoCurso;
        cout << "Ingrese el nombre del curso: ";
        cin >> array[codigoCurso - 1].nombre;
        cout << "Ingrese la cantidad de horas: ";
        cin >> array[codigoCurso - 1].cantidadDeHoras;
        cout << endl;
    }
    return;
}

void cargarAlumnos(ST_ALUMNO array[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        cout << "******* Datos del alumno a cargar *******" << endl;
        cout << "Ingrese DNI: ";
        cin >> array[i].dni;
        cout << "Ingrese nombre: ";
        cin >> array[i].nombre;
        cout << "Ingrese edad: ";
        cin >> array[i].edad;
        cout << "Ingrese email: ";
        cin >> array[i].email;
        cout << "Ingrese telefono: ";
        cin >> array[i].telefono;
        cout << "Ingrese curso: ";
        cin >> array[i].curso;
    }
    return;
}

void burbujeo(ST_ALUMNO arr[], int n)
{
    int i, j, auxDni, auxEdad, auxCurso, auxTel;
    string auxNombre, auxEmail;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].dni > arr[j + 1].dni)
            {
                auxDni = arr[j].dni;
                auxNombre = arr[j].nombre;
                auxEdad = arr[j].edad;
                auxEmail = arr[j].email;
                auxTel = arr[j].telefono;
                auxCurso = arr[j].curso;
                arr[j].dni = arr[j + 1].dni;
                arr[j].nombre = arr[j + 1].nombre;
                arr[j].edad = arr[j + 1].edad;
                arr[j].email = arr[j + 1].email;
                arr[j].telefono = arr[j + 1].telefono;
                arr[j].curso = arr[j + 1].curso;
                arr[j + 1].dni = auxDni;
                arr[j + 1].nombre = auxNombre;
                arr[j + 1].edad = auxEdad;
                arr[j + 1].email = auxEmail;
                arr[j + 1].telefono = auxTel;
                arr[j + 1].curso = auxCurso;
            }
        }
    }
    return;
}

int busquedaBinaria(ST_ALUMNO alumno[], int tope, int valorBuscado)
{
    // Cuando alumnoanco evalúo todo el vector de 0 a N-1
    int inicio = 0;
    int final = tope - 1;
    while (final >= inicio)
    { // la condicion indica que el vector no se haya recorrido en su totalidad
        int medio = inicio + (final - inicio) / 2;

        // Si el elemento es el del medio, devolvemos la posición
        if (alumno[medio].dni == valorBuscado)
        {
            return medio;
        }
        // Si el elemento es menor entonces solo puede estar en la primer mitad

        if (alumno[medio].dni > valorBuscado)
        {
            final = medio - 1; // acota el limite superior
        }
        else
        {
            inicio = medio + 1; // acota limite inferior
        }
    }

    // Si salimos por acá, es que el valor no estaba
    return -1;
}

void imprimirResultado(ST_ALUMNO array[], ST_CURSO array2[], int posicion)
{
    int posicionCurso = array[posicion].curso;
    cout << "******** Datos Encontrados ********" << endl;
    cout << "DNI del alumno: ";
    cout << array[posicion].dni << endl;
    cout << "Nombre del alumno: ";
    cout << array[posicion].nombre << endl;
    cout << "Edad del alumno: ";
    cout << array[posicion].edad << endl;
    cout << "Email del alumno: ";
    cout << array[posicion].email << endl;
    cout << "Telefono del alumno: ";
    cout << array[posicion].telefono << endl;
    cout << "Numero de curso del alumno: ";
    cout << array[posicion].curso << endl;
    cout << "Nombre de curso del alumno: ";
    cout << array2[posicionCurso - 1].nombre << endl;
    cout << "Cantidad de horas del curso: ";
    cout << array2[posicionCurso - 1].cantidadDeHoras << endl
         << endl;
    return;
}

void ordenarPorCurso(ST_ALUMNO arr[], int n)
{
    int i, j;
    ST_ALUMNO aux;
    // int auxDni, auxEdad, auxCurso;
    // string auxNombre, auxEmail, auxTel;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].curso > arr[j + 1].curso)
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;

                // auxDni = arr[j].dni;
                // auxNombre = arr[j].nombre;
                // auxEdad = arr[j].edad;
                // auxEmail = arr[j].email;
                // auxTel = arr[j].telefono;
                // auxCurso = arr[j].curso;
                // arr[j].dni = arr[j + 1].dni;
                // arr[j].nombre = arr[j + 1].nombre;
                // arr[j].edad = arr[j + 1].edad;
                // arr[j].email = arr[j + 1].email;
                // arr[j].telefono = arr[j + 1].telefono;
                // arr[j].curso = arr[j + 1].curso;
                // arr[j + 1].dni = auxDni;
                // arr[j + 1].nombre = auxNombre;
                // arr[j + 1].edad = auxEdad;
                // arr[j + 1].email = auxEmail;
                // arr[j + 1].telefono = auxTel;
                // arr[j + 1].curso = auxCurso;
            }
        }
    }
    return;
}

void apareo(ST_ALUMNO vecA[], int n, ST_ALUMNO vecB[], int m, ST_ALUMNO vecC[], int &k)
{
    //contadores para la posicion de los vectores A y B
    int i = 0, j = 0;
    //contador para la posicion del vector resultante
    k = 0;

    //mientras pueda comparar valores
    while (i < n && j < m)
    {

        if (vecA[i].curso < vecB[j].curso)
        {
            vecC[k] = vecA[i];
            i++; //me muevo en el vector A
        }
        else
        {
            vecC[k] = vecB[j];
            j++;
        }
        k++;
    }
    //Para kos valores restantes de los vectores
    while (i < n)
    {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while (j < m)
    {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
}

void corteDeControl(ST_ALUMNO vector[], int cantidadDeElementos, ST_CURSO cursos[])
{
    //inicializacion de variables para recorrer vector
    int i = 0;
    int clave;
    //inicializacion de variables para obtener resultados variables
    int alumnosCurso = 0;
    int alumnosTotal = 0;
    float promedioEdades = 0;
    float promedioGeneralEdades = 0;

    //mientras tenga elementos el vector
    while (i < cantidadDeElementos)
    { //Corte de control
        //fijar la clave
        clave = vector[i].curso;

        //inicializar las variables de resultados
        alumnosCurso = 0;
        promedioEdades = 0;
        cout << "Curso: " << cursos[clave - 1].nombre << endl;
        cout << "Alumno \t Edad \t Email \t Teléfono" << endl;
        //ciclo para obtener resultados parciales
        //mientras tenga elementos el vector y se mantenga la clave
        while (i < cantidadDeElementos && clave == vector[i].curso)
        { //agrupamiento
            cout << vector[i].nombre << "\t"
                 << vector[i].edad << "\t"
                 << vector[i].email << "\t"
                 << vector[i].telefono << "\t"
                 << endl;
            //calculos para obtener resultados parciales
            alumnosCurso++;
            promedioEdades += vector[i].edad;
            //avanzamos i
            i++;
        }

        //acumulo las variables generales
        alumnosTotal += alumnosCurso;
        promedioGeneralEdades += promedioEdades;

        //calculo promedio de edades para mostrar
        promedioEdades = promedioEdades / alumnosCurso;

        //muestro resultados parciales

        cout << "__________________________________" << endl;
        cout << "Total alumnos del curso " << cursos[clave - 1].nombre << " : " << alumnosCurso << endl;
        cout << "Promedio de edad del curso " << cursos[clave - 1].nombre << " : " << promedioEdades << endl
             << endl;
    }

    promedioGeneralEdades /= alumnosTotal;
    cout << "__________________________________" << endl;
    cout << "Total General de alumnos: " << alumnosTotal << endl;
    cout << "Promedio General de edades:" << promedioGeneralEdades << endl;
}