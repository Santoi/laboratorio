/* http://gzalo.com/algoritmos_kuhn/ */

#include "final.h"

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
