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
	};
}