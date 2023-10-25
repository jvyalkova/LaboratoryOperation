#include <iostream>
using namespace std;

void moveDisk(int n, char source, char destination, char auxiliary)
{
    if (n == 1) {
        cout << "Перемещение: 1 с " << source << " на " << destination << endl;
        return;
    }

    moveDisk(n - 1, source, auxiliary, destination);
    cout << "Перемещение: " << n << " с " << source << " на " << destination << endl;
    moveDisk(n - 1, auxiliary, destination, source);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int numDisks;
    cout << "Введите количество дисков: ";
    cin >> numDisks;

    moveDisk(numDisks, 'A', 'C', 'B');

    return 0;
}