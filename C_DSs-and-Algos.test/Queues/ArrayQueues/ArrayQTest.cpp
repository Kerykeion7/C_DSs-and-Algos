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

	private:

		void SetupTestArrayQ(ArrayQ* q)
		{
			q->enqueue(q, 2);
			q->enqueue(q, 3);
			q->enqueue(q, 4);
			q->enqueue(q, 5);
		}
	};
}