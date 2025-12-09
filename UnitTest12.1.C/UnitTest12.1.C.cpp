#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include <fstream>
#include <cstdio>
#include "../PR12.1.C/fileops.c"
#include "../PR12.1.C/fileops.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest121C
{
	TEST_CLASS(UnitTest121C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

            const char* testFile = "test_values.bin";
            std::ofstream fout(testFile, std::ios::binary);
            double data[] = { -5.0, 2.0, -1.0, 10.0 };
            for (double v : data)
                fout.write((char*)&v, sizeof(double));
            fout.close();

            double maxNeg = 0, minPos = 0;
            bool ok = findValues(testFile, &maxNeg, &minPos);

            Assert::IsTrue(ok);
            Assert::AreEqual(-1.0, maxNeg);
            Assert::AreEqual(2.0, minPos);

            std::remove(testFile);
		}
	};
}
