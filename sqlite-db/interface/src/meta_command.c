#include "../inc/meta_command.h"
#include "../inc/input.h"
#include "../../backend/inc/table.h"
#include "../../backend/inc/sqlite.h"
#include "../../backend/inc/b_tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Execute meta commands
MetaCommandResult do_meta_command(InputBuffer *input_buffer, Table *table)
{
    if (strcmp(input_buffer->buffer, ".exit") == 0)
    {
        db_close(table);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(input_buffer->buffer, ".btree") == 0) {
        printf("Tree:\n");
        print_tree(table->pager, 0, 0);
        return META_COMMAND_SUCCESS;
    }
    else if (strcmp(input_buffer->buffer, ".const") == 0) {
        print_constants();
        return META_COMMAND_SUCCESS;
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}