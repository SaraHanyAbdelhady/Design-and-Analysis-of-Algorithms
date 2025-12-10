#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

vector<int> dijkstra(int start, int n, vector<Edge>& edges, vector<int>& parent) {
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    parent[start] = -1;

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (const Edge& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<Edge> edges;
    edges.push_back(Edge(4, 1, 4));
    edges.push_back(Edge(1, 2, 5));
    edges.push_back(Edge(1, 5, 3));
    edges.push_back(Edge(2, 3, 3));
    edges.push_back(Edge(5, 3, 2));

    vector<vector<int>> queries = { {4, 3}, {2, 5}, {5, 3} };

    for (auto& q : queries) {
        int start = q[0], end = q[1];
        vector<int> parent(n + 1, -1);
        vector<int> distances = dijkstra(start, n, edges, parent);

        if (distances[end] == INT_MAX) {
            cout << "Minimal path from vertix "<<start<<" to vertix "<<end<<" : N / A, Distance : -1.\n";
        }
        else {
            cout << "Minimal path from vertix " << start << "to vertix " << end << " :";
            vector<int> path;
            for (int v = end; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];
                if (i > 0) cout << " -> ";
            }

            cout << ", Distance: " << distances[end];
            cout << ".\n";
        }
    }

    return 0;
}