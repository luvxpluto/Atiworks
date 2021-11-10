#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

///// Colaboradores /////
typedef struct nodoColab nodoColab;
typedef struct colaborador colab;
typedef struct ListaColab ListaColab;

//// Bitacora /////
typedef struct nodoRendi nodoRendi;
typedef struct rendimiento rendi;
typedef struct ListaBitacora ListaBitacora;


//// Estructuras

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
        printf("Indique la fecha de cumpleanos del colaborador (dia/mes): ");
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
            printf("Por favor ingrese un .\n");
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
            printf("El colaborador con la cedula %s, en la fecha %s, recibio el siguiente comentario acerca de su rendimiento en la empresa:\n",i->rendimiento.cedula,i->rendimiento.fecha);
            printf("%s\n", i->rendimiento.comentario);
        }
        else if(i->siguiente==NULL){
            printf("\nEl colaborador no tiene comentarios acerca de su rendimiento\n");
        }
    }
}


int main(){
    ListaColab *Colaboradores;
    ListaBitacora *Bitacora;
    Colaboradores = listaNuevaColaboradores();
    Bitacora = listaNuevaBitacora();
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
        printf("\n6.Análisis de datos");
        printf("\n7.Salir\n");
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
            //// Registrar equipo
        }

        else if(strcmp(opcion1, "3") == 0){
            //// Funciones de archivos
        }
        else if(strcmp(opcion1, "4") == 0){
            while(1)
            {
                printf("\n-- Menu del Paseo de fin de año --\nMarque la opcion que desea realizar");
                printf("\n1.Registrar el domicilio de un colaborador");
                printf("\n2.Simular la ruta de paseo");
                printf("\n3.Regresar\n");
                printf("Opcion: ");
                gets(opcion2);
                if(strcmp(opcion2, "1") == 0){
                    //// Funcion que registre la info de las rutas
                }
                else if(strcmp(opcion2, "2") == 0){
                    //// funcion que simule el viaje
                }
                else if(strcmp(opcion2, "3") == 0){
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
            break;
        }
        else
        {
            printf("Por favor indique una de las opciones disponibles.\n");
        }

    }
}