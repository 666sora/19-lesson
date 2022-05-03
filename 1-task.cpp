#include <iostream>
#include <fstream>

int main() {
    std::string foundWord;
    std::cout << "Input word for search: ";
    std::cin >> foundWord;
    std::ifstream text;
    text.open("words.txt");
    int count = 0; 
    while (!text.eof()) {
        std::string word;
        text >> word;
        bool equal = true;
        for (int i = 0; i < foundWord.length() && equal; i++) {
            if (word[i] != foundWord[i]) {
                equal = false;
            }
        }
        if (equal) count++;
    }
    text.close();
    std::cout << "Total found words: " << count;
}

/*
Составьте небольшой текстовый файл «words.txt», 
в котором последовательно, через пробелы и переносы 
строк расположены различные слова. Можете использовать 
любые англоязычные слова. Разработайте программу, которая 
искала бы среди этих слов нужное пользователю и выводила бы 
общее количество повторений этого слова. 0 — если слово вообще не присутствует в файле.
*/