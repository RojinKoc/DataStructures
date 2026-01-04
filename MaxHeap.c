#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Heap'in maksimum boyutu

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i) {
    int largest = i;       // Kökü en büyük varsay
    int left = 2 * i + 1;  // Sol çocuk
    int right = 2 * i + 2; // Sağ çocuk

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        // Etkilenen alt ağacı da düzelt (Recursive)
        heapify(largest);
    }
}


void insert(int value) {
    if (size == MAX_SIZE) {
        printf("Heap dolu!\n");
        return;
    }

    heap[size] = value;
    int current = size;
    size++;
    while (current != 0 && heap[(current - 1) / 2] < heap[current]) {
        swap(&heap[(current - 1) / 2], &heap[current]);
        current = (current - 1) / 2; 
    }
    
    printf("%d eklendi.\n", value);
}

void deleteMax() {
    if (size <= 0) {
        printf("Heap bos, silinecek eleman yok.\n");
        return;
    }

    int deletedValue = heap[0];
    
    heap[0] = heap[size - 1];
    size--;

    heapify(0);

    printf("%d silindi (Max Deger).\n", deletedValue);
}

void printHeap() {
    if (size == 0) {
        printf("Heap bos.\n");
        return;
    }
    printf("Max Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20); // 20 başa geçmeli
    insert(15);
    insert(30); // 30 başa geçmeli
    insert(40); // 40 başa geçmeli

    printHeap(); // Beklenen: 40 30 15 10 20 (veya benzer yapı)

    deleteMax(); // 40 silinmeli, yerine 20 geçip aşağı itilmeli
    printHeap();

    deleteMax(); // 30 silinmeli
    printHeap();

    return 0;
}
