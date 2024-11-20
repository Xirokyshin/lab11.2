#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <Windows.h>

using namespace std;

// Функція, яка обробляє рядок: замінює малі літери перед першим пробілом на великі.
void processLine(char* line, ofstream& outputFile) {
    int i = 0;

    // Проходимо по кожному символу рядка до першого пробілу або до кінця рядка
    while (line[i] != '\0' && line[i] != ' ') {
        // Перевірка на малу букву і перетворення на велику
        if (islower(line[i])) {
            line[i] = toupper(line[i]);
        }
        // Записуємо оброблений символ у вихідний файл за допомогою <<
        outputFile << line[i];
        i++;
    }

    // Якщо знайдено пробіл, додаємо його до вихідного файлу
    if (line[i] == ' ') {
        outputFile << ' ';
        i++;
    }

    // Продовжуємо записувати решту рядка без змін
    while (line[i] != '\0') {
        outputFile << line[i];
        i++;
    }
}

int main() {
    // Налаштування кодування для консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* inputFileName = "t1.txt";  // Вхідний файл
    const char* outputFileName = "t2.txt"; // Вихідний файл

    // Відкриваємо файли
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Перевірка, чи відкрилися файли
    if (!inputFile.is_open()) {
        cerr << "Помилка відкриття вхідного файлу: " << inputFileName << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "Помилка відкриття вихідного файлу: " << outputFileName << endl;
        return 1;
    }

    char line[1024];  // Масив для зберігання рядка

    // Читання кожного рядка з файлу і обробка
    while (inputFile.getline(line, sizeof(line))) {
        cout << "Обробляється рядок: " << line << endl; // Виведення рядка для налагодження
        processLine(line, outputFile);
        outputFile << '\n'; // Додаємо перехід на новий рядок у вихідному файлі
    }

    // Закриваємо файли
    inputFile.close();
    outputFile.close();

    cout << "Обробка завершена. Результат записано у файл " << outputFileName << endl;
    return 0;
}
