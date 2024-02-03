void handle_push(stack_t **stack, char *arg) {
    /* Convert arg to an integer */
    int value = atoi(arg);

    /* Allocate memory for a new node */
    stack_t *new_node = malloc(sizeof(stack_t));

    /* Check if malloc was successful */
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Set the value of the new node */
    new_node->n = value;

    /* Update pointers to connect the new */ node to the existing stack
    new_node->prev = NULL;
    new_node->next = *stack;

    /* If the stack is not empty, update the previous pointer of the current top node */
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    /* Update the stack pointer to point to the new node */
    *stack = new_node;
}

void handle_pall(stack_t **stack, char *arg) {
    (void)arg;  /* Unused argument, as pall doesn't take an argument */

    /* Traverse the stack and print its contents */
    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}


void execute_instruction(stack_t **stack, char *opcode, char *arg) {
    for (int i = 0; instructions[i].opcode != NULL; i++) {
        if (strcmp(opcode, instructions[i].opcode) == 0) {
            instructions[i].f(stack, arg);
            return;
        }
    }

    /* Unknown opcode */
    fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
    exit(EXIT_FAILURE);
}
