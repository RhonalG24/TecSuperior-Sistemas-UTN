/*
Un establecimiento educativo que se encuentra lanzando una serie de cursos,
requiere de una aplicación que le permita inscribir a los participantes.
 
Para ello cuenta con una cantidad M de cursos a brindar a la comunidad.
 
Desalumnoollar una aplicación que permita:
   * Registrar una cantidad M de cursos. El código de curso, deberá asignarse de manera automática
   y debe ser un número entero en el rango [1, M].
   * Registrar una cantidad de N alumnos/as. Un alumno/a sólo puede inscribirse en un curso.
   * Imprimir los datos de un alumno/a y el curso al que se inscribió.
   * Para obtener los datos, se ingresará el dni de la persona.
 
Restricciones:
   * El conjunto de cursos no puede ser recorrido secuencialmente.
   * El conjunto de alumnos/as sólo puede ser recorrido secuencialmente 1 vez.
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
    string telefono;
    int curso; // 1,2,...M
} ST_ALUMNO;

int busquedaBinaria(ST_ALUMNO alumno[], int tope, int valorBuscado);
void burbujeo(ST_ALUMNO arr[], int n);
void cargarCurso(ST_CURSO array[], int cant);
void cargarAlumnos(ST_ALUMNO array[], int cant);
void imprimirResultado(ST_ALUMNO array[], ST_CURSO array2[], int posicion);

int main()
{
    int cantAlum, cantCursos;

    cout << "Ingrese la cantidad de cursos a lanzar: ";
    cin >> cantCursos;
    ST_CURSO curso[cantCursos];

    cout << "Ingresar cantidad de alumnos a inscribir: ";
    cin >> cantAlum;
    ST_ALUMNO alumno[cantAlum];

    cout << endl;

    // Funcion para cargar cursos
    cargarCurso(curso, cantCursos);

    // Ciclo para cargar alumnos
    cargarAlumnos(alumno, cantAlum);

    // Ordenamiento
    burbujeo(alumno, cantAlum);

    cout << "***********************************" << endl;
    // Busqueda alumno por DNI
    int valorBuscado;
    cout << "Ingrese DNI para buscar alumno: ";
    cin >> valorBuscado;
    cout << endl;

    int posicion = busquedaBinaria(alumno, cantAlum, valorBuscado);

    // Impresión
    if (posicion >= 0)
    {
        imprimirResultado(alumno, curso, posicion);
    }
    else
    {
        cout << "El DNI ingresado no corresponde a un alumno registrado" << endl;
    }

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
    int i, j, auxDni, auxEdad, auxCurso;
    string auxNombre, auxEmail, auxTel;
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
    cout << array2[posicionCurso - 1].cantidadDeHoras << endl;
    return;
}