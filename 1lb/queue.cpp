#include <iostream>
using namespace std;

const int max_size = 10;
int contents[max_size];
int n = 0;

void push(int x) {
  if (n == max_size) {
    cout << "Очередь пуста\n";
  } else {
    contents[n] = x;
    n++;
  }
}

void remove() {
  //cout << "Удаление элемента: " << endl;  
  if (n == 0) {
    cout << "Очередь пуста\n";
  } else {
    //Сдвиг элементов
    for (int i = 0; i < n-1; i++) {
      contents[i] = contents[i+1];
    }
    n--;
  }
}


int last() {
  if (n > 0) {
    return contents[n - 1];
  } else {
    cout << "Очередь пуста\n";
    return -1;  // возвращаем -1, если очередь пуста
  }
}

bool isEmpty() {
  return n == 0;
}

void print() {
  if (isEmpty()) {
    cout << "Очередь пуста\n";
  } else {
    cout << "Элементы очереди: ";
    for (int i = 0; i < n; i++) {
      cout << contents[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  //добавление элементов
  push(10);
  push(20);
  push(30);
  print();        // 10 20 30
  cout << "Последний элемент: " << last() << endl;  // 30

  remove();
  print();        // 10 20
  
  cout << "Проверка на пустоту (true – пустой; false – хотя бы 1 элемент): " << isEmpty() << endl;  // 0 (false)
  remove();
  remove();

  cout << "Проверка на пустоту (true – пустой; false – хотя бы 1 элемент): " << isEmpty() << endl;  // 1
  remove();     
  return 0;
}

