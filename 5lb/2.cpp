#include <iostream>
#include <stack>
#include <iomanip>
#include <string>
using namespace std;

const int max_vertices = 10; //максимальное количество вершин

class Graph {
private:
    int adjMatrix[max_vertices][max_vertices]; //матрица смежности
    int numVertices;

public:
    Graph(int vertices) : numVertices(vertices) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    //функция добавления ребра в граф
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    //отображение графа в виде схемы
    void displayGraph() {
        cout << "Схема графа (матрица смежности):\n";
        cout << "   ";
        for (int i = 0; i < numVertices; i++) {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        //текстовая визуализация связей графа
        cout << "Текстовая визуализация связей графа:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << i;
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << " -- " << j;
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    //обход в глубину (DFS) с построением каркаса
    void dfs(int start) {
        bool visited[max_vertices] = { false }; //массив посещённых вершин
        stack<int> s; //стек для обхода
        int spanningTree[max_vertices][2]; //для хранения каркаса графа
        for (int i = 0; i < max_vertices; i++) {
            spanningTree[i][0] = -1;
            spanningTree[i][1] = -1;
        }

        int treeIndex = 0;
        s.push(start);
        visited[start] = true;

        // Вывод заголовка таблицы
        cout << left << setw(25) << "Стек"
             << setw(25) << "Посещенные вершины"
             << setw(20) << "Новая вершина"
             << "Каркас" << endl;

        while (!s.empty()) {
            printStack(s); //вывод текущего состояния стека

            int v = s.top();
            bool newEdge = false;
            cout << setw(25) << displayVisited(visited); // отображение посещенных вершин

            //обход смежных вершин
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    s.push(i);

                    // Добавление ребра в каркас
                    spanningTree[treeIndex][0] = v;
                    spanningTree[treeIndex][1] = i;
                    treeIndex++;

                    // Вывод новой вершины и ребра каркаса
                    cout << setw(20) << i << v << "-" << i;
                    newEdge = true;
                    break;
                }
            }

            if (!newEdge) {
                s.pop();
                cout << setw(20) << "NO";
            }

            cout << endl;
        }

        // Вывод конечного каркаса
        cout << "\nКаркас: ";
        for (int i = 0; i < treeIndex; i++) {
            cout << spanningTree[i][0] << "-" << spanningTree[i][1] << " ";
        }
        cout << endl;
    }

    //вывод состояния стека
    void printStack(stack<int> s) {
        string result = "";
        stack<int> temp;
        //временный стек для правильного порядка вывода
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        while (!temp.empty()) {
            result += to_string(temp.top()) + " ";
            s.push(temp.top());
            temp.pop();
        }
        cout << left << setw(25) << result;
    }

    // Функция для отображения посещенных вершин
    string displayVisited(bool visited[]) {
        string result = "";
        for (int i = 0; i < numVertices; i++) {
            result += visited[i] ? "+" : "-";
        }
        return result;
    }
};

int main() {
    Graph g(7);
    g.addEdge(3, 2);
    g.addEdge(3, 5);
    g.addEdge(2, 0);
    g.addEdge(2, 4);
    g.addEdge(5, 1);
    g.addEdge(4, 7);
    g.addEdge(1, 6);

    cout << "Схема графа перед обходом:\n";
    g.displayGraph();

    int startVertex;
    cout << "Введите стартовую вершину: ";
    cin >> startVertex;

    g.dfs(startVertex);

    return 0;
}