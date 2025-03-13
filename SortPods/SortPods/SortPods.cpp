#include <iostream>
#include <clocale>
using namespace std;

void countingSort(int arr[], int size) {
    if (size == 0) return;

    // Находим минимальное и максимальное значение в массиве
    int min_val = arr[0];
    int max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Создаем массив для подсчета количества каждого элемента
    int range = max_val - min_val + 1;
    int* count = new int[range](); // Инициализируем массив нулями

    // Подсчитываем количество каждого элемента
    for (int i = 0; i < size; ++i) {
        count[arr[i] - min_val]++;
    }

    // Восстанавливаем отсортированный массив
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i + min_val;
            count[i]--;
        }
    }

    // Освобождаем память
    delete[] count;
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    countingSort(arr, size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}