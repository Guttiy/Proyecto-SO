#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include <unistd.h>
#include <ctype.h>

     
struct dogType {
	char Nombre[32];
	char Tipo[32];
	int Edad;
        char Raza[16];
        int Estatura;
	float Peso;
        char Sexo[1];
        struct dogType *next;
};

int main()
{
	srand(time(NULL));//Para generar numeros aleatorios
	int cont = 0,t,w,i;
	float f;
	size_t r;

	struct dogType *datos;
	datos = malloc(sizeof(struct dogType));
	if(datos==NULL){//errores	
		perror("Error al reservar memoria: ");	
		exit(-1);
	}
	struct dogType *dog;
	dog = datos;

	char *nom, *tip, *raz, *sex;
	nom = malloc(sizeof(nom));
	if(nom==NULL){//errores	
		perror("Error al reservar memoria: ");	
		exit(-1);
	}
	tip = malloc(sizeof(tip));
	if(tip==NULL){//errores	
		perror("Error al reservar memoria: ");	
		exit(-1);
	}
	raz = malloc(sizeof(raz));
	if(raz==NULL){//errores	
		perror("Error al reservar memoria: ");	
		exit(-1);
	}
	sex = malloc(sizeof(sex));
	if(sex==NULL){//errores	
		perror("Error al reservar memoria: ");	
		exit(-1);
	}

	FILE *nombre = fopen("nombresMascotas.txt", "r");
	if(nombre == NULL){//se validan errores
		perror("No se pudo abrir el archivo:");
	}
	FILE *tipo = fopen("tipo.txt", "r");
	if(nombre == NULL){//se validan errores
		perror("No se pudo abrir el archivo:");
	}
	FILE *raza = fopen("raza.txt", "r");
	if(raza == NULL){//se validan errores
		perror("No se pudo abrir el archivo:");
	}
	FILE *sexo = fopen("sexo.txt", "r");
	if(sexo == NULL){//se validan errores
		perror("No se pudo abrir el archivo:");
	}
	FILE *archivo = fopen("dataDogs.dat", "a+");
	if(archivo == NULL){//se validan errores
		perror("No se pudo abrir el archivo:");
	}

	//Generar los 10 millones de registros
	for(int j=1;j<=10000000;j++){
		//Pararse al inicio de cada archivo
		rewind(nombre);
		rewind(tipo);
		rewind(raza);
		rewind(sexo);

		//Escoger un nombre aleatorio
		cont = 0;
		t=rand()%1718;
		while(!feof(nombre)){
			fgets(nom, 50, nombre);
			if(nom==NULL){//errores
				perror("Error al leer linea: ");
				exit(-1);
			}
			cont++;
			if(cont == t)
			break;
		}
		nom[strlen(nom)-1] = '\0';//Quitar el ultimo caracter que es el de salto de linea "\n"

		strcpy(dog->Nombre, nom);//Guardar el nombre obtenido en la estructura
		
		//Escoger un tipo aleatorio
		cont = 0;
		t=rand()%7;
		while(!feof(tipo)){
			fgets(tip, 50, tipo);
			if(tip==NULL){//errores
				perror("Error al leer linea: ");
				exit(-1);
			}
			cont++;
			if(cont == t)
			break;
		}
		tip[strlen(tip)-1] = '\0';//Quitar el ultimo caracter que es el de salto de linea "\n"

		strcpy(dog->Tipo, tip);//Guardar el tipo obtenido en la estructura

		//Escoger una edad aleatoria
		t=rand()%21 + 1;
		dog->Edad = t;//Guardar la edad obtenida en la estructura

		//Escoger una raza aleatoria
		cont = 0;
		t=rand()%113;
		while(!feof(raza)){
			fgets(raz, 50, raza);
			if(raz==NULL){//errores
				perror("Error al leer linea: ");
				exit(-1);
			}
			cont++;
			if(cont == t)
			break;
		}
		raz[strlen(raz)-1] = '\0';//Quitar el ultimo caracter que es el de salto de linea "\n" 
		for(i = 0; raz[i]; i++) 
			raz[i] = toupper(raz[i]);//Cambia el texto a Mayusculas
		strcpy(dog->Raza, raz);//Guardar la raza obtenida en la estructura

		//Escoger una estatura aleatoria
		t=rand()%62 + 1;
		dog->Estatura = t;//Guardar la estatura obtenida en la estructura

		//Escoger un peso aleatorio
		f=((float)rand()/(float)(RAND_MAX))*90;
		dog->Peso = f;//Guardar el peso obtenido en la estructura

		//Escoger un sexo aleatorio
		cont = 0;
		t=rand()%2;
		while(!feof(sexo)){
			fgets(sex, 7, sexo);
			if(sex==NULL){//errores
				perror("Error al leer linea: ");
				exit(-1);
			}
			cont++;
			if(cont == t)
			break;
		}
		sex[strlen(sex)-1] = '\0';//Quitar el ultimo caracter que es el de salto de linea "\n" 
		strcpy(dog->Sexo, sex);//Guardar el sexo obtenido en la estructura

		//Escribir la estructura completa en el archivo .dat
		r = fwrite(datos, 1, sizeof(struct dogType), archivo);
		if(r == 0){//se validan errores
			perror("Error al escribir el archivo:");		
		}
	}
	w = fclose(nombre);
	if (w!=0){//se validan errores
		perror("No se pudo cerrar el archivo:");
	}
	w = fclose(raza);
	if (w!=0){//se validan errores
		perror("No se pudo cerrar el archivo:");
	}
	w = fclose(archivo);
	if (w!=0){//se validan errores
		perror("No se pudo cerrar el archivo:");
	}
	free(datos);
	free(nom);
	free(tip);
	free(raz);
	free(sex);
}
     
