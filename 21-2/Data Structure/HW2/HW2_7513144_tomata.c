#include <stdio.h>
#include <stdbool.h>
typedef struct{
    int z,y,x;
}xyz;
xyz queue[1000001];
int tom[101][101][101];
int dx[7] = { -1,0,1,0,0,0 };
int dy[7] = { 0,1,0,-1,0,0 };
int dh[7] = { 0,0,0,0,1,-1 };
int cnt=0,front=0,rear=0,day=0;
int N,H,M,i,j,k;
bool check(){
    for(i=0;i<H;i++){
        for(j=0;j<N;j++){
            for(k=0;k<M;k++){
                if(tom[i][j][k]==0)
                    return 0;
            }
        }
    }
    return 1;
}
void DFS(){
    int before=cnt;
    int tx,ty,tz;
    if(check()){
        printf("%d",day);
        return;
    }
    day++;
    int temp=rear-front;
    while(temp--){
        tx=queue[front].x,ty=queue[front].y,tz=queue[front].z;
        front++;
        for(int i=0;i<6;i++){
            int nx=tx+dx[i];
            int ny=ty+dy[i];
            int nz=tz+dh[i];
            if((nx>=0&&nx<M)&&(ny>=0&&ny<N)&&(nz>=0&&nz<H)){
                if(tom[nz][ny][nx]==0){
                    tom[nz][ny][nx]=1;
                    cnt++;
                    queue[rear].x=nx;
                    queue[rear].y=ny;
                    queue[rear].z=nz;
                    rear++;
                }
            }
        }
    }
    if(cnt==before){
        printf("-1");
        return;
    }
    DFS();
}

int main(void){
    scanf("%d %d %d",&M,&N,&H);
    for(i=0;i<H;i++){
        for(j=0;j<N;j++){
            for(k=0;k<M;k++){
                scanf("%d",&tom[i][j][k]);//i높이 j세로 k 가로
                if(tom[i][j][k]==1){
                    queue[rear].z=i,queue[rear].y=j,queue[rear].x=k;
                    rear++;
                    cnt++;
                }
            }
        }
    }
    DFS();
    return 0;
}