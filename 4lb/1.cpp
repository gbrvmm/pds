
/*
#include <iostream>
using namespace std;

//функция для суммы цифр числа
int sum_cifr(int n) {
    if (n == 0)
        return 0;
    return n % 10 + sum_cifr(n / 10);
}

//функция для вычисления цифрового корня числа
int cifr_root(int n) {
    if (n < 10)
        return n;
    return cifr_root(n % 10 + cifr_root(n / 10));
}

//функция для вычисления факториала числа
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int choice, num;
    
    cout << "Выберите операцию:\n";
    cout << "1. Сумма цифр числа\n";
    cout << "2. Цифровой корень числа\n";
    cout << "3. Факториал числа\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    
    cout << "Введите число: ";
    cin >> num;
    
    switch (choice) {
        case 1:
            cout << "Сумма цифр числа " << num << " = " << sum_cifr(num) << endl;
            break;
        case 2:
            cout << "Цифровой корень числа " << num << " = " << cifr_root(num) << endl;
            break;
        case 3:
            cout << "Факториал числа " << num << " = " << factorial(num) << endl;
            break;
        default:
            cout << "Некорректный выбор!" << endl;
    }
    
    return 0;
}
*/
#include <iostream>
using namespace std;

// функция для суммы цифр числа
int sum_cifr(int n) {
    if (n == 0)
        return 0;
    return n % 10 + sum_cifr(n / 10);
}

// функция для вычисления цифрового корня числа
int cifr_root(int n) {
    if (n < 10)
        return n;
    return cifr_root(n % 10 + cifr_root(n / 10));
}

// функция для вычисления факториала числа
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// функция для вычисления суммы чисел от 0 до N
int S(int n) {
    if (n == 0)
        return 0;
    return n + S(n - 1);
}

int main() {
    int choice, num;
    
    cout << "Выберите операцию:\n";
    cout << "1. Сумма цифр числа\n";
    cout << "2. Цифровой корень числа\n";
    cout << "3. Факториал числа\n";
    cout << "4. Сумма чисел от 0 до N\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    
    cout << "Введите число: ";
    cin >> num;
    
    switch (choice) {
        case 1:
            cout << "Сумма цифр числа " << num << " = " << sum_cifr(num) << endl;
            break;
        case 2:
            cout << "Цифровой корень числа " << num << " = " << cifr_root(num) << endl;
            break;
        case 3:
            cout << "Факториал числа " << num << " = " << factorial(num) << endl;
            break;
        case 4:
            cout << "Сумма чисел от 0 до " << num << " = " << S(num) << endl;
            break;
        default:
            cout << "Некорректный выбор!" << endl;
    }
    
    return 0;
}
