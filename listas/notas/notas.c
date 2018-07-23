#include "notas.h"
#include <stdio.h>

void enganchar_aplazos (materia_t * vec, alumno_t ** prim2) {

	alumno_t * alumno;
	alumno_t * aplazo = *prim2;
	if (vec->prim) {
		alumno = vec->prim;
		buscar_en_materia (alumno, &aplazo);
		enganchar_aplazos (vec+1, &aplazo);
	}
}

void buscar_en_materia (alumno_t * alumno, alumno_t ** aplazo) {
	if (alumno) {
		if (alumno->nota == 2) {
			*aplazo = alumno;
			buscar_en_materia (alumno->sig, &((*aplazo)->sig2));
		}
		buscar_en_materia (alumno->sig, aplazo);
	}
}