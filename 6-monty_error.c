#include "monty.h"
/**
 * cool_unknown_error - A function to print unkown error
 * @op_code: opcode
 * @line_number: This is the line number
 * Return: (EXIT_FAILURE) always.
 */
int cool_unknown_error(char *op_code, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, op_code);
	return (EXIT_FAILURE);
}
/**
 * __our_monty_usage_error - This function will print usage error
 * Return: (EXIT_FAILURE) always.
 */
int cool_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * cool_malloc_error - Function to print malloc error messages.
 */
int cool_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * cool_open_error - This function will print
 * @file_name: This is the name of file failed to open
 * Return: (EXIT_FAILURE) always.
 */
int cool_open_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}


/**
 * cool_int_error - Function to print invalid
 * @line_number: This the line number in Monty bytecodes
 * Return: (EXIT_FAILURE) always.
 */
int cool_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
