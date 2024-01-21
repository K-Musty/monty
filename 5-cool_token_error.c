#include "monty.h"
char **key_tok = NULL;
/**
 * cool_token_error - This function will element of key_tok
 * @error_c: integer as strijng
 */
void cool_token_error(int error_code)
{
	int token_len = 0, k = 0;
	char **token_s = NULL;
	char *exit_s = NULL;

	token_len = cool_array_len();
	token_s = malloc(sizeof(char *) * (token_len + 2));
	if (!key_tok)
	{
		cool_malloc_error();
		return;
	}
	while (k < token_len)
	{
		token_s[k] = key_tok[k];
		k++;
	}
	exit_s = get_int(error_code);
	if (!exit_s)
	{
		free(token_s);
		cool_malloc_error();
		return;
	}
	token_s[k++] = exit_s;
	token_s[k] = NULL;
	free(key_tok);
	key_tok = token_s;
}
