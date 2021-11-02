#include <stdio.h>

int N, Arr[64][64];                         //처음 입력받는 정수 N과 이차원 배열 설정
void quadtree(int y,int x,int k,int m){
    int f=1;
    char num=Arr[y][x];                     //문자열로 이차원 배열의 좌표를 지정
    for(int i=y;i<y+k&&f;i++){              
        for(int j=x;j<x+k&&f;j++){          
            if(num != Arr[i][j]){           //이차원 배열 중 num과 일치하지 않는 값이 있을시 for문 종료
                f=0;
            }
        }
    }
    if(f){                                  //f=1인 경우로(num과 모두 일치) for 문이 끝나면 num값 출력
        printf("%d",num);
    }
    else{                                   //일치하지 않을 경우 ( 출력 후 4개의 섹터로 나누고, k를 반으로 나눈 뒤 다시 quadtree 반복(재귀)
        printf("(");
        quadtree(y,x,k/2,0);
        quadtree(y,x+k/2,k/2,0);
        quadtree(y+k/2,x,k/2,0);
        quadtree(y+k/2,x+k/2,k/2,1);
    }
    if(m){                                  // m값(1)으로 쿼드트리가 마무리될 시 ) 출력
        printf(")");
    }
}

int main(){
    scanf("%d",&N);                         // 처음 입력받는 값인 정수를 N에 저장
    for(int i=0;i<N;i++){           
        for(int j=0;j<N;j++){
        scanf("%1d",&Arr[i][j]);            // 입력받는 문자열을 따로따로 이차원 배열에 저장
        }
    }
    quadtree(0,0,N,0);                      //quadtree 함수에서 Arr[0][0], k=8, m=1로 quadtree 시작
    return 0;
}