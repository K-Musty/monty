#include "monty.h"

/**
 * cool_initial_stack - Initializes stack
 * @stack: A pointer to an unitialized stack_t stack.
 * Return: If an error occurs - EXIT_FAILURE.
 */
int cool_initial_stack(stack_t **stack)
{
	stack_t *str;

	str = malloc(sizeof(stack_t));
	if (str == NULL)
		return (cool_malloc_error());

	str->n = STACK;
	str->prev = NULL;
	str->next = NULL;

	*stack = str;

	return (EXIT_SUCCESS);
}

/**
 * cool_free_stack - This function frees a stack
 * @stack: This is a pointer to stack head
 */
void cool_free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * cool_checker - Checks if a stack_t
 * @stack: A pointer to the head or tail
 * Return: 0 for stack, 1 for queue and 2 when not either
 */
int cool_checker(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
/**
 * cool_rotr - Rotates the bottom
 * @stack: pointer
 * @line_number: The current line number
 */
void cool_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

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
