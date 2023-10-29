#include <iostream>
using namespace std;

// Проверка, находится ли точка (x, y) на доске размером n x n
bool isValidMove(int x, int y, int n)
{
    return (x >= 0 && x < n&& y >= 0 && y < n);
}

// Функция для рекурсивного поиска ходов коня
void knightTourHelper(int** board, int x, int y, int moveCount, int n)
{
    // Устанавливаем номер хода на текущую позицию (x, y)
    board[x][y] = moveCount;

    // Проверяем все возможные ходы коня
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    for (int i = 0; i < 8; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // Если следующий ход допустим и точка не была посещена ранее, рекурсивно исследуем этот ход
        if (isValidMove(nextX, nextY, n) && board[nextX][nextY] == 0)
        {
            knightTourHelper(board, nextX, nextY, moveCount + 1, n);
        }
    }
}

// Функция для запуска алгоритма "Ход коня"
int** knightTour(int n, int startX, int startY)
{
    int** board = new int* [n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0; // Инициализируем доску значением 0
        }
    }

    knightTourHelper(board, startX, startY, 1, n);

    return board;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int n, startX, startY;
    cout << "Введите размер доски: ";
    cin >> n;
    cout << "Введите начальное положение коня (номер строки и номер столбца): ";
    cin >> startX;
    cin >> startY;

    int** board = knightTour(n, startX-1, startY-1);

    cout << "Матрица номеров ходов коня:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }

    // Освобождаем память, выделенную для доски
    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}