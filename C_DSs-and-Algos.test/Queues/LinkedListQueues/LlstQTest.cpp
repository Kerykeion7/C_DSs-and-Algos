#include "pch.h"
#include "CppUnitTest.h"
#include "../../../C_DSs-and-Algos.proj/Queues/LinkedListQueues/LlstQ.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LlstQTest
{
	TEST_CLASS(LlstQTest)
	{
	public:

		TEST_METHOD(TestNotNull)
		{
			LlstQ* q = init_lq_queue();
			Assert::IsNotNull(q);
		}

		TEST_METHOD(Test_IsEmpty)
		{
			LlstQ* q = init_lq_queue();
			Assert::IsTrue(q->count == 0 && q->is_Lq_empty(q));
			q->enqueue_Lq(q, 1);
			q->enqueue_Lq(q, 2);
			Assert::IsFalse(q->count == 0 && q->is_Lq_empty(q));
			Assert::IsTrue(q->count == 2 && !q->is_Lq_empty(q));
		}

		TEST_METHOD(Test_Dequeuing_and_Enqueuing)
		{
			LlstQ* q = SetupTestLlstQ();
			Assert::IsFalse(q->is_Lq_empty(q));
			q->enqueue_Lq(q, 5);
			q->enqueue_Lq(q, 6);
			Assert::IsTrue(q->count == 6);
			Assert::AreEqual(1, q->dequeue_Lq(q));
			Assert::IsTrue(q->count == 5);
			Assert::AreEqual(2, q->dequeue_Lq(q));
			Assert::AreEqual(3, q->dequeue_Lq(q));
			Assert::IsTrue(q->count == 3);
			Assert::AreEqual(4, q->dequeue_Lq(q));
			Assert::AreEqual(5, q->dequeue_Lq(q));
			Assert::AreEqual(6, q->dequeue_Lq(q));
			Assert::IsTrue(q->is_Lq_empty(q) && q->count == 0);
		}

	private:
		LlstQ* SetupTestLlstQ()
		{
			LlstQ* q = init_lq_queue();
			q->enqueue_Lq(q, 1);
			q->enqueue_Lq(q, 2);
			q->enqueue_Lq(q, 3);
			q->enqueue_Lq(q, 4);
			return q;
		}
	};
}