#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>

using namespace std;

int main() {
    string word; // переменная для хранения слов
    int choice; // переменная для хранения выбора
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "Введите слово: ";
    cin >> word;

    // Преобразуем слово в нижний регистр для единообразия
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    // Входим в цикл, который будет продолжаться до тех пор, пока пользователь не выберет выход
    do {
        // Выводим меню с доступными действиями
        cout << "\nВыберите действие:" << endl;
        cout << "1. Вывести слово задом наперед" << endl;
        cout << "2. Вывести слово без гласных" << endl;
        cout << "3. Вывести слово без согласных" << endl;
        cout << "4. Рандомно раскидывать буквы заданного слова" << endl;
        cout << "5. Выход" << endl;
        // Выводим запрос на выбор действия
        cout << "Ваш выбор: ";
        // Считываем выбор пользователя
        cin >> choice;

        // Переключаемся по выбору пользователя
        switch (choice) {
        case 1:
            // Выводим слово задом наперед
            cout << "Слово задом наперед: " << string(word.rbegin(), word.rend()) << endl;
            break;
        case 2:
            // Выводим слово без гласных
            cout << "Слово без гласных: ";
            // Удаляем гласные буквы из слова
            word.erase(remove_if(word.begin(), word.end(), [](char c) {
                return c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я';
                }), word.end());
            cout << word << endl;
            break;
        case 3:
            // Выводим слово без согласных
            cout << "Слово без согласных: ";
            // Удаляем согласные буквы из слова
            word.erase(remove_if(word.begin(), word.end(), [](char c) {
                return c != 'а' && c != 'е' && c != 'ё' && c != 'и' && c != 'о' && c != 'у' && c != 'ы' && c != 'э' && c != 'ю' && c != 'я';
                }), word.end());
            cout << word << endl;
            break;
        case 4:
            // Рандомизируем порядок букв в слове
            random_shuffle(word.begin(), word.end());
            // Выводим рандомизированное слово
            cout << "Рандомно раскиданное слово: " << word << endl;
            break;
        case 5:
            // Выводим сообщение о выходе
            cout << "До свидания!" << endl;
            break;
        default:
            // Выводим сообщение о неправильном выборе
            cout << "Неправильный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 5); // Цикл будет продолжаться до тех пор, пока пользователь не выберет выход

    return 0;
}