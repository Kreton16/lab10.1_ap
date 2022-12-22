#include <fstream>
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include "../Source.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char t[100] = "queue";
			ofstream fout(t);
			string s = "jgbiubiubiuah ioniospng ankjbsdccgiujb";
			fout << s << endl;
			int k = ProcessTXT1(t);
			Assert::AreEqual(k, 1);
		}
	};
}
