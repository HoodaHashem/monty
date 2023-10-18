#include "monty.h"
/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the command being executed.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		dallocateandclose();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

