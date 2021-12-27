//상근이의 여행_빠톰펀
//상근이가 가장 적은 종류의 비행기를 타고 모든 국가들을 여행할 수 있도록 도와주자.

#include <stdio.h>

int main(){
    int caseNum, n, m, array[10000][2];  
    
    scanf("%d", &caseNum); //테스트 케이스의 수 입력한다.
    for(int i = 0; i < caseNum; i++){
        scanf("\n%d %d", &n, &m);  //각 테스트 케이스의 국가의 수(n)과 비행기의 종류(m)을 입력한다.
        for(int j = 0; j < m; j++){
            scanf("\n%d %d", &array[m][0], &array[m][1]);
        } //M개의 줄에 a와 b 쌍들이 입력된다. a와 b를 왕복하는 비행기가 있다는 것을 의미한다.
        printf("%d\n", n-1); //비행 스케줄이 항상 연결 그래프를 이룬다고 했고 n개의 국가를 지나야한다면 n-1개의 비행기를 타는 것이 최소이기 때문이다.
    }

    return 0;
}