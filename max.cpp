#include <iostream> 
using namespace std;

int findMax(int arr[], int start, int end )
{
    if (start == end)
    {
        return arr[start];
    }

    int mid = (start + end) / 2;
    int leftMax = findMax(arr, start, mid);
    int rightMax = findMax(arr, mid + 1, end);

    if (leftMax >= rightMax)
    {
        return leftMax;
    }
    else
    {
        return rightMax;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    int maxIndex = 0;
    int max = findMax(arr, 0, size - 1 );
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == max)
        {
            maxIndex = i;
        }
    }
    cout << "Максимальный элемент массива: " << max << endl;
    cout << "Индекс максимального элемента: " << maxIndex << endl;
}
