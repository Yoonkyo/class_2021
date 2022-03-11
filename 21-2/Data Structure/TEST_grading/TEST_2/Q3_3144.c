#include <stdio.h>

int board[130][130];
int zc=0,oc=0;
void check(int x,int y,int n){
    int o=0;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(board[i][j]==1) o++;
        }
    }
    if(o==0) zc++;
    else if(o==(n*n)) oc++;
    else{
        check(x,y,n/2);
        check(x,y+n/2,n/2);
        check(x+n/2,y,n/2);
        check(x+n/2,y+n/2,n/2);
    }
    return;
}
int main(void){
    int N,i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            scanf("%d",&board[i][j]);
    }
    check(0,0,N);
    printf("%d\n%d",zc,oc);
    return 0;
}