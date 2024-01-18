#include "monty.h"
/**
 * cool_add - This function adds two linked list value
 * @stack:pointer to node
 * @line_number: line number
 */
void cool_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		cool_token_error(cool_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	cool_pop(stack, line_number);
}

/**
 * cool_sub - This function subtracts two linked list value
 * @stack: pointer to the top node
 * @line_number: line_number
 */
void cool_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		cool_token_error(cool_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	cool_pop(stack, line_number);
}

/**
 * cool_div - This function divides the two top values
 * @stack: This is the pointer to the top node
 * @line_number: line_number
 */
void cool_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		cool_token_error(cool_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		cool_token_error(cool_div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	cool_pop(stack, line_number);
}

/**
 * cool_mul - This function multiplies two top values
 * @stack: pointer to the head node
 * @line_number: line_number
 */
void cool_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		cool_token_error(cool_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	cool_pop(stack, line_number);
}

/**
 * cool_mod - This function shows remaider btw two values
 * @stack: pointer to head node
 * @line_number: line_number
 */
void cool_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		cool_token_error(cool_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		cool_token_error(cool_div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	cool_pop(stack, line_number);
}
