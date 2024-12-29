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
bool dfsCycleDetection(Graph* graph, int vertex, bool* recStack);
bool hasCycle(Graph* graph);

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

    if (hasCycle(graph)) {
        printf("\ndo thi co chu trinh\n");
    } else {
        printf("\ndo thi khong co chu trinh\n");
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
}

// ham kiem tra chu trinh su dung dfs
bool dfsCycleDetection(Graph* graph, int vertex, bool* recStack) {
    if (!graph->visited[vertex]) {
        // danh dau dinh hien tai la da tham va them vao ngan xep de quy
        graph->visited[vertex] = true;
        recStack[vertex] = true;

        // duyet cac dinh ke
        Node* temp = graph->adjLists[vertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex] && dfsCycleDetection(graph, adjVertex, recStack)) {
                return true;
            } else if (recStack[adjVertex]) {
                return true;
            }
            temp = temp->next;
        }
    }

    // loai bo dinh hien tai khoi ngan xep de quy
    recStack[vertex] = false;
    return false;
}

// ham kiem tra chu trinh trong do thi
bool hasCycle(Graph* graph) {
    bool* recStack = (bool*)malloc(graph->numVertices * sizeof(bool));
    for (int i = 0; i < graph->numVertices; i++) {
        recStack[i] = false;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (dfsCycleDetection(graph, i, recStack)) {
            free(recStack);
            return true;
        }
    }

    free(recStack);
    return false;
}
