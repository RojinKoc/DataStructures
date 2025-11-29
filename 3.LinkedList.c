#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısının tanımlanması
struct Node {
    int data;
    struct Node* next;
};

// --- EN ÖNEMLİ KISIM: YARDIMCI FONKSİYON EN BAŞTA OLMALI ---

// Yeni bir düğüm oluşturma (Memory Allocation)
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Hata: Bellek tahsis edilemedi!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// --- DİĞER FONKSİYONLAR ---

// 1. TOPLU LİSTE OLUŞTURMA (Create List)
void createList(struct Node** head_ref) {
    int n, data, i;
    struct Node *newNode, *temp;

    // Eğer listede zaten eleman varsa temp'i sona götür
    if (*head_ref != NULL) {
        printf("Liste zaten dolu! Yeni elemanlar sona eklenecek.\n");
        temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }

    printf("Kac elemanli liste olusturmak istiyorsunuz?: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Gecersiz sayi.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        printf("%d. eleman: ", i);
        scanf("%d", &data);

        newNode = createNode(data); // Artık hata vermeyecek çünkü createNode yukarıda tanımlı

        if (*head_ref == NULL) {
            *head_ref = newNode;
            temp = *head_ref;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("%d elemanli liste basariyla olusturuldu.\n", n);
}

// 2. LİSTENİN BAŞINA EKLEME
void insertAtHead(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf("%d listenin basina eklendi.\n", new_data);
}

// 3. LİSTENİN SONUNA EKLEME
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    
    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf("%d listenin sonuna eklendi (Liste bostu).\n", new_data);
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    printf("%d listenin sonuna eklendi.\n", new_data);
}

// 4. ARAYA EKLEME
void insertAfterPosition(struct Node* head, int position, int new_data) {
    struct Node* temp = head;
    
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Pozisyon listede bulunamadi!\n");
        return;
    }

    struct Node* newNode = createNode(new_data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d, %d. pozisyondan sonrasina eklendi.\n", new_data, position);
}

// 5. SİLME İŞLEMİ
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("%d listeden silindi.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d listede bulunamadi.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d listeden silindi.\n", key);
}

// 6. LİSTEYİ GEZME
void printList(struct Node* node) {
    if (node == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// --- MAIN FONKSİYONU ---
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while(1) {
        printf("\n--- Linked List Islemleri ---\n");
        printf("1. Liste Olustur (Toplu Veri Girisi)\n");
        printf("2. Basa Ekle\n");
        printf("3. Sona Ekle\n");
        printf("4. Araya Ekle (Pozisyona Gore)\n");
        printf("5. Eleman Sil (Degere Gore)\n");
        printf("6. Listeyi Yazdir (Traversal)\n");
        printf("7. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                printf("Eklenecek veri: ");
                scanf("%d", &data);
                insertAtHead(&head, data);
                break;
            case 3:
                printf("Eklenecek veri: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 4:
                printf("Hangi pozisyondan sonrasina eklenecek? (0 baslangic): ");
                scanf("%d", &pos);
                printf("Eklenecek veri: ");
                scanf("%d", &data);
                insertAfterPosition(head, pos, data);
                break;
            case 5:
                printf("Silinecek veri: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 6:
                printList(head);
                break;
            case 7:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}