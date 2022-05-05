#include <iostream>
#include <fstream>

int main () {
    std::string filePath;
    std::cout << "Input file path or file name in current directory: ";
    std::cin >> filePath;
    bool validPath = false;
    std::ifstream photo;
    while (!photo.is_open()) {
        photo.open(filePath, std::ios::binary);
        if (!photo.is_open()) {
            std::cout << "Invalid path" << std::endl;
            std::cout << "Input file path or file name in current directory: ";
            std::cin >> filePath;
        }
    }
    char validation[4];
    photo.read(validation, sizeof(validation));
    if (validation[0] == -119 && validation[1] == 'P' 
            && validation[2] == 'N' && validation[3] == 'G') {
        std::cout << "It's a png file";
    }
    else {
        std::cout << "It's not a png file";
    }
}

/*
Разработайте программу, которая получает на вход, в стандартный ввод, 
путь к файлу. На выходе программа должна определить, является ли данный файл PNG-изображением. 
Данная процедура не просто должна смотреть на расширение файла, 
но и произвести минимальный анализ его внутренностей, в бинарном режиме.
Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. 
Нас будут интересовать первые четыре байта. Первый байт всегда имеет значение −119 (число со знаком минус), 
а следующие — это просто символы ‘P’, ‘N’, ‘G’, расположенные друг за другом. Обратите внимание, что все они в верхнем регистре.
По результатам проверки пути и внутренностей требуется сообщить пользователю о результате проверки в стандартный вывод.
*/