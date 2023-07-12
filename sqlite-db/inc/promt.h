#ifndef PROMT_H
#define PROMT_H

#include "input.h"

void print_promt();

void print_unrecognized(InputBuffer *input_buffer);

void print_syntax_error(InputBuffer *input_buffer);

void print_executed();

void print_table_full();

#endif