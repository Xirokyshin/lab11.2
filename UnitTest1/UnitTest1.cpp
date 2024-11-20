#include "pch.h"
#include "CppUnitTest.h"
#include "../PR11.2.cpp"  // ϳ�������� ���� � ����� ���������

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestProcessLine)
        {
            // �������� �����
            char line[] = "hello world";

            // �������� ����
            ofstream outputFile("test_output.txt");

            // ��������� ������� ��� ������� �����
            processLine(line, outputFile);

            // ��������� ����
            outputFile.close();

            // ����������, �� ���������� ���������
            ifstream inputFile("test_output.txt");
            string result;
            getline(inputFile, result);  // ������ ������ �����

            // ���������� ���������
            Assert::AreEqual(result.c_str(), "HELLO world");  // ������������� c_str() ��� ���������

            // ��������� ������� ����
            inputFile.close();
        }

        TEST_METHOD(TestFileProcessing)
        {
            // ��������� �������� �����
            ofstream inputFile("test_input.txt");
            inputFile << "hello world\n";
            inputFile << "test example\n";
            inputFile.close();

            ofstream outputFile("test_output.txt");

            // ³�������� ������� ����
            ifstream input("test_input.txt");
            char line[1024];

            // ���������� ����� �����
            while (input.getline(line, sizeof(line))) {
                processLine(line, outputFile);
                outputFile << '\n';  // ������� �� ����� �����
            }

            // ��������� �����
            input.close();
            outputFile.close();

            // �������� ����������
            ifstream resultFile("test_output.txt");
            string result;
            getline(resultFile, result);
            Assert::AreEqual(result.c_str(), "HELLO world");

            getline(resultFile, result);
            Assert::AreEqual(result.c_str(), "TEST example");

            // ��������� ���� ����������
            resultFile.close();
        }
    };
}
