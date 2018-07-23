#include <stdio.h>
#define FILAS 1
#define COLS 6
void espiral (int mat [][COLS], int fila_1, int fila_n, int col_1, int col_n, int cont);

int main (void) {
	int i, j, matriz [FILAS][COLS];

	espiral (matriz, 0, FILAS, 0, COLS, 1);

	for (i = 0; i < FILAS; i++) {
		for (j = 0; j < COLS; j++) {
			printf ("%d\t", matriz [i][j]);
		}
		putchar ('\n');
	}
	return 1;
}

void espiral (int mat [][COLS], int fila_1, int fila_n, int col_1, int col_n, int cont) {
	int i = fila_1, j = col_1;
	if (fila_1 < fila_n && col_1 < col_n) {
		if (fila_n == 1 || col_n == 1) {
			if (fila_n == 1) {
				for (j; j < col_n; j++) {
					mat [i][j] = cont++;
				}
			}
			else {
				for (i; i < fila_n; i++) {
					mat [i][j] = cont++;
				}
			}
		}
		else {
			for (j; j < col_n-1; j++) {
				mat [i][j] = cont++;
			}

			for (i; i < fila_n-1; i++) {
				mat [i][j] = cont++;
			}

			for (j; j > col_1; j--) {
				mat [i][j] = cont++;
			}

			for (i; i > fila_1; i--) {
				mat [i][j] = cont++;
			}
			espiral (mat, fila_1+1, fila_n-1, col_1+1, col_n-1, cont);
		}
	}
}
