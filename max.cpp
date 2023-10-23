#include <iostream>
#include <vector>
using namespace  std;

int Max(const std::vector<int>& arr, int start, int end) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int leftMax = Max(arr, start, mid);
    int rightMax = Max(arr, mid + 1, end);

    return (arr[leftMax] > arr[rightMax]) ? leftMax : rightMax;
}

int main() {
    
    setlocale(LC_ALL, "Rus");
    int size;

    cout << "¬ведите размер массива: ";
    cin >> size;

    vector<int> arr(size);

    cout << "¬ведите элементы массива:"<< endl;
    for (int i = 0; i < size; i++) {
        cout << "Ёлемент " << i << ": ";
        cin >> arr[i];
    }

    int maxIndex = Max(arr, 0, size - 1);
    int maxValue = arr[maxIndex];

    cout << "ћаксимальный элемент: " << maxValue << ", его индекс: " << maxIndex << endl;

    return 0;
}