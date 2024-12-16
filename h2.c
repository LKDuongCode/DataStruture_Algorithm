#include <stdio.h>
#define MAX 100

int adjacencyMatrix[MAX][MAX];
int vertexCount = 0; // so luong dinh hien tai

void initializeGraph(int vertices);
void addEdge(int src, int dest, int isDirected);
void displayAdjacencyMatrix();

int main() {
    int vertices = 4;
    initializeGraph(vertices);

    addEdge(0, 1, 0); // do thi vo huong
    addEdge(0, 2, 0);
    addEdge(1, 2, 0);
    addEdge(1, 3, 0);

    displayAdjacencyMatrix();

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

void displayAdjacencyMatrix() {
    printf("ma tran ke:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}
