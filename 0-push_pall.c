#include "monty.h"

/**
 * push - Pushes an integer onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the command being executed.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = NULL, *ptr = *stack;
	char *num;

	num = strtok(NULL, " \n");
	if (num == NULL || (isd(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		dallocateandclose();
		exit(EXIT_FAILURE);
	}
	curr = malloc(sizeof(stack_t));
	if (!curr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		dallocateandclose();
		exit(EXIT_FAILURE);
	}
	curr->n = atoi(num);
	if (var.mode == 0 || !*stack)
	{
		curr->next = *stack;
		curr->prev = NULL;
		if (*stack)
			(*stack)->prev = curr;
		*stack = curr;
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = curr;
		curr->prev = ptr;
		curr->next = NULL;
	}
}



/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the command being executed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	if (current == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
