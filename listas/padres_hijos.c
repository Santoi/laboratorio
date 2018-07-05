#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct persona {
	struct persona * siguiente;
	char nombre [20];
	char antecesor [20];
} persona_t;


persona_t * buscar_hijos (char nombre_padre [], persona_t * hijos, size_t posicion);
void concatenar (persona_t ** lista1, persona_t * lista2);
void crear_nueva_lista (persona_t * padres, persona_t * hijos, persona_t ** nueva_lista);
void ins_recur (persona_t ** lista, char nombre[], char antecesor []);
persona_t * crear_lista (void);
void imprimir_lista (persona_t * lista);
void enganchar (persona_t ** padres, persona_t * hijos);
void liberar (persona_t **lista) ;


int main (void) {
	persona_t * padres, * hijos;
	puts("Insertar para lista de padres");
	padres = crear_lista();
	puts("Insertar para lista de hijos");
	hijos = crear_lista();
	enganchar(&padres, hijos);
	puts("Lista final");
	imprimir_lista(padres);
	return 0;
}


void enganchar (persona_t ** padres, persona_t * hijos) {
	persona_t * nueva_lista;
	crear_nueva_lista(*padres, hijos, &nueva_lista);
	*padres = nueva_lista;
}


void crear_nueva_lista (persona_t * padres, persona_t * hijos, persona_t ** nueva_lista) {
	size_t i;
	persona_t * aux;
	if(padres) {
		*nueva_lista = padres;
		aux = *nueva_lista;
		for (i = 0; ; i++) {
			aux->siguiente = buscar_hijos(padres->nombre, hijos, i);
			aux = aux -> siguiente;
			if(aux == NULL)
				break;
		}
		crear_nueva_lista (padres->siguiente, hijos, &aux);
	}
}

void concatenar (persona_t ** lista1, persona_t * lista2) {
	if(*lista1)
		*lista1 = lista2;
	concatenar(&((*lista1)->siguiente), lista2);
}

persona_t * buscar_hijos (char nombre_padre [], persona_t * hijos, size_t posicion) {
	if(hijos) {
		if(!strcmp(hijos->antecesor, nombre_padre)) {
			if(!posicion)
				return hijos;
			posicion--;
			}
		return buscar_hijos (nombre_padre, hijos->siguiente, posicion);	
		}
	return NULL;
}

persona_t * crear_lista (void) {
	int cant, i;
	char nombre[20], antecesor[20];
	persona_t * lista;
	lista = NULL;
	puts("cantidad");
	scanf("%d", &cant);
	for(i = 0; i < cant; i++) {
		printf("Nombre:");
		scanf("%s", nombre);
		printf("Antecesor: ");
		scanf("%s", antecesor);
		ins_recur(&lista, nombre, antecesor);
	}
	return lista;
}


void ins_recur (persona_t ** lista, char nombre[], char antecesor []) {
	if(!(*lista)) {
		*lista = (persona_t *) calloc(1, sizeof(persona_t));
		(*lista)->siguiente = NULL;
		strcpy((*lista)->nombre, nombre);
		strcpy((*lista)->antecesor, antecesor);
	}
	else {
		ins_recur(&((*lista)->siguiente), nombre, antecesor);
	}
}

void imprimir_lista (persona_t * lista) {
	if(lista) {
		printf("Nombre: %s. Antecesor: %s\n", lista->nombre, lista->antecesor);
		imprimir_lista(lista->siguiente);
	}
	else
		return;
}

void liberar (persona_t **lista) {
	persona_t * aux;
	while(*lista){
		aux = *lista;
		free(aux);
		*lista = (*lista)->siguiente;
	}
}
