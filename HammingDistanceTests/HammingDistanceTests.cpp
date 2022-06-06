#include "pch.h"
#include "CppUnitTest.h"
#include "../HammingDistance.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HammingDistanceTests
{
	TEST_CLASS(HammingDistanceTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			SEQUENCE_LENGTH = 6;
			HAMMING_DISTANCE = 1;
			std::string s1 = int_to_str(1);
			std::string s2 = int_to_str(4);

			Assert::AreEqual(s1, std::string("000001"));
			Assert::AreEqual(s2, std::string("000010"));
		}
	};
}
