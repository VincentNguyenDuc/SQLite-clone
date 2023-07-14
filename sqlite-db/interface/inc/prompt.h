#ifndef PROMPT_H
#define PROMPT_H

#include "input.h"

void print_promt();

void print_unrecognized_error(InputBuffer *input_buffer);

void print_syntax_error(InputBuffer *input_buffer);

void print_executed();

void print_table_full_error();

void print_value_error();

void print_key_error();

void print_filename_error();

void print_open_file_error();

void print_reading_input_error();

void print_db_close_error();

void print_db_file_error();

void print_page_number_error();

void print_page_flush_error();

void print_read_file_error();

void print_seeking_error();

void print_writing_error();

void print_duplicate_key_error();

#endif