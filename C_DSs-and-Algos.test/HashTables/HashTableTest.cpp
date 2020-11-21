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

		TEST_METHOD(Test_Get)
		{
			HashTable* table = SetUpTestHashTable();
			Assert::IsTrue(table->count == 12);

			Assert::IsTrue(table->exists(table, 1)
				&& table->exists(table, 2)
				&& table->exists(table, 3)
				&& table->exists(table, 4)
				&& table->exists(table, 88)
				&& table->exists(table, 37)
				&& table->exists(table, 38)
				&& table->exists(table, 111)
				&& table->exists(table, 234)
				&& table->exists(table, 9)
				&& table->exists(table, 23)
				&& table->exists(table, 14));

			Assert::IsNull(get_entry(table, 76));
			Assert::IsNull(table->get(table, 76));
			Assert::IsFalse(table->exists(table, 76));

			Assert::IsNull(get_entry(table, 0));
			Assert::IsNull(table->get(table, 0));
			Assert::IsFalse(table->exists(table, 0));

			table->add(table, 0, "ZeroTest");
			Assert::IsNotNull(get_entry(table, 0));
			Assert::IsNotNull(table->get(table, 0));
			Assert::IsTrue(table->exists(table, 0));

			Assert::AreEqual("TestOne", table->get(table, 1));
			Assert::AreEqual("TestTwo", table->get(table, 2));
			Assert::AreEqual("TestThree", table->get(table, 3));
			Assert::AreEqual("TestFour", table->get(table, 4));
			Assert::AreEqual("TestFive", table->get(table, 88));
			Assert::AreEqual("TestSix", table->get(table, 37));
			Assert::AreEqual("TestSeven", table->get(table, 38));
			Assert::AreEqual("TestEight", table->get(table, 111));
			Assert::AreEqual("TestNine", table->get(table, 234));
			Assert::AreEqual("TestTen", table->get(table, 9));
			Assert::AreEqual("TestEleven", table->get(table, 23));
			Assert::AreEqual("TestTwelve", table->get(table, 14));
		}

		TEST_METHOD(Test_Removing)
		{
			HashTable* table = SetUpTestHashTable();
			Assert::IsTrue(table->exists(table, 3));
			Assert::IsTrue(table->exists(table, 88));
			Assert::IsTrue(table->exists(table, 23));
			Assert::IsNotNull(get_entry(table, 3));
			Assert::IsNotNull(get_entry(table, 88));
			Assert::IsNotNull(get_entry(table, 23));
			table->remove_key_value_pair(table, 3);
			table->remove_key_value_pair(table, 88);
			table->remove_key_value_pair(table, 23);
			Assert::IsFalse(table->exists(table, 3));
			Assert::IsFalse(table->exists(table, 88));
			Assert::IsFalse(table->exists(table, 23));
			Assert::IsNull(get_entry(table, 3));
			Assert::IsNull(get_entry(table, 88));
			Assert::IsNull(get_entry(table, 23));
			table->add(table, 3, "New3");
			table->add(table, 88, "New88");
			table->add(table, 23, "New23");
			Assert::IsTrue(table->exists(table, 3));
			Assert::IsTrue(table->exists(table, 88));
			Assert::IsTrue(table->exists(table, 23));
			Assert::IsNotNull(get_entry(table, 3));
			Assert::IsNotNull(get_entry(table, 88));
			Assert::IsNotNull(get_entry(table, 23));
			Assert::AreEqual("New3", table->get(table, 3));
			Assert::AreEqual("New88", table->get(table, 88));
			Assert::AreEqual("New23", table->get(table, 23));
		}

		TEST_METHOD(Test_Overriding)
		{
			HashTable* table = SetUpTestHashTable();
			Assert::AreEqual("TestOne", table->get(table, 1));
			Assert::AreEqual("TestFour", table->get(table, 4));
			Assert::AreEqual("TestNine", table->get(table, 234));
			Assert::AreEqual("TestTen", table->get(table, 9));

			table->add(table, 1, "OverrideTestOne");
			table->add(table, 4, "OverrideTestFour");
			table->add(table, 234, "OverrideTestNine");
			table->add(table, 9, "OverrideTestTen");

			Assert::AreEqual("OverrideTestOne", table->get(table, 1));
			Assert::AreEqual("OverrideTestFour", table->get(table, 4));
			Assert::AreEqual("OverrideTestNine", table->get(table, 234));
			Assert::AreEqual("OverrideTestTen", table->get(table, 9));
		}

		TEST_METHOD(Test_Resizes_AtAppropriateTime)
		{
			HashTable* table = init_hashtable();
			Assert::IsTrue(table->capacity == 10 
				&& table->resize_treshold == 6
				&& table->count == 0);
			table->add(table, 1, "TestOne");
			table->add(table, 2, "TestTwo");
			table->add(table, 3, "TestThree");
			table->add(table, 4, "TestFour");
			table->add(table, 88, "TestFive");
			table->add(table, 37, "TestSix");
			table->add(table, 38, "TestSeven");
			table->add(table, 111, "TestEight");
			table->add(table, 234, "TestNine");
			table->add(table, 9, "TestTen");
			Assert::IsTrue(table->capacity == 20
				&& table->resize_treshold == 13
				&& table->count == 10);
			table->add(table, 23, "TestEleven");
			table->add(table, 14, "TestTwelve");
			table->add(table, 79, "TestThirteen");
			Assert::IsTrue(table->capacity == 40
				&& table->resize_treshold == (int)(40 * table->max_load_factor)
				&& table->count == 13);
		}

	private:
		HashTable* SetUpTestHashTable()
		{
			HashTable* table = init_hashtable();
			table->add(table, 1, "TestOne");
			table->add(table, 2, "TestTwo");
			table->add(table, 3, "TestThree");
			table->add(table, 4, "TestFour");
			table->add(table, 88, "TestFive");
			table->add(table, 37, "TestSix");
			table->add(table, 38, "TestSeven");
			table->add(table, 111, "TestEight");
			table->add(table, 234, "TestNine");
			table->add(table, 9, "TestTen");
			table->add(table, 23, "TestEleven");
			table->add(table, 14, "TestTwelve");
			return table;
		}
	};
}