#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cau truc do thi
typedef struct Graph {
    int n;                     // So dinh
    int adjMatrix[MAX][MAX];   // Ma tran ke
} Graph;

// Khoi tao do thi
void initGraph(Graph* g, int vertices) {
    g->n = vertices;
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Them canh vao do thi
void addEdge(Graph* g, int src, int dest) {
    if (src >= g->n || dest >= g->n) {
        printf("Dinh khong hop le!\n");
        return;
    }
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // Do thi vo huong
}

// Hien thi ma tran ke cua do thi
void displayGraph(Graph* g) {
    printf("\nMa tran ke cua do thi:\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Duyet DFS (su dung de quy)
void DFS(Graph* g, int vertex, int visited[]) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < g->n; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

// Ham goi DFS
void DFS_Call(Graph* g, int start) {
    int visited[MAX] = {0};
    printf("Duyet DFS bat dau tu dinh %d: ", start);
    DFS(g, start, visited);
    printf("\n");
}

// Duyet BFS (su dung hang doi)
void BFS(Graph* g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    printf("Duyet BFS bat dau tu dinh %d: ", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < g->n; i++) {
            if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Menu chuc nang
void menu() {
    printf("\n--- MENU ---\n");
    printf("1. Them canh vao do thi\n");
    printf("2. Hien thi do thi\n");
    printf("3. Duyet do thi theo DFS\n");
    printf("4. Duyet do thi theo BFS\n");
    printf("5. Thoat\n");
    printf("------------\n");
}

int main() {
    Graph g;
    int vertices, choice, src, dest, start;

    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    do {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap dinh nguon va dinh dich (src dest): ");
                scanf("%d %d", &src, &dest);
                addEdge(&g, src, dest);
                break;
            case 2:
                displayGraph(&g);
                break;
            case 3:
                printf("Nhap dinh bat dau DFS: ");
                scanf("%d", &start);
                DFS_Call(&g, start);
                break;
            case 4:
                printf("Nhap dinh bat dau BFS: ");
                scanf("%d", &start);
                BFS(&g, start);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 5);

    return 0;
}

