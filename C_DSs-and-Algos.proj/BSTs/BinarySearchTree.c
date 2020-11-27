#include <stdlib.h>
#include "BinarySearchTree.h"

BinarySearchTree* init_bin_srch_tree()
{
	BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
	if (!tree) return NULL;
	tree->Root = NULL;
	tree->count = 0;
	return tree;
}

BinarySearchTreeNode* traverse_and_return_parent(BinarySearchTreeNode* node, int value) {
	if (node->value == value) return NULL;
	if (!node->RightChild || !node->LeftChild) return node;
	if (value < node->value) return traverse_and_return_parent(node->LeftChild, value);
	return traverse_and_return_parent(node->RightChild, value);
}

void set_bin_srch_tree_root(BinarySearchTree* tree, int value) {
	tree->Root = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
	if (!tree->Root) exit(EXIT_FAILURE);
	tree->Root->value = value;
	tree->Root->Parent = tree->Root;
	tree->Root->LeftChild = NULL;
	tree->Root->RightChild = NULL;
}

BinarySearchTreeNode* set_new_tree_node(BinarySearchTreeNode* parent, int value) {
	BinarySearchTreeNode* newNode = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
	if (!newNode) exit(EXIT_FAILURE);
	newNode->Parent = parent;
	newNode->value = value;
	newNode->LeftChild = NULL;
	newNode->RightChild = NULL;
	return newNode;
}

void insert_tree_node(BinarySearchTree* tree, int value)
{
	if (!tree->Root) {
		set_bin_srch_tree_root(tree, value);
		tree->count++;
		return;
	}

	BinarySearchTreeNode* parent = traverse_and_return_parent(tree->Root, value);
	if (!parent) return;

	BinarySearchTreeNode* newNode = set_new_tree_node(parent, value);
	if (value < parent->value) parent->LeftChild = newNode;
	if (value > parent->value) parent->RightChild = newNode;
	tree->count++;
}

int get_tree_node_count(BinarySearchTree* tree)
{
	return tree->count;
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
