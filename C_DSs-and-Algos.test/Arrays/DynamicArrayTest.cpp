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
			Assert::IsNotNull(arr);
		}
	};
}