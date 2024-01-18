#include "monty.h"

/**
 * cool_push - This function pushes to linked lists
 * @stack: Pointer to head of node
 * @current: current status
 */
void cool_push(stack_t **stack, unsigned int current)
{
	int k;
	stack_t *top, *temp;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		cool_token_error(cool_malloc_error());
		return;
	}

	if (key_tok[1] == NULL)
	{
		cool_token_error(cool_int_error(current));
		return;
	}

	for (k = 0; key_tok[1][k]; k++)
	{
		if (key_tok[1][k] == '-' && k == 0)
			continue;
		if (key_tok[1][k] < '0' || key_tok[1][i] > '9')
		{
			cook_token_error(cool_int_error(current));
			return;
		}
	}
	top->n = atoi(key_tok[1]);

	if (cool_monty_check(*stack) == STACK)
	{
		temp = (*stack)->next;
		top->prev = *stack;
		top->next = temp;
		if (temp)
			temp->prev = top;
		(*stack)->next = top;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		top->prev = temp;
		top->next = top;
		top->next = NULL;
	}
}

/**
 * cool_pall - Prints value of lists
 * @stack: pointer head
 * @line_number: integer number
 */
void cool_pall(stack_t **stack, unsigned int line_number)
{
	stack_t temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}
