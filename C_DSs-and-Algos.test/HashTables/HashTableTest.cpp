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

		TEST_METHOD(Test_Hash_AlwaysReturnsSameValue)
		{
			HashTable* table = init_hashtable();
			int twentyFiveHash = hash(25, table->capacity);
			int thirtyThreeHash = hash(33, table->capacity);
			int fortyFiveHash = hash(45, table->capacity);
			int oneHash = hash(1, table->capacity);

			for (size_t i = 0; i < 10; i++)
			{
				Assert::AreEqual(twentyFiveHash, hash(25, table->capacity));
				Assert::AreEqual(thirtyThreeHash, hash(33, table->capacity));
				Assert::AreEqual(fortyFiveHash, hash(45, table->capacity));
				Assert::AreEqual(oneHash, hash(1, table->capacity));
			}
		}
	};
}