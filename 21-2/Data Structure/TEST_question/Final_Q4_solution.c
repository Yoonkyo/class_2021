#include <stdio.h>
#include <stdbool.h>
int ax[8]={1,1,1,-1,-1,-1,0,0};
int ay[8]={1,0,-1,1,0,-1,1,-1};
void BFS(int h,int w,int i,int j,bool map[][52],bool BFS_V[][52]){
    if(i<0||j<0||i>h-1||j>w-1||map[i][j]==0||BFS_V[i][j]==1)//섬을 체크하는 조건에 만족하지 않는 좌표면 return
        return;
    BFS_V[i][j]=1;//방문한 섬임을 표시
    for(int k=0;k<8;k++)//섬을 체크하는 조건에 만족하면 다음 8개의 좌표를 BFS함수에 넣어 이어진 섬 조사
        BFS(h,w,i+ay[k],j+ax[k],map,BFS_V);
    return;
}
int main(void){
    int w,h,temp;
    while(1){
        bool map[52][52]={0,};//용량 감소를 위해 bool타입으로 섬의 지도인 map과 섬을 왔다갔음을 표시하는 BFS_V함수를 생성 및 초기화
        bool BFS_V[52][52]={0,};
        int result=0;
        scanf("%d %d",&w,&h);
        if(w==0&&h==0)
            break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                scanf("%d",&temp);
                map[i][j]=(temp==1?1:0);
            }
        }

        //BFS
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j]==1&&BFS_V[i][j]==0){//모든 좌표를 조사하여 방문하지 않은 섬을 BFS 함수에 넣어 조사
                    BFS(h,w,i,j,map,BFS_V);
                    printf("%d %d\n", i, j);
                    result++;//방문한 섬과 이어진 모든 섬을 조사하고 섬의개수증가
                }
            }
        }
        printf("%d\n",result);// 모든 좌표 조사가 끝나면 섬의 개수 출력
    }
    return 0;
}