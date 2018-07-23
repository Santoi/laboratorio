#ifndef LISTA__H
#define LISTA__H

#include <stdio.h>

#define CANT_PREDETERMINADA 10
#define CANT_ELEM_PRED 3

typedef struct nodo {
	int valor;
	struct nodo * sig;
} nodo_t, * lista_t;

nodo_t * crear (void);
void crear_lista (nodo_t ** lista);
void imprimir_lista (nodo_t * lista);
void cat_lista (nodo_t ** lista1, nodo_t * lista2);
void liberar_lista (nodo_t ** lista);
void liberar_vector_punteros2listas (lista_t ** vec, int cant);
void limpiar_buffer (void);
void crear_vector_punteros (nodo_t *** vec, int * cant);
void llenar_vector_con_listas (nodo_t ** vec, int cant);
void elim_cols (nodo_t ** vec, nodo_t ** vcols);
void swap (lista_t * ptr1, lista_t * ptr2);
void ordenar_vector_listas (lista_t ** vec, int n);
int largo_lista (lista_t lista);
void list_bubble_sort (lista_t ** vec, int n);
void hallar_lista_min (lista_t * vec, int cant, lista_t * lista_min);
void recorrer_columnas (lista_t * vec, lista_t * cols, int n);

#endif
