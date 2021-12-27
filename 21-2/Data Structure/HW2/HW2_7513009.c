#include <stdio.h>

int map[51][51];
int visited[51][51];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={-1,-1,0,1,1,1,0,-1};

void reset(int *, int);

int search(int y, int x){
    if(map[y][x]==0 || visited[y][x]==1)
        return 0;
    visited[y][x]=1;
    for(int i=0; i<8; i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(map[yy][xx]==1 && visited[yy][xx]==0)
            search(yy,xx);
    }
    
    return 1;
}

int main(){

    while(1){
        int num=0;
        int w, h;
        reset(map, sizeof(map)/4);
        reset(visited, sizeof(visited)/4);
        scanf("%d%d", &w, &h);
        if(w==0 || h==0) return 0;
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                scanf("%d", &map[i][j]);
            }
        }
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                num += search(i,j);
            }
        }
        printf("%d\n", num);
        
    }
    
    return 0;    
}

void reset(int *arr, int size){
    for(int i=0; i<size; i++)
        arr[i]=0;
}