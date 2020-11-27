#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/BSTs/BinarySearchTree.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTreeTest
{
	TEST_CLASS(BinarySearchTreeTest)
	{
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
			Assert::IsTrue(tree->Root == tree->Root->Parent);
			Assert::IsTrue(tree->Root->value == 5);
			Assert::IsNull(tree->Root->LeftChild);
			Assert::IsNull(tree->Root->RightChild);
		}

		TEST_METHOD(TestInsertion) {
			BinarySearchTree* tree = init_bin_srch_tree();
			insert_tree_node(tree, 5);
			insert_tree_node(tree, 3);
			Assert::IsNotNull(tree->Root->LeftChild);
			insert_tree_node(tree, 8);
			Assert::IsNotNull(tree->Root->RightChild);
			Assert::IsTrue(tree->Root->LeftChild->value == 3);
			Assert::IsTrue(tree->Root->RightChild->value == 8);
			Assert::IsTrue(tree->Root->RightChild->Parent == tree->Root 
				&& tree->Root->LeftChild->Parent == tree->Root);
			insert_tree_node(tree, 9);
			insert_tree_node(tree, 6);
			Assert::IsTrue(tree->Root->RightChild->RightChild->value = 9);
			Assert::IsTrue(tree->Root->RightChild->LeftChild->value = 6);
			insert_tree_node(tree, 1);
			insert_tree_node(tree, 4);
			insert_tree_node(tree, 1);
			insert_tree_node(tree, 4);
			Assert::IsTrue(tree->Root->LeftChild->LeftChild->value == 1);
			Assert::IsTrue(tree->Root->LeftChild->RightChild->value == 4);
			insert_tree_node(tree, 2);
			insert_tree_node(tree, -1);
			Assert::IsTrue(tree->Root->LeftChild->LeftChild->RightChild->value == 2);
			Assert::IsTrue(tree->Root->LeftChild->LeftChild->LeftChild->value == -1);
			Assert::IsTrue(tree->count == 9);
		}
	};
}