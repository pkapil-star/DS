#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20;
const int INF = 1000000000;

struct Edge {
    int u;
    int v;
    int w;
};

int graph[MAX][MAX];
int parentDSU[MAX];
int rankDSU[MAX];

int findSet(int x) {
    if (parentDSU[x] == x) return x;
    parentDSU[x] = findSet(parentDSU[x]);
    return parentDSU[x];
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return;
    if (rankDSU[a] < rankDSU[b]) parentDSU[a] = b;
    else if (rankDSU[a] > rankDSU[b]) parentDSU[b] = a;
    else {
        parentDSU[b] = a;
        rankDSU[a]++;
    }
}

void bfs(int n, int start) {
    bool visited[MAX] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int n, int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (graph[u][v] != 0 && !visited[v]) {
            dfsUtil(n, v, visited);
        }
    }
}

void dfs(int n, int start) {
    bool visited[MAX] = {false};
    cout << "DFS: ";
    dfsUtil(n, start, visited);
    cout << endl;
}

void primMST(int n) {
    int key[MAX];
    bool inMST[MAX];
    int parent[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }
    key[0] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minKey = INF;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        inMST[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    int total = 0;
    cout << "Prim MST edges:\n";
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "  weight " << graph[parent[i]][i] << endl;
            total += graph[parent[i]][i];
        }
    }
    cout << "Total weight: " << total << endl;
}

void kruskalMST(int n) {
    Edge edges[MAX * MAX];
    int eCount = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] != 0) {
                edges[eCount].u = i;
                edges[eCount].v = j;
                edges[eCount].w = graph[i][j];
                eCount++;
            }

    sort(edges, edges + eCount, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    for (int i = 0; i < n; i++) {
        parentDSU[i] = i;
        rankDSU[i] = 0;
    }

    int total = 0;
    cout << "Kruskal MST edges:\n";
    int chosen = 0;
    for (int i = 0; i < eCount && chosen < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (findSet(u) != findSet(v)) {
            unionSet(u, v);
            cout << u << " - " << v << "  weight " << w << endl;
            total += w;
            chosen++;
        }
    }
    cout << "Total weight: " << total << endl;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    bool visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int best = INF;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    cout << "Dijkstra distances from " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "To " << i << " : INF\n";
        else cout << "To " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of vertices (<= " << MAX << "): ";
    cin >> n;
    cout << "Enter adjacency matrix (weight, 0 if no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int choice;
    do {
        cout << "\n1. BFS\n2. DFS\n3. Prim MST\n4. Kruskal MST\n5. Dijkstra\n0. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            int s;
            cout << "Enter start vertex: ";
            cin >> s;
            bfs(n, s);
        } else if (choice == 2) {
            int s;
            cout << "Enter start vertex: ";
            cin >> s;
            dfs(n, s);
        } else if (choice == 3) {
            primMST(n);
        } else if (choice == 4) {
            kruskalMST(n);
        } else if (choice == 5) {
            int s;
            cout << "Enter source vertex: ";
            cin >> s;
            dijkstra(n, s);
        }
    } while (choice != 0);

    return 0;
}
