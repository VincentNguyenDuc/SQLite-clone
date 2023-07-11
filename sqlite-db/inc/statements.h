#ifndef STATEMENT_H
#define STATEMENT_H

#include "meta_commands.h"

typedef enum StatementType
{
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct Statement
{
    StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement);

void execute_statement(Statement *statement);

#endif