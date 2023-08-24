#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - separate text into partitions
 * @ptr: pointer to file
 * @buff: One line of file
 * @option: first command of line
 * @num: second command of line
 * Return: always 0
 */
struct global_vars glob_t = {NULL, NULL};

int main(int argc, char **argv)
{
	char buff[100];
	char option[30];
	char value[30];
	stack_t *head = NULL;
	int i = 0;
	int j = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	glob_t.ptr = fopen(argv[1], "r");
	if (glob_t.ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	memset(buff, 0, sizeof(buff));
	while (fgets(buff, 100, glob_t.ptr))
	{
		i++;
		memset(option, 0, sizeof(option));
		memset(value, 0, sizeof(value));
		j = sscanf(buff, "%s%s", option, value);
		if (option[0] == '\0' || j == 0)
			continue;
		glob_t.number = value;
		fun(&head, i, option);
	}
	free_stack(&head);
	fclose(glob_t.ptr);
	return (0);
}
/**
 * fun - calls appropriate function
 * @stack: pointer to list
 * @line_number: line number of file
 * @option: Opcode to be compared
 */
void fun(stack_t **stack, unsigned int line_number, char *option)
{
	instruction_t arr_instructions[2];
	void (*i)(stack_t **stack, unsigned int line_number) = NULL;

	arr_instructions[0].opcode = "push";
	arr_instructions[0].f = _push;
	arr_instructions[1].opcode = "pall";
	arr_instructions[1].f = _pall;

	i = isvalid(arr_instructions, option);
	if (i == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, option);
		free_stack(stack);
		fclose(glob_t.ptr);
		exit(EXIT_FAILURE);
	}
	else
		(i)(stack, line_number);
}

