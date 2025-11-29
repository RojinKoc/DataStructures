#include <stdio.h>
#include <stdlib.h>

// Çift Yönlü Düğüm Yapısı
struct Node {
    int data;
    struct Node* next; // Sonraki düğüm
    struct Node* prev; // Önceki düğüm
};

// Yeni düğüm oluşturma
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 1. LİSTENİN SONUNA EKLEME (Insert at End)
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    // Eğer liste boşsa, yeni düğüm head olur
    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf("%d sona eklendi (Liste bostu).\n", new_data);
        return;
    }

    // Sona kadar git
    while (last->next != NULL) {
        last = last->next;
    }

    // Bağlantıları kur
    last->next = newNode; // Eskinin sonu -> Yeni
    newNode->prev = last; // Yeninin arkası -> Eski son
    printf("%d sona eklendi.\n", new_data);
}

// 2. ARAYA EKLEME (Insert After a Node)
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Hata: Onceki dugum NULL olamaz.\n");
        return;
    }

    struct Node* newNode = createNode(new_data);

    // 1. Yeni düğümün next'i, önceki düğümün next'i olur
    newNode->next = prev_node->next;

    // 2. Önceki düğümün next'i, yeni düğüm olur
    prev_node->next = newNode;

    // 3. Yeni düğümün prev'i, önceki düğüm olur
    newNode->prev = prev_node;

    // 4. Eğer yeni düğüm son eleman değilse, sonraki elemanın prev'ini güncelle
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
    printf("%d, %d degerinden sonraya eklendi.\n", new_data, prev_node->data);
}

// 3. RECURSIVE (ÖZYİNELEMELİ) SİLME
// Mantık: Sona kadar git, dönerken free et (Post-order traversal)
void deleteListRecursive(struct Node* node) {
    if (node == NULL)
        return;

    // Özyineleme: Önce sonrakini sil
    deleteListRecursive(node->next);

    // İşlem: Dönerken sil
    printf("Dugum siliniyor: %d\n", node->data);
    free(node);
}

// Listeyi Yazdırma (İleri Yönlü)
void printList(struct Node* node) {
    struct Node* last;
    printf("\nListe (Ileri): ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // 1. Sona Ekleme Testleri
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printList(head);

    // 2. Araya Ekleme Testi (Head'den sonraya ekle: 10 ile 20 arasına 15)
    // Head şu an 10'u gösteriyor.
    insertAfter(head, 15);
    
    // 20'den sonraya 25 ekleyelim (Manuel traversal ile 20'yi bulup)
    insertAfter(head->next->next, 25); 

    printList(head);

    // 3. Recursive Silme Testi
    printf("\n--- Recursive Silme Basliyor ---\n");
    deleteListRecursive(head);
    head = NULL; // Dangling pointer olmaması için head'i sıfırla
    
    printf("Liste silindi.\n");

    return 0;
}