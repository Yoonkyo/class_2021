#include <stdio.h>

int Graph[1001][1001]={0}; //그래프 배열 만들기
int DFSvisit[1001]={0};     //DFS 배열 만들기 여기서 DFS는  최대한 깊게 탐색 >>인접배열로 표현
int BFSvisit[1001]={0};     //BFS 배열 만들기 여기서 BFS는 최대한 넓게 탐색 >>인접배열로 표현
int queue[1001];    //큐 배열 만들기

void BFS(int v, int N){ //BFS 함수 생성 
    int front=0,rear=0,Pop,i; //큐를 사용할 예정
    
    printf("%d ",v); //시작 정점 출력
    queue[0]=v; //시작정점을 큐에 저장
    rear++; //큐 한칸 늘리기
    BFSvisit[v]=1; //정점 v의 방문표시
    
    while(front<rear){ //큐가 비어 있지 않을 때>>front=rear 때 까지 반복
        Pop=queue[front]; //큐에 저장된 정점 선택
        front++; //dequeue 기능을 하게 함
        
        for(i=1;i<=N;i++){ //인접 정점 탐색
            if(Graph[Pop][i]==1 && BFSvisit[i]==0){ //미방문 정점 탐색
                printf("%d ",i);
                queue[rear]=i; //정점을 큐에 삽입
                rear++;
                BFSvisit[i]=1; //방문 표시
            }
        }
    }
    return;
}
int main(){
    int N,M,Start; //변수 선언 >> 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 start
    int i,x,y; //변수 선언 x,y >> 간선이 연결하는 두 정점의 번호
    
    scanf("%d %d %d",&N,&M,&Start); //입력값 >> 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 start
    for(i=0;i<M;i++){   //간선의 개수 만틈 반복
        scanf("%d %d",&x,&y); //입력값 >> x,y 간선이 연결하는 두 정점의 번호
        Graph[x][y]=1;
        Graph[y][x]=1;
    }
    BFS(Start,N); //BFS 함수에 Start 값과 N 값 대입
    return 0;
}