#include "pch.h"
#include "CppUnitTest.h"

#include "../MySet.h"
#include "..\OrderedArray.h"
#include "../OrderedArray.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySetTest
{
	TEST_CLASS(MySetTests)
	{
		TEST_METHOD(TestInsertion)
		{
			MySet<int> s;
			s.insert(5);
			Assert::AreEqual(1, s.length());
			Assert::AreEqual(5, s.getElement(0));
		}
	};
}