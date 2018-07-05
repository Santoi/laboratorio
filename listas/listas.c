#include <stdlib.h>

typedef struct nodo {
	int dato;
	struct nodo * sig;
} nodo_t, * lista_t;

lista_t crear_lista (void);
void crear_nodo (nodo_t ** pnodo, int dato);
void insertar_al_ppio (lista_t * plista, int dato);
void insertar_al_final (lista_t * plista, int dato);

lista_t crear_lista (void) {
	lista_t lista = NULL;
	return lista;
}
void crear_nodo (nodo_t ** pnodo, int dato) {
	*pnodo = (nodo_t *) calloc (1, sizeof (nodo_t));
	
	(*pnodo)->dato = dato;
	(*pnodo)->sig = NULL;
}

void insertar_al_ppio (lista_t * plista, int dato) {
	nodo_t * nuevo;
	
	crear_nodo (&nuevo, dato);
	
	nuevo->sig = *plista;
	*plista = nuevo;
}

void insertar_al_final (lista_t * plista, int dato) {

	if (!(*plista)->sig)
		insertar_al_ppio (plista, dato);
	else
		insertar_al_final (&((*plista)->sig), dato);
}

void quitar_dato (lista_t * plista, int dato) {
	nodo_t * aux = *plista;
	nodo_t * aux2;
	
	if (aux->sig) {
		if (aux->sig->dato == dato) {
			aux2 = aux->sig;
			aux->sig = aux->sig->sig;
			free (aux2);
		}
		quitar_dato (&(aux->sig), dato);
	}
}





















