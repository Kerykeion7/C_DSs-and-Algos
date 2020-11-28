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
	if (value < node->value) {
		if (!node->LeftChild) return node;
		return traverse_and_return_parent(node->LeftChild, value);
	}
	if (!node->RightChild) return node;
	return traverse_and_return_parent(node->RightChild, value);
}

void set_bin_srch_tree_root(BinarySearchTree* tree, int value) {
	tree->Root = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
	if (!tree->Root) exit(EXIT_FAILURE);
	tree->Root->value = value;
	tree->Root->Parent = NULL;
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

int _index = 0;
void order_values(BinarySearchTreeNode* node, int treeCount, int* values) {
	if (node) {
		if (_index == treeCount) return;
		order_values(node->LeftChild, treeCount, values);
		*(values + _index) = node->value;
		_index++;
		order_values(node->RightChild, treeCount, values);
	}
}

int* get_all_ordered(BinarySearchTree* tree)
{
	_index = 0;
	int* values = (int*)malloc(tree->count * sizeof(int));
	if(!values) exit(EXIT_FAILURE);
	order_values(tree->Root, tree->count, values);
	return values;
}

void destroy_bin_srch_tree_node(BinarySearchTreeNode* node) {
	node->Parent = NULL;
	node->LeftChild = NULL;
	node->RightChild = NULL;
	node = NULL;
	free(node);
}

void traverse_to_destroy(BinarySearchTreeNode* node) {
	if (node) {
		traverse_to_destroy(node->LeftChild);
		traverse_to_destroy(node->RightChild);
		destroy_bin_srch_tree_node(node);
	}
}

void delete_bin_srch_tree(BinarySearchTree* tree)
{
	traverse_to_destroy(tree->Root);
	tree = NULL;
	free(tree);
}

BinarySearchTreeNode* traverse_and_return_node_with_given_value(BinarySearchTreeNode* node, int value) {
	if (!node) return NULL;
	if (node->value == value) return node;
	if (value < node->value) return traverse_and_return_node_with_given_value(node->LeftChild, value);
	return traverse_and_return_node_with_given_value(node->RightChild, value);
}

bool tree_node_exists(BinarySearchTree* tree, int value)
{
	return (traverse_and_return_node_with_given_value(tree->Root, value));
}

int count_node_depth(BinarySearchTreeNode* node) {
	if (!node) return 0;
	int leftCount = count_node_depth(node->LeftChild);
	int rightCount = count_node_depth(node->RightChild);

	if (leftCount > rightCount) return leftCount + 1;
	return rightCount + 1;
}

int get_tree_height(BinarySearchTree* tree)
{
	if (!tree->Root) return 0;
	return count_node_depth(tree->Root);
}

int get_left_min_val(BinarySearchTreeNode* node) {
	if (node->LeftChild) return get_left_min_val(node->LeftChild);
	return node->value;
}

int get_min_tree_value(BinarySearchTree* tree)
{
	if (!tree->Root) return 0;
	return get_left_min_val(tree->Root);
}

int get_right_max_val(BinarySearchTreeNode* node) {
	if (node->RightChild) return get_right_max_val(node->RightChild);
	return node->value;
}

int get_max_tree_value(BinarySearchTree* tree)
{
	if (!tree->Root) return 0;
	return get_right_max_val(tree->Root);
}

bool left_is_all_smaller(BinarySearchTreeNode* node, int rootValue) {
	if (node) {
		if (node->value > rootValue) return false;
		left_is_all_smaller(node->LeftChild, rootValue);
		left_is_all_smaller(node->RightChild, rootValue);
	}
}

bool right_is_all_bigger(BinarySearchTreeNode* node, int rootValue) {
	if (node) {
		if (node->value < rootValue) return false;
		right_is_all_bigger(node->LeftChild, rootValue);
		right_is_all_bigger(node->RightChild, rootValue);
	}
}

bool is_bst(BinarySearchTreeNode* node) {
	if (node) {
		if (!left_is_all_smaller(node->LeftChild, node->value) ||
			!right_is_all_bigger(node->RightChild, node->value))
			return false;
		is_bst(node->LeftChild);
		is_bst(node->RightChild);
	}
}

bool is_bin_srch_tree(BinarySearchTree* tree)
{
	if (!tree->Root) return true;

	return is_bst(tree->Root);

	return false;
}

void replace_parent_or_root(BinarySearchTree* tree, BinarySearchTreeNode* parent, BinarySearchTreeNode* newNode) {
	if (parent) {
		if (parent->value < newNode->value) parent->RightChild = newNode;
		if (parent->value > newNode->value) parent->LeftChild = newNode;
	}
	else tree->Root = newNode;
}

void replace_with_left_child(BinarySearchTree* tree, BinarySearchTreeNode* node) {
	node->LeftChild->Parent = node->Parent;
	if (node->RightChild) {
		node->RightChild->Parent = node->LeftChild;
		node->LeftChild->RightChild = node->RightChild;
	}
	replace_parent_or_root(tree, node->Parent, node->LeftChild);
}

void replace_with_right_child(BinarySearchTree* tree, BinarySearchTreeNode* node) {
	node->RightChild->Parent = node->Parent;
	if (node->LeftChild) {
		node->LeftChild->Parent = node->RightChild;
		node->RightChild->LeftChild = node->LeftChild;
	}
	replace_parent_or_root(tree, node->Parent, node->RightChild);
}

void just_remove_when_childless(BinarySearchTreeNode* node) {
	if (!node->RightChild && !node->LeftChild) {
		if (node->Parent) {
			if (node->value < node->Parent->value) node->Parent->LeftChild = NULL;
			if (node->value > node->Parent->value) node->Parent->RightChild = NULL;
		}
	}
	destroy_bin_srch_tree_node(node);
}

void remove_and_replace_appropriately(BinarySearchTree* tree, BinarySearchTreeNode* node) {
	if (node->LeftChild && !node->RightChild) replace_with_left_child(tree, node);
	if (node->RightChild && !node->LeftChild) replace_with_right_child(tree, node);
	just_remove_when_childless(node);
	tree->count--;
}

void dig_as_far_right_of_left_sub_tree_and_replace_appropriately(BinarySearchTree* tree, BinarySearchTreeNode* nodeToRemove, BinarySearchTreeNode* nodeToReplaceWith) {
	if (nodeToReplaceWith->RightChild) {
		dig_as_far_right_of_left_sub_tree_and_replace_appropriately(tree, nodeToRemove, nodeToReplaceWith->RightChild);
		return;
	}
	BinarySearchTreeNode* tempNodeToRemove = nodeToRemove;
	BinarySearchTreeNode* tempNodeToReplaceWith = nodeToReplaceWith;
	remove_and_replace_appropriately(tree, nodeToReplaceWith);
	nodeToRemove = nodeToReplaceWith;
	nodeToReplaceWith->Parent = tempNodeToRemove->Parent;

	if (tempNodeToRemove->Parent) tempNodeToRemove->Parent->RightChild = nodeToReplaceWith;
	else tree->Root = nodeToReplaceWith;

	nodeToReplaceWith->LeftChild = tempNodeToRemove->LeftChild;
	nodeToReplaceWith->RightChild = tempNodeToRemove->RightChild;
	tempNodeToRemove->LeftChild->Parent = nodeToReplaceWith;
	tempNodeToRemove->RightChild->Parent = nodeToReplaceWith;

	destroy_bin_srch_tree_node(tempNodeToRemove);
}

void remove_and_replace_with_appropriate_child(BinarySearchTree* tree, BinarySearchTreeNode* node) {
	if (!node) exit(EXIT_FAILURE);

	if (node->LeftChild && node->RightChild) dig_as_far_right_of_left_sub_tree_and_replace_appropriately(tree, node, node->LeftChild);
	else remove_and_replace_appropriately(tree, node);
}

void delete_tree_node_by_given_value(BinarySearchTree* tree, int value)
{
	remove_and_replace_with_appropriate_child(
		tree,
		traverse_and_return_node_with_given_value(tree->Root, value));
}

int get_successor_of(BinarySearchTree* tree, int value)
{
	int* values = get_all_ordered(tree);
	for (int i = 0; i < _index; i++)
	{
		if (*(values + i) > value) return *(values + i);
	}

	return -1;
}
