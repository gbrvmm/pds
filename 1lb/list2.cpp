#include <iostream>
#include <cstdlib> // для функции rand()
#include <ctime>   // для инициализации генератора случайных чисел
using namespace std;

const int max_size = 100;
int contents[max_size];
int n = 0;

// вставка элемента в указанное место
void insert(double x, int pos) {
  if (n == max_size) {
    cout << "Cписок полон" << endl;
  } else if (!(0 <= pos && pos <= n)) {
    cout << "Некорректный индекс" << endl;
  } else {
    // сдвиг элементов вправо
    for (int i = n-1; i >= pos; i--) {
      contents[i+1] = contents[i];
    }
    contents[pos] = x;
    n++;
  }
}

void print() {
  // проверка на пустоту
  if (n == 0) {cout << "Список пуст" << endl;}
  for (int i = 0; i < n; i++) {
    cout << contents[i] << " ";
  }
  cout << endl;
}

// индекс первого вхождения элемента (-1, если не найден)
int find(double x) {
  for (int i = 0; i < n; i++) {
    if (contents[i] == x) {
      return i;
    }
  }
  return -1;
}

// удаленить элемент с заданным индексом
void remove(double x) {
  int pos = find(x);
  if (pos == -1) {
    cout << "Такого элемента нет" << endl;
  } else {
    // cдвиг элементов влево
    for (int i = pos; i < n-1; i++) {
      contents[i] = contents[i+1];
    }
    n--;
  }
}

int main() {
    srand(time(0)); // инициализация генератора случайных чисел

    insert(10, 0);
    insert(20, 1);
    insert(30, 2);
    cout << "Элементы списка: ";
    print(); 
    cout << "\n";

    // Цикл на 30 итераций, добавляющий случайные элементы
    for (int i = 0; i < 30; i++) {
        int random_num = rand() % 100 + 1;  // случайное число от 1 до 100
        int random_pos = rand() % (n + 1);  // случайная позиция от 0 до n
        cout << "Добавляем " << random_num << " на позицию " << random_pos << endl;
        insert(random_num, random_pos);
        cout << "Новый список: ";
        print(); // вывод обновленного списка
        cout << "\n";
    }

    return 0;
}
