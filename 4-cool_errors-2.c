#include "monty.h"

/**
 * cool_malloc_error - Malloc error function
 *
 * Return: EXIT FAILURE
 */
int cool_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

