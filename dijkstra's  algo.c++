#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);
    // adj[u] = {v, weight}

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove for directed graph
    }

    int src;
    cin >> src;

    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currDist > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output shortest distances
    for (int i = 0; i < V; i++) {
        cout << "Distance from " << src << " to " << i
             << " is " << dist[i] << endl;
    }

    return 0;
}
