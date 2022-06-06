#include "pch.h"
#include "CppUnitTest.h"

#include "../HammingDistance.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HammingDistanceTests
{
	TEST_CLASS(TestUtilities)
	{
	public:
		
		TEST_METHOD(Test_int_to_str)
		{
			SEQUENCE_LENGTH = 6;
			HAMMING_DISTANCE = 1;
			std::string s1 = int_to_str(1);
			std::string s2 = int_to_str(4);

			Assert::AreEqual(s1, std::string("000001"));
			Assert::AreEqual(s2, std::string("000010"));
		}

		TEST_METHOD(Test_get_tetra_hamming_distance)
		{
			SEQUENCE_LENGTH = 6;
			HAMMING_DISTANCE = 1;
			std::string s1 = int_to_str(1);
			std::string s2 = int_to_str(4);

			Assert::AreEqual(get_tetra_hamming_distance(s1, s2), 2);
		}
	};
}
