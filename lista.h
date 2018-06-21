#ifndef LISTA__H
#define LISTA__H

#define CANT_PREDETERMINADA 10
#define CANT_ELEM_PRED 3

typedef struct nodo {
	int valor;
	struct nodo * sig;
} nodo_t;

nodo_t * crear (void);
void crear_lista (nodo_t ** lista);
void imprimir_lista (nodo_t * lista);
void cat_lista (nodo_t ** lista1, nodo_t * lista2);
void limpiar_buffer (void);
void crear_vector_punteros (nodo_t *** vec, int * cant);
void llenar_vector_con_listas (nodo_t ** vec, int cant);
void elim_cols (nodo_t ** vec, nodo_t ** vcols);

#endif
