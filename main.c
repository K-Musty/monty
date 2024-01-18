#include "monty.h"

char **key_tok = null;

/**
 * main - Monty interpreter
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Success on success failed on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (cool_usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (cool_open_error(argv[1]));
	exit_code = cool_monty_run(script_fd);
	fclose(script_fd);
	return (exit_code);
}

