#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}


void draw_line(int** pegs,int n, int i){

    int line_width = 2*n-1;

    int *size = malloc(sizeof(int)*3);

    if(pegs[0][i] != 0){
        size[0] = 2*pegs[0][i]-1;

    }
    if(pegs[1][i]!= 0){
        size[1] = 2*pegs[1][i]-1;
    }

    if(pegs[2][i]!= 0){
        size[2] = 2*pegs[2][i]-1;
    }

    // for cases where pegs[i][k] is 0, then size[1] is negative
    size[0] = max(size[0],0);
    size[1] = max(size[1],0);
    size[2] = max(size[2],0);
    

    for ( int k = 0; k < 3; k++){

        for (int j = 0; j< line_width/2-size[k]/2; j++){
            printf(" ");
        }

        if(size[k]==0){
            printf("|");
        }
        else{
            for (int j = line_width/2 -size[k]/2 ; j< line_width/2 +size[k]/2 +1; j++){
                printf("*");
            }
        }

        for ( int j= line_width/2 +size[k]/2 +1; j < line_width; j++){
            printf(" ");
        }

        printf("   ");

    }
    printf("\n");


}


void draw(int** pegs, int n){

    

    // first dim always 3
    for (int k = 1; k <= n; k++){
        draw_line(pegs,n,n-k);
    }

    printf("\n");

}

bool move(int** pegs, int n, int a,int b){
    // mvoe disks from a to b

    // search for topdisk
    int k = n-1;
    while(pegs[a][k] == 0 && k >=0){
        k--; 

    }

    int swap = pegs[a][k];
    pegs[a][k] = 0;

    // search for top of b
    k = n-1;

    while(pegs[b][k] == 0 && k>=0){
        k--;
    }

    if(k >= 0 && swap > pegs[b][k]){
        printf("ILLEGAL MOVE");
        printf("\n");
        return false;
    }

    pegs[b][k+1] = swap;

    return true;

}

// returns position of top disk on peg a
int top(int ** pegs, int n ,int a){

    int k = 0;

    while(k < n && pegs[a][k] != 0){
        k++;
    }

    k--;
    return k;
}

// where a is the starting peg and b the target peg , c is the storage peg , disks is from which disk on the upper disks should be moved
void solve(int ** pegs, int n, int a,int b,int c,int disks){

    // if its the top disk, simply move it to target
    if ( disks == top(pegs,n,a)){
        move(pegs,n,a,b);
        draw(pegs,n);
    }

    else {

        // must now from wich disks on to move later
        int t = top(pegs,n,c);
        // else move all upper disks to storage, 
        solve(pegs,  n,  a,c,  b, disks+1);

        // after that move the current disk to target
        move(pegs,n,a,b);
        draw(pegs,n);

        // then the disks on sotrage need to get moved on top of the current disk

        solve(pegs,n,c,b,a,t+1);
    }



}

int main(){

    // getting user input
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("You entered: %d", num);
    printf("\n");

    // init 2d arrray
    int** pegs = (int**)malloc(3*sizeof(int*));
    for ( int k = 0; k < 3 ; k++){
        pegs[k] = (int*)malloc(num*sizeof(int));
    }

    // populating first peg with all disks
    for ( int i = 0; i < 3; i++){

        for (int k= 1; k<= num ; k++){
            if ( i == 0){

                pegs[i][num-k] = k;

            }
            else{
                pegs[i][num-k] = 0;
            }
        }
    }

    // printf("%d",pegs[0][num-1]);
    draw(pegs,num);

    // move(pegs,num,0,2);

    // draw(pegs,num);

    // move(pegs,num,0,1);

    // draw(pegs,num);

    // move(pegs,num,2,1);

    // draw(pegs,num);

    // printf("%d",move(pegs,num,0,1));
    // printf("\n");

    // draw(pegs,num);
    solve(pegs,num,0,1,2,0);
    // draw(pegs,num);


    return 0;
}