#ifndef TABLE_H

#define TABLE_H

#include <stdint.h>
#include <stdbool.h>
#include "pager.h"

// TABLE: Table of the database
typedef struct Table
{
    Pager *pager;
    uint32_t root_page_num;
} Table;


// CURSOR: Representing a location in the table
typedef struct Cursor
{
    Table *table;
    uint32_t page_num;
    uint32_t cell_num;
    bool end_of_table; // Indicates a position one past the last element
} Cursor;

Cursor *table_start(Table *table);

Cursor *table_end(Table *table);

void *cursor_value(Cursor *cursor);

void cursor_advance(Cursor *cursor);

#endif