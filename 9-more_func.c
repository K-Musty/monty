#include "monty.h"

/**
 * cool__pchar - This function will print character
 * @stack: pointer to head
 * @line_number: our current working line number of a Monty bytecodes file.
 */
void cool_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		cool_token_error(cool_pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		cool_token_error(cool_pchar_error(line_number, "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
/**
 * cool_monty_nop - This function does
 * @stack: pointer to head or tail
 * @line_number: line number
 */
void cool_monty_nop(stack_t **stack, unsigned int line_number)
{
        (void)stack;
        (void)line_number;
}

/**
 * cool__pstr - This function will print string in stack_t
 * @stack: poijnter to head
 * @line_number: line number
 */
void cool_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)line_number;
}
