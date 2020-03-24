#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectProject/inter.hpp"
#include "assert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InterSectTest
{
	TEST_CLASS(InterSectTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			inter x = inter(2, 3);
			inter y = inter(3, 4);
			assert(y.length2() == 25);
		}
		TEST_METHOD(TestMethod2)
		{
			inter x = inter(2, 3);
			inter y = inter(3, 4);
			assert(y.length2() == 25);
		}
		TEST_METHOD(TestMethod3)
		{
			inter x = inter(2, 3);
			inter y = inter(3, 4);
			assert(y.length2() == 25);
		}
		TEST_METHOD(TestMethod4)
		{
			inter x = inter(2, 3);
			inter y = inter(3, 4);
			assert(y.length2() == 25);
		}
		TEST_METHOD(TestMethod5)
		{
			inter x = inter(2, 3);
			inter y = inter(3, 4);
			assert(y.length2() == 25);
		}
		TEST_METHOD(TestMethod6)
		{
			inter x = inter(2, 3);
			inter y = inter(3, 4);
			assert(y.length2() == 25);
		}

	};
}
