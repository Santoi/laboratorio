#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int cant;
	nodo_t ** vec;
	size_t i;
	crear_vector_punteros (&vec, &cant);
	llenar_vector_con_listas (vec, cant);
	for (i = 0; i < cant; i++)
		imprimir_lista (vec [i]);
	liberar_vector_punteros2listas (&vec, cant);
	
	return 0;
}

void limpiar_buffer (void) {
	int c;
	while ((c = getchar ()) != '\n' && c != EOF)
		;
}

nodo_t * crear (void) {
	nodo_t * lista = NULL, * aux = NULL;
	int cant;
	aux = lista;
	puts ("Ingrese la cantidad de elementos para la lista");
	scanf ("%d", &cant);
	limpiar_buffer();
	if (cant < 1) {
		puts ("Cantidad invalida");
		cant = CANT_ELEM_PRED;
		printf ("%s: %d\n", "Cantidad de elementos predeterminada", cant);
	}
	lista = (nodo_t *) calloc (1, sizeof (nodo_t));
	aux = lista;
	puts ("Ingrese un numero entero");
	scanf ("%d", &aux->valor);
	limpiar_buffer();
	cant--;
	
	while (cant > 0) {
		aux->sig = (nodo_t *) calloc (1, sizeof (nodo_t));
		/*pido memoria desde el anterior*/
		aux = aux->sig;
		puts ("Ingrese un numero entero");
		scanf ("%d", &aux->valor);
		limpiar_buffer();
		cant--;
	}
	aux->sig = NULL;
	return lista;
}

void crear_lista (nodo_t ** lista) {
	nodo_t * aux = NULL;
	int cant;
	puts ("Ingrese la cantidad de elementos para la lista");
	scanf ("%d", &cant);
	limpiar_buffer();
	if (cant < 1) {
		puts ("Cantidad invalida");
		cant = CANT_ELEM_PRED;
		printf ("%s: %d\n", "Cantidad de elementos predeterminada", cant);
	}
	
	*lista = (nodo_t *) calloc (1, sizeof (nodo_t));
	aux = *lista;
	puts ("Ingrese un numero entero");
	scanf ("%d", &aux->valor);
	limpiar_buffer();
	cant--;
	
	while (cant > 0) {
		aux->sig = (nodo_t *) calloc (1, sizeof (nodo_t));
		aux = aux->sig;
		puts ("Ingrese un numero entero");
		scanf ("%d", &aux->valor);
		limpiar_buffer();
		cant--;
	}
	aux->sig = NULL;
}

void imprimir_lista (nodo_t * lista) {
	printf ("%s:\n", "Lista");
	while (lista) {
		printf ("%d\t", lista->valor);
		lista = lista->sig;
	}
	putchar ('\n');
}

void cat_lista (nodo_t ** lista1, nodo_t * lista2) {
	nodo_t * aux = NULL;
	
	if (!(*lista1)) {
		*lista1 = lista2;
	}
	else {
		aux = *lista1;
		
		while (aux->sig)
			aux = aux->sig;
			
		aux->sig = lista2;
	}
}

void crear_vector_punteros (nodo_t *** vec, int * cant) {
	puts ("Ingresar cantidad de listas");
	scanf ("%d", cant);
	limpiar_buffer ();
	if (*cant < 0)
		*cant = CANT_PREDETERMINADA;
	*vec = (nodo_t **) calloc (*cant, sizeof (nodo_t *));
}

void llenar_vector_con_listas (nodo_t ** vec, int cant) {
	size_t i;
	
	for (i = 0; i < cant; i++)
		vec [i] = crear ();
}

void liberar_lista (nodo_t ** lista) {
	nodo_t * aux = NULL;
	if (!(*lista)) {
	}
	else {
		while ((*lista)->sig) {
			aux = (*lista)->sig;
			free (*lista);
			*lista = NULL;
		}
	}
}
			
void liberar_vector_punteros2listas (nodo_t *** vec, int cant) {
	size_t i;
	if (!vec || !(*vec)) {
	}
	else {
		for (i = 0; i < cant; i++)
			liberar_lista (vec [i]);
			
		free (*vec);
		*vec = NULL;
	}
}

/* http://gzalo.com/algoritmos_kuhn/ */

void elim_cols (nodo_t ** vec, nodo_t ** vcols) {
	nodo_t * aux;
	nodo_t * aux_cols;
	
	aux = *vec;
	aux_cols = *vcols;
	while (aux->sig) {
		while (aux_cols->sig) 
			aux_cols = aux_cols->sig;
		
		aux_cols->sig = aux->sig;
		*vcols++;
		if (aux->sig->sig) {
			aux = aux->sig->sig;
		}
		else {
			break;
		}
	}
	elim_cols (vec + 1, vcols);
}





























