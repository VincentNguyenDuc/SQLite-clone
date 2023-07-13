#ifndef SQLITE_H
#define SQLITE_H

#include "table.h"

Table *db_open(const char *filename);

void db_close(Table *table);

#endif