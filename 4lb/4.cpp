#include <iostream>
using namespace std;

//рекурсивная реализация без оптимизации
int fibRecursive(int n) {
    if (n < 2)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

//рекурсивная реализация с кеш-памятью

int cache[100];  //инициализируем массив для кеша значениями -1

void resetCache() {
    for (int i = 0; i < 100; i++) {
        cache[i] = -1;
    }
}
int fibCaching(int n) {
    if (n < 2)
        return n;
    if (cache[n] != -1)
        return cache[n];
    return cache[n] = fibCaching(n - 1) + fibCaching(n - 2);
}

// Итеративная реализация с временным массивом
int fibIterativeArray(int n) {
    if (n < 2)
        return n;
    int fibs[100] = { 0, 1 }; // Массив для хранения чисел Фибоначчи
    for (int i = 2; i <= n; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    return fibs[n];
}

// Итеративная реализация с вычислением "на лету"
int fibIterativeOnTheFly(int n) {
    if (n < 2)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Основная функция для выбора и выполнения каждой реализации
int main() {
    setlocale(LC_ALL, "ru");
    int choice, n;
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;

    cout << "Выберите реализацию:\n";
    cout << "1. Рекурсивная без оптимизации\n";
    cout << "2. Рекурсивная с кеш-памятью\n";
    cout << "3. Итеративная с временным массивом\n";
    cout << "4. Итеративная с вычислением 'на лету'\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    int result;
    switch (choice) {
    case 1:
        result = fibRecursive(n);
        break;
    case 2:
        resetCache();
        result = fibCaching(n);
        break;
    case 3:
        result = fibIterativeArray(n);
        break;
    case 4:
        result = fibIterativeOnTheFly(n);
        break;
    default:
        cout << "Некорректный выбор!" << endl;
        return 1;
    }

    cout << "Число Фибоначчи F(" << n << ") = " << result << endl;
    return 0;
}
