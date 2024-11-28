#include <iostream>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

const int max_vertices = 8; // количество вершин в графе

class Graph {
private:
    int adjMatrix[max_vertices][max_vertices]; // матрица смежности
    int numVertices;

public:
    Graph(int vertices) : numVertices(vertices) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // функция добавления ребра в граф
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    void print() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // обход в ширину (BFS) с построением каркаса
    void bfs(int start) {
        bool visited[max_vertices] = {false}; // массив посещённых вершин
        queue<int> q; // очередь для обхода
        int spanningTree[max_vertices][2]; // для хранения каркаса графа
        for (int i = 0; i < max_vertices; i++) {
            spanningTree[i][0] = -1;
            spanningTree[i][1] = -1;
        }

        int treeIndex = 0;

        q.push(start);
        visited[start] = true;

        cout << left << setw(15) << "Очередь"
             << setw(20) << "Посещенные вершины"
             << setw(15) << "Новая вершина"
             << "Каркас" << endl;

        while (!q.empty()) {
            printQueue(q);

            int v = q.front();
            q.pop();

            cout << setw(20) << displayVisited(visited);

            bool newEdge = false;
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);

                    // Добавление ребра в каркас
                    spanningTree[treeIndex][0] = v;
                    spanningTree[treeIndex][1] = i;
                    treeIndex++;

                    // Вывод новой вершины и ребра каркаса
                    cout << setw(15) << i << v << "-" << i << " ";
                    newEdge = true;
                }
            }

            if (!newEdge) {
                cout << setw(15) << "NO";
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

    // Функция для печати состояния очереди
    void printQueue(queue<int> q) {
        string result = "";
        while (!q.empty()) {
            result += to_string(q.front()) + " ";
            q.pop();
        }
        cout << left << setw(15) << result;
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
    Graph g(8);

    // Добавляем ребра 
    g.addEdge(3, 2);
    g.addEdge(3, 5);
    g.addEdge(2, 0);
    g.addEdge(2, 4);
    g.addEdge(5, 1);
    g.addEdge(4, 7);
    g.addEdge(1, 6);

    g.print();
    int startVertex = 3; // Стартовая вершина по примеру
    cout << "Стартовая вершина: " << startVertex << endl;
    g.bfs(startVertex);

    return 0;
}