#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the command being executed.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int swaped;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		dallocateandclose();
		exit(EXIT_FAILURE);
	}
	swaped = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swaped;
}
