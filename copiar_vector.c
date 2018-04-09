#include "copiar_vector.h"
#include <stdio.h>

status_t copiar_vector (double * v_dest, double * v_orig, size_t len_dest, size_t len_orig)
{
	size_t i;
	if (v_dest == NULL || v_orig)
		return ST_ERROR_NULL_POINTER;
	
	if (len_dest != len_orig)
		return ST_ERROR_LEN;
	
	for (i = 0; i < len_orig; i++)
		v_dest [i] = v_orig [i];
	
	return ST_OK;
}
	
