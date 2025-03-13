#include <iostream>
#include <clocale>
using namespace std;

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
    float** buckets = new float* [bucketSize]; // Динамическое выделение памяти для ведер
    int bucketCount[bucketSize] = { 0 };

    // Инициализация каждого ведра
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = new float[n]; // Каждое ведро может содержать до n элементов
    }

    // Распределяем элементы по ведрам
    for (int i = 0; i < n; i++) {
        int bucketIndex = static_cast<int>(bucketSize * arr[i]); // Приведение к int
        if (bucketIndex >= bucketSize) { // Защита от выхода за границы
            bucketIndex = bucketSize - 1;
        }
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

    // Освобождаем выделенную память
    for (int i = 0; i < bucketSize; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
}

int main() {
    setlocale(LC_ALL, "russian");
    float arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}