#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main (void) {
	int cant;
	lista_t * vec, cols [10];
	size_t i;
	crear_vector_punteros (&vec, &cant);
	llenar_vector_con_listas (vec, cant);

	//list_bubble_sort (&vec, cant);
	recorrer_columnas (vec, cols, cant);
	for (i = 0; i < largo_lista (vec [0]); i++)
		imprimir_lista (cols [i]);
	liberar_vector_punteros2listas (&vec, cant);

	return EXIT_SUCCESS;
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
		printf ("|%d|\t", lista->valor);
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


void liberar_vector_punteros2listas (lista_t ** vec, int cant) {
	size_t i;
	if (vec && *vec) {
		for (i = 0; i < cant; i++) {
			liberar_lista (vec [i]);
		}

		free (*vec);
		*vec = NULL;
	}
}

void liberar_lista (nodo_t ** lista) {
	nodo_t * aux = NULL;
	if (*lista) {
		aux = (*lista)->sig;
		free (*lista);
		*lista = NULL;
		liberar_lista (&aux);
	}
}
/* http://gzalo.com/algoritmos_kuhn/ */
/*
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

void ordenar_vector_listas (lista_t ** vec, int n) {
	lista_t lista_min;
	size_t i;
	for (i = 0; i < n-1; i++) {
		lista_min = *vec[i];
		hallar_lista_min (vec[i], n-i, &lista_min);
		swap (vec[i], &lista_min);
	}
}

void hallar_lista_min (lista_t * vec, int cant, lista_t * lista_min) {
	size_t j, min = largo_lista (*lista_min);
	while (cant > 0) {
		j = largo_lista (*vec);
		if (min > j) {
			min = j;
			lista_min = vec;
		}
		vec++;
		cant--;
	}
}
*/
void list_bubble_sort (lista_t ** vec, int n) {
	int cant = n;
	lista_t * aux = *vec;
	if (vec && *vec) {
		if (n > 1) {
			while (cant > 1) {
				if (largo_lista (*aux) > largo_lista (*(aux+1))) {
					swap (aux, aux+1);
				}
				cant--;
				aux++;
			}
			list_bubble_sort (vec, n-1);
		}
	}
}

int largo_lista (lista_t lista) {
	int i = 0;
	while (lista) {
		lista = lista->sig;
		i++;
	}
	return i;
}

void swap (lista_t * ptr1, lista_t * ptr2) {
	lista_t temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void recorrer_columnas (lista_t * vec, lista_t * cols, int n) {
	size_t i, j;
	lista_t aux_col, * aux_vec;
	int cant;
	aux_vec = vec;

	while (1) {
		j = 0;
		for (i = 0; i < cant; i++) {
			if (!largo_lista (vec [i]))
				j++;
		}
		if (j >= n)
			break;
		*cols = *vec;
		aux_col = *cols;
		cant = n;

		while (cant > 0) {
			if (*vec) {
				aux_col = *vec;
				*vec = aux_col->sig;
				vec++;
				aux_col->sig = *vec;
				aux_col = aux_col->sig;
				cant--;
			}
			else {
				vec++;
				cant--;
			}
		}
		cols++;
		vec = aux_vec;
	}
}











