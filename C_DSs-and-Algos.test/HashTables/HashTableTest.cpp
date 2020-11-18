#include "pch.h"
#include "CppUnitTest.h"
#include "../../C_DSs-and-Algos.proj/HashTables/HashTable.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:

		TEST_METHOD(TestNotNull)
		{
			HashTable* table = init_hashtable();
			Assert::IsNotNull(table);
		}
	};
}