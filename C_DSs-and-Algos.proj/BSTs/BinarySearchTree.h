#include <stdbool.h>
#include "BinarySearchTreeNode.h"

typedef struct BinarySearchTree {
	struct BinarySearchTreeNode* Root;
} BinarySearchTree;

BinarySearchTree* init_bin_srch_tree();
void insert_tree_node(BinarySearchTree* tree, int value);
int get_tree_node_count(BinarySearchTree* tree);
int* get_all_ordered(BinarySearchTree* tree);
void delete_bin_srch_tree(BinarySearchTree* tree);
bool tree_node_exists(BinarySearchTree* tree, int value);
int get_tree_height(BinarySearchTree* tree);
int get_min_tree_value(BinarySearchTree* tree);
int get_max_tree_value(BinarySearchTree* tree);
void delete_tree_node_by_given_value(BinarySearchTree* tree, int value);
int get_successor_of(BinarySearchTree* tree, int value);



