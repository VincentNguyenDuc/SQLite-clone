#ifndef TABLE_H

#define TABLE_H

#include <stdint.h>
#include "pager.h"

// TABLE
typedef struct Table
{
    Pager *pager;
    uint32_t num_rows;
} Table;

void *table_slot(Table *table, uint32_t row_num);

#endif