#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 

int adjacencyMatrix[MAX][MAX];
int vertexCount = 0; 

void initializeGraph(int vertices);
void addEdge(int src, int dest, int isDirected);
bool dfsDirected(int vertex, bool visited[], bool recStack[]);
bool hasCycleDirected();
bool dfsUndirected(int vertex, bool visited[], int parent);
bool hasCycleUndirected();

int main() {
    int vertices, edges, isDirected;

    printf("nhap so luong dinh: ");
    scanf("%d", &vertices);
    initializeGraph(vertices);

    printf("nhap so luong canh: ");
    scanf("%d", &edges);

    printf("do thi co huong (1) hay vo huong (0)?: ");
    scanf("%d", &isDirected);

    printf("nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest, isDirected);
    }

    if (isDirected) {
        if (hasCycleDirected()) {
            printf("do thi co chu ky\n");
        } else {
            printf("do thi khong co chu ky\n");
        }
    } else {
        if (hasCycleUndirected()) {
            printf("do thi co chu ky\n");
        } else {
            printf("do thi khong co chu ky\n");
        }
    }

    return 0;
}


void initializeGraph(int vertices) {
    vertexCount = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0; // ma tran ke ban dau la 0
        }
    }
}

void addEdge(int src, int dest, int isDirected) {
    adjacencyMatrix[src][dest] = 1;
    if (!isDirected) {
        adjacencyMatrix[dest][src] = 1; // neu la do thi vo huong
    }
}

bool dfsDirected(int vertex, bool visited[], bool recStack[]) {
    visited[vertex] = true;
    recStack[vertex] = true;

    for (int i = 0; i < vertexCount; i++) {
        if (adjacencyMatrix[vertex][i]) {
            if (!visited[i] && dfsDirected(i, visited, recStack)) {
                return true;
            } else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[vertex] = false;
    return false;
}

bool hasCycleDirected() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < vertexCount; i++) {
        if (!visited[i] && dfsDirected(i, visited, recStack)) {
            return true;
        }
    }

    return false;
}

bool dfsUndirected(int vertex, bool visited[], int parent) {
    visited[vertex] = true;

    for (int i = 0; i < vertexCount; i++) {
        if (adjacencyMatrix[vertex][i]) {
            if (!visited[i]) {
                if (dfsUndirected(i, visited, vertex)) {
                    return true;
                }
            } else if (i != parent) {
                return true;
            }
        }
    }

    return false;
}

bool hasCycleUndirected() {
    bool visited[MAX] = {false};

    for (int i = 0; i < vertexCount; i++) {
        if (!visited[i] && dfsUndirected(i, visited, -1)) {
            return true;
        }
    }

    return false;
}
