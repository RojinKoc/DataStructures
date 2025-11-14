#include <stdio.h>

#define MAX 100

// DİZİYİ YAZDIRMA FONKSİYONU
void printArray(int arr[], int n) {
    printf("Dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. TERS ÇEVİRME
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1, temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

// 2. EKLEME
void insertElement(int arr[], int *n, int pos, int value) {
    if (*n >= MAX) {
        printf("Dizi dolu!\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;
}

// 3. ÇIKARTMA
void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Gecersiz index!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

// ANA PROGRAM
int main() {
    int arr[MAX];
    int n, choice, pos, value;

    // Kullanıcıdan başlangıç dizisini al
    printf("Dizi kac elemanli olsun? ");
    scanf("%d", &n);

    printf("%d elemani girin:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1 - Diziyi Tersine Cevir\n");
        printf("2 - Diziye Eleman Ekle\n");
        printf("3 - Diziden Eleman Sil\n");
        printf("4 - Diziyi Yazdir\n");
        printf("0 - Cikis\n");
        printf("Secim: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverseArray(arr, n);
                printf("Dizi tersine cevrildi.\n");
                break;

            case 2:
                printf("Hangi indexe eklenecek? ");
                scanf("%d", &pos);
                printf("Eklenecek deger: ");
                scanf("%d", &value);
                insertElement(arr, &n, pos, value);
                break;

            case 3:
                printf("Silinecek index: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;

            case 4:
                printArray(arr, n);
                break;

            case 0:
                printf("Program kapatiliyor...\n");
                return 0;

            default:
                printf("Gecersiz secim!\n");
        }
    }

    return 0;
}
