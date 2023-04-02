#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// with 2 pivots
void printArray(int * A, int size){

    for ( int k = 0; k < size; k++){
        printf("%d",A[k]);
        printf("%s",",");
    }
    printf("%s","\n");
}

void swap(int * A, int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void partitioning(int A[], int low, int high, int *p1, int *p2) {
    int l = low+1;
    int c = low+1;
    int r = high;

    while(c < r) {
        if (A[c] < A[low]) {
            swap(A, l++, c++);
        }
        else if (A[c] >= A[high]) {
            swap(A, c, --r);
        }
        else {
            c++;
        }
    }
    swap(A, low, l-1);
    swap(A, high, c);
    *p1 = l-1;
    *p2 = c;
}

void quicksort(int A[], int low, int high) {
    if (high - low <= 0) {
        return;
    }
    if (A[low] > A[high]) {
        swap(A, low, high);
    }
    int p1, p2;
    partitioning(A, low, high, &p1, &p2);
    quicksort(A, low, p1-1 );
    quicksort(A, p1+1, p2-1 );
    quicksort(A, p2+1 , high);
}




int main(){

    int a[] = {10, 7, 3, 15, 6, 2, 5, 1, 17, 8};

    int size_a = sizeof(a)/ sizeof(a[0]);

    int *A  = a;

    int b[] = {1,2,3,5,6,7,8,10,15,17};

    int size_b = sizeof(b)/sizeof(b[0]);

    int * B = b;

    quicksort(A,0,size_a-1);

    printArray(A,size_a);


    return 0;
}

