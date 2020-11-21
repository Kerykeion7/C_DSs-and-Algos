#include "pch.h"
#include "CppUnitTest.h"
#include "../../../C_DSs-and-Algos.proj/Queues/ArrayQueues/ArrayQ.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayQTest
{
	TEST_CLASS(ArrayQTest)
	{
	public:

		TEST_METHOD(TestNotNull)
		{
			ArrayQ* q = init_array_q();
			Assert::IsNotNull(q);
		}

		TEST_METHOD(Test_IsEmpty)
		{
			ArrayQ* q = init_array_q();
			Assert::IsTrue(q->count == 0 && q->is_arrayQ_empty(q));
			q->enqueue(q, 1);
			q->enqueue(q, 2);
			Assert::IsFalse(q->count == 0 && q->is_arrayQ_empty(q));
			Assert::IsTrue(q->count == 2 && !q->is_arrayQ_empty(q));
		}

		TEST_METHOD(Test_IsFull)
		{
			ArrayQ* q = SetupTestArrayQ();
			Assert::IsFalse(q->is_full(q));
			q->enqueue(q, 5);
			q->enqueue(q, 6);
			Assert::IsTrue(q->is_full(q));
		}

		TEST_METHOD(Test_Dequeuing_and_Enqueuing)
		{
			ArrayQ* q = SetupTestArrayQ();
			Assert::IsFalse(q->is_arrayQ_empty(q));
			q->enqueue(q, 5);
			q->enqueue(q, 6);
			Assert::IsTrue(q->count == 6);
			Assert::AreEqual(1, q->dequeue(q));
			Assert::IsTrue(q->count == 5);
			Assert::AreEqual(2, q->dequeue(q));
			Assert::AreEqual(3, q->dequeue(q));
			Assert::IsTrue(q->count == 3);
			Assert::AreEqual(4, q->dequeue(q));
			Assert::AreEqual(5, q->dequeue(q));
			Assert::AreEqual(6, q->dequeue(q));
			Assert::IsTrue(q->is_arrayQ_empty(q) && q->count == 0);
		}

	private:

		ArrayQ* SetupTestArrayQ()
		{
			ArrayQ* q = init_array_q();
			q->enqueue(q, 1);
			q->enqueue(q, 2);
			q->enqueue(q, 3);
			q->enqueue(q, 4);
			return q;
		}
	};
}