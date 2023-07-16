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

void initialize_internal_node(void *node);

uint32_t *leaf_node_num_cells(void *node);

void *leaf_node_cell(void *node, uint32_t cell_num);

uint32_t *leaf_node_key(void *node, uint32_t cell_num);

void *leaf_node_value(void *node, uint32_t cell_num);

void leaf_node_insert(Cursor* cursor, uint32_t key, Row *value);

NodeType get_node_type(void *node);

void set_node_type(void *node, NodeType type);

Cursor *leaf_node_find(Table *table, uint32_t page_num, uint32_t key);

void print_constants();

void print_tree(Pager *pager, uint32_t page_num, uint32_t indentation_level);

void leaf_node_split_and_insert(Cursor *cursor, uint32_t key, Row *row);

void create_new_root(Table *table, uint32_t right_child_page_num);

void set_node_root(void *node, bool is_root);

bool is_node_root(void *node);

uint32_t *internal_node_num_keys(void *node);

uint32_t *internal_node_right_child(void *node);

uint32_t *internal_node_cell(void *node, uint32_t cell_num);

uint32_t *internal_node_child(void *node, uint32_t child_num);

uint32_t *internal_node_key(void *node, uint32_t key_num);

uint32_t get_node_max_key(void *node);

Cursor *internal_node_find(Table* table, uint32_t page_num, uint32_t key);

uint32_t *leaf_node_next_leaf(void *node);

#endif