#include "monty.h"


void execute_instructions(stack_t **stack, char *opcode, char *arg)
{
	int i; 
	instruction_t instructions[] =
	{
		{"push", handle_push},
		{"pall", handle_pall},
		{NULL, NULL}
	};

for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, arg);
			return;

		}
	}

	/* Unknown opcode */
	fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
	exit(EXIT_FAILURE);
}
