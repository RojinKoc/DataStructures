#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10 // Maksimum düğüm sayısı

// --- QUEUE YAPISI (BFS İçin Gerekli) ---
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isQueueEmpty() {
    return (front == -1 || front > rear);
}

void resetQueue() {
    front = -1;
    rear = -1;
}

// --- 1. DFS ALGORİTMASI (Recursive - Stack Mantığı) ---
void DFS(int u, int n, int adj[MAX][MAX], bool visited[]) {
    // 1. Ziyaret et ve yazdır
    visited[u] = true;
    printf("%d ", u);

    // 2. Komşulara derinlemesine git
    for (int v = 0; v < n; v++) {
        // Bağlantı var mı (1) VE daha önce gidildi mi?
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v, n, adj, visited);
        }
    }
}

// --- 2. BFS ALGORİTMASI (Iterative - Queue Mantığı) ---
void BFS(int startNode, int n, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    
    // Kuyruğu sıfırla
    resetQueue();

    // 1. Başlangıç düğümünü işaretle ve kuyruğa at
    visited[startNode] = true;
    enqueue(startNode);

    printf("BFS Traversal: ");

    while (!isQueueEmpty()) {
        // 2. Kuyruğun başındakini al ve yazdır
        int u = dequeue();
        printf("%d ", u);

        // 3. Bu düğümün tüm komşularını gez
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true; // Kuyruğa girerken ziyaret edildi sayılır
                enqueue(v);
            }
        }
    }
    printf("\n");
}

int main() {
    int numVertices = 6;
    
    int adjMatrix[MAX][MAX] = {
        // 0  1  2  3  4  5
        {0, 1, 1, 0, 0, 0}, // 0
        {1, 0, 0, 1, 0, 0}, // 1
        {1, 0, 0, 1, 0, 0}, // 2
        {0, 1, 1, 0, 1, 1}, // 3
        {0, 0, 0, 1, 0, 0}, // 4
        {0, 0, 0, 1, 0, 0}  // 5
    };

    // --- DFS TESTİ ---
    bool visitedDFS[MAX] = {false}; // DFS için temiz visited dizisi
    printf("DFS Traversal: ");
    DFS(0, numVertices, adjMatrix, visitedDFS); // 0'dan başla
    printf("\n");

    // --- BFS TESTİ ---
    BFS(0, numVertices, adjMatrix); // 0'dan başla

    return 0;
}
