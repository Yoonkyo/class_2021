/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int paper[200][200];
int white=0, blue=0, n=0;  //white?뒗 0 blue?뒗 1

void divide(int x, int y, int n){
    int number;
    number = paper[x][y];
    for (int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if (number == 0 && paper[i][j]==1){
                number = 2;
            }
            else if (number == 1 && paper[i][j]==0){
                number = 2;
            }
            if (number ==2){
                divide(x, y, n/2);
                divide(x, y+ n/2, n/2);
                divide(x+ n/2, y, n/2);
                divide(x+ n/2, y+ n/2, n/2);
                return;
            }
        }
    }
    if (number==0){
        white++;
    }
    else if (number==1){
        blue++;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &paper[i][j]);
        }
    }
    divide(0, 0, n);
    printf("%d\n", white);
    printf("%d", blue);
    return 0;
}