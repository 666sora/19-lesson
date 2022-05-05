#include <iostream>
#include <fstream>

int countOfBytes(std::string& filePath) {
    std::ifstream text;
    text.open(filePath, std::ios::binary);
    int count = 0;
    do {
        text.get();
        count++;
    } while (!text.eof());
    return count - 1;
}

int main() {
    std::string filePath;
    std::cout << "Input file path or file name in current directory: ";
    std::cin >> filePath;
    bool validPath = false;
    std::ifstream text;
    while (!text.is_open()) {
        text.open(filePath, std::ios::binary);
        if (!text.is_open()) {
            std::cout << "Invalid path" << std::endl;
            std::cout << "Input file path or file name in current directory: ";
            std::cin >> filePath;
        }
    }
    std::cout << std::endl;
    int bytes = countOfBytes(filePath);
    do {
        int position;
        if (100 > bytes - text.tellg()) {
            position = bytes - text.tellg();
        }
        else {
            position = 100;
        }
        char buffer[100];
        text.read(buffer, position);
        for (int i = 0; i < position; i++) {
            std::cout << buffer[i];
        }
        std::cout << std::endl;
        char answer = '0';
        while (answer != 'q') {
            std::cout << "--------------------------" << std::endl;
            std::cout << "Enter \"q \" to continue: ";
            std::cin >> answer;
            std::cout << std::endl;
        }
    } while (text.tellg() < bytes);
    text.close();
}

/*
Разработайте простейший просмотрщик текстовых файлов.
В начале программы пользователь вводит путь к текстовому
файлу, который требуется открыть и просмотреть.
Внутренности файла необходимо вывести в стандартный вывод.
Программа должна работать для любых текстовых файлов в
формате TXT, но вы можете создать и свой отдельный файл для
теста. Главное, чтобы файл был англоязычным, дабы избежать проблем с кодировками.
*/