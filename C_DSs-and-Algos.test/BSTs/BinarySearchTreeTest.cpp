#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/BSTs/BinarySearchTree.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTreeTest
{
	TEST_CLASS(BinarySearchTreeTest)
	{
	private:
		BinarySearchTree* SetupTestTree() {
			BinarySearchTree* tree = init_bin_srch_tree();
			insert_tree_node(tree, 5);
			insert_tree_node(tree, 3);
			insert_tree_node(tree, 8);
			insert_tree_node(tree, 9);
			insert_tree_node(tree, 6);
			insert_tree_node(tree, 1);
			insert_tree_node(tree, 4);
			insert_tree_node(tree, 2);
			insert_tree_node(tree, -1);
			return tree;
		}

	public:
		TEST_METHOD(TestIsNull) {
			BinarySearchTree* tree = init_bin_srch_tree();
			Assert::IsNotNull(tree);
			Assert::IsNull(tree->Root);
		}

		TEST_METHOD(TestFirstInsertion) {
			BinarySearchTree* tree = init_bin_srch_tree();
			Assert::IsNull(tree->Root);
			insert_tree_node(tree, 5);
			Assert::IsNotNull(tree->Root);
			Assert::IsNull(tree->Root->Parent);
			Assert::IsTrue(tree->Root->value == 5);
			Assert::IsNull(tree->Root->LeftChild);
			Assert::IsNull(tree->Root->RightChild);
		}

		TEST_METHOD(TestInsertion) {
			BinarySearchTree* tree = SetupTestTree();
			Assert::IsNotNull(tree->Root->LeftChild);
			Assert::IsNotNull(tree->Root->RightChild);
			Assert::IsTrue(tree->Root->LeftChild->value == 3);
			Assert::IsTrue(tree->Root->RightChild->value == 8);
			Assert::IsTrue(tree->Root->RightChild->Parent == tree->Root 
				&& tree->Root->LeftChild->Parent == tree->Root);
			Assert::IsTrue(tree->Root->RightChild->RightChild->value = 9);
			Assert::IsTrue(tree->Root->RightChild->LeftChild->value = 6);
			insert_tree_node(tree, 1);
			insert_tree_node(tree, 4);
			Assert::IsTrue(tree->Root->LeftChild->LeftChild->value == 1);
			Assert::IsTrue(tree->Root->LeftChild->RightChild->value == 4);
			Assert::IsTrue(tree->Root->LeftChild->LeftChild->RightChild->value == 2);
			Assert::IsTrue(tree->Root->LeftChild->LeftChild->LeftChild->value == -1);
			Assert::IsTrue(tree->count == 9);
		}

		TEST_METHOD(TestGetOrdered) {
			BinarySearchTree* tree = SetupTestTree();
			int arr[9] = {-1, 1, 2, 3, 4, 5, 6, 8, 9};
			int* orderedVals = get_all_ordered(tree);
			for (int i = 0; i < 9; i++)
			{
				Assert::AreEqual(arr[i], *(orderedVals + i));
			}
		}

		TEST_METHOD(TestTreeDeletion) {
			BinarySearchTree* tree = SetupTestTree();
			Assert::IsNotNull(tree);
			Assert::IsNotNull(tree->Root);
			Assert::IsNotNull(tree->Root->LeftChild);
			Assert::IsNotNull(tree->Root->RightChild);
			delete_bin_srch_tree(tree);
		}

		TEST_METHOD(TestNodeDeletion) {
			BinarySearchTree* tree = SetupTestTree();
			insert_tree_node(tree, 7);
			Assert::AreEqual(10, tree->count);
			Assert::AreEqual(4, tree->Root->LeftChild->RightChild->value);
			Assert::IsTrue(tree_node_exists(tree, 4));
			delete_tree_node_by_given_value(tree, 4);

			Assert::AreEqual(9, tree->count);

			Assert::IsFalse(tree_node_exists(tree, 4));
			Assert::IsNull(tree->Root->LeftChild->RightChild);
			Assert::AreEqual(8, tree->Root->RightChild->value);
			Assert::IsTrue(tree_node_exists(tree, 8));
			Assert::AreEqual(7, tree->Root->RightChild->LeftChild->RightChild->value);
			delete_tree_node_by_given_value(tree, 8);

			Assert::AreEqual(8, tree->count);

			Assert::IsFalse(tree_node_exists(tree, 8));
			Assert::AreEqual(7, tree->Root->RightChild->value);
			Assert::AreEqual(6, tree->Root->RightChild->LeftChild->value);
			Assert::IsNull(tree->Root->RightChild->LeftChild->RightChild);
			Assert::AreEqual(5, tree->Root->value);
			Assert::IsTrue(tree_node_exists(tree, 5));
			delete_tree_node_by_given_value(tree, 5);

			Assert::AreEqual(7, tree->count);

			Assert::IsFalse(tree_node_exists(tree, 5));
			Assert::AreEqual(3, tree->Root->value);
			Assert::AreEqual(7, tree->Root->RightChild->value);
			Assert::AreEqual(1, tree->Root->LeftChild->value);
			Assert::AreEqual(2, tree->Root->LeftChild->RightChild->value);
			insert_tree_node(tree, 12);

			Assert::AreEqual(4, get_tree_height(tree));
			insert_tree_node(tree, 8);

			Assert::AreEqual(4, get_tree_height(tree));
			Assert::AreEqual(9, tree->Root->RightChild->RightChild->value);
			Assert::AreEqual(12, tree->Root->RightChild->RightChild->RightChild->value);
			Assert::AreEqual(8, tree->Root->RightChild->RightChild->LeftChild->value);
			insert_tree_node(tree, 10);

			Assert::AreEqual(5, get_tree_height(tree));
			Assert::AreEqual(10, tree->Root->RightChild->RightChild->RightChild->LeftChild->value);
			Assert::AreEqual(10, tree->count);

			delete_tree_node_by_given_value(tree, 3);
			Assert::IsTrue(tree->Root->value == 2
				&& !tree_node_exists(tree, 3)
				&& get_tree_node_count(tree) == 9
				&& tree->Root->LeftChild->value == 1 
				&& tree->Root->LeftChild->LeftChild->value == -1
				&& tree->Root->RightChild->value == 7);
			Assert::IsNull(tree->Root->LeftChild->RightChild);
		}

		TEST_METHOD(TestExists) {
			BinarySearchTree* tree = SetupTestTree();
			Assert::IsTrue(tree_node_exists(tree, 9));
			Assert::IsTrue(tree_node_exists(tree, -1));
			Assert::IsTrue(tree_node_exists(tree, 5));
			Assert::IsFalse(tree_node_exists(tree, 11));
			insert_tree_node(tree, 11);
			Assert::IsTrue(tree_node_exists(tree, 11));
			Assert::IsFalse(tree_node_exists(tree, 30));
		}

		TEST_METHOD(TestGetHeight) {
			BinarySearchTree* tree = SetupTestTree();
			Assert::AreEqual(4, get_tree_height(tree));
		}

		TEST_METHOD(TestGetHeightB) {
			BinarySearchTree* tree = init_bin_srch_tree();
			Assert::AreEqual(0, get_tree_height(tree));
			insert_tree_node(tree, 10);
			Assert::AreEqual(1, get_tree_height(tree));
			insert_tree_node(tree, 20);
			insert_tree_node(tree, 15);
			Assert::AreEqual(15, tree->Root->RightChild->LeftChild->value);
			Assert::AreEqual(3, get_tree_height(tree));
			insert_tree_node(tree, 1);
			Assert::AreEqual(3, get_tree_height(tree));
			insert_tree_node(tree, 5);
			Assert::AreEqual(3, get_tree_height(tree));
			insert_tree_node(tree, 7);
			Assert::AreEqual(4, get_tree_height(tree));
			insert_tree_node(tree, 2);
			Assert::AreEqual(4, get_tree_height(tree));
		}

		TEST_METHOD(GetMinValue) {
			BinarySearchTree* tree = SetupTestTree();
			Assert::AreEqual(-1, get_min_tree_value(tree));
		}

		TEST_METHOD(GetMinValueB) {
			BinarySearchTree* tree = init_bin_srch_tree();
			insert_tree_node(tree, 10);
			insert_tree_node(tree, 20);
			insert_tree_node(tree, 15);
			insert_tree_node(tree, 1);
			insert_tree_node(tree, 5);
			insert_tree_node(tree, 7);
			insert_tree_node(tree, 2);
			Assert::AreEqual(1, get_min_tree_value(tree));
		}
		TEST_METHOD(GetMaxValue) {
			BinarySearchTree* tree = SetupTestTree();
			Assert::AreEqual(9, get_max_tree_value(tree));
		}

		TEST_METHOD(GetMaxValueB) {
			BinarySearchTree* tree = init_bin_srch_tree();
			insert_tree_node(tree, 10);
			insert_tree_node(tree, 20);
			insert_tree_node(tree, 15);
			insert_tree_node(tree, 1);
			insert_tree_node(tree, 5);
			insert_tree_node(tree, 7);
			insert_tree_node(tree, 2);
			Assert::AreEqual(20, get_max_tree_value(tree));
		}

		TEST_METHOD(TestIsBinarySearchTree) {
			BinarySearchTree* tree = SetupTestTree();
			BinarySearchTree* tree1 = init_bin_srch_tree();
			insert_tree_node(tree1, 10);
			insert_tree_node(tree1, 20);
			insert_tree_node(tree1, 15);
			insert_tree_node(tree1, 1);
			insert_tree_node(tree1, 5);
			insert_tree_node(tree1, 7);
			insert_tree_node(tree1, 2);
			Assert::IsTrue(is_bin_srch_tree(tree));
			Assert::IsTrue(is_bin_srch_tree(tree1));
		}

		TEST_METHOD(TestGetSuccessor) {
			BinarySearchTree* tree = SetupTestTree();
			Assert::AreEqual(1, get_successor_of(tree, -1));
			Assert::AreEqual(-1, get_successor_of(tree, 9));
			Assert::AreEqual(9, get_successor_of(tree, 8));
		}
	};
}