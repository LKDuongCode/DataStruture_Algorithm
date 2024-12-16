#include <stdio.h>
#include <stdlib.h>
#define MAX 100 

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX]; //danh sach ke
int adjacencyMatrix[MAX][MAX]; // Ma tran ke
int vertexCount = 0; // So luong dinh hien tai

void initializeGraph(int vertices);
void addEdge(int src, int dest, int isDirected);
void displayAdjacencyMatrix();
void displayAdjacencyList();

int main() {
    int vertices = 4; 
    initializeGraph(vertices);

    addEdge(0, 1, 0); 
    addEdge(0, 2, 0);
    addEdge(1, 2, 0);
    addEdge(1, 3, 0);

    displayAdjacencyMatrix();
    printf("\n");
    displayAdjacencyList();

    return 0;
}


void initializeGraph(int vertices) {
    vertexCount = vertices;
    for (int i = 0; i < vertices; i++) {
        adjacencyList[i] = NULL; // Danh sach ke ban dau rong
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0; // Ma tran ke ban dau la 0
        }
    }
}

void addEdge(int src, int dest, int isDirected) {
    // Cap nhat ma tran ke
    adjacencyMatrix[src][dest] = 1;
    if (!isDirected) {
        adjacencyMatrix[dest][src] = 1; // Neu la do thi vo huong
    }

    // Cap nhat danh sach ke
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    if (!isDirected) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = src;
        newNode->next = adjacencyList[dest];
        adjacencyList[dest] = newNode;
    }
}

void displayAdjacencyMatrix() {
    printf("Ma tran ke:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayAdjacencyList() {
    printf("Danh sach ke:\n");
    for (int i = 0; i < vertexCount; i++) {
        printf("%d: ", i);
        Node* temp = adjacencyList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
