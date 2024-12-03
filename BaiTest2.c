#include <stdio.h>
#include <stdlib.h>

void nhapMang(int arr[][100], int *rows, int *cols) {
    printf("Nh?p s? hàng: ");
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
    printf("Các ph?n t? n?m trên du?ng biên:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", arr[i][j]);
                product *= arr[i][j];
            }
        }
    }
    printf("\nTích các ph?n t? du?ng biên: %d\n", product);
}

void duongCheoChinh(int arr[][100], int rows, int cols) {
    printf("Các ph?n t? n?m trên du?ng chéo chính:\n");
    for (i = 0; i < rows && i < cols; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void duongCheoPhu(int arr[][100], int rows, int cols) {
    printf("Các ph?n t? n?m trên du?ng chéo ph?:\n");
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

    printf("Ðu?ng chéo chính sau khi s?p x?p tang d?n:\n");
    duongCheoChinh(arr, rows, cols);
}

void timKiem(int arr[][100], int rows, int cols) {
    int x, found = 0;
    printf("Nh?p giá tr? c?n tìm: ");
    scanf("%d", &x);

    printf("V? trí c?a %d trong m?ng:\n", x);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == x) {
                printf("arr[%d][%d]\n", i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Không tìm th?y giá tr? %d trong m?ng.\n", x);
    }
}

int main() {
    int arr[100][100], rows, cols;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nh?p kích c? và giá tr? các ph?n t? c?a m?ng\n");
        printf("2. In giá tr? các ph?n t? c?a m?ng theo ma tr?n\n");
        printf("3. In ra các ph?n t? n?m trên du?ng biên và tính tích\n");
        printf("4. In ra các ph?n t? n?m trên du?ng chéo chính\n");
        printf("5. In ra các ph?n t? n?m trên du?ng chéo ph?\n");
        printf("6. S?p x?p du?ng chéo chính theo th? t? tang d?n\n");
        printf("7. Tìm ki?m m?t ph?n t? và in ra v? trí c?a ph?n t? dó trong m?ng\n");
        printf("8. Thoát\n");
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
                printf("Chuong trình k?t thúc. T?m bi?t!\n");
                break;
            default:
                printf("L?a ch?n không h?p l?. Vui lòng ch?n l?i.\n");
        }
    } while (choice != 8);

    return 0;
}
