#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    private:
        int numberVertex;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int banyakTitik) {
            numberVertex = banyakTitik;
            adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
        }

        void addEdge(int i, int j) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;
        }

        void bfs(int startVertex) {
            vector<bool> visited(numberVertex, false);
            queue<int> titikVisit;

            visited[startVertex] = true;
            titikVisit.push(startVertex);

            while (!titikVisit.empty()) {
                int currentVertex = titikVisit.front();
                titikVisit.pop();
                cout << char('A' + currentVertex) << " ";

                for (int i = 0; i < numberVertex; i++) {
                    if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        titikVisit.push(i);
                    }
                }
            }
            cout << endl;
        }
};

int main() {
    Graph graphh(6);
    int jumlahEdge;
    char a, b, awal;

    cout << "Masukkan jumlah edge : ";
    cin >> jumlahEdge;

    for (int i = 0; i < jumlahEdge; i++) {
        cout << "Edge ke-" << i + 1 << " : ";
        cin >> a >> b;
        graphh.addEdge(a - 'A', b - 'A');
    }

    cout << "Masukkan vertex awal : ";
    cin >> awal;

    cout << "Urutan BFS : ";
    graphh.bfs(awal - 'A');

    return 0;
}