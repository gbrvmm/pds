/* #include <iostream>
using namespace std;

//вывод чисел от 1 до N
void ot1doN(int n) {
    if (n > 0) {
        ot1doN(n - 1);
        cout << n << " ";
    }
}

//вывод чисел от N до 1
void otNdo1(int n) {
    if (n > 0) {
        cout << n << " ";
        otNdo1(n - 1);
    }
}

//вывод четных чисел от 1 до N
void ot1doN_chet(int n) {
    if (n > 0) {
        ot1doN_chet(n - 1);
        if (n % 2 == 0) {
            cout << n << " ";
        }
    }
}

//вывод нечетных чисел от 1 до N
void ot1doN_nechet(int n) {
    if (n > 0) {
        ot1doN_nechet(n - 1);
        if (n % 2 != 0) {
            cout << n << " ";
        }
    }
}

//вывод чисел от -N до N
void minNdoN(int n) {
    if (n > 0) {
        minNdoN(n - 1);
        cout << -n << " ";
    }
    cout << n << " ";
}

int main() {
    int choice, n;

    cout << "Выберите последовательность:\n";
    cout << "1. Числа от 1 до N\n";
    cout << "2. Числа от N до 1\n";
    cout << "3. Четные числа от 1 до N\n";
    cout << "4. Нечетные числа от 1 до N\n";
    cout << "5. Числа от -N до N\n"; 
    // от н до -н добавить
    cout << "Ваш выбор: ";
    cin >> choice;

    cout << "Введите значение N: ";
    cin >> n;

    switch (choice) {
        case 1:
            ot1doN(n);
            break;
        case 2:
            otNdo1(n);
            break;
        case 3:
            ot1doN_chet(n);
            break;
        case 4:
            ot1doN_nechet(n);
            break;
        case 5:
            minNdoN(n);
            break;
        default:
            cout << "Некорректный выбор!" << endl;
    }

    cout << endl;
    return 0;
}
*/

#include <iostream>
using namespace std;

// вывод чисел от 1 до N
void ot1doN(int n) {
    if (n > 0) {
        ot1doN(n - 1);
        cout << n << " ";
    }
}

// вывод чисел от N до 1
void otNdo1(int n) {
    if (n > 0) {
        cout << n << " ";
        otNdo1(n - 1);
    }
}

// вывод четных чисел от 1 до N
void ot1doN_chet(int n) {
    if (n > 0) {
        ot1doN_chet(n - 1);
        if (n % 2 == 0) {
            cout << n << " ";
        }
    }
}

// вывод нечетных чисел от 1 до N
void ot1doN_nechet(int n) {
    if (n > 0) {
        ot1doN_nechet(n - 1);
        if (n % 2 != 0) {
            cout << n << " ";
        }
    }
}

// вывод чисел от -N до N
void minNdoN(int n) {
    if (n > 0) {
        minNdoN(n - 1);
        cout << -n << " ";
    }
    cout << n << " ";
}

// вывод чисел от N до -N
void otNdoMinN(int n) {
    if (n >= 0) {
        cout << n << " ";
        if (n != 0) {  
            otNdoMinN(n - 1);
            cout << -n << " ";
        }
    }
}

int main() {
    int choice, n;

    cout << "Выберите последовательность:\n";
    cout << "1. Числа от 1 до N\n";
    cout << "2. Числа от N до 1\n";
    cout << "3. Четные числа от 1 до N\n";
    cout << "4. Нечетные числа от 1 до N\n";
    cout << "5. Числа от -N до N\n";
    // от н до -н добавить
    cout << "6. Числа от N до -N\n"; 
    cout << "Ваш выбор: ";
    cin >> choice;

    cout << "Введите значение N: ";
    cin >> n;

    switch (choice) {
        case 1:
            ot1doN(n);
            break;
        case 2:
            otNdo1(n);
            break;
        case 3:
            ot1doN_chet(n);
            break;
        case 4:
            ot1doN_nechet(n);
            break;
        case 5:
            minNdoN(n);
            break;
        case 6:
            otNdoMinN(n);
            break;
        default:
            cout << "Некорректный выбор!" << endl;
    }

    cout << endl;
    return 0;
}
