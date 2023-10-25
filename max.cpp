#include <iostream>
using namespace std;

int findMax(int arr[], int start, int end, int& maxIndex)
{
    if (start == end)
    {
        maxIndex = start;
        return arr[start];
    }

    int mid = (start + end) / 2;
    int leftMax = findMax(arr, start, mid, maxIndex);
    int rightMax = findMax(arr, mid + 1, end, maxIndex);
    
    if (leftMax >= rightMax) 
    {
        return leftMax;
    }
    else {
        maxIndex = maxIndex + (mid - 1 - start);
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
    cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    int maxIndex;
    int max = findMax(arr, 0, size - 1, maxIndex);

    cout << "Максимальный элемент массива: " << max << endl;
    cout << "Индекс максимального элемента: " << maxIndex << endl;
    delete[] arr;
    return 0;
}
