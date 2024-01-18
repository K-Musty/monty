#include "monty.h"

/**
 * cool_pop_error - Function for empty error
 * @line_number: integer
 * Return: EXIT_FAILURE
 */
int cool_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * cool_pint_error - Function for empty error
 * @line_number: integer
 * Return: EXIT_FAILURE
 */
int cool_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * cool_stack_error - Function for mathemathical error
 * @line_number: ou line number in
 * @p: pointer operation
 * Return: EXIT_FAILURE
 */
int cool_stack_error(unsigned int line_number, char *p)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

