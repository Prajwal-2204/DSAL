#include <iostream>
#include <cstdlib>
using namespace std;

int cost[10][10] = {0}, i, j, k, n;
int qu[10], front = 0, rear = 0, visit[10] = {0}, visited[10] = {0};
int stk[10], top = -1, visit1[10] = {0}, visited1[10] = {0};

void BFS(int v) {
    cout << "BFS Traversal: ";
    cout << v << " ";
    visited[v] = 1;
    qu[rear++] = v;

    while (front < rear) {
        v = qu[front++];
        for (j = 0; j < n; j++) {
            if (cost[v][j] == 1 && !visited[j]) {
                cout << j << " ";
                visited[j] = 1;
                qu[rear++] = j;
            }
        }
    }
    cout << endl;
}

void DFS(int v) {
    cout << "DFS Traversal: ";
    cout << v << " ";
    visited1[v] = 1;
    stk[++top] = v;

    while (top >= 0) {
        v = stk[top--];
        for (j = n - 1; j >= 0; j--) {
            if (cost[v][j] == 1 && !visited1[j]) {
                cout << j << " ";
                visited1[j] = 1;
                stk[++top] = j;
            }
        }
    }
    cout << endl;
}
int main() {
    int m, v;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEnter edges (start end):\n";
    for (k = 0; k < m; k++) {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    cout << "The adjacency matrix of the graph is:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter initial vertex for BFS: ";
    cin >> v;
    BFS(v);
    cout << "Enter initial vertex for DFS: ";
    cin >> v;
    DFS(v);
    return 0;
}




