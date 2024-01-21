#include "monty.h"
/**
 * cool_div_error - This function will print division error
 * @line_number: Our line number in Monty bytecodes file where error occurred.
 * Return: EXIT_FAILURE
 */
int cool_div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * cool_pchar_error - This function will print pchar error
 * @line_number: integer number
 * @message: error message
 * Return: EXIT_FAILURE
 */
int cool_pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
