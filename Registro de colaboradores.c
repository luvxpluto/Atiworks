#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* colaboradores: datos{cedula, nombres, apellidos, correo electronico, rol en la organizacion,
 * fecha de cumpleaños}
 * Funciones:
 * eliminar y modificar info con la cedula.
 */

///// Jugadores /////
typedef struct nodoColab nodoColab;
typedef struct colaborador colab;
typedef struct ListaColab ListaColab;

/// Estructura de una lista simple
struct ListaColab
        {
    nodoColab *inicio;
        };

/// Estructura de los jugadores
struct colaborador{
    char* cedula;
    char* nombre;
    char* apellidos;
    char* correo;
    char* rol;
    char* fechaCumpleanos;
};

/// Estructura de los nodos
struct nodoColab
        {
    colab colaborador;
    nodoColab *siguiente;
        };


/// Funcion que crea una lista nueva para almacenar los colaboradores
/* Entradas:
 * Ninguna
 * Salidas:
 * La creacion de una nueva lista (vacia)
 * Restricciones:
 * Ninguna
 */
ListaColab *listaNuevaColaboradores(void)
{
    ListaColab *C;
    C = (ListaColab*) malloc(sizeof(ListaColab));
    C->inicio = NULL;
    return C;
}


/// Funcion que registra un colaborador
/* Entradas:
 * Colaboradores Una lista que contiene los colaboradores de la empresa
 * colaborador Un colaborador que trabaja para la empresa
 * Salidas:
 * Se ingresa el trabajador(colaborador) dentro de la lista que contiene todos los colaboradores
 * Restricciones:
 * Ninguna
 */
void registrarColaboradores(ListaColab *Colaboradores, colab colaborador)
{
    nodoColab *n, *aux;
    if(Colaboradores->inicio == NULL)
    {
        Colaboradores->inicio = (nodoColab *) malloc(sizeof(nodoColab));
        Colaboradores->inicio->colaborador = colaborador;
        Colaboradores->inicio->siguiente = NULL;
        return;
    }
    n = Colaboradores->inicio;
    while(n!= NULL)
    {
        aux = n;
        n = n->siguiente;
    }
    aux->siguiente = (nodoColab *) malloc(sizeof(nodoColab));
    aux->siguiente->siguiente = NULL;
    aux->siguiente->colaborador = colaborador;
}


/// Funcion que revisa si la cedula de un colaborador ya fue registrada
/* Entradas:
 * La lista que contiene a los colaboradores
 * La cedula de un colaborador
 * Salidas:
 * La funcion retorna 1 si la cedula ingresada ya existe en la lista colaboradores, de no existir retorna 0
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula debe de ser tipo char
 */
int existeCedula(ListaColab *Colaboradores, char *cedula)
{
    nodoColab *i;
    for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
    {
        if(strcmp(i->colaborador.cedula, cedula) == 0)
        {
            return 1;
        }
    }
    return 0;
}


/// Funcion que le pide los datos al usuario para registrar un colaborador
/* Entradas:
 * La lista que contiene los colaboradores (mediante un parametro)
 * Los diferentes datos necesarios para registrar un colaborador(se le solicita al usuario)
 * Salidas:
 * Se registran los datos del colaborador en la lista donde se encuentra todos los colaboradores
 * Restricciones:
 * El parametro Colaboradores debe ser una lista
 */
void obtenerDatosJugador(ListaColab *Colaboradores){

    char *cedula, *nombre, *apellidos,*correo, *rol,*fechaCumpleanos;
    cedula = malloc(sizeof(char) * 25);
    nombre = malloc(sizeof(char) * 40);
    apellidos = malloc(sizeof(char) * 40);
    correo = malloc(sizeof(char) * 40);
    rol = malloc(sizeof(char) * 40);
    fechaCumpleanos = malloc(sizeof(char) * 25);

    while(1){
        printf("Indique la cedula del colaborador (todo junto, sin simbolos ni espacios): ");
        gets(cedula);
        if(existeCedula(Colaboradores,cedula) == 0){
            break;
        }
        printf("La cedula ingresada ya esta registrada, por favor ingrese una cedula valida\n");
    }
    while(1){
        printf("Indique el nombre del colaborador: ");
        gets(nombre);
        if(strlen(nombre) == 0)
        {
            printf("Por favor ingrese un nombre.\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique los apellidos del colaborador: ");
        gets(apellidos);
        if(strlen(apellidos) == 0)
        {
            printf("Por favor ingrese los apellidos.\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique el correo del jugador: ");
        gets(correo);
        if(strlen(correo) == 0)
        {
            printf("Por favor ingrese un correo.\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique el rol en la organización del colaborador: ");
        gets(rol);
        if(strlen(rol) == 0)
        {
            printf("Por favor ingrese el rol del colaborador.\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique la fecha de cumpleanos del jugador (dia/mes): ");
        gets(fechaCumpleanos);
        if(strlen(fechaCumpleanos) == 0)
        {
            printf("Por favor ingrese una fecha de cumpleanos.\n");
        }
        else{
            break;
        }
    }
    printf("\n");
    colab colaborador = {cedula, nombre, apellidos, correo, rol,fechaCumpleanos};
    registrarColaboradores(Colaboradores, colaborador);
}



void consultarColaboradores(const ListaColab *Colaboradores)
{
    nodoColab *i;
    printf("La lista de jugadores es: \n\n");
    for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
    {
        printf("--------------------------------------------------------------------------------------------\n");
        printf("\n");
        printf("La cedula del colaborador es: %s\n", i->colaborador.cedula);
        printf("El nombre del es: %s\n", i->colaborador.nombre);
        printf("Los apellidos de %s son: %s\n",i->colaborador.nombre, i->colaborador.apellidos);
        printf("El correo de %s es: %s\n", i->colaborador.nombre, i->colaborador.correo);
        printf("El rol en la organizacion de %s es: %s\n", i->colaborador.nombre, i->colaborador.rol);
        printf("La fecha de cumplenos de %s es: %s\n", i->colaborador.nombre, i->colaborador.fechaCumpleanos);
        printf("\n");
    }
}

/// Funcion que elimina un jugador
/* Entradas:
 * La lista que contiene a los colaboradores
 * La cedula del colaborador que se quiere eliminar
 * Salidas:
 * Se elimina el colaborador de la lista de colaboradores registrados
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula del jugador debe de ser tipo char
 */
void eliminarColaborador(ListaColab *Colaboradores){
    {
        char *cedula;
        cedula = malloc(sizeof(char) * 25);

        printf("Indique la cedula del colaborador que desea eliminar: ");
        gets(cedula);

        nodoColab *aux = Colaboradores->inicio, *anterior = NULL;
        if(Colaboradores->inicio == NULL)
        {
            printf("No hay colaboradores registrados..\n");
        }
        else
        {
            if(strcmp(Colaboradores->inicio->colaborador.cedula, cedula) == 0)
            {
                aux = Colaboradores->inicio;
                Colaboradores->inicio = Colaboradores->inicio->siguiente;
            }
            else
            {
                while(aux!= NULL)
                {
                    if(strcmp(aux->colaborador.cedula, cedula) == 0)
                    {
                        anterior->siguiente = aux->siguiente;
                        break;
                    }
                    else if(aux->siguiente == NULL)
                    {
                        aux = aux->siguiente;
                        printf("\nEl colaborador esta registrado\n");
                        break;
                    }
                    else
                    {
                        anterior = aux;
                        aux = aux->siguiente;
                    }
                }
            }
            if(aux != NULL)
            {
                printf("\nLa pregunta %s fue eliminada\n", aux->colaborador.cedula);
                free(aux);
            }
        }
    }
}


/// Funcion que modifica el nombre de un colaborador
/* Entradas:
 * La lista que contiene los colaboradores (parametro)
 * La cedula del colaborador (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituye el nombre del colaborador por el nuevo que se ingreso,si el colaborador no existe se notificara
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula del colaborador debe de ser tipo char
 * El modificacion debe de ser tipo char
 */
void modificarNombre(ListaColab *Colaboradores){
    {
        char *cedula,*modificacion;
        cedula = malloc(sizeof(char) * 25);
        modificacion = malloc(sizeof(char) * 45);
        printf("Indique la cedula del colaborador: ");
        gets(cedula);
        printf("Indique el nuevo nombre del colaborador: ");
        gets(modificacion);
        nodoColab *i;
        for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
        {
            if(strcmp(i->colaborador.cedula, cedula) == 0)
            {
                i->colaborador.nombre = modificacion;
                break;
            }
            else if(i->siguiente == NULL)
            {
                printf("\nEl colaborador no fue encontrado\n");
            }
        }
    }
}

/// Funcion que modifica los apellidos de un colaborador
/* Entradas:
 * La lista que contiene los colaboradores (parametro)
 * La cedula del colaborador (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituyen los apellidos del colaborador por los nuevos que se ingresaron,si el colaborador no existe se notificara
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula del colaborador debe de ser tipo char
 * El modificacion debe de ser tipo char
 */
void modificarApellidos(ListaColab *Colaboradores){
    char *cedula,*modificacion;
    cedula = malloc(sizeof(char) * 25);
    modificacion = malloc(sizeof(char) * 45);
    printf("Indique la cedula del colaborador: ");
    gets(cedula);
    printf("Indique los nuevos apellidos del colaborador: ");
    gets(modificacion);
    nodoColab *i;
    for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
    {
        if(strcmp(i->colaborador.cedula, cedula) == 0)
        {
            i->colaborador.apellidos = modificacion;
            break;
        }
        else if(i->siguiente == NULL)
        {
            printf("\nEl colaborador no fue encontrado\n");
        }
    }
}

/// Funcion que modifica el correo de un colaborador
/* Entradas:
 * La lista que contiene los colaboradores (parametro)
 * La cedula del colaborador (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituye el correo del colaborador por el nuevo que se ingreso,si el colaborador no existe se notificara
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula del colaborador debe de ser tipo char
 * El modificacion debe de ser tipo char
 */
void modificarCorreo(ListaColab *Colaboradores){
    char *cedula,*modificacion;
    cedula = malloc(sizeof(char) * 25);
    modificacion = malloc(sizeof(char) * 45);
    printf("Indique la cedula del colaborador: ");
    gets(cedula);
    printf("Indique el nuevo correo del colaborador: ");
    gets(modificacion);
    nodoColab *i;
    for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
    {
        if(strcmp(i->colaborador.cedula, cedula) == 0)
        {
            i->colaborador.correo = modificacion;
            break;
        }
        else if(i->siguiente == NULL)
        {
            printf("\nEl colaborador no fue encontrado\n");
        }
    }
}

/// Funcion que modifica el rol en la empresa de un colaborador
/* Entradas:
 * La lista que contiene los colaboradores (parametro)
 * La cedula del colaborador (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituye el rol en la empresa del colaborador por el nuevo que se ingreso,si el colaborador no existe se notificara
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula del colaborador debe de ser tipo char
 * El modificacion debe de ser tipo char
 */
void modificarRol(ListaColab *Colaboradores){
    char *cedula,*modificacion;
    cedula = malloc(sizeof(char) * 25);
    modificacion = malloc(sizeof(char) * 45);
    printf("Indique la cedula del colaborador: ");
    gets(cedula);
    printf("Indique el nuevo nombre del colaborador: ");
    gets(modificacion);
    nodoColab *i;
    for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
    {
        if(strcmp(i->colaborador.cedula, cedula) == 0)
        {
            i->colaborador.rol = modificacion;
            break;
        }
        else if(i->siguiente == NULL)
        {
            printf("\nEl colaborador no fue encontrado\n");
        }
    }
}

/// Funcion que modifica la fecha de cumpleanos de un colaborador
/* Entradas:
 * La lista que contiene los colaboradores (parametro)
 * La cedula del colaborador (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituye la fecha de cumpleanos del colaborador por la nueva que se ingreso,si el colaborador no existe se notificara
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula del colaborador debe de ser tipo char
 * El modificacion debe de ser tipo char
 */
void modificarFechaCumple(ListaColab *Colaboradores){
    char *cedula,*modificacion;
    cedula = malloc(sizeof(char) * 25);
    modificacion = malloc(sizeof(char) * 45);
    printf("Indique la cedula del colaborador: ");
    gets(cedula);
    printf("Indique el nuevo nombre del colaborador: ");
    gets(modificacion);
    nodoColab *i;
    for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
    {
        if(strcmp(i->colaborador.cedula, cedula) == 0)
        {
            i->colaborador.fechaCumpleanos = modificacion;
            break;
        }
        else if(i->siguiente == NULL)
        {
            printf("\nEl colaborador no fue encontrado\n");
        }
    }
}



int main(){
    ListaColab *Colaboradores;
    Colaboradores = listaNuevaColaboradores();
    obtenerDatosJugador(Colaboradores);
    obtenerDatosJugador(Colaboradores);
    consultarColaboradores(Colaboradores);
}