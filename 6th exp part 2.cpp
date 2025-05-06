#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 10
#define TRUE 1
#define FALSE 0

class lgra {
private:
    struct node1 {
        int vertex;
        struct node1* next;
    };
    node1* head[MAX];
    int visited[MAX];

public:
    lgra();
    void create();
    void dfs(int);
};

lgra::lgra() {
    for (int v1 = 0; v1 < MAX; v1++) {
        visited[v1] = FALSE;
        head[v1] = NULL;
    }
}

void lgra::create() {
    int v1, v2;
    char ans;
    node1* N, * first;

    cout << "Enter the vertices no. beginning with 0";
    do {
        cout << "\nEnter the Edge of a graph (e.g., 0 1): ";
        cin >> v1 >> v2;

        if (v1 >= MAX || v2 >= MAX) {
            cout << "Invalid Vertex Value\n";
        }
        else {
            // Create first node
            N = new node1;
            if (N == NULL) {
                cout << "Insufficient Memory\n";
                return;
            }
            N->vertex = v2;
            N->next = NULL;
            if (head[v1] == NULL)
                head[v1] = N;
            else {
                first = head[v1];
                while (first->next != NULL)
                    first = first->next;
                first->next = N;
            }

            // Create second node (for undirected graph)
            N = new node1;
            if (N == NULL) {
                cout << "Insufficient Memory\n";
                return;
            }
            N->vertex = v1;
            N->next = NULL;
            if (head[v2] == NULL)
                head[v2] = N;
            else {
                first = head[v2];
                while (first->next != NULL)
                    first = first->next;
                first->next = N;
            }
        }

        cout << "\nWant to add more edges? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
}

void lgra::dfs(int v1) {
    node1* first;
    cout << v1 << " ";
    visited[v1] = TRUE;
    first = head[v1];

    while (first != NULL) {
        if (visited[first->vertex] == FALSE)
            dfs(first->vertex);
        first = first->next; // Move to next node
    }
}

int main() {
    int v1;
    lgra g;
    g.create();

    cout << "\nEnter the vertex from where you want to traverse: ";
    cin >> v1;

    if (v1 >= MAX)
        cout << "Invalid Vertex\n";
    else {
        cout << "The DFS of the graph: ";
        g.dfs(v1);
    }

    return 0;
}
