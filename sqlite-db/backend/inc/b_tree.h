#ifndef B_TREE_H
#define B_TREE_H

#include <stdint.h>
#include "table.h"
#include "row.h"

typedef enum 
{
    NODE_INTERNAL,
    NODE_LEAF
} NodeType;

extern const uint32_t LEAF_NODE_MAX_CELLS;

void initialize_leaf_node(void *node);

uint32_t *leaf_node_num_cells(void *node);

void *leaf_node_cell(void *node, uint32_t cell_num);

uint32_t *leaf_node_key(void *node, uint32_t cell_num);

void *leaf_node_value(void *node, uint32_t cell_num);

void leaf_node_insert(Cursor* cursor, uint32_t key, Row *value);

NodeType get_node_type(void *node);

void set_node_type(void *node, NodeType type);

Cursor *leaf_node_find(Table *table, uint32_t page_num, uint32_t key);

void print_constants();

void print_leaf_node(void *node);

#endif