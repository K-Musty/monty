#include "monty.h"

/**
 * cool_abs - Function to get absolute value of int
 * @k: integer
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int cool_abs(int k)
{
	if (k < 0)
		return (-(unsigned int)k);
	return ((unsigned int)k);
}

/**
 * get_int - gets a character pointer to new string containing int
 * @n: number
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int n)
{
	int len = 0;
        long num = 0;
	unsigned int tmp;
	char *ret;

	tmp = cool_abs(n);
	len =  get_nbase_len(tmp, 10);

	if (n < 0 || num < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	fill_nbase_buffer(tmp, 10, ret, len);
	if (n < 0 || num < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * fill_nbase_buff - fills with number till 36
 * @num: number
 * @base: basenumber
 * @buff: buffer
 * @buff_size: size of buffer
 *
 * Return: always void.
 */
void fill_nbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int r, k = buff_size - 1;

	buff[buff_size] = '\0';
	while (k >= 0)
	{
		r = num % base;
		if (r > 9)
			buff[k] = r + 87;
		else
			buff[k] = r + '0';
		num /= base;
		k--;
	}
}

/**
 * get_nbase_len - Function to get number base length
 * @n: number for length
 * @b: base number
 * Return: integer
 */
int get_nbase_len(unsigned int n, unsigned int b)
{
	int length = 1; /* all numbers contain atleast one digit */

	while (n > b - 1)
	{
		length++;
		n /= b;
	}
	return (length);
}
