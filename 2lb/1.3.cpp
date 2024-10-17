#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для сортировки массива методом пузырька
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Последовательный поиск с подсчетом количества сравнений
int sequential_search(int arr[], int size, int target, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; ++i) {
        comparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Элемент не найден
}

// Двоичный поиск с подсчетом количества сравнений
int binary_search(int arr[], int size, int target, int& comparisons) {
    comparisons = 0;
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Элемент не найден
}

int main() {
    srand(time(0));  // Инициализация генератора случайных чисел
    
    // Параметры задачи
    const int start_size = 20;  // Начальный размер массива
    const int step = 20;        // Шаг увеличения размера
    const int max_size = 500;   // Максимальный размер массива
    const int value_range = 1000; // Диапазон значений элементов массива

    // Заголовок таблицы
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "Размер массива (N)\tПрактическая сложность последовательного поиска\tПрактическая сложность двоичного поиска\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    
    // Цикл по размерам массива
    for (int size = start_size; size <= max_size; size += step) {
        int* arr = new int[size];  // Динамический массив
        
        // Заполнение массива случайными числами
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % value_range + 1;
        }
        
        // Выбор случайного элемента для поиска
        int target = arr[rand() % size];

        // Подсчет сравнений для последовательного поиска
        int comparisons_seq = 0;
        sequential_search(arr, size, target, comparisons_seq);

        // Сортировка массива для двоичного поиска
        bubble_sort(arr, size);

        // Подсчет сравнений для двоичного поиска
        int comparisons_bin = 0;
        binary_search(arr, size, target, comparisons_bin);
        
        // Вывод результатов в таблицу
        cout << size << "\t\t\t" << comparisons_seq << "\t\t\t\t\t" << comparisons_bin << endl;
        cout << "------------------------------------------------------------------------------------------------------------\n";

        delete[] arr;  // Освобождаем память
    }
    
    return 0;
}
