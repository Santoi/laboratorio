#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
	int valor;
	struct nodo * sig;
} nodo_t;

nodo_t * crear (void);
void crear_lista (nodo_t ** lista);
void imprimir_lista (nodo_t * lista);

int main (void)
{
	nodo_t * lis = NULL;
	lis = crear ();
	/*crear_lista (&lis);*/
	imprimir_lista (lis);
	
	return 0;
}

nodo_t * crear (void) {
	nodo_t * lista = NULL, * aux = NULL;
	int cant, c;
	aux = lista;
	puts ("Ingrese la cantidad de elementos para la lista");
	if (scanf ("%d", &cant) != 1) {
		return NULL;
	}
	while ((c = getchar ()) != '\n' && c != EOF)
		;
	if (cant < 1)
		return lista;
	
	lista = (nodo_t *) calloc (1, sizeof (nodo_t));
	aux = lista;
	
	while (cant > 0) {
		aux->sig = (nodo_t *) calloc (1, sizeof (nodo_t));
		/*pido memoria desde el anterior*/
		puts ("Ingrese un numero entero");
		aux = aux->sig;
		if (scanf ("%d", &aux->valor) != 1) {
			return NULL;
		}
		while ((c = getchar ()) != '\n' && c != EOF)
			;
		
		cant--;
	}
	aux->sig = NULL;
	return lista;
}

void crear_lista (nodo_t ** lista) {
	nodo_t * aux = NULL;
	int cant, c;
	aux = (*lista)->sig;
	puts ("Ingrese la cantidad de elementos para la lista");
	if (scanf ("%d", &cant) != 1) {
		return;
	}
	while ((c = getchar ()) != '\n' && c != EOF)
		;
	if (cant < 1)
		return;
		
	*lista = (nodo_t *) calloc (1, sizeof (nodo_t));
	aux = *lista;
	
	while (cant > 0) {
		aux->sig = (nodo_t *) calloc (1, sizeof (nodo_t));
		aux = aux->sig;
		puts ("Ingrese un numero entero");
		if (scanf ("%d", &aux->valor) != 1) {
			return;
		}
		while ((c = getchar ()) != '\n' && c != EOF)
			;
		cant--;
	}
	aux->sig = NULL;
}

void imprimir_lista (nodo_t * lista) {
	while (lista) {
		printf ("%d\t", lista->valor);
		lista = lista->sig;
	}
}







































