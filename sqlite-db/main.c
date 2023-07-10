#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "./inc/input.h"
 

// Read-Exucute-Print-Loop (REPL)
int main() {
    InputBuffer* input_buffer = new_input_buffer();
    while (true) {
        print_promt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, "exit") == 0) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            print_unrecognized_command(input_buffer);
        }
    }
}
