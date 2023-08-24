#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * _push - add item to the top of list
 * @stack: pointer to pointer of list
 * @line_number: line number of file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int i = 0;

	if (isnumber(glob_t.number) == 1)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		free_stack(stack);
		fclose(glob_t.ptr);
		exit(EXIT_FAILURE);
	}
	i = atoi(glob_t.number);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		fclose(glob_t.ptr);
		exit(EXIT_FAILURE);
	}
	new_node->n = i;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
/**
 * _pall - prints all elements
 * @stack: pointer to pointer of list
 * @line_number: line number of file
 */
void _pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *curr = *stack;

	if (*stack != NULL)
	{
		while (curr != NULL)
		{
			printf("%i\n", curr->n);
			curr = curr->next;
		}
	}
}
/**
 * free_stack - frees list
 * @stack: pointer to pointer of list
 */
void free_stack(stack_t **stack)
{
	stack_t *curr = *stack;

	if (curr != NULL)
	{
		while (curr->next != NULL)
		{
			curr = curr->next;
			free(curr->prev);
		}
		free(curr);
	}
}
/**
 * isnumber - checks if string is numeric
 * @s: string to be checked
 * Return: 1 if not a number; 0 if is a number
 */
int isnumber(char *s)
{
	int i = 0;

	if (s[0] == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
