#ifndef META_COMMAND_H
#define META_COMMAND_H

#include "input.h"

typedef enum MetaCommandResult
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum PrepareResult
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

MetaCommandResult do_meta_command(InputBuffer *input_buffer);

#endif