#include <stdio.h>

int paper[129][129];
int zeros=0;
int ones=0;
void solve(int y, int x, int size){
    int check=paper[y][x];
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(check==0 && paper[i][j]==1){
                check=2;
            }
            else if(check==1 && paper[i][j]==0){
                check=2;
            }
            if(check==2){
                solve(y, x, size/2);
                solve(y, x+size/2, size/2);
                solve(y+size/2,x,size/2);
                solve(y+size/2, x+size/2, size/2);
                return;
            }
        }
    }
    if(check==0) zeros++;
    else ones++;
}

int main(){
    int size;
    scanf("%d", &size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d", &paper[i][j]);
        }
    }
    solve(0,0,size);
    printf("%d\n", zeros);
    printf("%d", ones);
    return 0;
}