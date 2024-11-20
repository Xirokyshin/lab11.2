#include "pch.h"
#include "CppUnitTest.h"
#include "../PR11.2.cpp"  // Підключаємо файл з вашою програмою

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestProcessLine)
        {
            // Тестовий рядок
            char line[] = "hello world";

            // Вихідний файл
            ofstream outputFile("test_output.txt");

            // Викликаємо функцію для обробки рядка
            processLine(line, outputFile);

            // Закриваємо файл
            outputFile.close();

            // Перевіряємо, чи правильний результат
            ifstream inputFile("test_output.txt");
            string result;
            getline(inputFile, result);  // Читаємо перший рядок

            // Очікуваний результат
            Assert::AreEqual(result.c_str(), "HELLO world");  // Використовуємо c_str() для порівняння

            // Закриваємо вхідний файл
            inputFile.close();
        }

        TEST_METHOD(TestFileProcessing)
        {
            // Створення тестових файлів
            ofstream inputFile("test_input.txt");
            inputFile << "hello world\n";
            inputFile << "test example\n";
            inputFile.close();

            ofstream outputFile("test_output.txt");

            // Відкриваємо вхідний файл
            ifstream input("test_input.txt");
            char line[1024];

            // Обробляємо кожен рядок
            while (input.getline(line, sizeof(line))) {
                processLine(line, outputFile);
                outputFile << '\n';  // Перехід на новий рядок
            }

            // Закриваємо файли
            input.close();
            outputFile.close();

            // Перевірка результатів
            ifstream resultFile("test_output.txt");
            string result;
            getline(resultFile, result);
            Assert::AreEqual(result.c_str(), "HELLO world");

            getline(resultFile, result);
            Assert::AreEqual(result.c_str(), "TEST example");

            // Закриваємо файл результату
            resultFile.close();
        }
    };
}
