#include "monty.h"
/**
 * _pop - Deletes from the top of the stack
 * @stack: the pointer to the list
 * @line_number: file line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		if (head->next == NULL)
		{
			free(head);
			*stack = NULL;
		}
		else
		{
			*stack = (*stack)->next;
			free((*stack)->prev);
			(*stack)->prev = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		fclose(glob_t.ptr);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pint - prints the top element of the list
 * @stack: the pointer to the list
 * @line_number: file line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		printf("%d\n", head->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		fclose(glob_t.ptr);
		exit(EXIT_FAILURE);
	}
}
/**
 * _add - Adds the two top elements of the stack
 * @stack: the pointer to the list
 * @line_number: file line number
 */
void  _add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		if (head->next != NULL)
		{
			*stack = (*stack)->next;
			(*stack)->n += (*stack)->prev->n;
			free((*stack)->prev);
			(*stack)->prev = NULL;
		}
		else
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			free_stack(stack);
			fclose(glob_t.ptr);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		fclose(glob_t.ptr);
		exit(EXIT_FAILURE);
	}
}
/**
 * _swap - swaps the two top elements of the stack
 * @stack: the pointer to the list
 * @line_number: file line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head != NULL)
	{
		if (head->next != NULL)
		{
			*stack = (*stack)->next;
			(*stack)->prev->next = (*stack)->next;
			if ((*stack)->next != NULL)
				(*stack)->next->prev = (*stack)->prev;
			(*stack)->next = (*stack)->prev;
			(*stack)->prev->prev = *stack;
			(*stack)->prev = NULL;
		}
		else
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			free_stack(stack);
			fclose(glob_t.ptr);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		fclose(glob_t.ptr);
		exit(EXIT_FAILURE);
	}
}
