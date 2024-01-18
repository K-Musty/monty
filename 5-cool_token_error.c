#include "monty.h"
/**
 * cool_token_error - This function will element of key_tok
 * @error_c: integer as strijng
 */
void cool_token_error(int error_code)
{
	int toks_len = 0, k = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = __our_monty_token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!key_tok)
	{
		cool_malloc_error();
		return;
	}
	while (k < toks_len)
	{
		new_toks[i] = key_tok[i];
		k++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		cool_malloc_error();
		return;
	}
	new_toks[k++] = exit_str;
	new_toks[k] = NULL;
	free(key_tok);
	key_tok = new_toks;
}
