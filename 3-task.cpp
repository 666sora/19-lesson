#include <iostream>
#include <fstream>

int main() {
    std::ifstream statement;
    statement.open("statement.txt");
    int sum = 0;
    int max = 0;
    std::string maxName;
    while (!statement.eof()) {
        std::string firstName = "0", secondName, data;
        int count;
        statement >> firstName >> secondName >> count >> data;
        if (firstName == "0") {
            continue;
        }
        sum += count;
        if (count > max) {
            max = count;
            maxName = firstName;
            maxName += ' ' + secondName;
        }
    }
    statement.close();
    std::cout << "Name and surname of person who contributed max money is " << maxName << std::endl;
    std::cout << "Total sum is " << sum;
}

/*
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу: 
имя и фамилия человека; 
количество денег, которые были выплачены лицу; 
дата выплаты в формате ДД.ММ.ГГГГ.

На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной суммой выплат.
*/