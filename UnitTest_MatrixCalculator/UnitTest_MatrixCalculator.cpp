#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrixCalculator
{
	TEST_CLASS(UnitTestMatrixCalculator)
	{
	public:
		
		TEST_METHOD(ClassExisting)
		{
			MatrixCalculator* calc = new MatrixCalculator();
			Assert::IsNotNull(calc);
			delete calc;
		}
	};
}
