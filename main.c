#include "monty.h"
gvar var;

int main(int argc, char**argv)
{
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (startpoint(&var) != 0)
	{
		return (EXIT_FAILURE);
	}
	var.file = fopen(argv[1], "r");
	if (var.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		dallocateandclose();
		return (EXIT_FAILURE);
	}
	while (getline(&var.buff, &var.bytes, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \n");
		if (opcode != NULL)
		{
			if (functionscalls(&var, opcode) == EXIT_FAILURE)
			{
				dallocateandclose();
				return(EXIT_FAILURE);
			}
			var.linenum++;
		}
	}
	dallocateandclose();
	return (EXIT_SUCCESS);
}
