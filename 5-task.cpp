#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string sector[13] = { "1", "2", "3", "4", "5",
                              "6", "7", "8", "9", "10",
                              "11", "12", "13" };
    int scoreOfPlayer = 0, scoreOfViewer = 0;
    while (scoreOfPlayer != 6 && scoreOfViewer != 6) {
        std::string number;
        std::cout << "Player chooses a sector: ";
        std::cin >> number;
        while (sector[stoi(number) - 1] == "0") {
            if (number == "13" && sector[12] == "0") {
                number = "1";
            } 
            else {
                number = std::to_string(stoi(number) + 1);
            }
        }
        sector[stoi(number) - 1] = "0";

        std::ifstream question;
        std::string filePath = "question" + number + ".txt";
        question.open(filePath);
        if (!question.is_open()) std::cout << "Err";
        std::string questionForPlayer;
        std::getline(question, questionForPlayer);
        question.close();

        std::cout << "The question is " << questionForPlayer << std::endl;
        std::string playerAnswer;
        std::cout << "Player, your answer: ";
        std::cin.ignore();
        std::getline(std::cin, playerAnswer);


        std::ifstream answer;
        filePath = "answer" + number + ".txt";
        answer.open("answer" + number + ".txt");
        if (!answer.is_open()) std::cout << "Err";
        std::string answerForPlayer;
        std::getline(answer, answerForPlayer);
        answer.close();

        if (playerAnswer == answerForPlayer) {
            std::cout << "Player was right! Player's score increases by 1" << std::endl;
            scoreOfPlayer++;
            std::cout << "Now player's score is " << scoreOfPlayer << std::endl;
        }
        else {
            std::cout << "Player was wrong! Viewer's score increases by 1" << std::endl;
            scoreOfViewer++;
            std::cout << "Now viewer's score is " << scoreOfViewer << std::endl;
        }
    }
    if (scoreOfPlayer == 6) {
        std::cout << "Player won";
    }
    else {
        std::cout << "Viewers won";
    }
}

/*
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет. Всего таких секторов 13.
Сектор выбирается так: с клавиатуры вводится офсет (смещение)
относительно текущего сектора на барабане. Исходя из этого офсета вычисляется новый активный сектор,
который и будет играть в этом ходе. Если выпавший сектор уже играл, выбирает следующий неигравший за ним. В начале всей игры стрелка установлена на первом секторе.
Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного сектора. Вопрос показывается на экране.
После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного ввода. То, что он ввёл,
сравнивается с ответом, который хранится во втором файле, ассоциированном с активным сектором. Данный файл должен содержать лишь одно слово-ответ.
Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.
Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется победитель и программа заканчивает работу.
*/