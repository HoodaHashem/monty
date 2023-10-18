#include "monty.h"

int startpoint(gvar *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->bytes = 0;
	var->instruct = functionstime();
	if (var->instruct == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->linenum = 1;
	var->mode = 0;

	return (EXIT_SUCCESS);
}
