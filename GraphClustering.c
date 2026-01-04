#include <stdio.h>
#include <stdbool.h>

#define MAX 10 // Maksimum düğüm sayısı

// --- DFS ALGORİTMASI ---
// Verilen düğümden (u) başlayıp gidebildiği her yeri gezer ve işaretler
void DFS(int u, int n, int adj[MAX][MAX], bool visited[]) {
    // 1. Şu anki düğümü ziyaret edildi olarak işaretle ve yazdır
    visited[u] = true;
    printf("%d ", u);

    // 2. Bu düğümün komşularını gez
    for (int v = 0; v < n; v++) {
        // Eğer u ile v arasında bağ varsa (adj[u][v] == 1)
        // VE v henüz ziyaret edilmemişse
        if (adj[u][v] == 1 && !visited[v]) {
            DFS(v, n, adj, visited); // Derinlemesine git (Recursive)
        }
    }
}

// --- CLUSTER (Connected Components) BULMA ---
void findClusters(int n, int adj[MAX][MAX]) {
    bool visited[MAX];
    int clusterCount = 0;

    // Başlangıçta kimse ziyaret edilmedi
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    printf("\n--- Graph Kumeleme Analizi ---\n");

    // Tüm düğümleri kontrol et
    for (int i = 0; i < n; i++) {
        // Eğer düğüme daha önce gidilmediyse, yeni bir küme başlangıcıdır
        if (visited[i] == false) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            
            // Bu düğümden erişilebilen herkesi bu kümeye dahil et
            DFS(i, n, adj, visited);
            
            printf("}\n");
        }
    }
    
    printf("\nToplam Cluster Sayisi: %d\n", clusterCount);
}

int main() {
    int numVertices = 7;

    // Örnek Adjacency Matrix (Komşuluk Matrisi)
    // 1: Bağlantı var, 0: Bağlantı yok
    // Bu matriste 2 ayrı kopuk parça (Cluster) var.
    int adjMatrix[MAX][MAX] = {
        // 0  1  2  3  4  5  6
        {0, 1, 1, 0, 0, 0, 0}, // 0. Düğüm (1 ve 2'ye bağlı)
        {1, 0, 0, 0, 0, 0, 0}, // 1. Düğüm (0'a bağlı)
        {1, 0, 0, 0, 0, 0, 0}, // 2. Düğüm (0'a bağlı)
        {0, 0, 0, 0, 1, 1, 0}, // 3. Düğüm (4 ve 5'e bağlı) - AYRI KÜME
        {0, 0, 0, 1, 0, 0, 0}, // 4. Düğüm (3'e bağlı)
        {0, 0, 0, 1, 0, 0, 1}, // 5. Düğüm (3 ve 6'ya bağlı)
        {0, 0, 0, 0, 0, 1, 0}  // 6. Düğüm (5'e bağlı)
    };
    /*
       Görsel Yapı:
       Cluster 1:  1 -- 0 -- 2  (Üçgenimsi yapı)
       
       Cluster 2:  4 -- 3 -- 5 -- 6 (Zincir yapı)
    */

    findClusters(numVertices, adjMatrix);

    return 0;
}
