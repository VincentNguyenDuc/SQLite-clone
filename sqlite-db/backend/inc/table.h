#ifndef TABLE_H

#define TABLE_H

#include <stdint.h>

#define TABLE_MAX_PAGES 100
#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

// TABLE
typedef struct Table
{
    uint32_t num_rows;
    void *pages[TABLE_MAX_PAGES];
} Table;

Table *new_table();

void free_table(Table *table);

// ROWS
typedef struct Row
{
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE + 1];
    char email[COLUMN_EMAIL_SIZE + 1];
} Row;

void print_row(Row *row);

void serialize_row(Row *source, void *destination);

void deserialize_row(void *source, Row *destination);

void *row_slot(Table *table, uint32_t row_num);

#endif