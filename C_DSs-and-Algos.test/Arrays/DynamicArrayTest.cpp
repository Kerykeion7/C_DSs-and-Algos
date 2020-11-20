#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/Arrays/DynamicArray.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayTest
{
	TEST_CLASS(DynamicArrayTest)
	{
	public:

		TEST_METHOD(TestNotNull)
		{
			DynamicArray* arr = init(10);
			Assert::AreEqual(arr->count, 0);
			Assert::AreEqual(arr->capacity, 10);
			Assert::IsNotNull(arr);
		}

		TEST_METHOD(TestDynamicArrayCapacityEquals12AfterResize)
		{
			DynamicArray* arr = init(2);
			Assert::AreEqual(arr->capacity, 6);
			SetUpMainArray(arr);
			Assert::AreEqual(arr->capacity, 12);
		}

		TEST_METHOD(TestArrayResizesAtAppropriateTimes)
		{
			DynamicArray* arr = init(2);
			SetUpMainArray(arr);
			Assert::AreEqual(arr->count, 8);
			Assert::AreEqual(arr->capacity, 12);
			arr->push(arr, 11);
			arr->push(arr, 12);
			arr->push(arr, 13);
			arr->push(arr, 14);
			Assert::AreEqual(arr->count, arr->capacity);
			arr->push(arr, 15);
			Assert::AreEqual(arr->count, 13);
			Assert::AreEqual(arr->capacity, 24);
			arr->pop(arr);
			arr->pop(arr);
			arr->pop(arr);
			arr->pop(arr);
			Assert::AreEqual(arr->count, 9);
			Assert::AreEqual(arr->capacity, 24);
			arr->pop(arr);
			arr->pop(arr);
			arr->pop(arr);
			Assert::AreEqual(arr->count, 6);
			Assert::AreEqual(arr->capacity, 6);
		}

		TEST_METHOD(TestPopReturnsCorrectValue) {
			DynamicArray* arr = init(2);
			SetUpMainArray(arr);
			Assert::AreEqual(10, arr->pop(arr));
		}

		TEST_METHOD(TestIsEmpty) {
			DynamicArray* arr = init(2);
			Assert::IsTrue(arr->is_empty(arr));
			SetUpMainArray(arr);
			Assert::IsFalse(arr->is_empty(arr));
		}

		TEST_METHOD(TestClear) {
			DynamicArray* arr = init(2);
			SetUpMainArray(arr);
			Assert::AreEqual(8, arr->count);
			Assert::AreEqual(8, arr->get_size(arr));
			Assert::AreEqual(12, arr->capacity);
			Assert::AreEqual(12, arr->get_capacity(arr));
			Assert::IsFalse(arr->is_empty(arr));
			arr->clear(arr);
			Assert::IsTrue(arr->is_empty(arr));
			arr->push(arr, 1);
			arr->push(arr, 2);
			arr->push(arr, 7);
			arr->push(arr, 111);
			Assert::AreEqual(4, arr->count);
			Assert::AreEqual(2, arr->index_of(arr, 7));
			arr->clear(arr);
			Assert::AreEqual(-1, arr->index_of(arr, 7));
			Assert::IsTrue(arr->is_empty(arr));
		}

		TEST_METHOD(TestArrayItemsAreCorrect)
		{
			DynamicArray* arr = init(2);
			SetUpMainArray(arr);
			Assert::AreEqual(12, arr->capacity);
			arr->push(arr, 11);
			arr->push(arr, 12);
			arr->insert_at(arr, 2, 3);
			arr->prepend(arr, 0);
			arr->insert_at(arr, 7, 7);
			Assert::AreEqual(13, arr->count);
			Assert::AreEqual(24, arr->capacity);
			for (int i = 0; i < arr->count; i++)
			{
				Assert::AreEqual((int)i, arr->index_of(arr, i));
			}
		}

		TEST_METHOD(Test_RemoveItem_RemovesAll)
		{
			DynamicArray* arr = init(2);
			SetUpMainArray(arr);
			arr->insert_at(arr, 2, 2);
			arr->insert_at(arr, 7, 2);
			arr->push(arr, 2);
			Assert::AreNotEqual(-1, arr->index_of(arr, 2));
			arr->remove_item(arr, 2);
			Assert::AreEqual(-1, arr->index_of(arr, 2));
		}

		TEST_METHOD(Test_RemoveAt_Method)
		{
			DynamicArray* arr = init(2);
			SetUpMainArray(arr);
			Assert::AreEqual(2, arr->index_of(arr, 4));
			arr->remove_at(arr, 2);
			Assert::AreNotEqual(2, arr->index_of(arr, 4));
			Assert::AreEqual(2, arr->index_of(arr, 5));
		}

		TEST_METHOD(Test_GetAt_Method)
		{
			DynamicArray* arr = init(2);
			SetUpMainArray(arr);
			Assert::IsTrue(5 == arr->get_at(arr, 3));
		}

	private:
		void SetUpMainArray(DynamicArray* arr) 
		{
			arr->push(arr, 1);
			arr->push(arr, 2);
			arr->push(arr, 4);
			arr->push(arr, 5);
			arr->push(arr, 6);
			arr->push(arr, 8);
			arr->push(arr, 9);
			arr->push(arr, 10);
		}
	};
}