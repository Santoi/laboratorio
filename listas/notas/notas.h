/*Dadas las siguientes estructuras:

struct alumno{
	char nombre[20];
	int nota;
	alumno *sig2;
	alumno *sig;
};
struct materia{
	char nombre[20];
	alumno *prim;
};

Hay un vector de materias. La última materia tiene un NULL en el campo prim.

Escribir un procedimiento void enganchar(materia *materias, alumno **primer2); que enganche a los alumnos que tienen nota 2,
poniendo el primero de ellos en la variable primer2, de tal forma que recorriendo por sig2 pases por todos ellos.
*/
#ifndef NOTAS__H
#define NOTAS__H

typedef struct alumno {
	char nombre [20];
	int nota;
	struct alumno * sig2;
	struct alumno * sig;
} alumno_t;

typedef struct materia {
	char materia [20];
	alumno_t * prim;
} materia_t;

void enganchar_aplazos (materia_t * vec, alumno_t ** prim2);
void buscar_en_materia (alumno_t * alumno, alumno_t ** aplazo);

#endif