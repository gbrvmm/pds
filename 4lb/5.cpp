/*#include <iostream>
#include <ctime>       //для функции clock()
#include <iomanip>     //для fixed и setprecision
using namespace std;

//рекурсивная реализация без оптимизации
int fibRecursive(int n) {
    if (n < 2)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

//рекурсивная реализация с кеш-памятью
int cache[100];  // инициализируем массив для кеша значениями -1

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

//итеративная реализация с временным массивом
int fibIterativeArray(int n) {
    if (n < 2)
        return n;
    int fibs[100] = {0, 1};  // Массив для хранения чисел Фибоначчи
    for (int i = 2; i <= n; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    return fibs[n];
}

//итеративная реализация с вычислением "на лету"
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
    clock_t start_time = clock();  // Засекаем начальное время

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

    clock_t end_time = clock();  // Засекаем конечное время
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    cout << "Число Фибоначчи F(" << n << ") = " << result << endl;
    cout << "Время выполнения: " << fixed << setprecision(6) << elapsed_time << " секунд" << endl;

    return 0;
}
*/

#include <iostream>
#include <ctime>       // для функции clock()
#include <iomanip>     // для fixed и setprecision
using namespace std;

// рекурсивная реализация без оптимизации
int fibRecursive(int n) {
    if (n < 2)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// рекурсивная реализация с кеш-памятью
int cache[100];  // инициализируем массив для кеша значениями -1

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

// итеративная реализация с временным массивом
int fibIterativeArray(int n) {
    if (n < 2)
        return n;
    int fibs[100] = {0, 1};  // Массив для хранения чисел Фибоначчи
    for (int i = 2; i <= n; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    return fibs[n];
}

// итеративная реализация с вычислением "на лету"
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

int main() {
    cout << left << setw(15) << "Номер" << setw(20) << "Число Фибоначчи" << setw(25) << "Время вычисления (с)" << endl;
    cout << "-------------------------------------------------------------" << endl;

    //вычисление чисел Фибоначчи от 0 до 60 с выводом времени выполнения
    for (int i = 0; i <= 60; i++) {
        clock_t start_time = clock();  //засекаем начальное время
        int result = fibRecursive(i);
        clock_t end_time = clock();    //засекаем конечное время

        //вычисляем время выполнения в секундах
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

        //выводим номер числа, значение Фибоначчи и вуремя вычисления в формате таблицы
        cout << left << setw(15) << i << setw(20) << result << fixed << setprecision(6) << setw(25) << elapsed_time << endl;
    }

    return 0;
}
