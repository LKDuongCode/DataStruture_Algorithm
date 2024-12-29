#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    bool* visited;
} Graph;


Node* createNode(int vertex);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void dfs(Graph* graph, int vertex);
bool isConnected(Graph* graph);

int main() {
    int V, E;
    printf("nhap so dinh: ");
    scanf("%d", &V);
    printf("nhap so canh: ");
    scanf("%d", &E);

    Graph* graph = createGraph(V);

    printf("nhap cac canh (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (isConnected(graph)) {
        printf("\nDo thi lien thong\n");
    } else {
        printf("\nDo thi khong lien thong\n");
    }

    return 0;
}

// ham tao mot nut moi
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// ham tao do thi
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// ham them canh vao do thi
void addEdge(Graph* graph, int src, int dest) {
    // them canh tu src den dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // them canh tu dest den src (do thi vo huong)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// ham dfs thuat toan de quy
void dfs(Graph* graph, int vertex) {
    graph->visited[vertex] = true;

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// ham kiem tra tinh lien thong
bool isConnected(Graph* graph) {
    // bat dau dfs tu dinh 0
    dfs(graph, 0);

    // kiem tra tat ca cac dinh da duoc tham
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            return false; // co dinh chua duoc tham
        }
    }
    return true;
}
