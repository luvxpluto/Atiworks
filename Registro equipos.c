///////// PROYECTO PROGRAMADO 2 - ALGORITMOS Y ESTRUCTURAS DE DATOS /////////
///// Estudiantes /////
/* Iris Bejarano Durán 2021579466
 * Esteban Sánchez Mora 2021447793
 * Keeler Jiménez Brenes 2021132597
 * Jonathan Carmona Sequeira 2021152913
*/

///////// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

///////// DEFINICION DE LAS ESTRUCTURAS
///// Colaboradores /////
typedef struct nodoColab nodoColab;
typedef struct colaborador colab;
typedef struct ListaColab ListaColab;

//// Bitacora /////
typedef struct nodoRendi nodoRendi;
typedef struct rendimiento rendi;
typedef struct ListaBitacora ListaBitacora;

///// Paseo /////
typedef struct nodoDomicilio nodoDomicilio;
typedef struct domicilio domic;
typedef struct GrafoPaseo GrafoPaseo;
typedef struct nodoRuta nodoRuta;
typedef struct infoRuta infoR;
typedef struct Rutas Rutas;

///// Equipos /////
typedef struct nodoEquipos nodoEquipos;
typedef struct infoEquipos infoE;
typedef struct Equipos Equipos;
typedef struct nodoTraba nodoTraba;
typedef struct Trabajadores Trabajadores;


////////// Estructuras
///// Colaboradores /////
/// Estructura de una lista simple
struct ListaColab
        {
    nodoColab *inicio;
        };

/// Estructura de los colaboradores
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

///// Bitacora /////
/// Estructura de una lista simple
struct ListaBitacora
        {
    nodoRendi *inicio;
        };

/// Estructura del rendimiento
struct rendimiento
        {
    char* cedula;
    char* fecha;
    char* comentario;
        };

/// Estructura de los nodos
struct nodoRendi
        {
    rendi rendimiento;
    nodoRendi *siguiente;
        };


///// Paseo /////
/// Estructura del grafo
struct GrafoPaseo
        {
    nodoDomicilio *inicio;
        };

/// Estructura de un domicilio
struct domicilio
        {
    char* codigo;
    char* nombre;
    char* codigoPos;
        };

/// Estructura del nodo domicilio
struct nodoDomicilio
        {
    domic domicilio;
    nodoDomicilio *siguiente;
    Rutas *adyacencia;
        };

/// Estructura de las rutas
struct Rutas{
    nodoRuta *destinos;
};

/// Estructura de la informacion de las rutas
struct infoRuta{
    char* destino;
    float tiempo;
    float distancia;
    char* tipoR;
};

/// Estructura del nodo de la ruta
struct nodoRuta{
    infoR informacion;
    nodoRuta *siguiente;
};

///// Equipos /////
/// Estructura de los equipos
struct Equipos{
    nodoEquipos *inicio;
};

/// Estructura de un equipo
struct infoEquipos{
    char* nombre;
    char* descripcion;
};

/// Estructura del nodo de equipos
struct nodoEquipos{
    infoE infoEquipos;
    nodoEquipos *siguiente;
    Trabajadores *miembros;
};

/// Estructura del nodo de los trabajadores
struct nodoTraba{
    char *cedula;
    nodoTraba *siguiente;
};
/// Estructura de los trabajadores
struct Trabajadores{
    nodoTraba *inicio;
};

////////////////////// FUNCIONES RELACIONADAS CON LOS COLABORADORES //////////////////////
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
 * Colaboradores debe ser un struct ListaColab
 * colaborador debe ser un strict colaborador
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
void obtenerDatosColaborador(ListaColab *Colaboradores){

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
        printf("Indique el correo del colaborador: ");
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
        printf("Indique la fecha de cumpleaños del colaborador (dia/mes): ");
        gets(fechaCumpleanos);
        if(strlen(fechaCumpleanos) == 0)
        {
            printf("Por favor ingrese una fecha de cumpleaños.\n");
        }
        else{
            break;
        }
    }
    printf("\n");
    colab colaborador = {cedula, nombre, apellidos, correo, rol,fechaCumpleanos};
    registrarColaboradores(Colaboradores, colaborador);
}

/// Funcion que imprime la informacion de un colaborador
/* Entradas:
 * La lista que contiene a los colaboradores
 * Salidas:
 * Se imprimen todos los colaboradores que contiene la lista
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 */
void consultarColaboradores(const ListaColab *Colaboradores)
{
    nodoColab *i;
    printf("La lista de colaboradores es: \n\n");
    for(i = Colaboradores->inicio; i!= NULL; i = i->siguiente)
    {
        printf("--------------------------------------------------------------------------------------------\n");
        printf("\n");
        printf("La cedula del colaborador es: %s\n", i->colaborador.cedula);
        printf("El nombre del colaborador es: %s\n", i->colaborador.nombre);
        printf("Los apellidos de %s son: %s\n",i->colaborador.nombre, i->colaborador.apellidos);
        printf("El correo de %s es: %s\n", i->colaborador.nombre, i->colaborador.correo);
        printf("El rol en la organización de %s es: %s\n", i->colaborador.nombre, i->colaborador.rol);
        printf("La fecha de cumpleaños de %s es: %s\n", i->colaborador.nombre, i->colaborador.fechaCumpleanos);
        printf("\n");
    }
}

/// Funcion que elimina un colaborador
/* Entradas:
 * La lista que contiene a los colaboradores
 * La cedula del colaborador que se quiere eliminar
 * Salidas:
 * Se elimina el colaborador de la lista de colaboradores registrados
 * Restricciones:
 * El parametro Colaboradores debe de ser una lista
 * La cedula del colaborador debe de ser tipo char
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
                        printf("\nEl colaborador no esta registrado\n");
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
                printf("\nEl colaborador %s fue eliminado\n", aux->colaborador.cedula);
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
void modificarNombre(ListaColab *Colaboradores)
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
    printf("Indique el nuevo rol que cumple el colaborador dentro de la organización: ");
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

/// Funcion que modifica la fecha de cumpleaños de un colaborador
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
    printf("Indique la nueva fecha de cumpleaños del colaborador: ");
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

////////////////////// FIN DE LAS FUNCIONES RELACIONADAS CON LOS COLABORADORES //////////////////////


////////////////////// FUNCIONES RELACIONADAS CON LA BITACORA DE RENDIMIENTO //////////////////////
/// Funcion que crea una lista nueva para almacenar la bitacora de rendimiento
/* Entradas:
 * Ninguna
 * Salidas:
 * La creacion de una nueva lista (vacia)
 * Restricciones:
 * Ninguna
 */
ListaBitacora *listaNuevaBitacora(void)
{
    ListaBitacora *X;
    X = (ListaBitacora*) malloc(sizeof(ListaBitacora));
    X -> inicio = NULL;
    return X;
}

/// Funcion que registra una observacion en la bitacora
/* Entradas:
 * Bitacora Una lista que contiene todas las observaciones
 * rendimiento Una observacion acerca del rendimiento de un colaborador
 * Salidas:
 * Se ingresa la observacion del rendimiento del colaborador en la bitacora
 * Restricciones:
 * Bitacora debe ser un struct ListaBitacora
 * rendiento debe ser un struct rendimiento
 */
void registrarRendimiento(ListaBitacora *Bitacora, rendi rendimiento){
    nodoRendi *n,*aux;
    if(Bitacora->inicio == NULL)
    {
        Bitacora->inicio = (nodoRendi *) malloc(sizeof(nodoRendi));
        Bitacora->inicio->rendimiento = rendimiento;
        Bitacora->inicio->siguiente = NULL;
        return;
    }
    n = Bitacora->inicio;
    while(n!= NULL)
    {
        aux = n;
        n = n->siguiente;
    }
    aux->siguiente = (nodoRendi *) malloc(sizeof(nodoRendi));
    aux->siguiente->siguiente = NULL;
    aux->siguiente->rendimiento = rendimiento;
}

/// Funcion para obtener la fecha actual
/* Entradas:
 * Un char fecha el cual esta vacio
 * Salidas:
 * Se escribe en el char la fecha actual
 * Restricciones:
 * El parametro fecha debe ser de tipo char
 */
void obtenerFecha(char *fecha){
    time_t t;
    struct tm *tm;
    t=time(NULL);
    tm=localtime(&t);
    strftime(fecha, 100, "%d/%m/%Y", tm);
}

/// Funcion que le pide los datos al usuario para registrar una observacion acerca de un colaborador
/* Entradas:
 * La lista que contiene la bitacora de observaciones (mediante un parametro)
 * La lista que contiene los colaboradores (mediante un parametro)
 * Los diferentes datos necesarios para registrar una observacion (se le solicita al usuario)
 * Salidas:
 * Se registran los datos de la observacion en la bitacora, de no estar registrado el colaborador se indicara
 * Restricciones:
 * Bitacora debe ser un struct ListaBitacora
 * Colaboradores debe ser un struct ListaColab
 */
void obtenerDatosBitacora(ListaBitacora *Bitacora,ListaColab *Colaboradores){
    char *cedula, *comentario,*fecha;
    cedula = malloc(sizeof(char) * 25);
    comentario = malloc(sizeof(char) * 300);
    fecha = malloc(sizeof(char) * 25);
    while(1){
        printf("Indique la cedula del colaborador (todo junto, sin simbolos ni espacios): ");
        gets(cedula);
        if(existeCedula(Colaboradores,cedula) == 1){
            break;
        }
        printf("El colaborador no esta registrado, por favor ingrese una cedula valida\n");
    }
    while(1){
        printf("Ingrese el comentario acerca del rendimiento del colaborador: ");
        gets(comentario);
        if(strlen(comentario) == 0)
        {
            printf("Por favor ingrese un comentario.\n");
        }
        else{
            break;
        }
    }
    obtenerFecha(fecha);
    rendi rendimiento = {cedula, fecha, comentario};
    registrarRendimiento(Bitacora,rendimiento);
}

/// Funcion que muestra los comentarios que se le han realizado a un colaborador en especifico
/* La lista que contiene la bitacora de observaciones (mediante un parametro)
 * La lista que contiene los colaboradores (mediante un parametro)
 * La cedula del colaborador que se quiere consultar
 * Salidas:
 * Se muestran los comentarios realizados al colaborador, de no existir comentarios o de no estar registrado
 * el colaborador se indicara
 * Restricciones:
 * Bitacora debe ser un struct ListaBitacora
 * Colaboradores debe ser un struct ListaColab
 */
void revisarRendimiento(ListaBitacora *Bitacora,ListaColab *Colaboradores){
    char *cedula;
    cedula = malloc(sizeof(char) * 25);
    printf("Digite la cedula del colaborador el cual desea revisar su rendimiento: ");
    gets(cedula);
    nodoRendi *i;
    if(existeCedula(Colaboradores,cedula) == 0){
        printf("El colaborador no ha sido registrado...");
        return;
    }

    for(i = Bitacora->inicio; i!= NULL; i = i->siguiente)
    {
        if(strcmp(i->rendimiento.cedula, cedula) == 0)
        {
            printf("El colaborador con la cedula %s, en la fecha %s, recibio el siguiente "
                   "comentario acerca de su rendimiento en la empresa:\n",i->rendimiento.cedula,i->rendimiento.fecha);
            printf("%s\n", i->rendimiento.comentario);
        }
        else if(i->siguiente==NULL){
            printf("\nEl colaborador no tiene comentarios acerca de su rendimiento\n");
        }
    }
}

////////////////////// FIN DE LAS FUNCIONES RELACIONADAS CON LA BITACORA DE RENDIMIENTO //////////////////////

////////////////////// FUNCIONES RELACIONADAS CON EL PASEO DE FIN DE AÑO //////////////////////
/// Funcion que crea un grafo nueva para almacenar los domicilios de los colaboradores para el paseo
/* Entradas:
 * Ninguna
 * Salidas:
 * La creacion de un nuevo grafo (vacio)
 * Restricciones:
 * Ninguna
 */
GrafoPaseo *grafoNuevoPaseo(void){
    GrafoPaseo *P;
    P = (GrafoPaseo*)malloc(sizeof(GrafoPaseo));
    P->inicio = NULL;
    return P;
}

/// Funcion que registra un domicilio en el grafo paseo
/* Entradas:
 * Paseo Un grafo que contiene todos los domicilios y las rutas del paseo
 * domicilio Un lugar de domicilio de uno de los colaboradores
 * Salidas:
 * Se ingresa el lugar de domicilio del colaborador en el grafo paseo
 * Restricciones:
 * Paseo debe ser un struct GrafoPaseo
 * domicilio debe ser un struct domic
 */
void registrarDomicilio(GrafoPaseo *Paseo,domic domicilio){
    nodoDomicilio *n,*aux;
    if(Paseo->inicio == NULL){
        Paseo->inicio = (nodoDomicilio*)malloc(sizeof(nodoDomicilio));
        Paseo->inicio->domicilio = domicilio;
        Paseo->inicio->siguiente = NULL;
        return;
    }
    n = Paseo->inicio;
    while(n!=NULL){
        aux = n;
        n = n->siguiente;
    }
    aux->siguiente = (nodoDomicilio*)malloc(sizeof(nodoDomicilio));
    aux->siguiente->siguiente = NULL;
    aux->siguiente->domicilio = domicilio;
}

/// Funcion que revisa si el nombre de un domicilio ya fue registrado
/* Entradas:
 * El grafo que contiene los domicilios
 * EL nombre del lugar de domicilio de un colaborador
 * Salidas:
 * La funcion retorna 1 si el nombre del lugar ingresado ya existe en el grafo paseo, de no existir retorna 0
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * EL nombre debe de ser tipo char
 */
int existeNombreDomicilio(GrafoPaseo *Paseo,char *nombre){
    nodoDomicilio *i;
    for(i=Paseo->inicio;i!=NULL;i=i->siguiente)
    {
        if(strcmp(i->domicilio.nombre,nombre)==0)
        {
            return 1;
        }
    }
    return 0;
}

/// Funcion que revisa si el codigo de un domicilio ya fue registrado
/* Entradas:
 * El grafo que contiene los domicilios
 * EL codigo del lugar de domicilio de un colaborador
 * Salidas:
 * La funcion retorna 1 si el codigo del lugar ingresado ya existe en el grafo paseo, de no existir retorna 0
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * EL codigo debe de ser tipo char
 */
int existeCodigoDomicilio(GrafoPaseo *Paseo,char *codigo){
    nodoDomicilio *i;
    for(i=Paseo->inicio;i!=NULL;i=i->siguiente)
    {
        if(strcmp(i->domicilio.codigo,codigo)==0)
        {
            return 1;
        }
    }
    return 0;
}

/// Funcion que revisa si el codigo postal de un domicilio ya fue registrado
/* Entradas:
 * El grafo que contiene los domicilios
 * EL codigo postal del lugar de domicilio de un colaborador
 * Salidas:
 * La funcion retorna 1 si el codigo postal del lugar ingresado ya existe en el grafo paseo, de no existir retorna 0
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * EL codigo postal debe de ser tipo char
 */
int existeCodigoPostalDomicilio(GrafoPaseo *Paseo,char *codigoPos){
    nodoDomicilio *i;
    for(i=Paseo->inicio;i!=NULL;i=i->siguiente)
    {
        if(strcmp(i->domicilio.codigoPos,codigoPos)==0){
            return 1;
        }
    }
    return 0;
}

/// Funcion que le pide los datos al usuario para registrar un lugar de domicilio
/* Entradas:
 * EL grafo que contiene los domicilios del paseo (mediante un parametro)
 * Los diferentes datos necesarios para registrar un domicilio (se le solicita al usuario)
 * Salidas:
 * Se registran los datos del lugar de domicilio en el grafo paseo
 * Restricciones:
 * Paseo debe ser un struct GrafoPaseo
 */
void obtenerDatosDomicilio(GrafoPaseo *Paseo){
    char *codigo;
    char *nombre;
    char *codigoPostal;
    codigo = malloc(sizeof(char) * 25);
    nombre = malloc(sizeof(char) * 40);
    codigoPostal = malloc(sizeof(char) * 25);
    while(1){
        printf("Ingrese el codigo: ");
        gets(codigo);
        if(strlen(codigo)==0)
        {
            printf("Por favor ingrese un codigo\n");
        }
        else if(existeCodigoDomicilio(Paseo,codigo)==1)
        {
            printf("El codigo ya fue registrado, por favor ingrese un codigo valido\n");
        }
        else{
            break;
        }
    }
    while(1){
        printf("Ingrese el nombre del lugar: ");
        gets(nombre);
        if(strlen(nombre)==0)
        {
            printf("Por favor ingrese un nombre\n");
        }
        else if(existeNombreDomicilio(Paseo,nombre)==1)
        {
            printf("El nombre ya fue registrado, por favor ingrese un nombre valido\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Ingrese el codigo Postal: ");
        gets(codigoPostal);
        if(strlen(codigoPostal)==0)
        {
            printf("Por favor ingrese un codigo postal\n");
        }
        else if(existeCodigoPostalDomicilio(Paseo,codigoPostal)==1)
        {
            printf("El codigo postal ya fue registrado, por favor ingrese un codigo postal valido\n");
        }
        else{
            break;
        }
    }
    domic domicilio = {codigo,nombre,codigoPostal};
    registrarDomicilio(Paseo,domicilio);
}

/// Funcion que elimina un lugar de domicilio del grafo paseo
/* Entradas:
 * El grafo que contiene los domicilios de los colaboradores
 * El nombre del lugar de domicilio que se quiere eliminar
 * Salidas:
 * Se elimina el lugar de domicilio del grafo para el paseo
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * El nombre del domicilio debe de ser tipo char
 */
void eliminarDomicilio(GrafoPaseo *Paseo){
    char *nombre;
    nombre = malloc(sizeof(char) * 45);
    while(1){
        printf("Indique el nombre del lugar de domicilio que desea eliminar: ");
        gets(nombre);
        if(strlen(nombre) == 0){
            printf("Por favor ingrese el nombre del domicilio\n");
        }
        else{
            break;
        }
    }
    nodoDomicilio *aux = Paseo->inicio,*anterior = NULL;
    if(Paseo->inicio == NULL)
    {
        printf("No hay domicilios registrados..\n");
    }
    else
    {
        if(strcmp(Paseo->inicio->domicilio.nombre, nombre) == 0)
        {
            aux = Paseo->inicio;
            Paseo->inicio = Paseo->inicio->siguiente;
        }
        else
        {
            while(aux!= NULL)
            {
                if(strcmp(aux->domicilio.nombre, nombre) == 0)
                {
                    anterior->siguiente = aux->siguiente;
                    break;
                }
                else if(aux->siguiente == NULL)
                {
                    aux = aux->siguiente;
                    printf("\nEl domicilio no esta registrado\n");
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
            printf("\nEl domicilio %s, con codigo %s y codigo postal %s fue eliminado \n",
                   aux->domicilio.nombre,aux->domicilio.codigo,aux->domicilio.codigoPos);
            free(aux);
        }
    }
}

/// Funcion que modifica el codigo postal de un domicilio del grafo paseo
/* Entradas:
 * El grafo que contiene los domicilios (parametro)
 * El nombre del lugar de domicilio (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituye el codigo postal del lugar de domicilio por el nuevo que se ingreso,si el domicilio
 * no existe se notificara
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * El nombre del lugar debe de ser tipo char
 * La modificacion debe de ser tipo char
 */
void modificarCodigoPostal(GrafoPaseo *Paseo){
    char *nombre,*modificacion;
    nombre = malloc(sizeof(char) * 45);
    modificacion = malloc(sizeof(char) * 45);

    while(1){
        printf("Indique el nombre del lugar de domicilio que desea modificar: ");
        gets(nombre);
        if(strlen(nombre)==0)
        {
            printf("Por favor ingrese un nombre\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique el nuevo codigo postal del lugar de domicilio: ");
        gets(modificacion);
        if(strlen(modificacion)==0)
        {
            printf("Por favor ingrese un codigo postal\n");
        }
        else if(existeCodigoPostalDomicilio(Paseo,modificacion)==1){
            printf("El codigo postal ya fue registrado, por favor ingrese un codigo postal valido\n");
        }
        else{
            break;
        }
    }
    nodoDomicilio *i;
    for(i= Paseo->inicio;i!=NULL;i = i->siguiente)
    {
        if(strcmp(i->domicilio.nombre,nombre)==0)
        {
            i->domicilio.codigoPos = modificacion;
            break;
        }
        else if(i->siguiente == NULL)
        {
            printf("\nEl domicilio no esta registrado\n");
        }
    }
}

/// Funcion que modifica el codigo de un domicilio del grafo paseo
/* Entradas:
 * El grafo que contiene los domicilios (parametro)
 * El nombre del lugar de domicilio (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituye el codigo del lugar de domicilio por el nuevo que se ingreso,si el domicilio no existe se notificara
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * El nombre del lugar debe de ser tipo char
 * La modificacion debe de ser tipo char
 */
void modificarCodigo(GrafoPaseo *Paseo){
    char *nombre,*modificacion;
    nombre = malloc(sizeof(char) * 45);
    modificacion = malloc(sizeof(char) * 45);

    while(1){
        printf("Indique el nombre del lugar de domicilio que desea modificar: ");
        gets(nombre);
        if(strlen(nombre)==0)
        {
            printf("Por favor ingrese un nombre\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique el nuevo codigo del lugar de domicilio: ");
        gets(modificacion);
        if(strlen(modificacion)==0)
        {
            printf("Por favor ingrese un \n");
        }
        else if(existeCodigoDomicilio(Paseo,modificacion)==1){
            printf("El codigo ya fue registrado, por favor ingrese un codigo valido\n");
        }
        else{
            break;
        }
    }

    nodoDomicilio *i;
    for(i= Paseo->inicio;i!=NULL;i = i->siguiente)
    {
        if(strcmp(i->domicilio.nombre,nombre)==0)
        {
            i->domicilio.codigo = modificacion;
            break;
        }
        else if(i->siguiente == NULL)
        {
            printf("\nEl domicilio no esta registrado\n");
        }
    }
}

/// Funcion que modifica el nombre de un domicilio del grafo paseo
/* Entradas:
 * El grafo que contiene los domicilios (parametro)
 * El nombre del lugar de domicilio (lo ingresa el usuario)
 * La modificacion que se va a realizar (lo ingresa el usuario)
 * Salidas:
 * Se sustituye el nombre del domicilio por el nuevo que se ingreso,si el domicilio no existe se notificara
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * El nombre del lugar debe de ser tipo char
 * La modificacion debe de ser tipo char
 */
void modificarNombreDomicilio(GrafoPaseo *Paseo){
    char *nombre,*modificacion;
    nombre = malloc(sizeof(char) * 45);
    modificacion = malloc(sizeof(char) * 45);

    while(1){
        printf("Indique el nombre del lugar de domicilio que desea modificar: ");
        gets(nombre);
        if(strlen(nombre)==0)
        {
            printf("Por favor ingrese un nombre\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique el nuevo nombre del lugar de domicilio: ");
        gets(modificacion);
        if(strlen(modificacion)==0)
        {
            printf("Por favor ingrese un nombre\n");
        }
        else if(existeNombreDomicilio(Paseo,modificacion)==1)
        {
            printf("El nombre ya fue registrado, por favor ingrese un nombre valido\n");
        }
        else{
            break;
        }
    }
    nodoDomicilio *i;
    for(i= Paseo->inicio;i!=NULL;i = i->siguiente)
    {
        if(strcmp(i->domicilio.nombre,nombre)==0)
        {
            i->domicilio.nombre = modificacion;
            break;
        }
        else if(i->siguiente == NULL)
        {
            printf("\nEl domicilio no esta registrado\n");
        }
    }
}

/// Funcion que agrega una ruta en la lista de adyacencia de un domicilio
/* Entradas:
 * El domicilio al que se le desea agregar la ruta (parametro)
 * El lugar de destino de la ruta (parametro)
 * El tiempo que se tarda en recorrer la ruta (Lo ingresa el usuario)
 * La distancia de la ruta (lo ingresa el usuario)
 * El tipo de ruta (lo ingresa el usuario)
 * Salidas:
 * Se agrega una nueva ruta dentro de la lista de adyacencia (contiene todas las rutas) del domicilio
 * Restricciones:
 * aux debe ser de tipo struct nodoDomicilio
 * destino debe ser de tipo char y debe corresponder al nombre de un domicilio registrado anteriormente
 * tiempo debe ser de tipo float
 * distancia debe ser de tipo float
 * el tipo de ruta debe ser de tipo char
 */
void agregarRuta(nodoDomicilio *aux,char *destino){

    char *tipoRuta;
    tipoRuta = malloc(sizeof(char) * 45);
    float tiempo,distancia;

    printf("Ingrese el tiempo estimado de ir de un lugar a otro (en minutos): ");
    scanf("%f",&tiempo);
    printf("Ingrese la distancia que hay de un lugar a otro (en Kilometros): ");
    scanf("%f",&distancia);

    while(1)
    {
        fflush(stdin);
        printf("\nIngrese el tipo de la ruta"
               "\nIndique 1 si el tipo de ruta es Terrestre"
               "\nIndique 2 si el tipo de ruta es Aerea"
               "\nIndique 3 si el tipo de ruta es Maritima"
               "\nOpcion: ");
        gets(tipoRuta);

        if(strcmp(tipoRuta, "1") == 0)
        {
            strcpy(tipoRuta, "Terrestre");
            break;
        }
        else if(strcmp(tipoRuta, "2") == 0)
        {
            strcpy(tipoRuta, "Aerea");
            break;
        }
        else if(strcmp(tipoRuta, "3") == 0)
        {
            strcpy(tipoRuta, "Maritima");
            break;
        }
        else
        {
            printf("\nPor favor indique una de las opciones disponibles.\n");
        }
    }

    infoR ruta = {destino,tiempo,distancia,tipoRuta};

    if(aux->adyacencia==NULL){
        Rutas* nuevo=(Rutas*)malloc(sizeof(Rutas));
        nuevo->destinos = (nodoRuta*)malloc(sizeof(nodoRuta));
        aux->adyacencia = nuevo;
        nuevo->destinos->informacion = ruta;
        nuevo->destinos->siguiente = NULL;
        return;
    }
    nodoRuta *n,*aux1;
    n = aux->adyacencia->destinos;
    while(n!=NULL){
        aux1 = n;
        n = n->siguiente;
    }
    aux1 -> siguiente = (nodoRuta*)malloc(sizeof(nodoRuta));
    aux1 -> siguiente -> siguiente = NULL;
    aux1 -> siguiente -> informacion = ruta;
}

/// Funcion que agrega una ruta dentro del grafo
/* Entradas:
 * El grafo que contiene los domicilios (parametro)
 * El nombre del lugar de origen de la ruta (lo ingresa el usuario)
 * El nombre del lugar de destino de la ruta (lo ingresa el usuario)
 * Salidas:
 * Se registra la ruta dentro del grafo solo si existe tanto el domicilio de origen como el de destino
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * el domicilio de origen y el de destino deben estar registrados en el grafo
 * el nombre del lugar de origen y destino deben ser de tipo char
 */
void insertarRuta(GrafoPaseo *Paseo){
    char *origen,*destino;
    nodoDomicilio *aux;
    origen  = malloc(sizeof(char) * 40);
    destino = malloc(sizeof(char) * 40);

    while(1){
        printf("Ingrese el nombre del lugar de origen: ");
        gets(origen);
        if(strlen(origen)==0)
        {
            printf("Por favor ingrese un nombre");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Ingrese el nombre del lugar de destino: ");
        gets(destino);
        if(strlen(destino)==0)
        {
            printf("Por favor ingrese un nombre");
        }
        else{
            break;
        }
    }
    if(existeNombreDomicilio(Paseo,destino)==0){
        printf("Error: El lugar de destino no ha sido registrado\n");
        return;
    }

    for(aux=Paseo->inicio;aux!=NULL;aux=aux->siguiente)
    {
        if(strcmp(aux->domicilio.nombre,origen)==0){
            agregarRuta(aux,destino);
            return;
        }
    }
    printf("Error: El lugar de origen no ha sido registrado\n");
}

/// Funcion de imprimir la ruta
/* Entradas:
 * El grafo que contiene todos los domicilios
 * Salidas:
 * Se imprimen los lugares de domicilio registrados en el grafo y sus rutas
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 */
void imprimirRutas(const GrafoPaseo *Paseo){
    nodoDomicilio *i;
    nodoRuta *i1;
    printf("La lista de los domicilio y sus rutas es: \n\n");
    for(i=Paseo->inicio;i!=NULL;i=i->siguiente){
        printf("----------------------------------------");
        printf("\n");
        printf("El nombre del lugar domicilio es: %s\n",i->domicilio.nombre);
        printf("El codigo del lugar de domicilio es: %s\n",i->domicilio.codigo);
        printf("El codigo postal del lugar de domicilio es: %s\n",i->domicilio.codigoPos);
        if(i->adyacencia == NULL){
            printf("El domicilio no cuenta con rutas registradas\n");
        }
        else{
            for(i1=i->adyacencia->destinos;i1!=NULL;i1=i1->siguiente){
                printf("\nLas rutas del domicilio son:\n");
                printf("El lugar de destino de la ruta es: %s\n",i1->informacion.destino);
                printf("El tiempo en minutos que se tarda en recorrer la ruta es: %f\n",i1->informacion.tiempo);
                printf("La distancia en kilometros que se tarda en recorrer la ruta es: %f\n",i1->informacion.distancia);
                printf("El tipo de ruta es: %s\n",i1->informacion.tipoR);
                printf("----------------------------------------\n");
            }
        }
    }
}

/// Funcion que modifica el tiempo de una ruta
/* Entradas:
 * El grafo que contiene los domicilios (parametro)
 * El nombre del lugar de origen de la ruta que se desea modificar(lo ingresa el usuario)
 * El nombre del lugar de destino de la ruta que se desea modificar (lo ingresa el usuario)
 * El tipo de ruta entre el lugar de origen y destino (lo ingresa el usuario)
 * La modificacion que se desea realizar (lo ingresa el usuario)
 * Salidas:
 * Se modifica el tiempo de la ruta entre el lugar de origen y el lugar de destino
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * El lugar de origen, destino y tipo de ruta deben estar registrados en el grafo
 * El nombre del lugar de origen, destino y tipo de ruta debe ser de tipo char
 * La modificacion debe ser de tipo float
 */
void modificarTiempoRuta(GrafoPaseo *Paseo){
    char *origen, *destino,*tipoRuta;
    origen = malloc(sizeof(char) * 40);
    destino = malloc(sizeof(char) * 40);
    tipoRuta = malloc(sizeof(char) * 40);
    float nuevoTiempo;
    nodoDomicilio *i;
    nodoRuta *i1;

    while(1){
        printf("Ingrese el lugar de origen de la ruta que se desea modificiar: ");
        gets(origen);
        if(strlen(origen)==0)
        {
            printf("Por favor ingrese un nombre");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Ingrese el lugar de destino de la ruta que se desea modificiar: ");
        gets(destino);
        if(strlen(destino)==0)
        {
            printf("Por favor ingrese un nombre");
        }
        else{
            break;
        }
    }

    while(1)
    {
        printf("\nIngrese el tipo de la ruta que se desea modificiar"
               "\nIndique 1 si el tipo de ruta es Terrestre"
               "\nIndique 2 si el tipo de ruta es Aerea"
               "\nIndique 3 si el tipo de ruta es Maritima"
               "\nOpcion: ");
        fflush(stdin);
        gets(tipoRuta);

        if(strcmp(tipoRuta, "1") == 0)
        {
            strcpy(tipoRuta, "Terrestre");
            break;
        }
        else if(strcmp(tipoRuta, "2") == 0)
        {
            strcpy(tipoRuta, "Aerea");
            break;
        }
        else if(strcmp(tipoRuta, "3") == 0)
        {
            strcpy(tipoRuta, "Maritima");
            break;
        }
        else
        {
            printf("\nPor favor indique una de las opciones disponibles.\n");
        }
    }


    printf("Ingrese el nuevo tiempo que se tarda en recorrer la ruta: ");
    scanf("%f",&nuevoTiempo);

    for(i=Paseo->inicio;i!=NULL;i=i->siguiente){
        if(strcmp(i->domicilio.nombre,origen) == 0)
        {
            for(i1=i->adyacencia->destinos;i1!=NULL;i1=i1->siguiente)
            {
                if(strcmp(i1->informacion.destino,destino)==0 && strcmp(i1->informacion.tipoR,destino)==0){
                    i1->informacion.tiempo = nuevoTiempo;
                    break;
                }
            }
            break;
        }
        else if(i->siguiente == NULL){
            printf("No se pudo realizar la modificacion");
        }
    }
}

/// Funcion que modifica la distancia de una ruta
/* Entradas:
 * El grafo que contiene los domicilios (parametro)
 * El nombre del lugar de origen de la ruta que se desea modificar(lo ingresa el usuario)
 * El nombre del lugar de destino de la ruta que se desea modificar (lo ingresa el usuario)
 * El tipo de ruta entre el lugar de origen y destino (lo ingresa el usuario)
 * La modificacion que se desea realizar (lo ingresa el usuario)
 * Salidas:
 * Se modifica la distancia de la ruta entre el lugar de origen y el lugar de destino
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * El lugar de origen, destino y tipo de ruta deben estar registrados en el grafo
 * El nombre del lugar de origen, destino y tipo de ruta debe ser de tipo char
 * La modificacion debe ser de tipo float
 */
void modificarDistanciaRuta(GrafoPaseo *Paseo){
    char *origen, *destino,*tipoRuta;
    origen = malloc(sizeof(char) * 40);
    destino = malloc(sizeof(char) * 40);
    tipoRuta = malloc(sizeof(char) * 40);
    float nuevaDistancia;
    nodoDomicilio *i;
    nodoRuta *i1;

    while(1){
        printf("Ingrese el lugar de origen de la ruta que se desea modificiar: ");
        gets(origen);
        if(strlen(origen)==0)
        {
            printf("Por favor ingrese un nombre");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Ingrese el lugar de destino de la ruta que se desea modificiar: ");
        gets(destino);
        if(strlen(destino)==0)
        {
            printf("Por favor ingrese un nombre");
        }
        else{
            break;
        }
    }

    while(1)
    {
        printf("\nIngrese el tipo de la ruta que se desea modificiar"
               "\nIndique 1 si el tipo de ruta es Terrestre"
               "\nIndique 2 si el tipo de ruta es Aerea"
               "\nIndique 3 si el tipo de ruta es Maritima"
               "\nOpcion: ");
        fflush(stdin);
        gets(tipoRuta);

        if(strcmp(tipoRuta, "1") == 0)
        {
            strcpy(tipoRuta, "Terrestre");
            break;
        }
        else if(strcmp(tipoRuta, "2") == 0)
        {
            strcpy(tipoRuta, "Aerea");
            break;
        }
        else if(strcmp(tipoRuta, "3") == 0)
        {
            strcpy(tipoRuta, "Maritima");
            break;
        }
        else
        {
            printf("\nPor favor indique una de las opciones disponibles.\n");
        }
    }

    printf("Ingrese la nueva distancia que hay entre el lugar de origen y el lugar de destino: ");
    scanf("%f",&nuevaDistancia);

    for(i=Paseo->inicio;i!=NULL;i=i->siguiente){
        if(strcmp(i->domicilio.nombre,origen) == 0)
        {
            for(i1=i->adyacencia->destinos;i1!=NULL;i1=i1->siguiente)
            {
                if(strcmp(i1->informacion.destino,destino)==0 && strcmp(i1->informacion.tipoR,destino)==0){
                    i1->informacion.distancia = nuevaDistancia;
                    break;
                }
            }
            break;
        }
        else if(i->siguiente == NULL){
            printf("No se pudo realizar la modificacion");
        }
    }
}

/// Funcion que elimina una ruta
/* Entradas:
 * El grafo que contiene los domicilios (parametro)
 * El nombre del lugar de origen de la ruta que se desea eliminar (lo ingresa el usuario)
 * El nombre del lugar de destino de la ruta que se desea eliminar (lo ingresa el usuario)
 * El tipo de ruta entre el lugar de origen y destino (lo ingresa el usuario)
 * Salidas:
 * Se elimina la ruta entre el lugar de domicilio y el lugar de destino del grafo para el paseo
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 * El lugar de origen, destino y tipo de ruta deben estar registrados en el grafo
 * El nombre del lugar de origen, destino y tipo de ruta debe ser de tipo char
 */
void eliminarRuta(GrafoPaseo *Paseo){
    char *origen, *destino,*tipoRuta;
    origen = malloc(sizeof(char) * 40);
    destino = malloc(sizeof(char) * 40);
    tipoRuta = malloc(sizeof(char) * 40);
    nodoDomicilio *i;
    while(1){
        printf("Ingrese el lugar de origen de la ruta que se desea modificiar: ");
        gets(origen);
        if(strlen(origen)==0)
        {
            printf("\nPor favor ingrese un nombre\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Ingrese el lugar de destino de la ruta que se desea modificiar: ");
        gets(destino);
        if(strlen(destino)==0)
        {
            printf("\nPor favor ingrese un nombre\n");
        }
        else{
            break;
        }
    }


    while(1)
    {
        printf("\nIngrese el tipo de la ruta que se desea modificiar"
               "\nIndique 1 si el tipo de ruta es Terrestre"
               "\nIndique 2 si el tipo de ruta es Aerea"
               "\nIndique 3 si el tipo de ruta es Maritima"
               "\nOpcion: ");
        fflush(stdin);
        gets(tipoRuta);

        if(strcmp(tipoRuta, "1") == 0)
        {
            strcpy(tipoRuta, "Terrestre");
            break;
        }
        else if(strcmp(tipoRuta, "2") == 0)
        {
            strcpy(tipoRuta, "Aerea");
            break;
        }
        else if(strcmp(tipoRuta, "3") == 0)
        {
            strcpy(tipoRuta, "Maritima");
            break;
        }
        else
        {
            printf("\nPor favor indique una de las opciones disponibles.\n");
        }
    }

    for(i=Paseo->inicio;i!=NULL;i=i->siguiente){
        if(strcmp(i->domicilio.nombre,origen) == 0)
        {
            nodoRuta *aux = i->adyacencia->destinos, *anterior = NULL;
            if(i->adyacencia->destinos == NULL)
            {
                printf("El domicilio no tine rutas registradas...\n");
                return;
            }
            else{
                if(strcmp(i->adyacencia->destinos->informacion.destino,destino)==0 &&
                strcmp(i->adyacencia->destinos->informacion.tipoR,tipoRuta)==0)
                {
                    aux = i->adyacencia->destinos;
                    i->adyacencia->destinos = i->adyacencia->destinos->siguiente;
                }
                else{
                    while(aux!= NULL){
                        if(strcmp(aux->informacion.destino,destino)==0 && strcmp(aux->informacion.tipoR,tipoRuta)==0){
                            anterior-> siguiente = aux ->siguiente;
                            break;
                        }
                        else if(aux->siguiente == NULL){
                            aux = aux->siguiente;
                            printf("\nLa ruta que se desea eliminar no esta registrada...\n");
                            break;
                        }
                        else{
                            anterior = aux;
                            aux = aux->siguiente;
                        }
                    }
                }
            }
            if(aux!=NULL){
                printf("La ruta de tipo %s entre el domicilio de origen %s y el domicilio de destino %s ha sido eliminada...",
                       aux->informacion.tipoR,i->domicilio.nombre,aux->informacion.destino);
                free(aux);
            }
        }
    }
}

/// Funcion que calcula el promedio de rutas por domicilio
/* Entradas:
 * El grafo que contiene todos los domicilios y las rutas (parametro)
 * Salidas:
 * La funcion calcula la cantidad total de domicilios y la cantidad total de rutas y los divide para
 * obtener el promedio de rutas
 * Restricciones:
 * El parametro Paseo debe de ser un struct GrafoPaseo
 */
void promedioDeRutasPorDomicilio(const GrafoPaseo*Paseo){
    nodoDomicilio *i;
    nodoRuta *i1;
    int cantidadDomicilios=0,cantidadRutas=0;
    for(i=Paseo->inicio;i!=NULL;i=i->siguiente){
        cantidadDomicilios ++;
        if(i->adyacencia != NULL){
            for(i1=i->adyacencia->destinos;i1!=NULL;i1=i1->siguiente){
               cantidadRutas++;
            }
        }
    }
    printf("El promedio de rutas por domicilio es de: %d\n",cantidadRutas/cantidadDomicilios);
}

////////////////////// FIN DE LAS FUNCIONES RELACIONADAS CON EL PASEO DE FIN DE AÑO //////////////////////



////////////////////// FUNCIONES RELACIONADAS CON EL REGISTRO DE EQUIPOS //////////////////////

Equipos *crearEquipos(void){
    Equipos *E;
    E = (Equipos*)malloc(sizeof(Equipos));
    E->inicio = NULL;
    return E;
}


void registrarEquipos(Equipos *Equipo, infoE informacionEquipo){
    nodoEquipos *n,*aux;
    if(Equipo->inicio == NULL){
        Equipo->inicio = (nodoEquipos*)malloc(sizeof(nodoEquipos));
        Equipo->inicio->infoEquipos = informacionEquipo;
        Equipo->inicio->siguiente = NULL;
        return;
    }
    n = Equipo->inicio;
    while(n!=NULL){
        aux = n;
        n = n->siguiente;
    }
    aux->siguiente = (nodoEquipos*)malloc(sizeof(nodoEquipos));
    aux->siguiente->siguiente = NULL;
    aux->siguiente->infoEquipos = informacionEquipo;
}


int existeNombreEquipo(Equipos *Equipo,char *nombre){
    nodoEquipos *i;
    for(i=Equipo->inicio;i!=NULL;i=i->siguiente)
    {
        if(strcmp(i->infoEquipos.nombre,nombre)==0)
        {
            return 1;
        }
    }
    return 0;
}


void obtenerDatosEquipo(Equipos *Equipo){
    char *nombre;
    char *descripcion;
    nombre = malloc(sizeof(char) * 40);
    descripcion = malloc(sizeof(char) * 100);

    while(1){
        printf("Ingrese el nombre del equipo: ");
        gets(nombre);
        if(strlen(nombre)==0)
        {
            printf("Por favor ingrese un nombre\n");
        }
        else if(existeNombreEquipo(Equipo,nombre)==1)
        {
            printf("El nombre del equipo ya fue registrado, por favor ingrese un nombre valido\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique la descripcion del equipo: ");
        gets(descripcion);
        if(strlen(descripcion) == 0)
        {
            printf("Por favor ingrese una descripcion.\n");
        }
        else{
            break;
        }
    }

    infoE informacion = {nombre,descripcion};
    registrarEquipos(Equipo,informacion);
}




void agregarMiembro(nodoEquipos *aux,char *cedula){
    if(aux->miembros==NULL){
        Trabajadores* nuevo=(Trabajadores*)malloc(sizeof(Trabajadores));
        nuevo->inicio = (nodoTraba*)malloc(sizeof(nodoTraba));
        aux->miembros = nuevo;
        nuevo->inicio->cedula = cedula;
        nuevo->inicio->siguiente = NULL;
        return;
    }
    nodoTraba *n,*aux1;
    n = aux->miembros->inicio;
    while(n!=NULL){
        aux1 = n;
        n = n->siguiente;
    }
    aux1 -> siguiente = (nodoTraba*)malloc(sizeof(nodoTraba));
    aux1 -> siguiente -> siguiente = NULL;
    aux1 -> siguiente -> cedula = cedula;
}

void insertarMiembro(Equipos *Equipo,ListaColab *Colaboradores){
    char *cedula, *nombreEquipo;
    nodoEquipos *aux;
    cedula = malloc(sizeof(char) * 25);
    nombreEquipo = malloc(sizeof(char) * 40);
    while(1){
        printf("Indique la cedula del miembro que desea registrar en el equipo (todo junto, sin simbolos ni espacios): ");
        gets(cedula);
        if(strlen(cedula)==0)
        {
            printf("Por favor ingrese una cedula\n");
        }
        else if(existeCedula(Colaboradores,cedula) == 0){
            printf("El miembro no esta registrado, por favor ingrese una cedula valida\n");
        }
        else{
            break;
        }
    }

    while(1){
        printf("Indique el nombre del equipo al cual se desea agregar el mimebro: ");
        gets(nombreEquipo);
        if(strlen(nombreEquipo) == 0)
        {
            printf("Por favor ingrese el nombre del equipo.\n");
        }
        else{
            break;
        }
    }

    for(aux=Equipo->inicio;aux!=NULL;aux=aux->siguiente)
    {
        if(strcmp(aux->infoEquipos.nombre,nombreEquipo)==0){
            agregarMiembro(aux,cedula);
            return;
        }
    }
    printf("Error: El equipo no ha sido registrado\n");
}



void imprimirLosEquipos(const Equipos *Equipo){
    nodoEquipos *i;
    nodoTraba *i1;
    printf("\nLa lista de los equipos y sus trabajadores es: \n\n");
    for(i=Equipo->inicio;i!=NULL;i=i->siguiente){
        printf("----------------------------------------");
        printf("\n");
        printf("El nombre del equipo es: %s\n",i->infoEquipos.nombre);
        printf("La descripcion del equipo es: %s\n",i->infoEquipos.descripcion);
        if(i->miembros == NULL){
            printf("El equipo no cuenta con trabajadores registrados\n");
        }
        else{
            for(i1 = i->miembros->inicio;i1!=NULL;i1=i1->siguiente){
                printf("Los cedula de los trabajadores del equipo son:\n");
                printf("Colaborador: %s\n",i1->cedula);
            }
        }
    }
}

void promedioDeColaboradores(const Equipos *Equipo){
    nodoEquipos *i;
    nodoTraba *i1;
    int cantidadEquipos = 0,cantidadColaboradores=0;
    for(i=Equipo->inicio;i!=NULL;i=i->siguiente){
        cantidadEquipos ++;
        if(i->miembros != NULL){
            for(i1 = i->miembros->inicio;i1!=NULL;i1=i1->siguiente){
                cantidadColaboradores++;
            }
        }
    }
    printf("El promedio de colaboradores por equipo es de: %d\n",cantidadColaboradores/cantidadEquipos);
}


////////////////////// FIN DE LAS FUNCIONES RELACIONADAS CON EL REGISTRO DE EQUIPOS //////////////////////






////////////////////////////////////////////// FUNCION PRINCIPAL //////////////////////////////////////////////
int main(){
    ListaColab *Colaboradores;
    ListaBitacora *Bitacora;
    GrafoPaseo *Paseo;
    Equipos *EquipoTrabajo;
    Colaboradores = listaNuevaColaboradores();
    Bitacora = listaNuevaBitacora();
    Paseo = grafoNuevoPaseo();
    EquipoTrabajo = crearEquipos();
    char *opcion1, *opcion2,*opcion3;
    opcion1 = malloc(sizeof(char) * 10);
    opcion2 = malloc(sizeof(char) * 10);
    opcion3 = malloc(sizeof(char) * 10);

    while(1)
    {
        printf("\n----- ATIWORKS -----\n"
               "\nSeleccione una opcion");
        printf("\n1.Colaborador");
        printf("\n2.Equipo");
        printf("\n3.Archivos");
        printf("\n4.Paseo");
        printf("\n5.Bitacora de trabajo");
        printf("\n6.Chat");
        printf("\n7.Análisis de datos");
        printf("\n8.Salir\n");
        printf("Opcion: ");
        gets(opcion1);
        if(strcmp(opcion1, "1") == 0)
        {
            while(1)
            {
                printf("\n-- Menu de Colaboradores --\nMarque la opcion que desea realizar");
                printf("\n1.Registrar un colaborador");
                printf("\n2.Realizar modificaciones sobre la informacion de los colaboradores");
                printf("\n3.Eliminar un colaborador");
                printf("\n4.Consultar los colaboradores registrados");
                printf("\n5.Regresar\n");
                printf("Opcion: ");
                gets(opcion2);
                if(strcmp(opcion2, "1") == 0){
                    obtenerDatosColaborador(Colaboradores);
                }
                else if(strcmp(opcion2, "2") == 0)
                {
                    while(1)
                    {
                        printf("\n---- Tipos de modificaciones ----"
                               "\nIndique el tipo de modificacion que desea realizar");
                        printf("\n1.Modificar el nombre");
                        printf("\n2.Modificar los apellidos");
                        printf("\n3.Modificar el correo");
                        printf("\n4.Modificar el rol dentro de la empresa");
                        printf("\n5.Modificar la fecha de cumpleanos");
                        printf("\n6.Regresar");
                        printf("\nOpcion: ");
                        gets(opcion3);

                        if(strcmp(opcion3, "1") == 0)
                        {
                            modificarNombre(Colaboradores);
                        }

                        else if(strcmp(opcion3, "2") == 0)
                        {
                            modificarApellidos(Colaboradores);
                        }

                        else if(strcmp(opcion3, "3") == 0)
                        {
                            modificarCorreo(Colaboradores);
                        }

                        else if(strcmp(opcion3, "4") == 0)
                        {
                            modificarRol(Colaboradores);
                        }

                        else if(strcmp(opcion3, "5") == 0)
                        {
                            modificarFechaCumple(Colaboradores);
                        }

                        else if(strcmp(opcion3, "6") == 0)
                        {
                            break;
                        }

                        else
                        {
                            printf("\nPor favor indique una de las opciones disponibles.\n");
                        }
                    }
                }
                else if(strcmp(opcion2, "3") == 0){
                    eliminarColaborador(Colaboradores);
                }
                else if(strcmp(opcion2, "4") == 0){
                    consultarColaboradores(Colaboradores);
                }
                else if(strcmp(opcion2, "5") == 0){
                    break;
                }
                else
                {
                    printf("\nPor favor indique una de las opciones disponibles.\n");
                }
            }
        }
        else if(strcmp(opcion1, "2") == 0){
            while(1)
            {
                printf("\n-- Menu de los equipos --\nMarque la opcion que desea realizar");
                printf("\n1.Crear un nuevo equipo de trabajo");
                printf("\n2.Agregar un colaborador a un equipo de trabajo");
                printf("\n3.Consultar todos los equipos de trabajo y sus colaboradores");
                printf("\n4.Regresar\n");
                printf("Opcion: ");
                gets(opcion2);
                if(strcmp(opcion2, "1") == 0){
                    obtenerDatosEquipo(EquipoTrabajo);
                }
                else if(strcmp(opcion2, "2") == 0){
                    insertarMiembro(EquipoTrabajo,Colaboradores);
                }
                else if(strcmp(opcion2, "3") == 0){
                    imprimirLosEquipos(EquipoTrabajo);
                }
                else if(strcmp(opcion2, "4") == 0){
                    break;
                }
                else{
                    printf("\nPor favor indique una de las opciones disponibles.\n");
                }
            }
        }

        else if(strcmp(opcion1, "3") == 0){
            //// Funciones de archivos
        }
        else if(strcmp(opcion1, "4") == 0){
            while(1)
            {
                printf("\n-- Menu del Paseo de fin de año --\nMarque la opcion que desea realizar");
                printf("\n1.Registrar el domicilio de un colaborador");
                printf("\n2.Registrar rutas entre domicilios");
                printf("\n3.Modificar lugares de domicilio");
                printf("\n4.Modificar rutas");
                printf("\n5.Eliminar lugares de domicilio");
                printf("\n6.Eliminar rutas");
                printf("\n7.Imprimir los domicilios y sus rutas");
                printf("\n8.Regresar\n");
                printf("Opcion: ");
                gets(opcion2);
                if(strcmp(opcion2, "1") == 0){
                    //// Funcion que registra la info de un domicilio
                    obtenerDatosDomicilio(Paseo);
                }
                else if(strcmp(opcion2, "2") == 0){
                    //// funcion que registre rutas
                    insertarRuta(Paseo);
                }
                else if(strcmp(opcion2, "3") == 0){
                    while(1){
                        printf("\n-- Menu de modificaciones de lugares de domicilio --\n"
                               "Marque la opcion que desea realizar");
                        printf("\n1.Modificar el codigo del lugar de domicilio");
                        printf("\n2.Modificar el nombre del lugar");
                        printf("\n3.Modificar el codigo postal del lugar de domicilio");
                        printf("\n4.Regresar\n");
                        printf("Opcion: ");
                        gets(opcion3);
                        if(strcmp(opcion3,"1")==0){
                            /// funcion que modifica el codigo
                            modificarCodigo(Paseo);
                        }
                        else if(strcmp(opcion3,"2")==0){
                            /// modificar nombre lugar
                            modificarNombreDomicilio(Paseo);
                        }
                        else if(strcmp(opcion3,"3")==0){
                            /// modificar codigo postal
                            modificarCodigoPostal(Paseo);
                        }
                        else if(strcmp(opcion3,"4")==0){
                            break;
                        }
                        else{
                            printf("\nPor favor indique una de las opciones disponibles.\n");
                        }
                    }
                }
                else if(strcmp(opcion2,"4")==0){
                    while(1){
                        printf("\n-- Menu de modificaciones de las rutas --\n"
                               "Marque la opcion que desea realizar");
                        printf("\n1.Modificar el tiempo de la ruta");
                        printf("\n2.Modificar la distancia de la ruta");
                        printf("\n3.Regresar\n");
                        printf("Opcion: ");
                        gets(opcion3);
                        if(strcmp(opcion3,"1")==0){
                            /// funcion que modifica el tiempo
                            modificarTiempoRuta(Paseo);
                        }
                        else if(strcmp(opcion3,"2")==0){
                            /// modificar la distancia
                            modificarDistanciaRuta(Paseo);
                        }

                        else if(strcmp(opcion3,"3")==0){
                            break;
                        }
                        else{
                            printf("\nPor favor indique una de las opciones disponibles.\n");
                        }
                    }
                }
                else if(strcmp(opcion2,"5")==0){
                    /// funcion que elimina un domicilio
                    eliminarDomicilio(Paseo);
                }
                else if(strcmp(opcion2,"6")==0){
                    /// funcion que elimina una ruta
                    eliminarRuta(Paseo);
                }
                else if(strcmp(opcion2,"7")==0){
                    /// funcion imprime el domicilio
                    imprimirRutas(Paseo);
                }
                else if(strcmp(opcion2,"8") == 0){
                    break;
                }
                else{
                    printf("Por favor indique una de las opciones disponibles.\n");
                }
            }
        }
        else if(strcmp(opcion1, "5") == 0){
            while(1)
            {
                printf("\n-- Menu la bitacora --\nMarque la opcion que desea realizar");
                printf("\n1.Realizar una observacion sobre el rendimiento de un colaborador");
                printf("\n2.Consultar las observaciones de un colaborador");
                printf("\n3.Regresar\n");
                printf("Opcion: ");
                gets(opcion2);
                if(strcmp(opcion2, "1") == 0){
                    obtenerDatosBitacora(Bitacora,Colaboradores);
                }
                else if(strcmp(opcion2, "2") == 0){
                    revisarRendimiento(Bitacora,Colaboradores);
                }
                else if(strcmp(opcion2, "3") == 0){
                    break;
                }
                else{
                    printf("\nPor favor indique una de las opciones disponibles.\n");
                }
            }
        }
        else if(strcmp(opcion1, "6") == 0){

        }
        else if(strcmp(opcion1, "7") == 0){
            while(1)
            {
                printf("\n-- Análisis de datos --\nMarque la opcion que desea realizar");
                printf("\n1.Cantidad de mensajes enviados");
                printf("\n2.Cantidad de archivos en total");
                printf("\n3.Cantidad de archivos en promedio");
                printf("\n4.Promedio de colaboradores por equipo");
                printf("\n5.Top 5 de equipos con mayor cantidad de colaboradores");
                printf("\n6.Promedio de rutas por domicilios");
                printf("\n7.Regresar\n");
                printf("Opcion: ");
                gets(opcion2);
                if(strcmp(opcion2, "1") == 0){

                }
                else if(strcmp(opcion2, "2") == 0){

                }
                else if(strcmp(opcion2, "3") == 0){

                }
                else if(strcmp(opcion2, "4") == 0){
                    promedioDeColaboradores(EquipoTrabajo);
                }
                else if(strcmp(opcion2, "5") == 0){

                }
                else if(strcmp(opcion2, "6") == 0){
                    promedioDeRutasPorDomicilio(Paseo);
                }
                else if(strcmp(opcion2, "7") == 0){
                    break;
                }
                else{
                    printf("\nPor favor indique una de las opciones disponibles.\n");
                }
            }
        }
        else if(strcmp(opcion1, "8") == 0){
            break;
        }
        else
        {
            printf("Por favor indique una de las opciones disponibles.\n");
        }
    }
}

