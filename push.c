#include "monty.h"

/**
 * push - function to push a node to the list
 * @stack: pointer to the list
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *new_args = global.args;

	if (is_digit(new_args) == 0 || new_args == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (global.format == 0)
	{
		head_stack(stack, atoi(new_args));
	}
	else
	{
		tail_stack(stack, atoi(new_args));
	}
}

/**
 * pall - function to print all the values of stack
 * @stack: pointer to the list
 * @line_number: the current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		if (current == *stack)
		{
			return;
		}
	}
}

/**
 * tail_stack - adds a stack at the end of the list
 * @stack: a pointer to the stack_t
 * @n: number to be added
 *
 * Return: New node
 */
stack_t *tail_stack(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
		return (new);
	}
	while (current)
	{
		if (current->next != NULL)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}
	return (new);
}

/**
 * head_stack - Initializes a stack_t stack with beginning
 * @stack: A pointer to an unitialized stack_t stack.
 * @n: integer value
 *
 * Return: The new stack
 */
stack_t *head_stack(stack_t **stack, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}
