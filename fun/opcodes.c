
void execute_instructions(stack_t **stack, char *opcode, char *arg)
{
	for (int i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].func(stack, arg);
			return;

		}
	}

	/* Unknown opcode */

