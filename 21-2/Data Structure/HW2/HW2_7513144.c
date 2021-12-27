#include <stdio.h>
#include <stdbool.h>
int ax[8]={1,1,1,-1,-1,-1,0,0};
int ay[8]={1,0,-1,1,0,-1,1,-1};
void BFS(int h,int w,int i,int j,bool map[][52],bool BFS_V[][52]){
    if(i<0||j<0||i>h-1||j>w-1||map[i][j]==0||BFS_V[i][j]==1)//���� üũ�ϴ� ���ǿ� �������� �ʴ� ��ǥ�� return
        return;
    BFS_V[i][j]=1;//�湮�� ������ ǥ��
    for(int k=0;k<8;k++)//���� üũ�ϴ� ���ǿ� �����ϸ� ���� 8���� ��ǥ�� BFS�Լ��� �־� �̾��� �� ����
        BFS(h,w,i+ay[k],j+ax[k],map,BFS_V);
    return;
}
int main(void){
    int w,h,temp;
    while(1){
        bool map[52][52]={0,};//�뷮 ���Ҹ� ���� boolŸ������ ���� ������ map�� ���� �Դٰ����� ǥ���ϴ� BFS_V�Լ��� ���� �� �ʱ�ȭ
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
                if(map[i][j]==1&&BFS_V[i][j]==0){//��� ��ǥ�� �����Ͽ� �湮���� ���� ���� BFS �Լ��� �־� ����
                    BFS(h,w,i,j,map,BFS_V);
                    result++;//�湮�� ���� �̾��� ��� ���� �����ϰ� ���ǰ�������
                }
            }
        }
        printf("%d\n",result);// ��� ��ǥ ���簡 ������ ���� ���� ���
    }
    return 0;
}