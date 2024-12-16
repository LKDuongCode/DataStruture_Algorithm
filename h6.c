#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100 

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjacencyList[MAX]; 
bool visited[MAX];

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* createQueue();
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void initializeGraph(int vertices);
void addEdge(int src, int dest);
void bfs(int startVertex);

int main() {
    int vertices, edges;
    
    printf("nhap so luong dinh: ");
    scanf("%d", &vertices);
    printf("nhap so luong canh: ");
    scanf("%d", &edges);

    initializeGraph(vertices);
    printf("nhap cac canh (dinh1 dinh2):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    int startVertex;
    printf("nhap dinh bat dau: ");
    scanf("%d", &startVertex);

    bfs(startVertex);

    return 0;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("hang doi day!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        adjacencyList[i] = NULL;
        visited[i] = false;
    }
}

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

void bfs(int startVertex) {
    Queue* q = createQueue();
    visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("duyet theo bfs: ");

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        Node* temp = adjacencyList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(q);
}
