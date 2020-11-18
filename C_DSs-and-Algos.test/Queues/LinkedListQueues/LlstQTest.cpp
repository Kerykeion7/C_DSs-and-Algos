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
	};
}