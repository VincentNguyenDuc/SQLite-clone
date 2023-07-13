#ifndef TABLE_H

#define TABLE_H

#include <stdint.h>
#include "row.h"


// PAGER
typedef struct Pager
{
    int file_descriptor;
    uint32_t file_length;
    void *pages[TABLE_MAX_PAGES];
} Pager;

// TABLE
typedef struct Table
{
    Pager *pager;
    uint32_t num_rows;
} Table;

Table *db_open();

void db_close(Table *table);

void print_row(Row *row);

void *row_slot(Table *table, uint32_t row_num);

Pager *pager_open(const char *filename);

void *get_page(Pager *pager, uint32_t page_num);

void pager_flush(Pager *pager, uint32_t page_num, uint32_t size);

#endif