#include "../inc/meta_command.h"
#include "../inc/input.h"
#include "../../backend/inc/table.h"
#include <string.h>
#include <stdlib.h>

// Execute meta commands
MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table)
{
    if (strcmp(input_buffer->buffer, ".exit") == 0)
    {
        db_close(table);
        exit(EXIT_SUCCESS);
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}