#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * isvalid - checks if opcode is a valid function
 * @codes: array of opcodes
 * @input: opcode to test
 * Return: function pointer on sucess; NULL on faliure
 */
typedef void (*instruction_function)(stack_t **, unsigned int);
instruction_function isvalid(instruction_t *codes, char *input)
{
	int i = 0;

	while (i < 2)
	{
		if (strcmp(input, codes[i].opcode) == 0)
			return (codes[i].f);
		i++;
	}
	return (NULL);
}
