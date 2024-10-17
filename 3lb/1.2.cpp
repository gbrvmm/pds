#include <iostream>
#include <ctime>

using namespace std;

// НОД полным перебором от 1 до min(M, N)
int nodPerebor1(int M, int N) {
    int nod = 1;
    int limit = min(M, N);
    for (int i = 1; i <= limit; ++i) {
        if (M % i == 0 && N % i == 0) {
            nod = i;
        }
    }
    return nod;
}

// НОД полным перебором от min(M, N) до 1
int nodPerebor2(int M, int N) {
    int limit = min(M, N);
    for (int i = limit; i >= 1; --i) {
        if (M % i == 0 && N % i == 0) {
            return i;
        }
    }
    return 1;
}

//алгоритм Евклида
int Euclid(int N, int M) {
    while (M != 0) {
        int temp = M;
        M = N % M;
        N = temp;
    }
    return N;
}

//замер времени работы
double measureTime(int (*nodFunc)(int, int), int M, int N) {
    clock_t start = clock();
    nodFunc(M, N);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

//проверка времени работы алгоритмов
void proverka() {
    int M_values[] = {1000, 5000, 10000, 50000, 100000};  //входные данные M
    int N_values[] = {500, 3000, 8000, 25000, 75000};     //входные данные N
    int trials = 100;  //количество испытаний для усреднения времени

    cout << "M\tN\tPerebor1\tPerebor2\tEuclid" << endl;
    for (int i = 0; i < 5; ++i) {
        int M = M_values[i];
        int N = N_values[i];
        double timePerebor1 = 0, timePerebor2 = 0, timeEuclid = 0;

        for (int j = 0; j < trials; ++j) {
            timePerebor1 += measureTime(nodPerebor1, M, N);
            timePerebor2 += measureTime(nodPerebor2, M, N);
            timeEuclid += measureTime(Euclid, M, N);
        }

        //усредненное время выполнения
        cout << M << "\t" << N << "\t" << endl;
             << timePerebor1 / trials << "\t"
             << timePerebor2 / trials << "\t"
             << timeEuclid / trials << "\t" << endl;
    }
}

int main() {
    srand(time(0));  //инициализация генератора случайных чисел
    proverka();

    return 0;
}
