#include <iostream>
using namespace std;
bool isSafe(int row, int col, int **board, int N)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}
bool solveNQueens(int col, int **board, int N)
{
    if (col == N)
    return true;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, board, N))
        {
            board[i][col] = 1;
            if (solveNQueens(col + 1, board, N))
            return true;
            board[i][col] = 0;
        }
    }

    return false;
}
void printSolution(int N, int** board)
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
    setlocale(LC_ALL, "RUS");
    int N;
    cout << "Размер доски: ";
    cin >> N;
    int** board = new int* [N];
    for (int i = 0; i < N; i++)
    {
        board[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    if (solveNQueens(0, board, N))
    {
        cout << "Решение найдено:" << endl;
        printSolution(N, board);
    }
    else
    {
        cout << "Решение не найдено." << endl;
    }

    return 0;
}
