#include <stdio.h>
#include <stdlib.h>

void nhapMang(int arr[][100], int *rows, int *cols) {
    printf("Nh?p s? h�ng: ");
    scanf("%d", rows);
    printf("Nh?p s? c?t: ");
    scanf("%d", cols);
    int i,j;
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            printf("Nh?p ph?n t? arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
    int i,j;
void inMang(int arr[][100], int rows, int cols) {
    printf("Ma tr?n:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void duongBien(int arr[][100], int rows, int cols) {
    int product = 1;
    printf("C�c ph?n t? n?m tr�n du?ng bi�n:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", arr[i][j]);
                product *= arr[i][j];
            }
        }
    }
    printf("\nT�ch c�c ph?n t? du?ng bi�n: %d\n", product);
}

void duongCheoChinh(int arr[][100], int rows, int cols) {
    printf("C�c ph?n t? n?m tr�n du?ng ch�o ch�nh:\n");
    for (i = 0; i < rows && i < cols; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void duongCheoPhu(int arr[][100], int rows, int cols) {
    printf("C�c ph?n t? n?m tr�n du?ng ch�o ph?:\n");
    for (i = 0; i < rows && i < cols; i++) {
        printf("%d ", arr[i][cols - 1 - i]);
    }
    printf("\n");
}

void sapXepDuongCheoChinh(int arr[][100], int rows, int cols) {
    int n = (rows < cols) ? rows : cols;
    int temp[100], index = 0;

    for (i = 0; i < n; i++) {
        temp[index++] = arr[i][i];
    }

    for ( i = 0; i < index - 1; i++) {
        for (j = i + 1; j < index; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    index = 0;
    for ( i = 0; i < n; i++) {
        arr[i][i] = temp[index++];
    }

    printf("�u?ng ch�o ch�nh sau khi s?p x?p tang d?n:\n");
    duongCheoChinh(arr, rows, cols);
}

void timKiem(int arr[][100], int rows, int cols) {
    int x, found = 0;
    printf("Nh?p gi� tr? c?n t�m: ");
    scanf("%d", &x);

    printf("V? tr� c?a %d trong m?ng:\n", x);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == x) {
                printf("arr[%d][%d]\n", i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Kh�ng t�m th?y gi� tr? %d trong m?ng.\n", x);
    }
}

int main() {
    int arr[100][100], rows, cols;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nh?p k�ch c? v� gi� tr? c�c ph?n t? c?a m?ng\n");
        printf("2. In gi� tr? c�c ph?n t? c?a m?ng theo ma tr?n\n");
        printf("3. In ra c�c ph?n t? n?m tr�n du?ng bi�n v� t�nh t�ch\n");
        printf("4. In ra c�c ph?n t? n?m tr�n du?ng ch�o ch�nh\n");
        printf("5. In ra c�c ph?n t? n?m tr�n du?ng ch�o ph?\n");
        printf("6. S?p x?p du?ng ch�o ch�nh theo th? t? tang d?n\n");
        printf("7. T�m ki?m m?t ph?n t? v� in ra v? tr� c?a ph?n t? d� trong m?ng\n");
        printf("8. Tho�t\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &rows, &cols);
                break;
            case 2:
                inMang(arr, rows, cols);
                break;
            case 3:
                duongBien(arr, rows, cols);
                break;
            case 4:
                duongCheoChinh(arr, rows, cols);
                break;
            case 5:
                duongCheoPhu(arr, rows, cols);
                break;
            case 6:
                sapXepDuongCheoChinh(arr, rows, cols);
                break;
            case 7:
                timKiem(arr, rows, cols);
                break;
            case 8:
                printf("Chuong tr�nh k?t th�c. T?m bi?t!\n");
                break;
            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng ch?n l?i.\n");
        }
    } while (choice != 8);

    return 0;
}
