#include "monty.h"
/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the command being executed.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		dallocateandclose();
		exit(EXIT_FAILURE);
	}
	new_top = *stack;
	*stack = new_top->next;
	if (new_top->next)
		new_top->next->prev = NULL;
	free(new_top);
}
