/* Realizar una función que ordene un vector usando solamente recursividad,
 * aplicando el método de Selección. La función puede recibir por parámetro
 * solamente al vector y a su cantidad de elementos. Todas las sub-funciones
 * que se usen deben usar recursividad (pueden recibir más variables por
 * parámetro). No se puede usar nada iterativo. */
#include <stdio.h>

void print_vec (int *, size_t);
void ord_sel (int *, size_t);
void hallar_min (int , int *, size_t, int *, int);
void swap (int *, int, int);

int main (void) {
	int vec [8] = {3,1,-5,60,9,3,5,0};
	puts ("Vector viejo");
	print_vec (vec, 8);
	putchar ('\n');
	ord_sel (vec, 8);
	puts ("Vector nuevo");
	print_vec (vec, 8);
	putchar ('\n');
	return 1;
}

void ord_sel (int * vec, size_t cant) {
	int min = *vec, posmin = 0, i = 0;
	if (cant>0) {
		hallar_min (min, vec, cant, &posmin, i);
		swap (vec, 0, posmin);
		ord_sel (vec+1, cant-1);
	}
}

void hallar_min (int min, int * vec, size_t cant, int * posmin, int i) {
	if (cant>0) {
		if (min > *vec) {
			min = *vec;
			*posmin = i;
		}
		hallar_min (min, vec+1, cant-1, posmin, i+1);
	}
}

void print_vec (int * vec, size_t cant) {
	if (cant>0) {
		printf ("|%d|\t", *vec);
		print_vec (vec+1, cant-1);
	}
}

void swap (int * vec, int i, int j) {
	int temp;
	temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}
