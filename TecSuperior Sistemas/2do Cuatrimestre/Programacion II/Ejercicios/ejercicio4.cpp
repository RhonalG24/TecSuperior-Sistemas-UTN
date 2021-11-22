/*
El empleado administrativo de una empresa atiende durante su jornada laboral a una
indeterminada cantidad de personas; todas ellas deben indicar su nombre y número de
legajo para ser atendidos.
Todos los días al terminar el turno, se informa quién fue la primera persona en ser
atendida, quien poseía el legajo más bajo, la cantidad total de personas y cuántas
personas fueron atendidas por tipo de trámite; los empleados suelen acercarse a la
administración por temas relacionados al salario, vacaciones y cobertura médica.
*/

#include <iostream>
#include "stdio.h"

using namespace std;

#define CANT_PERSONAS 500

typedef struct
{
    char nombre[31];
    int legajo;
    int tramite;
} Persona;

typedef struct
{
    int salario;
    int vacaciones;
    int coberturaMed;
} Tramite;

void registrarPersonas(Persona personas[], Tramite &tramites, int &cantPersonas, int &legajoBajo)
{
    Persona aux;
    tramites = {0};

    printf("Ingrese el legajo de la persona o 0 para terminar:");
    scanf("%d", &aux.legajo);
    printf("\n");

    legajoBajo = aux.legajo;

    while (aux.legajo != 0)
    {
        if (aux.legajo < legajoBajo)
        {
            legajoBajo = aux.legajo;
        }

        printf("Ingrese el nombre de la persona: ");
        scanf("%s", &aux.nombre);
        printf("\n");

        printf("Ingrese el trámite a realizar: \n 1.- Salario \n 2.- Vacaciones \n 3.- Cobertura Médica\n");
        scanf("%d", &aux.tramite);
        printf("\n");

        switch (aux.tramite)
        {
        case 1:
            tramites.salario++;
            break;
        case 2:
            tramites.vacaciones++;
            break;
        case 3:
            tramites.coberturaMed++;
            break;
        }

        personas[cantPersonas] = aux;
        cantPersonas++;

        printf("Ingrese el legajo de la persona o 0 para terminar:");
        scanf("%d", &aux.legajo);
        printf("\n");
    }
}

// void informarPrimeraPersona(Persona persona)
// {
//     printf("La primera persona en ser atendida fue %s. \n", persona);
//     return;
// };

int main()
{

    Persona personas[CANT_PERSONAS];
    Tramite tramites;

    int cantPersonas = 0;
    int legajoBajo;

    registrarPersonas(personas, tramites, cantPersonas, legajoBajo);

    if (cantPersonas == 0)
    {
        printf("No se regritró ninguna persona.\n");
    }
    else
    {
        printf("La primera persona en ser atendida fue %s con el legajo %d. \n", personas[0].nombre, personas[0].legajo);
        printf("El legajo más bajo fue: %d \n ", legajoBajo);
        printf("Se atendieron en total %d personas, \n %d por salario \n %d por vacaciones \n %d por cobertura médica\n\n", cantPersonas, tramites.salario, tramites.vacaciones, tramites.coberturaMed);
    };

    return 0;
}

/*
printf("Legajo: "); scanf("%d", &empleado.legajo); while(empleado.legajo > 0){ printf("Nombre: "); scanf("%s", &empleado.nombre); fflush(stdin); printf("Tipo de tramite: "); scanf("%c", &empleado.tipoTramite); } 
*/