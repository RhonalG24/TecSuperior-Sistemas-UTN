/*  ARCHIVOS

Dos tipos:
    de texto: se pueden leer como texto (secuencia de caracteres) y abrir con cualquier editor de texto. Igualmente se guardan en bytes pero están interpretados y compilados.



    Se recuperan del disco rígido en forma de archivos
    s

    binarios: contienen bits de memoria


    APERTURA Y CIERRE

    FILE viene con el compilador (como tipo de variable)

    Se usa un puntero a FILE
        FILE *stdin
        FILE *stdout
        FILE *strerr

    Inicialización
        FILE *ptrArchivo = NULL;

    Apertura
        FILE *ptrArchivo = NULL;
        ptrArchivo = fopen("datos.txt", "r") //(archivo, modo)

    modos:
        "r" para lectura, el archivo debe existir. Se para al principio del archivo

        "w" para escritura. Si no existe lo crea, si existe, lo sobreescribe

        "a" para append, escritura al final. El archivo debe existir

        "rw" para lectura y escritura

        "r+" Lectura y escritura, No sobreescribe el archivo.

        "b" modo binario

    cierre del archivo
        siempre al terminar se debe cerrar el archivo que se abrió

        fclose(ptrArchivo);

ESCRITURA

fprintf(<archivo>, "texto a ingresar %s", miVariableAAniadir) - igual que el printf pero sobre el archivo


LECTURA

fgetc(FILE) - lee un caracter

    while((letra = fgetc(ptrArchivo)) != EOF){
        printf("Letra leida %c", )
    }


*/

#include <stdio.h>

int main()
{
    FILE *archivoTxt = NULL;
    archivoTxt = fopen("ejemplo.txt", "w"); //devuelve un puntero a file
    //la ruta usualmente al mismo nivel que el .exe (Windows)
    //****siempre verificar que el retorno es distinto a NULL**** para saber si lo encontró o no
    if (archivoTxt == NULL)
    {
        return -1;
    } //si todo va bien, el programa continua

    //ESCRITURA

    fputc('H', archivoTxt); //pone un caracter
    fputc('o', archivoTxt);
    fputc('l', archivoTxt);
    fputc('a', archivoTxt);

    fputs(" mundo!", archivoTxt); //pone cadenas
    int dia = 20210902;

    fprintf(archivoTxt, " Hoy es: %d", dia);

    fflush(archivoTxt); //para limpiar el buffer
    fclose(archivoTxt);

    archivoTxt = fopen("ejemplo.txt", "r");
    if (archivoTxt == NULL)
    {
        return -1;
    }
    char caracter;
    caracter = fgetc(archivoTxt);
    while (caracter != EOF)
    {
        fprintf(stdout, "%c", caracter); //stdout para mostrarlo por consola como si fuera printf
        caracter = fgetc(archivoTxt);
    }
    fclose(archivoTxt);
    //otra forma de lectura con fgets para leer cadenas
    //deja de leer cuando encuentra un salto de línea

    archivoTxt = fopen("ejemplo.txt", "r");
    if (archivoTxt == NULL)
    {
        return -1;
    }

    char buffer[5];
    //si pongo buffer[4] y fgets(buffer, 5, ...) en el buffer no se cargará el \0. De esta manera se puede usar
    while (fgets(buffer, 5, archivoTxt) != NULL)
    {
        printf("%s", buffer);
    } //lee 5 caracteres. se corta la lectura con un salto de linea o se acaba el archivo o cuando se acaban la cantidad de caracteres especificados en la condicion

    //scanf es mejor cuando la lectura tiene un cierto formato conocido

    //OTRA FORMA
    //fscanf si tiene un formato conocido
    //fscanf no lee los string que tienen espacios, en este caso hay que usar fgets()
    fclose(archivoTxt);
    archivoTxt = fopen("ejemplo.txt", "w");
    if (archivoTxt == NULL)
    {
        return -1;
    }
    fprintf(archivoTxt, "%s", "Leonardo 5 6 7 2021");
    fclose(archivoTxt);

    archivoTxt = fopen("ejemplo.txt", "r");
    if (archivoTxt == NULL)
    {
        return -1;
    }

    char nombre[40];
    int nota1, nota2, nota3, anio;

    fscanf(archivoTxt, "%s %d %d %d %d", nombre, &nota1, &nota2, &nota3, &anio);
    fclose(archivoTxt);

    return 0;
}