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
} Graph;

Node* createNode(int vertex);
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void DFSUtil(Graph* graph, int vertex, bool* visited);
void DFS(Graph* graph, int startVertex);
void BFS(Graph* graph, int startVertex);

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

    int startVertex;
    printf("nhap dinh bat dau duyet: ");
    scanf("%d", &startVertex);

    DFS(graph, startVertex);
    BFS(graph, startVertex);

    for (int i = 0; i < V; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}


Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}


Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    //  src den dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    //  dest den src 
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFSUtil(Graph* graph, int vertex, bool* visited) {
    visited[vertex] = true;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
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

    printf("dfs bat dau tu dinh %d: ", startVertex);
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

    printf("bfs bat dau tu dinh %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
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
