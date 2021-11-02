#include <stdio.h>
#include <string.h>

int main(void){
    char L[600000],R[300010],temp;//커서를 오른쪽과 왼쪽에 옮김에 따라 활용할 스택 L,R 선언
    int left,right,N;
    scanf("%s",L);
    left=strlen(L),right=300000;//L,R의 시작 포인터
    scanf("%d",&N);
    while(N--){
        scanf("\n%c",&temp);
        if(temp=='L'&&left!=0){//L이 입력되고 L의 포인터가 0이 아니면
            R[right--]=L[--left];//L의 포인터 문자를 R의 포인터 왼쪽 자리에 입력하고 L의 포인터 감소
            L[left]='\0'; 
        }
        else if(temp=='D'&&right!=300000){//D가 입력되고 R의 포인터가 시작포인터가 아니면
            L[left++]=R[++right];//R의 포인터 오른쪽 문자를 L의 포인터 위치에 입력
            R[right]='\0';
        }
        else if(temp=='B'&&left!=0){//B가 입력되고 L의 포인터가 0이 아니면
            L[--left]='\0';//L의 포인터 왼쪽 공백으로
        }
        else if(temp=='P'){
            scanf("\n%c",&temp);
            L[left++]=temp;//P가 입력되면 문자를 입력받고 L의 현 포인터에 저장
        }
    }
    printf("%s%s",L,&R[right+1]);//문자열 L과R을 이어 출력 R의 현재 포인터는 공백이므로 오른쪽부터 출력

}