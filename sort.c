#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void Display(int arr[MAX]) {
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int ary[MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (ary[i] > ary[j]) {
                int temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }
        }
    }
}

void insertion_sort(int ary[MAX], int n) {
    int i, j;
    int next;
    for (i = 1; i < n; i++) {
        next = ary[i];
        for (j = i - 1; j >= 0 && next < ary[j]; j--) {
            ary[j + 1] = ary[j];
        }
        ary[j + 1] = next;
    }
}

int Partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int low = left + 1;
    int high = right;
    printf("피벗: %d\n", pivot);
    while (low <= high) {
        while (pivot >= arr[low] && low <= right) {
            low++;
        }
        while (pivot <= arr[high] && high >= (left + 1)) {
            high--;
        }
        if (low <= high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    int temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;
    Display(arr);
    return high;
}

void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int q = Partition(arr, left, right);
        quick_sort(arr, left, q - 1);
        quick_sort(arr, q + 1, right);
    }
}

int main() {
    int arr[MAX] = { 5,8,3,1,10,15,2,9,12,18 };
    int temp1[MAX];
    int temp2[MAX];
    for (int i = 0; i < MAX; i++) {
        temp1[i] = arr[i];
        temp2[i] = arr[i];
    }
    printf("원래 리스트\n");
    Display(arr);
    printf("=======버블 정렬=======\n");
    bubble_sort(arr, MAX);
    Display(arr);
    printf("=======삽입 정렬=======\n");
    insertion_sort(temp1, MAX);
    Display(temp1);
    printf("=======퀵 정렬=======\n");
    quick_sort(temp2, 0, MAX - 1);
    printf("최종 배열\n");
    Display(temp2);
    return 0;
}
