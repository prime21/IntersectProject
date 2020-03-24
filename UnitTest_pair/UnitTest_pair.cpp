#include "pch.h"
#include "CppUnitTest.h"
#include "../step3_core/calc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestpair
{
	TEST_CLASS(UnitTest_Core)
	{
	public:

		TEST_METHOD(TestOnlineSegment)
		{
			Point A(2, 2);
			Point B(1, 1);
			Line l(A, B, 'L');
			Line r(A, B, 'R');
			Line s(A, B, 'S');
			Assert::IsFalse(s.online(1.1));
			Assert::IsFalse(s.online(-0.1));
			Assert::IsTrue(s.online(0.5));
		}

		TEST_METHOD(TestOnlineArrow)
		{
			Point A(2, 2);
			Point B(1, 1);
			Line l(A, B, 'L');
			Line r(A, B, 'R');
			Line s(A, B, 'S');
			Assert::IsTrue(r.online(1.1));
			Assert::IsFalse(r.online(-0.1));
			Assert::IsTrue(r.online(0.5));
		}
		TEST_METHOD(TestOnline)
		{
			Point A(2, 2);
			Point B(1, 1);
			Line l(A, B, 'L');
			Line r(A, B, 'R');
			Line s(A, B, 'S');
			Assert::IsTrue(l.online(1.1));
			Assert::IsTrue(l.online(-0.1));
			Assert::IsTrue(l.online(0.5));
		}
	};
	TEST_CLASS(UnitTest_Error) {
		TEST_METHOD(TestSameLine) {
			// 判断两条直线，线段，射线，是否是同一条 
		
			solve my;

			Assert::IsTrue(my.isSame("L 0 0 1 1", "L 1 1 2 2"));
			Assert::IsFalse(my.isSame("L 0 0 1 1", "L 1 1 1 2"));
		}
		TEST_METHOD(TestInvaildString) {
			// 判断是否为不合法输入
			solve my;
			Assert::IsTrue(my.isType("L 3 3 3,") == 0);
		}
		TEST_METHOD(TestSameArrow) {
			// 判断两条射线，是否是同一条 

			solve my;

			Assert::IsFalse(my.isSame("R 0 0 1 1", "R 1 1 2 2"));
			Assert::IsFalse(my.isSame("R 0 0 1 1", "R 1 1 1 2"));
			Assert::IsTrue(my.isSame("R 0 0 1 2", "R 0 0 2 4"));
		}
		TEST_METHOD(TestSameSegment) {
			// 判断两条线段，是否是同一条 

			solve my;

			Assert::IsTrue(my.isSame("S 0 0 1 1", "S 1 1 0 0"));
			Assert::IsFalse(my.isSame("S 0 0 1 1", "S 1 1 1 2"));
			Assert::IsFalse(my.isSame("S 0 0 1 2", "S 0 0 2 4"));
		}
	};
}
