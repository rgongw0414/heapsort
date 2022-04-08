#include "../tree2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapfy(int* arr, int index, int len){
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
    for (int i = 1; i <= len; i++){
        swap(&arr[0], &arr[len]);
        len--;
        heapfy(arr, (len+1)/2, len);
    }
}

int main(int argc, char* argv[]){
    //int len = atoi(argv[1]);
	//int* arr = malloc(sizeof(int) * len);
    int arr[] = {85, 83, 77, 15, 50};
    int len = sizeof(arr) / sizeof(arr[0]);
    srand(time(0));
    for (int i = 0; i < len; i++){
        //arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    putchar('\n');
    printTree(arr, len);

    for (int i = len/2; i >= 1; i--){
        heapfy(arr, i, len);
    }
    printf("\n-\nheapfy:\n");
    printTree(arr, len);

    printf("\n-\nafter heapsort:\n");
    heapsort(arr, len);
    putchar('\n');
    printTree(arr, len);
}

