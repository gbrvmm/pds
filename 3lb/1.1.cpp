#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// проверка на простоту полным перебором от 2 до N
bool isPrime2N(int n, int &checks) {
    if (n < 2) return false;
    for (int i = 2; i < n; ++i) {
        checks++;  // увеличиваем количество проверок
        if (n % i == 0) return false;
    }
    return true;
}

// перебор только нечетных чисел от 2 до N
bool isPrime2Nch(int n, int &checks) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i < n; i += 2) {
        checks++;  // увеличиваем количество проверок
        if (n % i == 0) return false;
    }
    return true;
}

// перебор от 2 до sqrt(N)
bool isPrimeSqrt(int n, int &checks) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        checks++;  // увеличиваем количество проверок
        if (n % i == 0) return false;
    }
    return true;
}

// перебор от 2 до sqrt(N) только нечетных чисел
bool isPrimeSqrt2Nch(int n, int &checks) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        checks++;  // увеличиваем количество проверок
        if (n % i == 0) return false;
    }
    return true;
}

// функция для замера времени работы и количества проверок
double measureTime(bool (*isPrime)(int, int&), int n, int &checks) {
    clock_t start = clock();
    isPrime(n, checks);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

// таблица зависимости времени и количества проверок от N
void proverka() {
    int N[] = {1000, 5000, 10000, 50000, 100000};  // размеры данных
    int trials = 1000;  // количество запусков для усреднения времени

    cout << "N\tВремя (от 2 до N)\t"
         << "Время (нечетные)\t"
         << "Время (от 2 до sqrt(N))\t"
         << "Время (sqrt нечетные)\t" << endl;

    for (int i = 0; i < 5; ++i) {
        int n = N[i];
        double time2N = 0, time2Nch = 0, timeSqrt = 0, timeSqrt2Nch = 0;
        int checks2N = 0, checks2Nch = 0, checksSqrt = 0, checksSqrt2Nch = 0;

        for (int j = 0; j < trials; ++j) {
            int randomNum = rand() % (n - 2 + 1) + 2;  // случайное число от 2 до N
            int checks = 0;

            time2N += measureTime(isPrime2N, randomNum, checks);
            checks2N += checks;

            checks = 0;
            time2Nch += measureTime(isPrime2Nch, randomNum, checks);
            checks2Nch += checks;

            checks = 0;
            timeSqrt += measureTime(isPrimeSqrt, randomNum, checks);
            checksSqrt += checks;

            checks = 0;
            timeSqrt2Nch += measureTime(isPrimeSqrt2Nch, randomNum, checks);
            checksSqrt2Nch += checks;
        }

        cout << fixed;
        cout.precision(10);
        // усреднение времени и проверок
        cout << n << "\t" 
             << time2N / trials << "\t" << checks2N / trials << "\t" 
             << time2Nch / trials << "\t" << checks2Nch / trials << "\t" 
             << timeSqrt / trials << "\t" << checksSqrt / trials << "\t" 
             << timeSqrt2Nch / trials << "\t" << checksSqrt2Nch / trials << endl;
    }
}

int main() {
    srand(time(0));  // инициализация генератора случайных чисел
    proverka();
    return 0;
}
