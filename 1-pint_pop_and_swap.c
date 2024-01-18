#include "monty.h"

**
 * cool_pint - Function of pint
 * @stack: Pointer
 * @line_number: integer number
 */
void cool_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		cool_token_error(cool_pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * cool_pop - Function to remove vaue
 * @stack: pointer
 * @line_number: integer number
 */
void cool_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		cool_token_error(cool_pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * cool_swap - swap function
 * @stack: pointer to the head node
 * @line_number: integer number
 */
void cool_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		cool_token_error(cool_stack_error(line_number, "swap"));
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
