#include <iostream>
using namespace std;
// Проверка, можно ли разместить ферзя на данной позиции
bool isSafe(int row, int col)
{
    // Проверка строки
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Проверка левой верхней диагонали
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Проверка левой нижней диагонали
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// Рекурсивная функция для расстановки ферзей на доске
bool solveNQueens(int col)
{
    // Базовый случай: все ферзи размещены
    if (col == N)
        return true;

    // Попробовать разместить ферзя в каждой строке в текущем столбце
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            // Размещаем ферзя на данной позиции
            board[i][col] = 1;

            // Рекурсивно размещаем оставшиеся ферзи
            if (solveNQueens(col + 1))
                return true;

            // Если текущая конфигурация не приводит к решению, отменяем размещение ферзя
            board[i][col] = 0;
        }
    }

    // Если ферзи не могут быть размещены на текущей конфигурации доски
    return false;
}

// Функция для вывода решения
void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cout << "Размер доски: ";
    cin >> N;
    int board[N][N]; // Доска

    // Инициализация доски
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    // Решение задачи расстановки ферзей
    if (solveNQueens(0))
    {
        cout << "Решение найдено:" << endl;
        printSolution();
    }
    else
    {
        cout << "Решение не найдено." << endl;
    }

    return 0;
}