#include "monty.h"

int functionscalls(gvar *var, char *opcode)
{
	int i;

	for (i = 0; var->instruct[i].opcode; i++)
		if (strcmp(opcode, var->instruct[i].opcode) == 0)
		{
			if (!var->instruct[i].f)
				return (EXIT_SUCCESS);
			var->instruct[i].f(&var->head, var->linenum);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->linenum, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

