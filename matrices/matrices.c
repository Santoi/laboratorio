#include <stdio.h>
void recorrer_matriz_caracol (int mat [][9], size_t filas, size_t cols);

int main (void) {
	int mat [6][9];
	size_t filas = 6, cols = 9;
	recorrer_matriz_caracol (mat, filas, cols);
	return 1;
}


void recorrer_matriz_caracol (int mat [][9], size_t filas, size_t cols) {
	int i = 0, j = 0, aux = 0, n = cols, m = filas, cont = 1;
	
	for (j = aux; j < n; j++) {
		mat [i][j] = cont++;
	}
	
	n--;
	j=n;
	
	while (n > aux && m > aux) {
		for (i = aux; i < m; i++) {
			mat [i][j] = cont++;
		}
		
		m--;
		i=m;
		
		for (j = n; j > aux -1; j--) {
			mat [i][j] = cont++;
		}
		
		j=aux;
		aux++;
		
		for (i = m; i > aux - 1; i--) {
			mat [i][j] = cont++;
		}
		
		i=aux;
		
		for (j=j; j <n; j++) {
			mat [i][j] = cont++;
		}
		n--;
		j=n;
	}
	
	for (i = 0; i < filas; i++) {
		for (j = 0; j < cols; j++) {
			printf ("%d\t", mat [i][j]);
		}
		putchar ('\n');
	}
	
	
		
}
	
