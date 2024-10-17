#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// функция для сортировки массива методом пузырька
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// функция двоичного поиска
int binary_search(int arr[], int size, int target, int& comparisons) {
    comparisons = 0;
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;  // счетчик сравнений
        
        if (arr[mid] == target) {
            return mid;  // возвращаем индекс найденного элемента
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // если элемент не найден
}

int main() {
    srand(time(0));  // инициализация генератора случайных чисел
    
    cout << "------------------------------------------" << endl;
    cout << "Размер\tЭлемент\tПозиция\tСравнений" << endl;
    cout << "------------------------------------------" << endl;

    for (int size = 20; size <= 1000; size += 20) {
        int* arr = new int[size];  // динамический массив
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 1000 + 1;  // генерация случайных чисел
        }
        
        bubble_sort(arr, size);  // сортировка массива методом пузырька
        
        int target = arr[rand() % size];  // случайный элемент для поиска
        int comparisons = 0;
        int index = binary_search(arr, size, target, comparisons);
        
        // выводим результат с использованием табуляции
        cout << size << "\t" << target << "\t" << index << "\t" << comparisons << endl;
        
        delete[] arr;  // освобождаем память
    }
    
    return 0;
}
