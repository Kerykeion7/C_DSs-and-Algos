#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/Arrays/DynamicArray.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CDSsandAlgostest
{
	TEST_CLASS(CDSsandAlgostest)
	{
	public:

		TEST_METHOD(TestNotNull)
		{
			DynamicArray* arr = init(10);
			Assert::IsNotNull(arr);
		}
	};
}