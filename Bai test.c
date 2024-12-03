#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;
int i,j;

bool isPrime(int n) {
    if (n < 2) return false;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so phan tu can nhap v� gi� tri c�c phan tu\n");
    printf("2. In ra gi� tri c�c phan tu dang quan l�\n");
    printf("3. In ra gi� tri lon nhat cua mang\n");
    printf("4. In ra c�c phan tu l� so nguy�n tu trong mang\n");
    printf("5. Th�m mot phan tu v�o trong mang\n");
    printf("6. X�a mot phan tu trong mang\n");
    printf("7. Sap xep mang theo thu tu tang dan\n");
    printf("8. T�m kiem phan tu v� in ra vi tr� index cua phan tu d�\n");
    printf("9. Tho�t\n");
    printf("Lua chon cua ban: ");
}

void inputArray() {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        printf("So phan tu qu� lon! Vui l�ng nhap lai.\n");
        size = 0;
        return;
    }
    for (i = 0; i < size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }
} 
 
void displayArray() {
    printf("C�c phan tu trong mang: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void findMax() {
    if (size == 0) {
        printf("Mang rong!\n");
        return;
    }
    int max = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
    }
    printf("Gi� tri lon nhat trong mang: %d\n", max);
}

void displayPrimes() {
    printf("C�c so nguy�n to trong mang: ");
    for (i = 0; i < size; i++) {
        if (isPrime(array[i])) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}
void addElement() {
    if (size >= MAX_SIZE) {
        printf("Mang d� day!\n");
        return;
    }
    printf("Nhap gia tri phan tu can them: ");
    scanf("%d", &array[size]);
    size++;
    printf("Them thanh cong!\n");
}
void deleteElement() {
    if (size == 0) {
        printf("Mang rong!\n");
        return;
    }
    int pos;
    printf("Nhap vi tri phan tu can xoa (0 - %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Vi tri kh�ng hop li!\n");
        return;
    }
    for (i = pos; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    printf("Xoa thanh cong!\n");
    
}
void sortArray() {
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Mang d� duoc sap xep!\n");
}


void searchElement() {
    if (size == 0) {
        printf("Mang rong!\n");
        return;
    }
    int value, found = 0;
    printf("Nhap gi� tri can t�m: ");
    scanf("%d", &value);
    printf("Vi tr� cua phan tu %d: ", value);
    for (i = 0; i < size; i++) {
        if (array[i] == value) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Kh�ng t�m thay\n");
    } else {
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: inputArray(); break;
            case 2: displayArray(); break;
            case 3: findMax(); break;
            case 4: displayPrimes(); break;
            case 5: addElement(); break;
            case 6: deleteElement(); break;
            case 7: sortArray(); break;
            case 8: searchElement(); break;
            case 9: printf("Tho�t chuong tr�nh.\n"); break;
            default: printf("Lua chon kh�ng hop li!\n");
        }
    } while (choice != 9);
    return 0;
}

















