#include "tree2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapfy(int* arr, int index, int len){
    if (len == 1) return;
    int min;
    if (arr[index*2-1] <= arr[index*2]){
        if (index*2-1 <= len-1)
            min = index*2 - 1;
        else
            min = index - 1;
    }
    else{
        if (index*2 <= len-1)
            min = index*2;
        else
            min = index*2 - 1;
    }
    if (arr[min] < arr[index-1]) 
        swap(&arr[min], &arr[index-1]);
    for (int i = index+1; i <= len; i++){
        if (i*2 > len || i*2+1 > len) 
            break;
        heapfy(arr, i, len);
    }
}

void heapsort(int* arr, int len){
    for (int i = len; i >= 2; i--){
        swap(&arr[0], &arr[i-1]);
        heapfy(arr, 1, i-1);
    }
}

int main(int argc, char* argv[]){
    int len = atoi(argv[1]);
	int* arr = malloc(sizeof(int) * len);
    fputs("\ninitial: ", stdout);
    //int arr[] = {85, 83, 77, 15, 50};
    //int len = sizeof(arr) / sizeof(arr[0]);
    srand(time(0));
    for (int i = 0; i < len; i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    fputs("\nbuild complete binary tree:\n\n", stdout);
    printTree(arr, len);

    for (int i = len/2; i >= 1; i--){
        heapfy(arr, i, len);
    }
    printf("\n-\nheapfy:\n");
    printTree(arr, len);

    printf("\n-\nheapsort:\n");
    heapsort(arr, len);
    putchar('\n');
    printTree(arr, len);
}

