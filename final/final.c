#include <stdio.h>

typedef struct nodo {
	int valor;
	struct nodo * sig;
} nodo_t;

void eliminar_diag (nodo_t * vec [], int c, nodo_t ** diagppal, nodo_t ** diagsec) {
	
	if (c > 0) {
		avanzar_listas (vec, &(vec[c-1]), *vec, vec[c-1]);
		
		if (*vec == vec [c-1]) {
			(*diagppal)->sig = (*vec)->sig;
			(*vec)->sig = (*vec)->sig->sig;
			(*diagppal)->sig->sig = NULL;
		}
		else {
			(*diagppal)->sig = (*vec)->sig;
			(*vec)->sig = (*vec)->sig->sig;
			(*diagppal)->sig->sig = NULL;
			(*diagsec)->sig = vec[c-1]->sig;
			vec[c-1]->sig = vec[c-1]->sig->sig;
			(*diagsec)->sig->sig = NULL;
		}
		eliminar_diag (vec+1, c-1, diagppal, diagsec);
	}
}

void avanzar_listas (nodo_t ** lista1, nodo_t ** lista2, nodo_t * vecppal, nodo_t * vecsec) {
	if (vecppal > vecsec) {
		while (vecppal+1 != vecsec) {
			*lista1 = (*lista1)->sig;
			*lista2 = (*lista2)->sig;
			vecppal++;
		}
	}
	else if (vecppal < vecsec) {
		while (vecsec+1 != vecppal) {
			*lista1 = (*lista1)->sig;
			*lista2 = (*lista2)->sig;
			vecsec++;
		}
	}
	else {
		
			
