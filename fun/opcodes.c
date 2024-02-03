#include "monty.h"

void handle_push(stack_t **stack, char *arg)
{
	/* convert arg to an integer */
	int value = atoi(arg);

	/* Allocate memory for a new node */
	stack_t *new_node = malloc(sizeof(stack_t));

	/* Check if malloc was successful */
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the value of the new node */
	new_node->n = value;

	/* Update pointers to connect the new node to the existing stack */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* If the stack is not empty, update the previous pointer of the current top node */
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	/* update the stack pointer to point to the new node */
	*stack = new_node;
}

void handle_pall(stack_t **stack, char *arg)
{
	stack_t *current = *stack;
	(void)arg;	/* unused argument, as pall doesn't take an argument */

	/* Traverse the stack and print its contents */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


