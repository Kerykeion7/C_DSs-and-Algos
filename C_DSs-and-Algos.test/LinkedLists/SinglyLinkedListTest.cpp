#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/LinkedLists/SinglyLinkedList.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SinglyLinkedListTest
{
	TEST_CLASS(SinglyLinkedListTest)
	{
	public:

		TEST_METHOD(TestNotNull)
		{
			SinglyLinkedList* lst = initialize_singlyLinkedList();
			Assert::IsNotNull(lst);
		}

		TEST_METHOD(Test_GetSize_And_IsEmpty)
		{
			SinglyLinkedList* lst = initialize_singlyLinkedList();
			Assert::IsTrue(lst->is_sllst_empty(lst));
			Assert::IsTrue(lst->get_sllst_size(lst) == 0 && lst->length == 0);
			SetupTestLst(lst);
			Assert::IsFalse(lst->is_sllst_empty(lst));
			Assert::IsTrue(lst->get_sllst_size(lst) == 6 && lst->length == 6);
		}

		TEST_METHOD(Test_Get_Funx) {
			SinglyLinkedList* lst = initialize_singlyLinkedList();
			SetupTestLst(lst);
			Assert::IsTrue(lst->get_front(lst) == 1 && lst->get_back(lst) == 10);
			lst->push_front(lst, 0);
			lst->push_back(lst, 11);
			Assert::IsTrue(lst->get_front(lst) == 0 && lst->get_back(lst) == 11);
			Assert::AreEqual(lst->get_value_at_from_start(lst, 2), 4);
			Assert::AreEqual(lst->get_value_at_from_end(lst, 2), 7);
		}

		TEST_METHOD(Test_Pop_ReturnsCorrectValue)
		{
			SinglyLinkedList* lst = initialize_singlyLinkedList();
			SetupTestLst(lst);
			Assert::IsTrue(lst->get_sllst_size(lst) == 6 && lst->length == 6);
			Assert::IsTrue(lst->pop_front(lst) == 1 && lst->pop_back(lst) == 10);
			Assert::IsTrue(lst->get_sllst_size(lst) == 4 && lst->length == 4);
		}

		TEST_METHOD(Test_LinkedListNodes_AreCorrect)
		{
			SinglyLinkedList* lst = initialize_singlyLinkedList();
			SetupTestLst(lst);
			lst->insert_sllst_at(lst, 2, 1);
			lst->push_front(lst, 0);
			lst->insert_sllst_at(lst, 3, 3);
			lst->insert_sllst_at(lst, 8, 8);
			lst->insert_sllst_at(lst, 9, 9);
			Assert::AreEqual(11, lst->length);
			for (int i = 0; i < lst->length; i++)
			{
				Assert::AreEqual(i, lst->get_value_at_from_start(lst, i));
			}

			lst->reverse(lst);
			for (int i = 0; i < lst->length; i++)
			{
				Assert::AreEqual(i, lst->get_value_at_from_end(lst, i));
			}
		}

		TEST_METHOD(Test_Remove_Funx)
		{
			SinglyLinkedList* lst = initialize_singlyLinkedList();
			SetupTestLst(lst);

			Assert::AreEqual(6, lst->length);
			Assert::AreEqual(4, lst->get_value_at_from_start(lst, 1));
			lst->remove_value(lst, 4);
			Assert::AreEqual(5, lst->length);
			Assert::AreNotEqual(4, lst->get_value_at_from_start(lst, 1));
			Assert::AreEqual(5, lst->get_value_at_from_start(lst, 1));
			lst->sllst_remove_at(lst, 1);
			Assert::AreNotEqual(5, lst->get_value_at_from_start(lst, 1));
			Assert::AreEqual(6, lst->get_value_at_from_start(lst, 1));
		}

	private:
		void SetupTestLst(SinglyLinkedList* lst) {
			lst->push_front(lst, 5);
			lst->push_front(lst, 4);
			lst->push_back(lst, 6);
			lst->push_back(lst, 7);
			lst->push_back(lst, 10);
			lst->push_front(lst, 1);
		}
	};
}