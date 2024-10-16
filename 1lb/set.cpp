#include <iostream>
using namespace std;

const int size = 10;
int numbers[size];
bool exists[size];

// функция инициализации (false - пустой массив)
void init() {
  for (int i = 0; i < size; i++) {
    exists[i] = false;
  }
}

// вспомогательная функция поиска пустой позиции 
int getEmptyPosition() {
  for (int i = 0; i < size; i++) {
    if (!exists[i]) {
      return i;
    }
  }
  return -1; // если не найдена
}

//добавление
void add(int x) {
  int pos = getEmptyPosition();
  if (pos != -1) {
    numbers[pos]=x;
    exists[pos]=true;
  } else {
    cout << "Нет места\n";
  }
}

// поиск элемента
bool contains(int x) {
  for (int i = 0; i < size; i++) {
    if (exists[i] && numbers[i] == x) {
      return true;
    }
  }
  return false; // если элемент не найден
}

// удаление
void deletes(int x) {
  int pos = contains(x);
  if (pos != -1) {
    exists[pos] = false;
  } else {
    cout << "Такого элемента нет" << endl;
  }
}

void print() {
  for (int i=0; i < size; i++) {
    if (exists[i]) {
      cout << numbers[i] << " ";
    }
  }
  cout << endl;
}



int main() {
add(10);
add(20);
add(30);
add(40);

cout << "Множество после добавления элементов: ";
print(); 

cout << "Содержит ли 20? " << (contains(20) ? "Да" : "Нет") << endl; 
cout << "Содержит ли 50? " << (contains(50) ? "Да" : "Нет") << endl; 

deletes(20);

cout << "после удаления 20: ";
print(); 

return 0;
}
