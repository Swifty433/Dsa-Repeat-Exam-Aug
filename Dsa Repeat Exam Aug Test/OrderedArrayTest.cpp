#include "pch.h"
#include "CppUnitTest.h"
#include "..\OrderedArray.h"
#include "../OrderedArray.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OrderedArrayTest
{
	TEST_CLASS(OrderedArrayTest)
	{
	public:
		
        TEST_METHOD(TestPushMaintainsNaturalOrder)
        {
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);
			arr.push(1);

			Assert::AreEqual(4, arr.length());
			Assert::AreEqual(1, arr.getElement(0));
			Assert::AreEqual(3, arr.getElement(1));
			Assert::AreEqual(5, arr.getElement(2));
			Assert::AreEqual(8, arr.getElement(3));
        }

		TEST_METHOD(TestRemoveElement)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);

			Assert::AreEqual(true, arr.remove(1));
			Assert::AreEqual(2, arr.length());
		}

		TEST_METHOD(TestRemoveInvalidIndex)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);
			Assert::AreEqual(false, arr.remove(5)); 
			Assert::AreEqual(3, arr.length()); 
		}

		TEST_METHOD(TestSearchForElement)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);

			Assert::AreEqual(1, arr.search(5));
		}

		TEST_METHOD(TestSearchForNonElement)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);

			Assert::AreEqual(-1, arr.search(10));
		}

		TEST_METHOD(TestClear)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);
			arr.clear();
			Assert::AreEqual(0, arr.length());
		}

		TEST_METHOD(TestGetElement)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);
			
			Assert::AreEqual(5, arr.getElement(1));
		}

		TEST_METHOD(TestGetElementInvalidIndex)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);
			
			Assert::AreEqual(0, arr.getElement(5));
		}

		TEST_METHOD(TestLength)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(8);
			
			Assert::AreEqual(3, arr.length());
		}

		TEST_METHOD(TestPushResizesArray)
		{
			OrderedArray<int> arr(2);
			arr.push(1);
			arr.push(2);
			Assert::AreEqual(2, arr.length());

			arr.push(3); 
			Assert::AreEqual(3, arr.length());
			Assert::AreEqual(1, arr.getElement(0));
			Assert::AreEqual(2, arr.getElement(1));
			Assert::AreEqual(3, arr.getElement(2));
		}

		TEST_METHOD(TestPushWithDefaultGrowSize)
		{
			OrderedArray<int> arr;
			arr.push(10);
			arr.push(20);
			arr.push(30);
			Assert::AreEqual(3, arr.length());
			Assert::AreEqual(10, arr.getElement(0));
			Assert::AreEqual(20, arr.getElement(1));
			Assert::AreEqual(30, arr.getElement(2));
		}

		TEST_METHOD(PushNegativeNumbers)
		{
			OrderedArray<int> arr;
			arr.push(-5);
			arr.push(-10);

			Assert::AreEqual(2, arr.length());
			Assert::AreEqual(-10, arr.getElement(0));
			Assert::AreEqual(-5, arr.getElement(1));
		}

		TEST_METHOD(TestRemoveFomEmptyArray)
		{
			OrderedArray<int> arr;
			Assert::AreEqual(false, arr.remove(0));
			Assert::AreEqual(0, arr.length()); 
		}

		TEST_METHOD(TestClearThenPush)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.clear();

			Assert::AreEqual(0, arr.length());
			arr.push(10);
			Assert::AreEqual(1, arr.length());
			Assert::AreEqual(10, arr.getElement(0));
		}

		TEST_METHOD(TestPushDuplicates)
		{
			OrderedArray<int> arr;
			arr.push(5);
			arr.push(3);
			arr.push(5); // Attempt to add duplicate
			Assert::AreEqual(3, arr.length()); // Should only contain unique elements
			Assert::AreEqual(3, arr.getElement(0));
			Assert::AreEqual(5, arr.getElement(1));
		}

		TEST_METHOD(TestPushString)
		{
			OrderedArray<std::string> arr;
			arr.push("pear");
			arr.push("apple");
			arr.push("banana");

			Assert::AreEqual(std::string("apple"), arr.getElement(0));
			Assert::AreEqual(std::string("banana"), arr.getElement(1));
			Assert::AreEqual(std::string("pear"), arr.getElement(2));
			Assert::AreEqual(1, arr.search("banana"));
			Assert::AreEqual(-1, arr.search("orange"));
		}

		TEST_METHOD(TestALotOfElementPushes)
		{
			OrderedArray<int> arr;
			for (int i = 0; i < 1000; ++i) {
				arr.push(i);
			}
			Assert::AreEqual(1000, arr.length());
			Assert::AreEqual(0, arr.getElement(0));
			Assert::AreEqual(999, arr.getElement(999));
			Assert::AreEqual(500, arr.getElement(500));
		}

		TEST_METHOD(TestSearchEmptyArray)
		{
			OrderedArray<int> arr;
			Assert::AreEqual(-1, arr.search(10)); 
		}

		TEST_METHOD(TestAddNegativeNumber)
		{
			OrderedArray<int> arr;
			arr.push(-5);

			Assert::AreEqual(1, arr.length());
		}

		TEST_METHOD(TestSearchNegativeNumber)
		{
			OrderedArray<int> arr;
			arr.push(-5);
			arr.push(10);
			arr.push(100);

			Assert::AreEqual(3, arr.length());
			Assert::AreEqual(0, arr.search(-5));
		}

		TEST_METHOD(TestSearchNegativeNumberNonExist)
		{
			OrderedArray<int> arr;
			arr.push(-5);
			arr.push(10);
			arr.push(100);

			Assert::AreEqual(3, arr.length());
			Assert::AreEqual(-1, arr.search(-10));
		}


	};
}
