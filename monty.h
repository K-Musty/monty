#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIMS " \n\t\a\b"
#define STACK 0
#define QUEUE 1
extern char **key_tok;

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

/*Arithmetic Fuction*/
void cool_add(stack_t **stack, unsigned int line_number);
void cool_sub(stack_t **stack, unsigned int line_number);
void cool_div(stack_t **stack, unsigned int line_number);
void cool_mul(stack_t **stack, unsigned int line_number);
void cool_mod(stack_t **stack, unsigned int line_number);

/*Monty Functions*/
int cool_monty_run(FILE *script_fd);
void cool_push(stack_t **stack, unsigned int current);
void cool_pall(stack_t **stack, unsigned int line_number);
void cool_pint(stack_t **stack, unsigned int line_number);
void cool_pop(stack_t **stack, unsigned int line_number);
void cool_swap(stack_t **stack, unsigned int line_number);
void cool_mon_stack(stack_t **stack, unsigned int line_number);
void cool_mon_queue(stack_t **stack, unsigned int line_number);
void cool_rotl(stack_t **stack, unsigned int line_number);
void cool_rotr(stack_t **stack, unsigned int line_number);

/*Error Function*/
int cool_pop_error(unsigned int line_number);
int cool_pint_error(unsigned int line_number);
int cool_stack_error(unsigned int line_number, char *p);
void cool_token_error(int error_code);
int cool_div_error(unsigned int line_number);
int cool_pchar_error(unsigned int line_number, char *message);

/**Interpreter func */
int cool_initial_stack(stack_t **stack);
void cool_free_stack(stack_t **stack);
int cool_checker(stack_t *stack);
void cool_token_error(int error_code);
unsigned int cool_array_len(void);

/*Error func*/
int cool_int_error(unsigned int line_number);
int cool_open_error(char *file_name);
int cool_malloc_error(void);
int cool_usage_error(void);
int cool_unknown_error(char *op_code, unsigned int line_number);

/**Stdlib */
char *get_int(int n);
unsigned int cool_abs(int);
int get_nbase_len(unsigned int n, unsigned int b);
void fill_nbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
char *get_next_word(char *str, char *delims);
void cool_free_tokens(void);
unsigned int cool_array_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
void cool_pstr(stack_t **stack, unsigned int line_number);
void cool_nop(stack_t **stack, unsigned int line_number);
void cool_pchar(stack_t **stack, unsigned int line_number);
void cool_rotr(stack_t **stack, unsigned int line_number);


int get_line(char **line, size_t *length, FILE *file);
#endif

