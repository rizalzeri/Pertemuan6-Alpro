// Nama: Rizal Zeri Subakti
// NIM: 24060120130062
// Lab: C2

#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i;
    int j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void counting_sort(int arr[], int n) {
    int max = arr[0];
    int i, j;

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];
    int sortedArr[n];

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        sortedArr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }
}

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void cetak_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("============= PROGRAM SORTING ==============\n");
    printf("Masukkan Panjang array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Masukkan arraynya: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray yang belum terurut: ");
    cetak_array(arr, n);

    char option;
    printf("Pilih sort yang digunakan (A, B, C, D): ");
    scanf(" %c", &option);

    printf("Sorting yang digunakan adalah ");
    switch (option) {
        case 'A':
            printf("Bubble Sort\n");
            bubble_sort(arr, n);
            break;
        case 'B':
            printf("Counting Sort\n");
            counting_sort(arr, n);
            break;
        case 'C':
            printf("Insertion Sort\n");
            insertion_sort(arr, n);
            break;
        case 'D':
            printf("Selection Sort\n");
            selection_sort(arr, n);
            break;
        default:
            printf("Opsi tidak valid\n");
            return 0;
    }

    printf("\nArray yang sudah terurut: ");
    cetak_array(arr, n);

    printf("\nProgram selesai\n");
    return 0;
}
