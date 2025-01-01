#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Graph {
    int numVertices;
    int** adjMatrix;
} Graph;


Node* createNode(int data);
Node* insert(Node* root, int data);
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void DFSUtil(Graph* graph, int vertex, bool* visited);
void DFS(Graph* graph, int startVertex);
void BFS(Graph* graph, int startVertex);
void measureTreeTraversal(Node* root);
void measureGraphTraversal(Graph* graph, int startVertex);

int main() {
    int n = 10;

    Node* root = NULL;
    for (int i = 1; i <= n; i++) {
        root = insert(root, i);
    }

    printf(" tree :\n");
    measureTreeTraversal(root);

    // tao do thi
    Graph* graph = createGraph(n);
    for (int i = 0; i < n - 1; i++) {
        addEdge(graph, i, i + 1);
    }

    printf("\n graph :\n");
    measureGraphTraversal(graph, 0);

    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; 
}


void DFSUtil(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)calloc(graph->numVertices, sizeof(bool));
    printf("DFS: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}

void BFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)calloc(graph->numVertices, sizeof(bool));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS: ");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
    free(queue);
    free(visited);
}

void measureTreeTraversal(Node* root) {
    clock_t start, end;

    start = clock();
    printf("Pre-order: ");
    preOrder(root);
    printf("\n");
    end = clock();
    printf("time for Pre-order: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("In-order: ");
    inOrder(root);
    printf("\n");
    end = clock();
    printf("time for In-order: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("Post-order: ");
    postOrder(root);
    printf("\n");
    end = clock();
    printf("time for Post-order: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void measureGraphTraversal(Graph* graph, int startVertex) {
    clock_t start, end;

    start = clock();
    DFS(graph, startVertex);
    end = clock();
    printf("time for DFS: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    BFS(graph, startVertex);
    end = clock();
    printf("time for BFS: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}
