#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#define max 100000

/* Estructuras y tipos */
typedef struct directorio directorio;
typedef struct archivo archivo;
archivo *nuevoArchivo(char nombre[max]);

//// Directorios ////
struct directorio {
   char nombre[max];
   char origen[max];
   archivo *archivos;
   directorio *derecha;
   directorio *izquierda;
};

//// Archivos ////
struct archivo {
   char nombre[max];
   archivo *derecha;
   archivo *izquierda;
};

////////////////////// FUNCIONES RELACIONADAS CON LOS Archivos ////////////////////// 
/// Función que crea un nuevo directorio
/*
 * Entradas: nombre y origen del directorio
 * Salidas: un nodo de tipo directorio
 * Restricciones: nombre y origen son de tipo char
 */
directorio *nuevoDirectorio(char nombre[max], char origen[max])
{
    // solicitar memoria
    directorio *nuevo = (directorio *)malloc(sizeof(directorio));
    // asignar el dato e iniciar hojas
    strcpy(nuevo->nombre,nombre);
    strcpy(nuevo->origen,origen);
    nuevo->archivos = nuevoArchivo(" ");
    nuevo->izquierda = nuevo->derecha = NULL;
    return nuevo;
}

/// Función que agrega un directorio a un árbol de directorios
/* 
 * Entradas: directorios, nombre y origen
 * Salidas: un directorio agregado al árbol de directorios
 * Restricciones: directorios es de tipo directorio, nombre y origen son de tipo char
 */
void mkdir(directorio *directorios, char *nombre, char *origen)
{
	if(directorios == NULL)
	{
		directorios = nuevoDirectorio(nombre, origen);
	}
    else if (strcmp(nombre, directorios->nombre) > 0)
    {
        if (directorios->derecha == NULL)
        {
            directorios->derecha = nuevoDirectorio(nombre, origen);
        }
        else
        {
            mkdir(directorios->derecha, nombre, origen);
        }
    }
    else
    {
        if (directorios->izquierda == NULL)
        {
            directorios->izquierda = nuevoDirectorio(nombre, origen);
        }
        else
        {
            mkdir(directorios->izquierda, nombre, origen);
        }
    }
}

/// Función que crea un archivo txt
/*
 * Entradas: nombre y texto
 * Salidas: un nuevo archivo txt
 * Restricciones: nombre y texto son de tipo char
 */
void crearArchivo_txt(char *nombre, char *texto){
    FILE *archivo;
    char name[max];
    strcpy(name,nombre);
    archivo = fopen(strcat(name,".txt"),"w");
    fprintf(archivo, "%s", texto);
    fclose(archivo);
}

/// Función que muestra un archivo txt
/* 
 * Entradas: nombre
 * Salidas: imprime en pantalla el contenido del txt
 * Restricciones: nombre es de tipo nombre
 */
void verArchivo(char *nombre){
	FILE *archivo;
	char texto[max];
	char name[max];
    strcpy(name,nombre);
    archivo = fopen(strcat(name,".txt"),"r");
	
	if(archivo == NULL)
	  exit(1);
	  
	else
	{
		while(feof(archivo) == 0)
		{
			fgets(texto,max,archivo);
			printf("%s\n",texto);
		}
	}
	fclose(archivo);
}

/// Función que crea un nuevo archivo
/* 
 * Entradas: nombre
 * Salidas: un nodo de tipo archivo
 * Restricciones: nombre es de tipo char
 */
archivo *nuevoArchivo(char nombre[max])
{
    // solicitar memoria
    archivo *nuevo = (archivo *)malloc(sizeof(archivo));
    // asignar el dato e iniciar hojas
    strcpy(nuevo->nombre,nombre);
    nuevo->izquierda = nuevo->derecha = NULL;
    return nuevo;
}

/// Función que agrega un archivo al árbol de archivos
/* 
 * Entradas: archivos y nombre
 * Salidas: el nuevo archvo agregado al árbol de archivos
 * Restricciones: archivos es de tipo archivo y nombre de tipo char
 */
void call(archivo *archivos, char *nombre)
{
	if(strcpy(archivos->nombre," "))
	{
		strcpy(archivos->nombre, nombre);
	}
    else if (strcmp(nombre, archivos->nombre) > 0)
    {
        if (archivos->derecha == NULL)
        {
            archivos->derecha = nuevoArchivo(nombre);
        }
        else
        {
            call(archivos->derecha, nombre);
        }
    }
    else
    {
        if (archivos->izquierda == NULL)
        {
            archivos->izquierda = nuevoArchivo(nombre);
        }
        else
        {
            call(archivos->izquierda, nombre);
        }
    }
}

/// Función que imprime los directorios del árbol de directorios
/* 
 * Entradas: árbol de directorios
 * Salidas: imprime en la pantalla los directorios de árbol de directorios
 * Restricciones: directorios es de tipo directorio
 */
void imprimirDirectorios(directorio *directorios)
{
    if (directorios != NULL)
    {
        imprimirDirectorios(directorios->izquierda);
        printf("Nombre del directorio: %s\n", directorios->nombre);
        imprimirDirectorios(directorios->derecha);
    }
}

/// Función que 
/* 
 * Entradas: árbol de archivos
 * Salidas: imprime en la pantalla los archivos del árbol de archivos
 * Restricciones: archivos es de tipo archivo
 */
void imprimirArchivos(archivo *archivos)
{
    if (archivos != NULL)
    {
        imprimirArchivos(archivos->izquierda);
        if(strcmp(archivos->nombre, " ") != 0)
        {
        	printf("Archivo: %s\n", archivos->nombre);
		}
        imprimirArchivos(archivos->derecha);
    }
}

/// Función que imprime todos los archivos y directorios de un árbol
/* 
 * Entradas: directorios
 * Salidas: imprime en pantalla todos los archivos y diectorios del árbol de directorios
 * Restricciones: directorios es de tipo directorio
 */
void tree(directorio *directorios)
{
    if (directorios != NULL)
    {
        tree(directorios->izquierda);
        printf("Directorio: %s\n", directorios->nombre);
        imprimirArchivos(directorios->archivos);
        tree(directorios->derecha);
    }
}

/// Función que muestra los subdirectorios de un directorio
/* Entradas: directorios, origen
 * Salidas: imprime en pantalla los subdirrectorios de un directorio
 * Restricciones: diectorios es de tipo directorio y origen es de tipo char 
 */
void subDir(directorio *directorios, char *origen)
{
    if (directorios != NULL)
    {
        subDir(directorios->izquierda, origen);
        if(strcmp(directorios->nombre, origen) != 0 && strcmp(directorios->origen, origen) == 0)
        {
        	printf("\nDirectorio: %s", directorios->nombre);
		}
        subDir(directorios->derecha, origen);
    }
}

/// Función que muestra todos los subdirectorios y archivos de un directorio
/* Entradas: directorios y origen
 * Salidas: imprime en pantalla todos los subdirectorios y archivos de un directorio
 * Restricciones: directorios es de tipo cdirectorio y origen de tipo char
 */
void dir(directorio *directorios, char *origen)
{
	printf("\n\nSubdirectrios de la carpeta %s:", origen);
    subDir(directorios,origen);
    printf("\n\nArchivos de la carpeta %s:", origen);
	imprimirArchivos(directorios->archivos);
}

/// Función que renombre un directorio
/* Entradas: directorios, origen, nombre y nuevo
 * Salidas: el directorio con un nuevo nombre
 * Restricciones: directorios es de tipo directorio, origen, nombre y nuevo son de tipo char
 */
void renombrarDrirectorio(directorio *directorios, char *origen, char *nombre, char *nuevo)
{
	if (directorios != NULL)
    {
        renombrarDrirectorio(directorios->izquierda, origen, nombre, nuevo);
        if(strcmp(directorios->origen, origen) == 0 && strcmp(directorios->nombre, nombre) == 0)
        {
        	strcpy(directorios->nombre, nuevo);
		}
		else if(strcmp(directorios->origen, origen) == 0)
        {
        	strcpy(directorios->origen, nuevo);
		}
        renombrarDrirectorio(directorios->derecha, origen, nombre, nuevo);
	}
}

/// Función que renombra un archivo
/* Entradas: archivos, nombre y nuevo
 * Salidas: un archivo con un nuevo nombre
 * Restricciones: archivos es de tipo archivo, nombre y nuevo son de tipo char 
 */
void renombrarArchivo(archivo *archivos, char *nombre, char *nuevo)
{
	if (archivos != NULL)
    {
        renombrarArchivo(archivos->izquierda, nombre, nuevo);
        if(strcmp(archivos->nombre, nombre) == 0)
        {
        	char a[max], b[max];
        	strcpy(a, nombre), strcpy(b, nuevo);
			//strcat(nombre,".txt") strcat(nuevo,".txt");
        	strcpy(archivos->nombre, nuevo);
        	rename(strcat(a,".txt"),strcat(b,".txt"));
        	return;
		}
        renombrarArchivo(archivos->derecha, nombre, nuevo);
	}
}

/// Función que copia un archivo de un directorio a otro
/* Entradas: directorios, directorio y archivo
 * Salidas: el archivo copiado en el directorio
 * Restricciones: directorio es de tipo directorio, directorio y archivo son de tipo archivo 
 */
void copy(directorio *directorios, char *directorio, char *archivo)
{
	if (directorios != NULL)
    {
        copy(directorios->izquierda, directorio, archivo);
        if(strcmp(directorios->nombre, directorio) == 0)
        {
        	call(directorios->archivos, archivo);
        	return;
		}
        copy(directorios->derecha, directorio, archivo);
	}
}

/// Función que identifica el último directorio del lado izquierdo del árbol de directorios
/* Entradas: directorios
 * Salidas: el nodo del último directorio al lado izquiero del árbol de archivos
 * Restricciones: directorios es de tipo directorio
 */
directorio* ultimoDirectorio(directorio* directorios)
{
	directorio* current = directorios;

	while (current && current->izquierda != NULL)
		current = current->izquierda;

	return current;
}

/// Función que elimina un directorio
/* Entradas: directorios y nombre
 * Salidas: el directorio eliminado
 * Restricciones: directorios es de tipo directorios y nombre de tipo char
 */
directorio *rmdir(directorio* directorios, char *nombre)
{
	if (directorios == NULL)
		return directorios;

	if (strcmp(nombre,directorios->nombre) < 0)
		directorios->izquierda = rmdir(directorios->izquierda, nombre);

	else if (strcmp(nombre,directorios->nombre) > 0)
		directorios->derecha = rmdir(directorios->derecha, nombre);

	else {
		if (directorios->izquierda == NULL) {
			directorio* temp = directorios->derecha;
			free(directorios);
			return temp;
		}
		else if (directorios->derecha == NULL) {
			directorio* temp = directorios->izquierda;
			free(directorios);
			return temp;
		}

		directorio* temp = ultimoDirectorio(directorios->derecha);

		strcpy(directorios->nombre,temp->nombre);

		directorios->derecha = rmdir(directorios->derecha, temp->nombre);
	}
	return directorios;
}

/// Función que borra los subdirectorios de un directorio
/* Entradas: directorios y origen
 * Salidas: el subdirectorio eliminado
 * Restricciones: directorios es de tipo directorios y origen de tipo char 
 */
void borrarSubDirectorios(directorio *directorios, char *origen)
{
    if (directorios != NULL)
    {
        borrarSubDirectorios(directorios->izquierda, origen);
        if(strcmp(directorios->origen, origen) == 0)
        {
        	directorios = rmdir(directorios, directorios->nombre);
		}
        borrarSubDirectorios(directorios->derecha, origen);
    }
}

/// Función que identifica el último archivo del lado izquierdo del árbol de archivos
/* Entradas: archivos
 * Salidas: el nodo del último archivo del lado izquierdo del árbol de archivos
 * Restricciones: archivos es de tipo archivo
 */
archivo* ultimoArchivo(archivo* archivos)
{
	archivo* current = archivos;

	while (current && current->izquierda != NULL)
		current = current->izquierda;

	return current;
}

/// Función que elimina un archivo
/* Entradas: archivos y nombre
 * Salidas: el archivo eliminado
 * Restricciones: archivos es de tipo archivo y nombre de tipo char 
 */
archivo *rmfile(archivo* archivos, char *nombre)
{
	if (archivos == NULL)
		return archivos;

	if (strcmp(nombre,archivos->nombre) < 0)
		archivos->izquierda = rmfile(archivos->izquierda, nombre);

	else if (strcmp(nombre,archivos->nombre) > 0)
		archivos->derecha = rmfile(archivos->derecha, nombre);

	else {
		if (archivos->izquierda == NULL) {
			archivo* temp = archivos->derecha;
			remove(strcat(archivos->nombre,".txt"));
			free(archivos);
			return temp;
		}
		else if (archivos->derecha == NULL) {
			archivo* temp = archivos->izquierda;
			remove(strcat(archivos->nombre,".txt"));
			free(archivos);
			return temp;
		}

		archivo* temp = ultimoArchivo(archivos->derecha);

		strcpy(archivos->nombre,temp->nombre);

		archivos->derecha = rmfile(archivos->derecha, temp->nombre);
	}
	return archivos;
}

/// Función que mueve un archivo
/* Entradas: directorios, directorio y archivo
 * Salidas: el archivo movido
 * Restricciones: directorios de tipo directorio, directoro y archivo de tipo char 
 */
void move(directorio *directorios, char *directorio, char *archivo)
{
	if (directorios != NULL)
    {
        move(directorios->izquierda, directorio, archivo);
        if(strcmp(directorios->nombre, directorio) == 0)
        {
        	copy(directorios, directorio, archivo);
        	rmfile(directorios->archivos, archivo);
        	return;
		}
        move(directorios->derecha, directorio, archivo);
	}
}

/// Función que mueve un directorio
/* Entradas: directorios y directorio
 * Salidas: el directorio movido 
 * Restricciones: directorios es de tipo directorios y directorio es de tipo char 
 */
void mvdir(directorio *directorios, char *directorio)
{
	if (directorios != NULL)
    {
        mvdir(directorios->izquierda, directorio);
        if(strcmp(directorios->nombre, directorio) == 0)
        {
        	strcpy(directorios->nombre,directorio);
		}
		if(strcmp(directorios->origen, directorio) == 0)
        {
        	strcpy(directorios->origen,directorio);
		}
        mvdir(directorios->derecha, directorio);
	}
}

void cantidadDirectorios(directorio *reco,int *cant){
    if (reco != NULL)
    {
        (*cant)++;
        cantidadDirectorios(reco->izquierda, cant);
        cantidadDirectorios(reco->derecha, cant);
    }
}

int existeDirectorio(directorio *directorios, char *nombre)
{
    if (directorios != NULL)
    {
        existeDirectorio(directorios->izquierda, nombre);
        if(strcmp(directorios->nombre,nombre) == 0)
        {
        	return 1;
		}
        existeDirectorio(directorios->derecha, nombre);
    }
}

int existeArchivo(archivo *archivos, char *nombre)
{
    if (archivos != NULL)
    {
        existeArchivo(archivos->izquierda, nombre);
        if(strcmp(archivos->nombre,nombre) == 0)
        {
        	return 1;
		}
        existeArchivo(archivos->derecha, nombre);
    }
}

void crearDirectorio(directorio *directorios, char *directorio)
{
	char nombre[max];
    printf("\nEscriba el nombre del nuevo directorio: ");
    gets(nombre);
    
	mkdir(directorios, nombre , directorio);
	printf("\n");
}

void crearArchivo(archivo *archivos)
{
	char nombre[max];
    printf("\nEscriba el nombre del nuevo archivo: ");
    gets(nombre);
    
    if(strlen(nombre) == 0)
    {
    	printf("Error: Debe ingresar un nombre");
    	return;
	}
    
    char texto[max];
    printf("Escriba el texto del archivo: ");
    gets(texto);
    
    crearArchivo_txt(nombre,texto);
    call(archivos,nombre);
    printf("\n");
}

void copiarArchivo(directorio *directorios)
{
	char nombre[max];
    printf("\nEscriba el nombre del archivo: ");
    gets(nombre);
    
    if(existeArchivo(directorios->archivos,nombre) == 0)
    {
    	printf("Error: El archivo no existe en el directorio actual.");
    	return;
	}
    char directorio[max];
    printf("Escriba el nombre del directorio al que desea copiar el archivo: ");
    gets(directorio);
    
    
    if(existeDirectorio(directorios, directorio) == 0)
    {
    	printf("Error: El directorio no existe.");
    	return;
	}

    copy(directorios, directorio, nombre);
    printf("\n");
}

void toLower(char *cadena)
{
	int i;
	
	for(i = 0; i < strlen(cadena); i++)
	{
		cadena[i] = tolower(cadena[i]);
	}
}

int existeSubDirectorio(directorio *directorios, char *origen)
{
    if (directorios != NULL)
    {
        existeSubDirectorio(directorios->izquierda, origen);
        if(strcmp(directorios->origen,origen) == 0)
        {
        	return 1;
		}
        existeSubDirectorio(directorios->derecha, origen);
    }
}

void moverDirectorio(directorio *directorios, char *actual)
{
	printf("Los directorios que se encuentran en el directorio actual son los suiguientes: ");
	subDir(directorios,actual);
	
	char nombre[max];
    printf("\nEscriba el nombre del diectorio que desea mover: ");
    gets(nombre);
    
    if(existeSubDirectorio(directorios,nombre) == 0)
    {
    	printf("\nError: El directorio no existe en el directorio actual.\n");
    	return;
	}
	
    char directorio[max];
    printf("Escriba el nombre del directorio al que desea mover el directorio: ");
    gets(directorio);
    
     if(existeDirectorio(directorios,directorio) == 0)
    {
    	printf("\nError: El directorio no existe en el directorio actual.\n");
    	return;
	}
	
	mvdir(directorios, directorio);
	printf("\n");
}

void moverArchivo(directorio *directorios)
{
	char nombre[max];
    printf("\nEscriba el nombre del archivo: ");
    gets(nombre);
    
    if(existeArchivo(directorios->archivos,nombre) == 0)
    {
    	printf("Error: El archivo no existe en el directorio actual.");
    	return;
	}
    char directorio[max];
    printf("Escriba el nombre del directorio al que desea mover el archivo: ");
    gets(directorio);
    
    
    if(existeDirectorio(directorios, directorio) == 0)
    {
    	printf("Error: El directorio no existe.");
    	return;
	}

    move(directorios, directorio, nombre);
    printf("\n");
}

void eliminarDirectorio(directorio *directorios, char *actual)
{
	printf("Los directorios que se encuentran en el directorio actual son los suiguientes: ");
	subDir(directorios,actual);
	
	char nombre[max];
    printf("\nEscriba el nombre del diectorio que desea eliminar: ");
    gets(nombre);
    
    if(existeSubDirectorio(directorios,nombre) == 0)
    {
    	printf("\nError: El directorio no existe en el directorio actual.\n");
    	return;
	}
	
	rmdir(directorios, nombre);
	borrarSubDirectorios(directorios, nombre);
	printf("\n");
}

void eliminarrArchivo(directorio *directorios)
{
	char nombre[max];
    printf("\nEscriba el nombre del archivo: ");
    gets(nombre);
    
    if(existeArchivo(directorios->archivos,nombre) == 0)
    {
    	printf("Error: El archivo no existe en el directorio actual.");
    	return;
	}

    rmfile(directorios->archivos, nombre);
    printf("\n");
}

void renombrar(directorio *directorios, char *actual)
{
	dir(directorios, actual);
	char opcion[max];
	printf("\nIndique 1 para renombrar un archivo\n Indique 2 para renombrar directorio\nOpcion: ");
	gets(opcion);
	
	if(strcmp(opcion,"1") == 0)
	{
		printf("\nLos archivos disponibles son:\n");
		imprimirArchivos(directorios->archivos);
		
		char nombre[max];
	    printf("\nEscriba el nombre del archivo que desea renombrar: ");
	    gets(nombre);
	    
	    if(existeArchivo(directorios->archivos,nombre) == 0)
	    {
	    	printf("\nError: El archivo no existe en el directorio actual.\n");
	    	return;
		}
		
		char nuevo[max];
	    printf("\nEscriba el nuevo nombre del archivo: ");
	    gets(nuevo);
	    
		renombrarArchivo(directorios->archivos,nombre,nuevo);
	}
	else if(strcmp(opcion,"1") == 0)
	{
		printf("\nLos directorios disponibles son:\n");
		subDir(directorios, actual);
		
		char nombre[max];
	    printf("\nEscriba el nombre del directorio que desea renombrar: ");
	    gets(nombre);
	    
	    if(existeDirectorio(directorios,nombre) == 0)
	    {
	    	printf("\nError: El directorio no existe en el directorio actual.\n");
	    	return;
		}
		
		char nuevo[max];
	    printf("\nEscriba el nuevo nombre del directorio: ");
	    gets(nuevo);
	    
	    renombrarDrirectorio(directorios,actual,nombre,nuevo);
	}
	else
	{
		printf("Error: La opcion seleccionada es incorrecta.");
		return;
	}
	
}

void cd(directorio *directorios, char *nuevo)
{
	if (directorios != NULL)
    {
        cd(directorios->izquierda, nuevo);
        if(strcmp(directorios->nombre,nuevo) == 0)
        {
        	printf("El arbol de archivos es el siguiente:\n");
			dir(directorios,nuevo);
			char comando[max];
			
			
			
			printf("\nLos comandos disponibles son los siguientes:\n*    Cd: mueve la posicion actual a la carpeta seleccionada por el usuario.\n*    Mkdir: Crea un directorio nuevo.\n"
			"*    Copy: Realiza la copia de un archivo en otro directorio.\n*    Mvdir: Mueve un directorio completo a otro lugar.\n*    Move: Mueve un archivo de un directorio a otro.\n"
			"*    Rmdir: Elimina un directorio y todos los archivos contenidos en el.\n*    Tree: Despliega el arbol de archivos en consola.\n*    Dir: Despliega todos los hijos del directorio actual.\n"
			"*    Rmfile: Elimina un archivo.\n*    Rename: Cambia el nombre de un archivo o directorio.\n*    Call: Crea un nuevo archivo de texto y lo ingresa al arbol de archivos.\n*    Exit: regresa al menu principal");
			
			printf("\nIngrese el comando que desea ejecutar: ");
			gets(comando);
			toLower(comando);
			if(strcmp(comando, "cd") == 0) 
			{
				char nombre[max];
			    printf("\nEscriba el nombre del diectorio al que desea ir: ");
			    gets(nombre);
    
				if(existeSubDirectorio(directorios,nombre) == 0)
			    {
			    	printf("\nError: El directorio no existe en el directorio actual.\n");
			    	return;
				}
				cd(directorios, nombre);
				
			}
			else if(strcmp(comando, "mkdir") == 0) 
			{
				crearDirectorio(directorios, nuevo);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "copy") == 0) 
			{
				copiarArchivo(directorios);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "mvdir") == 0) 
			{
				moverDirectorio(directorios, nuevo);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "move") == 0) 
			{
				moverArchivo(directorios);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "rmdir") == 0) 
			{
				eliminarDirectorio(directorios, nuevo);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "tree") == 0) 
			{
				printf("El arbol de archivos es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "dir") == 0) 
			{
				printf("Los archivos y directorios del directorio actual son los siguientes:\n");
				dir(directorios, nuevo);
			}
			else if(strcmp(comando, "rmfile") == 0) 
			{
				eliminarrArchivo(directorios);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "rename") == 0) 
			{
				renombrar(directorios, nuevo);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "call") == 0) 
			{
				crearArchivo(directorios->archivos);
				printf("El arbol de archivos actualizado es el siguiente:\n");
				tree(directorios);
			}
			else if(strcmp(comando, "exit") == 0) 
			{
				return;   
			}
			else
			{
				printf("\nError: Comando invalido.\n");
				return;
			}
		}
        cd(directorios->derecha, nuevo);
    }
}

void operacionesDeArchivos(directorio *directorios)
{
	printf("El arbol de archivos es el siguiente:\n");
	tree(directorios);
	char comando[max];
	
	printf("\nLos comandos disponibles son los siguientes:\n*    Cd: mueve la posicion actual a la carpeta seleccionada por el usuario.\n*    Mkdir: Crea un directorio nuevo.\n"
	"*    Copy: Realiza la copia de un archivo en otro directorio.\n*    Mvdir: Mueve un directorio completo a otro lugar.\n*    Move: Mueve un archivo de un directorio a otro.\n"
	"*    Rmdir: Elimina un directorio y todos los archivos contenidos en el.\n*    Tree: Despliega el arbol de archivos en consola.\n*    Dir: Despliega todos los hijos del directorio actual.\n"
	"*    Rmfile: Elimina un archivo.\n*    Rename: Cambia el nombre de un archivo o directorio.\n*    Call: Crea un nuevo archivo de texto y lo ingresa al arbol de archivos.\n*    Exit: regresa al menu principal");
	
	printf("\nIngrese el comando que desea ejecutar: ");
	gets(comando);
	toLower(comando);
	if(strcmp(comando, "cd") == 0) 
	{
		char nombre[max];
	    printf("\nEscriba el nombre del diectorio al que desea ir: ");
	    gets(nombre);

		if(existeSubDirectorio(directorios,nombre) == 0)
	    {
	    	printf("\nError: El directorio no existe en el directorio actual.\n");
	    	return;
		}
		cd(directorios, nombre);
	}
	else if(strcmp(comando, "mkdir") == 0) 
	{
		crearDirectorio(directorios, "main");
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "copy") == 0) 
	{
		copiarArchivo(directorios);
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "mvdir") == 0) 
	{
		moverDirectorio(directorios, "main");
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "move") == 0) 
	{
		moverArchivo(directorios);
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "rmdir") == 0) 
	{
		eliminarDirectorio(directorios, "main");
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "tree") == 0) 
	{
		tree(directorios);
	}
	else if(strcmp(comando, "dir") == 0) 
	{
		dir(directorios, "main");
	}
	else if(strcmp(comando, "rmfile") == 0) 
	{
		eliminarrArchivo(directorios);
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "rename") == 0) 
	{
		renombrar(directorios, "main");
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "call") == 0) 
	{
		crearArchivo(directorios->archivos);
		printf("El arbol de archivos actualizado es el siguiente:\n");
		tree(directorios);
	}
	else if(strcmp(comando, "exit") == 0) 
	{
		return;   
	}
	else
	{
		printf("\nError: Comando invalido.\n");
		return;
	}
	
}

void main(){
	
	directorio *directorios = nuevoDirectorio("main", "main");
	operacionesDeArchivos(directorios);
}

