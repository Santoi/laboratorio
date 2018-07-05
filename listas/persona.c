/* Hay dos listas de personas, una de padres y una de hijos.
 * 
 * 
 * struct persona{
 * 	char nombre[20];
 * 	char antecesor[20];
 * 	persona *sig;
 * };
 * 
 * hay que escribir un procedimiento void enganchar(persona *padres, persona
 * **hijos); que cambiase la lista de padres de tal manera que la lista
 * quedara de la siguiente forma: A → 1er hijo de A → 2do hijo de A → B → 1er hijo de B → C → NULL
 * 
 * Es decir, que estén los padres ordenados según el mismo orden que la
 * lista original, pero que entre ellos estén todos los hijos correctos. */

#include <stdio.h>

typedef struct persona {
	char nombre [20];
	char antecesor [20];
	struct persona * sig;
} persona_t;

void enganchar (persona_t * padres, persona_t ** hijos) {
	persona_t aux_p, *aux_h, * aux_h_2;
	aux_p = *padres;
	aux_h = *hijos;
	if ((*aux_h)->sig && padres->sig) {
		if (!strcmp((*aux_h)->sig->antecesor, padres->sig->nombre)) {
			padres = padres->sig;
			*aux_p = padres->sig;
			*aux_h_2 = (*aux_h)->sig;
			padres->sig = *aux_h_2;
			(*aux_h)->sig = (*aux_h)->sig->sig;
			(*aux_h_2)->sig = *aux_p;
		}
		else {
			*aux_h = (*aux)->sig;
