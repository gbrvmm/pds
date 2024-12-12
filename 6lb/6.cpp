#include <iostream>
#include <cmath>

using namespace std;

const int max_size = 20;
int pyramid[max_size];
int n = 0; // текущее число элементов в пирамиде

//обмен элементов для упорядочивания
void swap(int i, int j) {
    int t = pyramid[i];
    pyramid[i] = pyramid[j];
    pyramid[j] = t;
}

//добавление элемента в пирамиду
void add(int x) {
    pyramid[n] = x;
    int i = n;
    n++;
    while (i > 0 && pyramid[i] > pyramid[(i - 1) / 2]) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

//получение максимального элемента
int top() {
    return n > 0 ? pyramid[0] : -1; // -1, если пирамида пуста
}

//удаление максимального элемента
void pop() {
    if (n == 0) return;
    pyramid[0] = pyramid[n - 1];
    n--;
    int i = 0;
    while (2 * i + 1 < n) {
        int largest = i;
        if (2 * i + 1 < n && pyramid[2 * i + 1] > pyramid[largest]) {
            largest = 2 * i + 1;
        }
        if (2 * i + 2 < n && pyramid[2 * i + 2] > pyramid[largest]) {
            largest = 2 * i + 2;
        }
        if (largest == i) break;
        swap(i, largest);
        i = largest;
    }
}

// вывод пирамиды в виде дерева
void displayPyramidTree() {
    int level = 0; // текущий уровень дерева
    int nodesInLevel = 1; // количество узлов на текущем уровне
    int i = 0; // индекс в массиве пирамиды

    while (i < n) {
        int spaces = pow(2, log2(n) - level); //количество пробелов перед узлами
        for (int j = 0; j < spaces; ++j) {
            cout << "  ";              //печатаем начальные отступы
        }

        for (int j = 0; j < nodesInLevel && i < n; ++j, ++i) {
            if (j > 0) {
                for (int s = 0; s < spaces * 2 - 1; ++s) {
                    cout << " ";      // промежуточные отступы между элементами
                }
            }
            cout << pyramid[i];
        }

        cout << endl;
        level++;
        nodesInLevel = 1 << level;    //количество узлов удваивается на каждом уровне
    }
}


//пирамидальная сортировка
void heapSort(int arr[], int len) {
    n = 0;
    for (int i = 0; i < len; ++i) {
        add(arr[i]);
    }
    for (int i = len - 1; i >= 0; --i) {
        arr[i] = top();
        pop();
    }
}

//алгоритм Прима
void prim(int graph[5][5], int vertices, int startVertex) {
    bool visited[5] = {false};
    visited[startVertex] = true; // начать с указанной вершины
    int edgeCount = 0;
    int mstWeight = 0;

    while (edgeCount < vertices - 1) {
        int minWeight = INT_MAX;
        int from = -1, to = -1;

        for (int i = 0; i < vertices; ++i) {
            if (visited[i]) {
                for (int j = 0; j < vertices; ++j) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < minWeight) {
                        minWeight = graph[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        if (from != -1 && to != -1) {
            cout << from << " -- " << to << " вес: " << minWeight << endl;
            visited[to] = true;
            mstWeight += minWeight;
            edgeCount++;
        }
    }

    cout << "Вес остовного дерева: " << mstWeight << endl;
}


int main() {
    while (true) {
        cout << "Выберите операцию:\n";
        cout << "1. Очередь по приоритетам\n";
        cout << "2. Пирамидальная сортировка\n";
        cout << "3. Алгоритм Прима\n";
        cout << "4. Выход\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            int arr[] = {10, 20, 15, 30, 5};
            n = 0;
            for (int x : arr) {
                add(x);
            }
            cout << "Куча:\n";
            displayPyramidTree();
            cout << "Максимальный элемент: " << top() << endl;
            pop();
            cout << "Куча после удаления максимального элемента:\n";
            displayPyramidTree();
        } else if (choice == 2) {
            int arr[] = {10, 20, 15, 30, 5};
            int len = sizeof(arr) / sizeof(arr[0]);
            cout << "Исходный массив: ";
            for (int i = 0; i < len; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
            n = 0;
            for (int i = 0; i < len; ++i) {
                add(arr[i]);
            }
            cout << "Массив в виде пирамиды:\n";
            displayPyramidTree();
            heapSort(arr, len);
            cout << "Отсортированный массив: ";
            for (int i = 0; i < len; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else if (choice == 3) {
            int graph[5][5] = {
                {0, 2, 0, 6, 0},
                {2, 0, 3, 8, 5},
                {0, 3, 0, 0, 7},
                {6, 8, 0, 0, 9},
                {0, 5, 7, 9, 0}
            };
            cout << "Минимальное остовное дерево (Прим):\n";
            prim(graph, 5, 2);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Неверный выбор.\n";
        }
    }

    return 0;
}
