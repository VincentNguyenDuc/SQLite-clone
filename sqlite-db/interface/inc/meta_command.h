#ifndef META_COMMAND_H
#define META_COMMAND_H

#include "input.h"
#include "../../backend/inc/table.h"

typedef enum MetaCommandResult
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table);

#endif