#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Проверка, безопасно ли разместить ферзя в данной позиции
bool isSafe(vector<string>& board, int row, int col, int n) {
    // Проверяем вертикаль вверх
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Проверяем левую верхнюю диагональ
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Проверяем правую верхнюю диагональ
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// Решение задачи о расстановке ферзей
void solveNQueens(int row, int n, vector<string>& board, vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q'; // Размещаем ферзя
            solveNQueens(row + 1, n, board, result); // Рекурсивно решаем подзадачу для следующей строки
            board[row][col] = '.'; // Возвращаемся к предыдущему состоянию - бэктрекинг
        }
    }
}

// Функция для получения всех возможных решений для задачи о расстановке ферзей
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.')); // Создаем доску n x n, инициализируя все положения точками

    solveNQueens(0, n, board, result); // Начинаем решать задачу с первой строки

    return result;
}

int main() {
    string choice;
    do {
        int n = 4; // Измените значение n для других размеров доски
        vector<vector<string>> solutions = solveNQueens(n);

        cout << "Solutions for " << n << " queens on the board " << n << "x" << n << ":\n";
        for (const auto& solution : solutions) {
            for (const string& row : solution) {
                cout << row << endl; // Выводим решение
            }
            cout << "-----------------\n";
        }
        cout << "Run again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y"); // Повторяем цикл, если пользователь ввел 'y' или 'Y'
    return 0;
}
