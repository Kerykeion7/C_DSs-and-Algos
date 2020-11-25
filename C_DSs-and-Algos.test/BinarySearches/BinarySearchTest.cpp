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
			int result = binary_search(arr, 10, 7);
			Assert::AreEqual(7, result);
		}

		TEST_METHOD(TestB)
		{
			int arr[20] = {5, 10, 13, 21, 25, 35, 42, 68, 69, 72, 73, 76, 85, 99, 101, 102, 111, 209, 235, 333};
			int result = binary_search(arr, 20, 111);
			Assert::AreEqual(111, result);
		}

		TEST_METHOD(TestC)
		{
			int arr[2] = { 5, 10 };
			int result = binary_search(arr, 2, 5);
			Assert::AreEqual(5, result);
		}
	};
}