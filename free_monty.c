#include "monty.h"
/**
 * cool_free_tokens - Frees the key_tok
 */
void cool_free_tokens(void)
{
	size_t i = 0;

	if (key_tok == NULL)
		return;

	for (i = 0; key_tok[i]; i++)
		free(key_tok[i]);

	free(key_tok);
}

/**
 * cool_arr_len - This function will get array length
 * Return: This is the length of current op_toks (as int).
 */
unsigned int cool_array_len(void)
{
	unsigned int tok_len = 0;

	while (key_tok[tok_len])
		tok_len++;
	return (tok_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, k;

	for (i = 0; line[i]; i++)
	{
		for (k = 0; delims[k]; k++)
		{
			if (line[k] == delims[k])
				break;
		}
		if (delims[k] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches corresponding functions
 * @opcode: The opcode to match.
 *
 * Return: A pointer
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", cool_push},
		{"pall", cool_pall},
		{"pint", cool_pint},
		{"pop", cool_pop},
		{"swap", cool_swap},
		{"add", cool_add},
		{"nop", cool_nop},
		{"sub", cool_sub},
		{"div", cool_div},
		{"mul", cool_mul},
		{"mod", cool_mod},
		{"pchar", cool_pchar},
		{"pstr", cool_pstr},
		{"rotl", cool_rotl},
		{"rotr",  cool_rotr},
		{"stack", cool_mon_stack},
		{"queue", cool_mon_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}
