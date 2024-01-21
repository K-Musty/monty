#include "monty.h"
/**
 * cool_monty_run - Function to execute monty
 * @script_fd: File descriptor
 * Return: EXIT ON FAILURE
 */
int cool_monty_run(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t length = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_num = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (cool_initial_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &length, script_fd) != -1)
	{
		line_num++;
		key_tok = strtow(line, DELIMS);
		if (key_tok == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			cool_free_stack(&stack);
			return (cool_malloc_error());
		}
		else if (key_tok[0][0] == '#')
		{
			cool_free_tokens();
			continue;
		}
		op_func = get_op_func(key_tok[0]);
		if (op_func == NULL)
		{
			cool_free_stack(&stack);
			exit_status = cool_unknown_error(key_tok[0], line_num);
			cool_free_tokens();
			break;
		}
		prev_tok_len = cool_array_len();
		op_func(&stack, line_num);
		if (cool_array_len() != prev_tok_len)
		{
			if (key_tok && key_tok[prev_tok_len])
				exit_status = atoi(key_tok[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			cool_free_tokens();
			break;
		}
		cool_free_tokens();
	}
	cool_free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (cool_malloc_error());
	}

	free(line);
	return (exit_status);
}
