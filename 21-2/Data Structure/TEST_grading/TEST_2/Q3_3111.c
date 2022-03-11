#include <stdio.h>

int paper[128][128], zero=0, one=0;

void papercomp(int y, int x, int size){

    int head = paper[y][x], flag=0;

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(paper[y+i][x+j]!=head){
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag!=1){
        if(head==1)
            one++;
        else 
            zero++;
        return;
    }
    else{
        int half=size/2;
        papercomp(y, x, half);
        papercomp(y, x+half, half);
        papercomp(y+half, x, half);
        papercomp(y+half, x+half, half);
        return;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &paper[i][j]);
        }
    }

    papercomp(0, 0, n);
    printf("%d\n%d", zero, one);

    return 0;
}
