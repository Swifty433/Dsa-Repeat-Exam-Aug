#include "pch.h"
#include "CppUnitTest.h"

#include "../MySet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySetTest
{
	// Helper function to check if a set contains a value
	void AssertContains(const MySet<int>& s, int value)
	{
		Assert::IsTrue(s.search(value) >= 0, L"Set does not contain expected value");
	}

	TEST_CLASS(MySetTests)
	{
		TEST_METHOD(TestInserting)
		{
			MySet<int> s;
			s.insert(5);
			Assert::AreEqual(1, s.length());
			Assert::AreEqual(5, s.getElement(0));
		}

		TEST_METHOD(TestInsertion)
		{
			MySet<int> s;
			s.insert(1);
			s.insert(2);
			s.insert(3);
			Assert::AreEqual(3, s.length());
		}

		TEST_METHOD(TestInsertionDuplicate)
		{
			MySet<int> s;
			s.insert(1);
			s.insert(1);
			Assert::AreEqual(1, s.length());
		}

		TEST_METHOD(TestRemove)
		{
			MySet<int> s;
			s.insert(10);
			s.remove(0);
			Assert::AreEqual(0, s.length());
		}

		TEST_METHOD(TestRemoveMany)
		{
			MySet<int> s;
			s.insert(10);
			s.insert(20);
			s.insert(30);
			s.remove(0);
			s.remove(1);
			Assert::AreEqual(1, s.length());
		}

		TEST_METHOD(TestRemoveMiddle)
		{
			MySet<int> s;
			s.insert(1);
			s.insert(2);
			s.insert(3);
			s.remove(1);
			Assert::AreEqual(2, s.length());
			Assert::AreEqual(1, s.getElement(0));
			Assert::AreEqual(3, s.getElement(1));
		}

		TEST_METHOD(TestRemoveInvalidIndex)
		{
			MySet<int> s;
			s.insert(1);
			Assert::IsFalse(s.remove(5));
		}

		TEST_METHOD(TestClear)
		{
			MySet<int> s;
			s.insert(1);
			s.insert(2);
			s.clear();
			Assert::AreEqual(0, s.length());
		}

		TEST_METHOD(TestSearch)
		{
			MySet<int> s;
			s.insert(5);
			Assert::AreEqual(0, s.search(5));
		}

		TEST_METHOD(TestSearchNotFound)
		{
			MySet<int> s;
			s.insert(5);
			Assert::AreEqual(-1, s.search(10));
		}

		TEST_METHOD(TestGetElement)
		{
			MySet<int> s;
			s.insert(10);
			Assert::AreEqual(10, s.getElement(0));
			s.insert(20);
			Assert::AreEqual(20, s.getElement(1));
		}

		TEST_METHOD(TestGetElementInvalidIndex)
		{
			MySet<int> s;
			s.insert(1);
			Assert::AreEqual(0, s.getElement(-1)); // assuming default T() is 0
			Assert::AreEqual(0, s.getElement(5));
		}

		TEST_METHOD(TestLengthEmpty)
		{
			MySet<int> s;
			Assert::AreEqual(0, s.length());
		}

		TEST_METHOD(TestLength)
		{
			MySet<int> s;
			s.insert(1);
			s.insert(2);
			Assert::AreEqual(2, s.length());
		}

		TEST_METHOD(TestInsertMany)
		{
			MySet<int> s;
			for (int i = 0; i < 50; i++)
				s.insert(i);
			Assert::AreEqual(50, s.length());
		}

		TEST_METHOD(TestRemoveAll)
		{
			MySet<int> s;
			for (int i = 0; i < 10; i++)
				s.insert(i);
			for (int i = 0; i < 10; i++)
				s.remove(0);
			Assert::AreEqual(0, s.length());
		}

		TEST_METHOD(TestDuplicateInsertMany)
		{
			MySet<int> s;
			for (int i = 0; i < 5; i++)
			{
				s.insert(1); // all duplicates
			}
			Assert::AreEqual(1, s.length());
		}

		TEST_METHOD(TestInsertOrder)
		{
			MySet<int> s;
			s.insert(5);
			s.insert(3);
			s.insert(4);
			Assert::AreEqual(3, s.getElement(0));
			Assert::AreEqual(4, s.getElement(1));
			Assert::AreEqual(5, s.getElement(2));
		}

		TEST_METHOD(TestRemoveFromEmpty)
		{
			MySet<int> s;
			Assert::IsFalse(s.remove(0));
		}

		//Cant get them to work
		TEST_METHOD(TestUnionBasic)
		{
			MySet<int> a;
			a.insert(1);
			a.insert(2);
			MySet<int> b;
			b.insert(2);
			b.insert(3);

			MySet<int> c = a | b;

			Assert::AreEqual(3, c.length());
			AssertContains(c, 1);
			AssertContains(c, 2);
			AssertContains(c, 3);
		}

		TEST_METHOD(TestUnionWithEmpty)
		{
			MySet<int> a;
			a.insert(5);
			MySet<int> b; // empty set

			MySet<int> c = a | b;

			Assert::AreEqual(1, c.length());
			AssertContains(c, 5);
		}

		TEST_METHOD(TestUnionDuplicates)
		{
			MySet<int> a;
			a.insert(1);
			a.insert(2);
			MySet<int> b;
			b.insert(1);
			b.insert(2);

			MySet<int> c = a | b;

			Assert::AreEqual(2, c.length());
			AssertContains(c, 1);
			AssertContains(c, 2);
		}

		TEST_METHOD(TestIntersectionBasic)
		{
			MySet<int> a;
			a.insert(1);
			a.insert(2);
			a.insert(3);
			MySet<int> b;
			b.insert(2);
			b.insert(3);
			b.insert(4);

			MySet<int> c = a & b;

			Assert::AreEqual(2, c.length());
			AssertContains(c, 2);
			AssertContains(c, 3);
		}

		TEST_METHOD(TestIntersectionNoCommon)
		{
			MySet<int> a;
			a.insert(1);
			a.insert(2);
			MySet<int> b;
			b.insert(3);
			b.insert(4);

			MySet<int> c = a & b;

			Assert::AreEqual(0, c.length());
		}

		TEST_METHOD(TestIntersectionWithEmpty)
		{
			MySet<int> a;
			a.insert(1);
			MySet<int> b; // empty

			MySet<int> c = a & b;

			Assert::AreEqual(0, c.length());
		}
	};
}