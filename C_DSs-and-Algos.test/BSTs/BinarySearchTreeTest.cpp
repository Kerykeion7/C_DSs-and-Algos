#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/BSTs/BinarySearchTree.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTreeTest
{
	TEST_CLASS(BinarySearchTreeTest)
	{
	public:
		TEST_METHOD(TestNotNull) {
			BinarySearchTree* tree = init_bin_srch_tree();
			Assert::IsNotNull(tree);
		}
	};
}