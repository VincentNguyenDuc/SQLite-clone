#ifndef STATEMENT_H
#define STATEMENT_H

#include "meta_command.h"
#include "../../backend/inc/table.h"

typedef enum StatementType
{
    STATEMENT_INSERT,
    STATEMENT_SELECT,
} StatementType;

typedef enum PrepareResult
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
    PREPARE_SYNTAX_ERROR,
    PREPARE_STRING_TOO_LONG,
    PREPARE_NEGATIVE_ID
} PrepareResult;

typedef enum ExecuteResult 
{
    EXECUTE_TABLE_FULL,
    EXECUTE_SUCCESS
} ExecuteResult;

typedef struct Statement
{
    StatementType type;
    Row row_to_insert;
} Statement;

PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement);

ExecuteResult execute_statement(Statement *statement, Table *table);

#endif