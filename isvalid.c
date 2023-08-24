#include "monty.h"
/**
 * isvalid - checks if opcode is a valid function
 * @codes: array of opcodes
 * @input: opcode to test
 * Return: function pointer on sucess; NULL on faliure
 */
instruction_function isvalid(instruction_t *codes, char *input)
{
	int i = 0;

	while (i < 7)
	{
		if (strcmp(input, codes[i].opcode) == 0)
			return (codes[i].f);
		i++;
	}
	return (NULL);
}
