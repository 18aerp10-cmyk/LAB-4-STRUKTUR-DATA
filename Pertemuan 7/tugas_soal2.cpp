#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    private:
        int V;
        vector<vector<int>> adjMatrix;
        vector<int> distance;
        vector<int> parent;

        void cetakRute(int tujuan) {
            if (parent[tujuan] != -1) {
                cetakRute(parent[tujuan]);
                cout << " -> ";
            }
            cout << char('A' + tujuan);
        }

    public:
        Graph(int jumlahVertex) {
            V = jumlahVertex;
            adjMatrix.resize(V, vector<int>(V, 0));
        }

        void addEdge(int u, int v, int weight) {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight;
        }

        void dijkstra(int source) {
            vector<bool> visited(V, false);
            distance.assign(V, INT_MAX);
            parent.assign(V, -1);
            distance[source] = 0;

            for (int i = 0; i < V; i++) {
                int u = -1;

                for (int j = 0; j < V; j++) {
                    if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                        u = j;
                    }
                }

                visited[u] = true;

                for (int v = 0; v < V; v++) {
                    if (adjMatrix[u][v] != 0 && !visited[v]) {
                        int newDistance = distance[u] + adjMatrix[u][v];

                        if (newDistance < distance[v]) {
                            distance[v] = newDistance;
                            parent[v] = u;
                        }
                    }
                }
            }
        }

        void tampilSemuaRute(int source) {
            for (int i = 0; i < V; i++) {
                if (i != source) {
                    cetakRute(i);
                    cout << " : " << distance[i] << " km" << endl;
                }
            }
        }

        void rekomendasiRute(int tujuan) {
            cout << "Rute tercepat : ";
            cetakRute(tujuan);
            cout << endl;
            cout << "Total jarak : " << distance[tujuan] << " km" << endl;
        }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 4);
    graph.addEdge(4, 5, 3);

    graph.dijkstra(0);
    cout << "Rute terpendek dari A ke semua lokasi :" << endl;
    graph.tampilSemuaRute(0);
    cout << endl;

    char asal, tujuan;
    cout << "Masukkan lokasi asal : ";
    cin >> asal;
    cout << "Masukkan lokasi tujuan : ";
    cin >> tujuan;

    graph.dijkstra(asal - 'A');
    graph.rekomendasiRute(tujuan - 'A');

    return 0;
}