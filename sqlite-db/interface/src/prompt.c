#include "../inc/input.h"
#include "../inc/prompt.h"
#include <stdio.h>
#include <errno.h>

/**
 * STATEMENTS PROMPTS
 */

// Promt
void print_promt()
{
    printf("$ ");
}

// Executed
void print_executed()
{
    printf("> Executed.\n");
}

/**
 * ERROR PROMPTS
 */

// Table full
void print_table_full_error()
{
    printf("!!! FullError: Table full.\n");
}

// Data too long
void print_value_error()
{
    printf("!!! ValueError: String is too long.\n");
}

// Negative ID
void print_key_error()
{
    printf("!!! KeyError: Key Error.\n");
}

// File error
void print_filename_error()
{
    printf("!!! FileError: Must supply a database filename.\n");
}

void print_open_file_error()
{
    printf("!!! FileError: Unable to open file\n");
}

void print_read_file_error()
{
    printf("!!! FileError: Cannot read file: %d\n", errno);
}

void print_seeking_error()
{
    printf("!!! FileError: Cannot seek: %d\n", errno);
}

void print_writing_error()
{
    printf("!!! FileError: Cannot write %d\n", errno);
}
// Input Unrecognized
void print_unrecognized_error(InputBuffer *input_buffer)
{
    printf("!!! InputError: Unrecognized '%s'.\n", input_buffer->buffer);
}

// Input Syntax Error
void print_syntax_error(InputBuffer *input_buffer)
{
    printf("!!! InputError: Not a valid statement '%s'.\n", input_buffer->buffer);
}

// Input Reading Error
void print_reading_input_error()
{
    printf("!!! InputError: Cannot read input\n");
}

// DB Close Error
void print_db_close_error()
{
    printf("!!! DatabaseError: Fail closing db file.\n");
}

// DB File Error
void print_db_file_error()
{
    printf("!!! DatabaseError: Db file is not a whole number of pages. Corrupt file.\n");
}

// Page Number Out of Bound Error
void print_page_number_error()
{
    printf("!!! PageError: Tried to fetch page number out of bounds.\n");
}

// Page Flush an empty page
void print_page_flush_error()
{
    printf("!!! PageError: Tried to flush null page\n");
}
