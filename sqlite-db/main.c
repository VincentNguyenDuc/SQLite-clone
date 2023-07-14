#include <stdbool.h>
#include <stdlib.h>
#include "./interface/inc/input.h"
#include "./interface/inc/meta_command.h"
#include "./interface/inc/prompt.h"
#include "./interface/inc/statement.h"
#include "./backend/inc/table.h"
#include "./backend/inc/sqlite.h"


// Read-Exucute-Print-Loop (REPL). This is basically the whole program
int main(int argc, char *argv[])
{
    if (argc < 2) {
        print_filename_error();
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    Table* table = db_open(filename);

    InputBuffer *input_buffer = new_input_buffer();
    while (true)
    {

        // GET INPUT
        print_promt();
        read_input(input_buffer);

        // HANDLE META COMMMANDS
        if (input_buffer->buffer[0] == '.')
        {
            switch (do_meta_command(input_buffer, table))
            {
            case META_COMMAND_SUCCESS:
                continue;
            case META_COMMAND_UNRECOGNIZED_COMMAND:
                print_unrecognized_error(input_buffer);
                continue;
            }
        }

        // HANDLE STATEMENT
        Statement statement;
        switch (prepare_statement(input_buffer, &statement))
        {
        case PREPARE_SUCCESS:
            break;
        case PREPARE_UNRECOGNIZED_STATEMENT:
            print_unrecognized_error(input_buffer);
            continue;
        case PREPARE_SYNTAX_ERROR:
            print_syntax_error(input_buffer);
            continue;
        case PREPARE_STRING_TOO_LONG:
            print_value_error();
            continue;
        case PREPARE_NEGATIVE_ID:
            print_key_error();
            continue;
        }

        switch (execute_statement(&statement, table))
        {
        case EXECUTE_SUCCESS:
            print_executed();
            break;
        case EXECUTE_TABLE_FULL:
            print_table_full_error();
            break;
        }
    }
}
