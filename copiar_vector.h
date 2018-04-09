#include <stdio.h>

typedef enum {
	ST_OK,
	ST_ERROR_NULL_POINTER,
	ST_ERROR_LEN
} status_t;

status_t copiar_vector (double * v_dest, double * v_orig, size_t len_dest, size_t len_orig);
