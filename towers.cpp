#include <iostream>
using namespace std;

void moveDisk(int n, char source, char destination, char auxiliary)
{
    if (n == 1) {
        cout << "�����������: 1 � " << source << " �� " << destination << endl;
        return;
    }

    moveDisk(n - 1, source, auxiliary, destination);
    cout << "�����������: " << n << " � " << source << " �� " << destination << endl;
    moveDisk(n - 1, auxiliary, destination, source);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int numDisks;
    cout << "������� ���������� ������: ";
    cin >> numDisks;

    moveDisk(numDisks, 'A', 'C', 'B');

    return 0;
}