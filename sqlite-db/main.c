#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "./inc/input.h"
#include "./inc/meta_commands.h"
#include "./inc/statements.h"

// Read-Exucute-Print-Loop (REPL)
int main()
{
    InputBuffer *input_buffer = new_input_buffer();
    while (true)
    {

        // GET INPUT
        print_promt();
        read_input(input_buffer);

        // HANDLE META COMMMANDS
        if (input_buffer->buffer[0] == '.')
        {
            switch (do_meta_command(input_buffer))
            {
            case META_COMMAND_SUCCESS:
                continue;
            case META_COMMAND_UNRECOGNIZED_COMMAND:
                print_unrecognized_command(input_buffer);
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
            print_unrecognized_command(input_buffer);
            continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
    }
}
