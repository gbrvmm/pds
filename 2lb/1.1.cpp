
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//функция поиска
int sequential_search(int arr[], int size, int target, int& comparisons) {
    comparisons = 0;  //cчетчик сравнений
    for (int i = 0; i < size; ++i) {
        comparisons++;  //увеличиваем количество сравнений
        if (arr[i] == target) {
            return i;  //возвращаем индекс найденного элемента
        }
    }
    return -1;  //если элемент не найден
}

int main() {
    srand(time(0));  //инициализация генератора случайных чисел
    
    int array_sizes[] = {20, 40, 60, 80, 500};  //размеры массивов
    for (int size : array_sizes) {
        int* arr = new int[size];  //динамический массив
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % 1000 + 1;  //генерация случайных чисел
        }
        
        int target = arr[rand() % size];  //случайный элемент для поиска
        int comparisons = 0;
        int index = sequential_search(arr, size, target, comparisons);
        
        cout << "Массив размера " << size << ": элемент " << target 
             << " найден на позиции " << index << " после " << comparisons 
             << " сравнений." << endl;
        
        delete[] arr;  //освобождаем память
    }
    
    return 0;
}
