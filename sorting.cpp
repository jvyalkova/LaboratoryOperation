#include <iostream>
using namespace std;

const int N = 200;

void result_out(int comps, int swaps)
{
    cout << "Сравнения:\t" << comps << "\t";
    cout << "Перестановки:\t" << swaps << "\n";
}

void simple_selection(int input_arr[])
{
    int ind, arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];

    for (int i = 0; i < N - 1; i++)
    {
        ind = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[ind])
                ind = j;
            comparisons++;
        }
        swap(arr[i], arr[ind]);
        swaps++;
    }

    result_out(comparisons, swaps);
}

void simple_exchange(int input_arr[])
{
    int arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];

    for (int i = 0; i < N - 1; i++)
        for (int j = N - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                swaps++;
            }
            comparisons++;
        }

    result_out(comparisons, swaps);
}

void simple_insertion(int input_arr[])
{
    int buff, j, arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];

    for (int i = 1; i < N; i++)
    {
        j = i;
        buff = arr[i];
        while (j > 0 && buff < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
            swaps++;
            comparisons++;
        }
        arr[j] = buff;
        swaps++;
    }

    result_out(comparisons, swaps);
}

void binary_insertion(int input_arr[])
{
    int left, right, m, x, arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];

    for (int i = 1; i < N; i++)
    {
        x = arr[i];
        left = 0;
        right = i - 1;
        while (left <= right)
        {
            m = (left + right) / 2;
            (x < arr[m]) ? right = m - 1 : left = m + 1;
            comparisons++;
        }
        for (int j = i - 1; j >= left; j--)
        {
            arr[j + 1] = arr[j];
            swaps++;
        }
        arr[left] = x;
        swaps++;
    }

    result_out(comparisons, swaps);
}

void shaker(int input_arr[])
{
    int left = 1, right = N - 1, k = N - 1, arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];

    while (left <= right)
    {
        for (int j = right; j >= left; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
                swaps++;
            }
            comparisons++;
        }
        left = k + 1;
        for (int j = 1; j <= right; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                k = j;
                swaps++;
            }
            comparisons++;
        }
        right = k - 1;
        comparisons++;
    }

    result_out(comparisons, swaps);
}

void shell(int input_arr[])
{
    int arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];

    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; ++i) {
            int buff = arr[i], j;

            for (j = i; j >= gap && arr[j - gap] > buff; j -= gap)
            {
                arr[j] = arr[j - gap];
                swaps++;
            }
            comparisons++;
            arr[j] = buff;
            swaps++;
        }
    }
    result_out(comparisons, swaps);
}


int partit(int arr[], int low, int high, int& comps, int& swaps)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[j], arr[i]);
            i++;
            swaps++;
        }
        comps++;
    }

    swap(arr[i], arr[high]);
    swaps++;
    return i;
}

void quicksort(int arr[], int low, int high, int& comparisons, int& swaps)
{
    if (low >= high)
        return;
    int pi = partit(arr, low, high, comparisons, swaps);

    quicksort(arr, low, pi - 1, comparisons, swaps);
    quicksort(arr, pi + 1, high, comparisons, swaps);
}

void quick(int input_arr[])
{
    int arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];
    quicksort(arr, 0, N - 1, comparisons, swaps);

    result_out(comparisons, swaps);
}


void heapify(int arr[], int n, int i, int& comparisons, int& swaps) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    comparisons++;

    if (right < n && arr[right] > arr[largest])
        largest = right;
    comparisons++;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        swaps++;
        heapify(arr, n, largest, comparisons, swaps);
    }
}

void heaps(int input_arr[])
{
    int arr[N], comparisons = 0, swaps = 0;

    for (int i = 0; i < N; i++)
        arr[i] = input_arr[i];

    for (int i = N / 2 - 1; i >= 0; --i)
        heapify(arr, N, i, comparisons, swaps);

    for (int i = N - 1; i >= 0; --i)
    {
        swap(arr[0], arr[i]);
        swaps++;
        heapify(arr, i, 0, comparisons, swaps);
    }

    result_out(comparisons, swaps);
}


int main()
{
    setlocale(LC_ALL, "RU");
    int rndarray[N];
    int downarray[N];
    int uparray[N];

    for (int i = 0; i < N; i++)
        rndarray[i] = rand() % 200;

    for (int i = N - 1; i >= 0; i--)
        downarray[i] = N - i;

    for (int i = 1; i <= N; i++)
        uparray[i - 1] = i;

    cout << "Сортировка простым выбором\n\n";
    cout << "Случайный массив:\t";
    simple_selection(rndarray);
    cout << "Убывающий массив:\t";
    simple_selection(downarray);
    cout << "Возрастающий массив:\t";
    simple_selection(uparray);

    cout << "\nСортировка простым обменом\n\n";
    cout << "Случайный массив:\t";
    simple_exchange(rndarray);
    cout << "Убывающий массив:\t";
    simple_exchange(downarray);
    cout << "Возрастающий массив:\t";
    simple_exchange(uparray);

    cout << "\nСортировка простой вставки\n\n";
    cout << "Случайный массив:\t";
    simple_insertion(rndarray);
    cout << "Убывающий массив:\t";
    simple_insertion(downarray);
    cout << "Возрастающий массив:\t";
    simple_insertion(uparray);

    cout << "\nСортировка бинарной вставки\n\n";
    cout << "Случайный массив:\t";
    binary_insertion(rndarray);
    cout << "Убывающий массив:\t";
    binary_insertion(downarray);
    cout << "Возрастающий массив:\t";
    binary_insertion(uparray);

    cout << "\nШейкер-сортировка\n\n";
    cout << "Случайный массив:\t";
    shaker(rndarray);
    cout << "Убывающий массив:\t";
    shaker(downarray);
    cout << "Возрастающий массив:\t";
    shaker(uparray);

    cout << "\nСортировка Шелла\n\n";
    cout << "Случайный массив:\t";
    shell(rndarray);
    cout << "Убывающий массив:\t";
    shell(downarray);
    cout << "Возрастающий массив:\t";
    shell(uparray);

    cout << "\nБыстрая сортировка\n\n";
    cout << "Случайный массив:\t";
    quick(rndarray);
    cout << "Убывающий массив:\t";
    quick(downarray);
    cout << "Возрастающий массив:\t";
    quick(uparray);

    cout << "\nСортировка \"куч\"\n\n";
    cout << "Случайный массив:\t";
    heaps(rndarray);
    cout << "Убывающий массив:\t";
    heaps(downarray);
    cout << "Возрастающий массив:\t";
    heaps(uparray);
}