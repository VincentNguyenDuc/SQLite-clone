#include "../inc/input.h"
#include "../inc/promt.h"
#include <stdio.h>


// Promt
void print_promt()
{
    printf("$ ");
}

// Unrecognized
void print_unrecognized(InputBuffer *input_buffer)
{
    printf("Unrecognized '%s'.\n", input_buffer->buffer);
}

// Syntax Error
void print_syntax_error(InputBuffer *input_buffer)
{
    printf("Syntax Error '%s'.\n", input_buffer->buffer);
}

// Executed
void print_executed() 
{
    printf("Executed.\n");
}

// Table full
void print_table_full() {
    printf("Error: Table full.\n");
}
