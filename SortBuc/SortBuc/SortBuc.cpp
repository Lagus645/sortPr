#include <iostream>

// Функция для сортировки вставками
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция блочной сортировки
void bucketSort(float arr[], int n) {
    // Создаем массив ведер (блоков)
    const int bucketSize = 10;
    float buckets[bucketSize][n];
    int bucketCount[bucketSize] = { 0 };

    // Распределяем элементы по ведрам
    for (int i = 0; i < n; i++) {
        int bucketIndex = bucketSize * arr[i];
        buckets[bucketIndex][bucketCount[bucketIndex]] = arr[i];
        bucketCount[bucketIndex]++;
    }

    // Сортируем каждое ведро с помощью сортировки вставками
    for (int i = 0; i < bucketSize; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    // Собираем элементы обратно в исходный массив
    int index = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = { 0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    bucketSort(arr, n);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}