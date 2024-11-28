/*#include <iostream>
using namespace std;

//рекурсивная функция возведения в степень
int power(int x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

//рекурсивная функция нахождения наибольшего общего делителя (алгоритм Евклида)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int choice;
    cout << "Выберите операцию:\n";
    cout << "1. Возведение в степень\n";
    cout << "2. Нахождение НОД (алгоритм Евклида)\n";
    // сделать вывод промежуточных шагов в евклиде
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
        int base, exponent;
        cout << "Введите основание: ";
        cin >> base;
        cout << "Введите степень: ";
        cin >> exponent;
        cout << base << "^" << exponent << " = " << power(base, exponent) << endl;
    } else if (choice == 2) {
        int num1, num2;
        cout << "Введите первое число: ";
        cin >> num1;
        cout << "Введите второе число: ";
        cin >> num2;
        cout << "НОД(" << num1 << ", " << num2 << ") = " << gcd(num1, num2) << endl;
    } else {
        cout << "Некорректный выбор!" << endl;
    }

    return 0;
}
*/

#include <iostream>
using namespace std;

// рекурсивная функция возведения в степень
int power(int x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

// рекурсивная функция нахождения наибольшего общего делителя (алгоритм Евклида) с выводом промежуточных шагов
int gcd(int a, int b) {
    cout << "Вычисляем gcd(" << a << ", " << b << ")" << endl;  // вывод текущих значений a и b
    if (b == 0) {
        cout << "Остаток равен 0, НОД найден: " << a << endl;
        return a;
    }
    cout << "Делим " << a << " на " << b << ", остаток: " << a % b << endl;
    return gcd(b, a % b);
}

int main() {
    int choice;
    cout << "Выберите операцию:\n";
    cout << "1. Возведение в степень\n";
    cout << "2. Нахождение НОД (алгоритм Евклида)\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
        int base, exponent;
        cout << "Введите основание: ";
        cin >> base;
        cout << "Введите степень: ";
        cin >> exponent;
        cout << base << "^" << exponent << " = " << power(base, exponent) << endl;
    } else if (choice == 2) {
        int num1, num2;
        cout << "Введите первое число: ";
        cin >> num1;
        cout << "Введите второе число: ";
        cin >> num2;
        cout << "Промежуточные шаги для нахождения НОД(" << num1 << ", " << num2 << "):" << endl;
        cout << "Наибольший общий делитель (" << num1 << ", " << num2 << ") = " << gcd(num1, num2) << endl;
    } else {
        cout << "Некорректный выбор!" << endl;
    }

    return 0;
}
