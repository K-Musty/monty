#include "monty.h"
/**
 * cool_rotr - Function to rotate to bottom
 * @stack: A pointer to the top node
 * @line_number: Line number
 */
void __our_monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *top;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * cool_rotl - Rotates the top to bottom
 * @stack: A pointer to the top node
 * @line_number: line number
 */
void cool_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *top;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}
