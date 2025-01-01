#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    int numVertices;
    GraphNode** adjLists;
} Graph;


Node* createTreeNode(int value);
Node* insert(Node* root, int value);
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void convertTreeToGraph(Node* root, Graph* graph);
void DFSUtil(Graph* graph, int vertex, bool* visited);
void DFS(Graph* graph, int startVertex);
void BFS(Graph* graph, int startVertex);

int main() {
    Node* root = NULL;
    int n;
    printf(" so  nut trong cay: ");
    scanf("%d", &n);

    printf(" cac gia tri cua nut: \n");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("pre: ");
    preOrder(root);
    printf("\n");

    printf("in: ");
    inOrder(root);
    printf("\n");

    printf("post ");
    postOrder(root);
    printf("\n");

    
    Graph* graph = createGraph(n + 1);
    convertTreeToGraph(root, graph);

    int startVertex;
    printf(" dinh bat dau : ");
    scanf("%d", &startVertex);

    DFS(graph, startVertex);
    BFS(graph, startVertex);

    return 0;
}

Node* createTreeNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createTreeNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
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
    graph->adjLists = (GraphNode**)malloc(vertices * sizeof(GraphNode*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void convertTreeToGraph(Node* root, Graph* graph) {
    if (root == NULL) return;

    if (root->left != NULL) {
        addEdge(graph, root->data, root->left->data);
        convertTreeToGraph(root->left, graph);
    }
    if (root->right != NULL) {
        addEdge(graph, root->data, root->right->data);
        convertTreeToGraph(root->right, graph);
    }
}

void DFSUtil(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    GraphNode* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    printf("DFS: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");

    free(visited);
}

void BFS(Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
    }

    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS: ");

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        GraphNode* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    printf("\n");

    free(queue);
    free(visited);
}
