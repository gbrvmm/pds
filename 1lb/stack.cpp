#include <iostream>
using namespace std;

const int max_size = 10;
int contents[max_size];
int n = 0;

void push(int x) {
  if (n == max_size) {
    cout << "Стек пуст\n";
  } else {
    contents[n] = x;
    n++;
  }
}

void pop() {
  if (n > 0) {
    n--;
  } else {
    cout << "Стек пуст\n";
  }
}

int last() {
  if (n > 0) {
    return contents[n - 1];
  } else {
    cout << "Стек пуст\n";
    return -1;  // возвращаем -1, если стек пуст
  }
}

bool isEmpty() {
  return n == 0;
}

void print() {
  if (isEmpty()) {
    cout << "Стек пуст\n";
  } else {
    cout << "Элементы cтека:" << endl;
    for (int i = 0; i < n; i++) {
      cout << contents[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  push(10);
  push(20);
  push(30);
  print();        
  cout << "Последний элемент: " << last() << endl;  

  pop();
  print();        

  cout << isEmpty() << endl; 
  pop();
  pop();
  cout << isEmpty() << endl; 
  pop();         
  return 0;
}
