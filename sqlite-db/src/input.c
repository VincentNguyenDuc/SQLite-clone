#include <stdio.h>
#include <stdlib.h>
#include "../inc/input.h"

// Struct wrapper to work with user input
InputBuffer *new_input_buffer()
{
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}

// A promt to the user
void print_promt()
{
    printf("$ ");
}

// Read input from user
void read_input(InputBuffer *input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    // Error handler
    if (bytes_read <= 0)
    {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

// Unrecognized command
void print_unrecognized_command(InputBuffer *input_buffer)
{
    printf("Unrecognized command '%s'.\n", input_buffer->buffer);
}


// Exit session
void close_input_buffer(InputBuffer *input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}