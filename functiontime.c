#include "monty.h"

instruction_t *functionstime(void)
{
	instruction_t *pointer = malloc(sizeof(instruction_t) * 10);

	if (pointer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	pointer[0].opcode = "pall", pointer[0].f = pall;
	pointer[1].opcode = "push", pointer[1].f = push;
	pointer[2].opcode = "pint", pointer[2].f = pint;
	pointer[3].opcode = "pop", pointer[3].f = pop;
	pointer[4].opcode = "swap", pointer[4].f = swap;
	pointer[5].opcode = "add", pointer[5].f = add;
	pointer[6].opcode = "nop", pointer[6].f = NULL;
	pointer[7].opcode = "stack", pointer[7].f = stack;
	pointer[8].opcode = "queue", pointer[8].f = queue;
	pointer[9].opcode = NULL, pointer[9].f = NULL;



	return (pointer);
}
