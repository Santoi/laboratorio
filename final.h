#ifndef FINAL__H
#define FINAL__H

#define MAX_LEN 100

typedef struct nodo {
	struct nodo * sig;
	void * valor;
} nodo_t;

void elim_cols (nodo_t ** vec, nodo_t ** vcols);

#endif
