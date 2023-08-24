#include "monty.h"
#define UNSD __attribute__((unused))
typedef unsigned int uint;
void _nop(stack_t **stack, unsigned int line_number);
struct global_vars glob_t = {NULL, NULL};
/**
 * main - driver program
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0 on sucess; 1 on faliure
 */

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
	instruction_t arr_instructions[7];
	void (*i)(stack_t **stack, unsigned int line_number) = NULL;

	arr_instructions[0].opcode = "push";
	arr_instructions[0].f = _push;
	arr_instructions[1].opcode = "pall";
	arr_instructions[1].f = _pall;
	arr_instructions[2].opcode = "pint";
	arr_instructions[2].f = _pint;
	arr_instructions[3].opcode = "swap";
	arr_instructions[3].f = _swap;
	arr_instructions[4].opcode = "pop";
	arr_instructions[4].f = _pop;
	arr_instructions[5].opcode = "add";
	arr_instructions[5].f = _add;
	arr_instructions[6].opcode = "nop";
	arr_instructions[6].f = _nop;

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
/**
 * _nop - does nothing
 * @stack: unused
 * @line_number: Unused
 */
void _nop(UNSD stack_t **stack, UNSD uint line_number)
{
}

