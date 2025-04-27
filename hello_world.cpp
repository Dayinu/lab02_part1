#include <iostream>
#include <string>

// Главная функция программы
int main() {
    // Объявление переменной для хранения имени
    std::string name;
    
    // Запрос имени пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Вывод приветствия
    std::cout << "Hello world from " << name << std::endl;
    
    // Возврат успешного статуса выполнения
    return 0;
}
