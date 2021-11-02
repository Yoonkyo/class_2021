#include <stdio.h>
#include <string.h>
#include <ctype.h>//문자숫자 판별 헤더

int main(void){
    int T,left,check,right;
    scanf("%d",&T);
    while(T--){
        char S[1000001]={0},L[1000001]={0},R[1000001]={0};//입력받은 문자열, '>'와'<'기준 L과R 배열로 스택처리
        scanf("%s",S);
        check=strlen(S);
        left=-1,right=1000000;//스택의 초기 포인터 
        for(int i=0;i<check;i++){//입력받은 문자열 하나씩 판별
            if(S[i]=='-'&&left!=-1){//'-'라면 L에서 문자 하나 지우기
                L[left]='\0';
                left--;
            }
            else if(S[i]=='<'&&left!=-1){//'<'라면 L의 가장 오른쪽 문자를 R의 가장 왼쪽으로 옮기기 
                R[--right]=L[left];
                L[left--]='\0';
            }
            else if(S[i]=='>'&&right!=1000000){//'>'라면 R의 가장 왼쪽 문자를 L의 가장 오른쪽으로 옮기기
                L[++left]=R[right++];
                R[right-1]='\0';
            }
            else if(isalpha(S[i])||isdigit(S[i])){//문자나 숫자라면 문자열에 추가
                L[++left]=S[i];
            }
        }
        printf("%s%s\n",L,&R[right]);//L과 R에 저장된 문자열 이어붙이기
    }
    return 0;
}