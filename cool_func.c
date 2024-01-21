/**
 * cool_pstr - This function will print string
 * @stack: This is pointer to the top node
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

/**
 * cool_nop - This function does nothing
 * @stack: This is the pointer
 * @line_number: line number
 */
void cool_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * cool_pchar - This function will print character in the top
 * @stack: This is the pointer to the top mode
 * @line_number: our current working line number of a Monty bytecodes file.
 */
void cool_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		__monty_set_op_tok_error(__our_pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		__monty_set_op_tok_error(__our_pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
