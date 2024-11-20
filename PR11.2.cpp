#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <Windows.h>

using namespace std;

// �������, ��� �������� �����: ������ ��� ����� ����� ������ ������� �� �����.
void processLine(char* line, ofstream& outputFile) {
    int i = 0;

    // ��������� �� ������� ������� ����� �� ������� ������ ��� �� ���� �����
    while (line[i] != '\0' && line[i] != ' ') {
        // �������� �� ���� ����� � ������������ �� ������
        if (islower(line[i])) {
            line[i] = toupper(line[i]);
        }
        // �������� ���������� ������ � �������� ���� �� ��������� <<
        outputFile << line[i];
        i++;
    }

    // ���� �������� �����, ������ ���� �� ��������� �����
    if (line[i] == ' ') {
        outputFile << ' ';
        i++;
    }

    // ���������� ���������� ����� ����� ��� ���
    while (line[i] != '\0') {
        outputFile << line[i];
        i++;
    }
}

int main() {
    // ������������ ��������� ��� ������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* inputFileName = "t1.txt";  // ������� ����
    const char* outputFileName = "t2.txt"; // �������� ����

    // ³�������� �����
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // ��������, �� ��������� �����
    if (!inputFile.is_open()) {
        cerr << "������� �������� �������� �����: " << inputFileName << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "������� �������� ��������� �����: " << outputFileName << endl;
        return 1;
    }

    char line[1024];  // ����� ��� ��������� �����

    // ������� ������� ����� � ����� � �������
    while (inputFile.getline(line, sizeof(line))) {
        cout << "������������ �����: " << line << endl; // ��������� ����� ��� ������������
        processLine(line, outputFile);
        outputFile << '\n'; // ������ ������� �� ����� ����� � ��������� ����
    }

    // ��������� �����
    inputFile.close();
    outputFile.close();

    cout << "������� ���������. ��������� �������� � ���� " << outputFileName << endl;
    return 0;
}
