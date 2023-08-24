struct global_vars
{
        FILE *ptr;
        char *number;
};
extern struct global_vars glob_t;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void (*isvalid(instruction_t *codes, char *input))(stack_t **stack, unsigned int line_number);
void fun(stack_t **stack, unsigned int line_number, char *option);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
int isnumber(char *s);
