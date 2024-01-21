#include "monty.h"


/**
 * __our_monty_stack - function to change queue to a stack.
 * @stack: A pointer to top node
 * @line_number: line number
 */
void cool_mon_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * cool_mon_queue -function to change a stack to a queue.
 * @stack: A pointer to the top node
 * @line_number: line number
 */
void cool_mon_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

