#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void heapify(int* A, int size, int d, int index){

    int k = index; 
    int max_index = k;
    int max_val = A[k];

    while(max_index < size){

        // max_val = A[k];
        for ( int j = 1; j<= d && k*d + j< size; j++){
            if ( A[k*d+j]> max_val){
                max_index = k*d+j;
                max_val = A[max_index];

            }
        }

        // now swap if indices are equal

        if(max_index != k){

            int swap = A[k];
            A[k] = A[max_index];
            A[max_index] = swap;

            k = max_index;
            max_val = swap;


        } else {
            return;
        }

    }
}

// pre: array A is not empty and d>0
void buildMaxHeap(int* A, int size ,int d){
    
    for ( int k = floor(size/d); k >= 0; k--){
        heapify(A,size,d,k);

    }

}
// post: A is a max heap in array form

void  heapSort(int* A , int size, int d ){

    buildMaxHeap(A,size,d);

    for ( int k = size-1; k >=0 ; k--){

        int swap = A[0];
        A[0] = A[k];
        A[k] = swap;

        heapify(A,k,d,0);

    }

    

}

void printArray(int * A, int size){


    for ( int k = 0; k < size; k++){
        printf("%d",A[k]);
        printf("%s",",");
    }
    printf("%s","\n");
}

void printHeap(int* A, int size ,int d){


    // height of teh d-ary tree
    int height = ceil(log(size*(d-1)+1)/(log(d)));

    // we know that we fill up the children of A up 
    printf("%s","g{");
    printf("%s","\n");

    for( int k = 0; k <= height; k++){

        for ( int j = 1;  k*d + j < size && j <= d; j++){

            printf("%s","(");
            printf("%d",A[k]);
            printf("%s","-");
            printf("%d",A[k*d+j]);
            printf("%s",")");
        }
        printf("%s","\n");
    }

    printf("%s","}");

}

int main() {

    int a[] = {6, 4, 3, 9, 5, 10, 15, 19, 11, 7, 8, 13};
    int *A = a; // pointer to the first element of A
    int size_A = sizeof(a)/sizeof(a[0]);

    int h[] = {19, 15, 11, 13, 5, 10, 4, 3, 6, 7, 8, 9};
    int * H = h;
    int size_H = sizeof(h)/sizeof(h[0]);

    int d = 3;

    printArray(A,size_A);

    buildMaxHeap(A,size_A,d);


    printArray(A,size_H);

    printHeap(A,size_A,d);

    heapSort(A,size_A,d);

    printArray(A,size_A);

    


    int b[] = {-2,5,0,1,30,3,1};
    A = b; // pointer to the first element of A
    size_A = sizeof(b)/sizeof(b[0]);

    
    d = 2;

    printArray(A,size_A);

    buildMaxHeap(A,size_A,d);


    printArray(A,size_A);

    printHeap(A,size_A,d);

    heapSort(A,size_A,d);

    printArray(A,size_A);


    return 0;
}