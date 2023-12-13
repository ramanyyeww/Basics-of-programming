
#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    char op;
    double num1, num2;

    bool exit = false;
    while (!exit) {
        cout << "Введите оператор (+, -, *, /) или 'q' для выхода: ";
        cin >> op;

        if (op == 'q') {
            exit = true;
            continue;
        }

        cout << "Введите два числа: ";
        cin >> num1 >> num2;

        switch (op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            else
                cout << "Ошибка: деление на ноль";
            break;
        default:
            cout << "Ошибка: неправильный оператор";
            break;
        }
        cout << endl;
    }

    return 0;
}

