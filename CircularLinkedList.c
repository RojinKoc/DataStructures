#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// --- YARDIMCI: Node Oluşturma ---
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1. TRAVERSAL (Gezme/Yazdırma)
// Fark: do-while döngüsü kullanılır.
void printList(struct Node* head) {
    struct Node* temp = head;
    
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    printf("Circular List: ");
    
    // do-while kullanıyoruz çünkü while(temp != head) desek,
    // ilk adımda zaten eşit olduğu için hiç girmez.
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(HEAD'e dondu)\n");
}

// 2. SONA EKLEME (Listeyi oluşturmak için gerekli)
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head_ref;

    // Liste boşsa, kendi kendini işaret eder
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref;
        printf("%d listeye eklendi (Ilk Eleman).\n", data);
        return;
    }

    // Sona git (Son düğüm head'i gösterir)
    while (temp->next != *head_ref) {
        temp = temp->next;
    }

    temp->next = newNode;     // Eski son artık yeniyi gösterir
    newNode->next = *head_ref; // Yeni son head'i gösterir
    printf("%d sona eklendi.\n", data);
}

// 3. ARAYA EKLEME (Insert After)
// Belirli bir değerden (key) sonraya ekler
void insertAfter(struct Node* head, int key, int newData) {
    if (head == NULL) return;

    struct Node *temp = head;
    struct Node *newNode;

    // Aranan elemanı (key) bulana kadar dön
    do {
        if (temp->data == key) {
            newNode = createNode(newData);
            
            // Bağlantıları güncelle
            newNode->next = temp->next; // Yeni düğüm, temp'in sonrakini göstersin
            temp->next = newNode;       // temp artık yeniyi göstersin
            
            printf("%d, %d degerinden sonraya eklendi.\n", newData, key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("%d listede bulunamadi, ekleme yapilmadi.\n", key);
}

// 4. SİLME İŞLEMİ (Deletion) - En Kritik Kısım!
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    struct Node *curr = *head_ref, *prev = NULL;

    // --- Durum 1: Liste tek elemanlıysa ve o silinecekse ---
    if (curr->data == key && curr->next == curr) {
        *head_ref = NULL;
        free(curr);
        printf("%d silindi (Liste simdi bos).\n", key);
        return;
    }

    // --- Durum 2: Silinecek eleman HEAD ise ---
    // (Head silinirse son elemanın next'ini güncellemek gerekir!)
    if (curr->data == key) {
        struct Node* last = *head_ref;
        
        // Son elemanı bul
        while (last->next != *head_ref) {
            last = last->next;
        }

        // Head'i bir yana kaydır
        *head_ref = curr->next;
        
        // Son eleman artık yeni head'i göstermeli
        last->next = *head_ref;
        
        free(curr);
        printf("%d silindi (Head dugumuydu).\n", key);
        return;
    }

    // --- Durum 3: Aradan veya sondan silme ---
    // Elemanı bulana kadar gez
    while (curr->next != *head_ref && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // Bulduysak
    if (curr->data == key) {
        prev->next = curr->next; // Aradan çıkar
        free(curr);
        printf("%d silindi.\n", key);
    } else {
        printf("%d listede bulunamadi.\n", key);
    }
}

// --- TEST MAIN ---
int main() {
    struct Node* head = NULL;

    // Liste Oluşturma
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printList(head); // 10 -> 20 -> 30 -> 40 -> (HEAD)

    // Araya Ekleme (20'den sonraya 25)
    printf("\n--- Araya Ekleme Testi ---\n");
    insertAfter(head, 20, 25);
    printList(head); // 10 -> 20 -> 25 -> 30 -> 40 -> (HEAD)

    // Silme İşlemleri
    printf("\n--- Silme Testleri ---\n");
    
    // Head'i sil (10) - En zor durum
    deleteNode(&head, 10);
    printList(head); // 20 -> 25 -> 30 -> 40 -> (HEAD)

    // Aradan sil (25)
    deleteNode(&head, 25); 
    printList(head);

    // Sondan sil (40)
    deleteNode(&head, 40);
    printList(head);

    return 0;
}
