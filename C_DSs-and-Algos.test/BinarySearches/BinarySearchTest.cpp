#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/BinarySearches/BinarySearch.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTest
{
	TEST_CLASS(BinarySearchTest)
	{
	public:

		TEST_METHOD(TestA)
		{
			int* arr = (int*)malloc(10 * sizeof(int));
			if (!arr) exit(EXIT_FAILURE);
			for (int i = 0; i < 10; i++)
			{
				arr[i] = i * 2 + 1;
			}
			Assert::AreEqual(1, binary_search(arr, 10, 1));
			Assert::AreEqual(3, binary_search(arr, 10, 3));
			Assert::AreEqual(5, binary_search(arr, 10, 5));
			Assert::AreEqual(7, binary_search(arr, 10, 7));
			Assert::AreEqual(9, binary_search(arr, 10, 9));
			Assert::AreEqual(11, binary_search(arr, 10, 11));
			Assert::AreEqual(13, binary_search(arr, 10, 13));
			Assert::AreEqual(15, binary_search(arr, 10, 15));
			Assert::AreEqual(17, binary_search(arr, 10, 17));
			Assert::AreEqual(19, binary_search(arr, 10, 19));
		}

		TEST_METHOD(TestB)
		{
			int arr[20] = {5, 10, 13, 21, 25, 35, 42, 68, 69, 72, 73, 76, 85, 99, 101, 102, 111, 209, 235, 333};
			Assert::AreEqual(5, binary_search(arr, 20, 5));
			Assert::AreEqual(10, binary_search(arr, 20, 10));
			Assert::AreEqual(13, binary_search(arr, 20, 13));
			Assert::AreEqual(21, binary_search(arr, 20, 21));
			Assert::AreEqual(25, binary_search(arr, 20, 25));
			Assert::AreEqual(35, binary_search(arr, 20, 35));
			Assert::AreEqual(42, binary_search(arr, 20, 42));
			Assert::AreEqual(68, binary_search(arr, 20, 68));
			Assert::AreEqual(69, binary_search(arr, 20, 69));
			Assert::AreEqual(72, binary_search(arr, 20, 72));
			Assert::AreEqual(73, binary_search(arr, 20, 73));
			Assert::AreEqual(76, binary_search(arr, 20, 76));
			Assert::AreEqual(85, binary_search(arr, 20, 85));
			Assert::AreEqual(99, binary_search(arr, 20, 99));
			Assert::AreEqual(101, binary_search(arr, 20, 101));
			Assert::AreEqual(102, binary_search(arr, 20, 102));
			Assert::AreEqual(111, binary_search(arr, 20, 111));
			Assert::AreEqual(209, binary_search(arr, 20, 209));
			Assert::AreEqual(235, binary_search(arr, 20, 235));
			Assert::AreEqual(333, binary_search(arr, 20, 333));
		}

		TEST_METHOD(TestC)
		{
			int arr[2] = { 5, 10 };
			Assert::AreEqual(5, binary_search(arr, 2, 5));
			Assert::AreEqual(10, binary_search(arr, 2, 10));
		}
	};
}