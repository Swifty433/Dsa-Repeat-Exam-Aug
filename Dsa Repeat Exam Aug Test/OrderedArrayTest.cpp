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
	};
}
