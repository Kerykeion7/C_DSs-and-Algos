#include <stdlib.h>
#include "BinarySearchTree.h"

BinarySearchTree* init_bin_srch_tree()
{
	BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
	if (!tree) return NULL;
	return tree;
}

void insert_tree_node(BinarySearchTree* tree, int value)
{
}

int get_tree_node_count(BinarySearchTree* tree)
{
	return 0;
}

int* get_all_ordered(BinarySearchTree* tree)
{
	return NULL;
}

void delete_bin_srch_tree(BinarySearchTree* tree)
{
}

bool tree_node_exists(BinarySearchTree* tree, int value)
{
	return false;
}

int get_tree_height(BinarySearchTree* tree)
{
	return 0;
}

int get_min_tree_value(BinarySearchTree* tree)
{
	return 0;
}

int get_max_tree_value(BinarySearchTree* tree)
{
	return 0;
}

void delete_tree_node_by_given_value(BinarySearchTree* tree, int value)
{
}

int get_successor_of(BinarySearchTree* tree, int value)
{
	return 0;
}
