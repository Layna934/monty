#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**
 * main - 
 *
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;	/* Initialize the stack pointer to NULL */

	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *opcode;
	char *arg;

	if(argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file) != -1))	/* consider using fgets */
	{
		line[strcspn(line, "\n")] = '\0';
		/**
		 * Tokenize the line to seperate opcode and argument if any 
		 * Parse and execute the instrustions using the instruction_t structure
		 * Update the stack based on the executed instructions
		 */
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");
		
		if (opcode == NULL)
		{
			continue;
		}

		if (arg != NULL)
		{
			execute_instructions(&stack, opcode, arg);
		}
		else
		{
			execute_instructions(&stack, opcode, arg);
		}
	}
	free_linked_list(stack);
	free(line);
	fclose(file);

	return (0);
}
