#include <stdio.h>
#include <string.h> //strlen 함수를 쓰기 위한 헤더파일입니다

int main(){
    int T;  //데이터를 T번 받아서 각각에 대해 판단하는 문제입니다
    char PS[50];  //문자열의 길이는 50 이하
    scanf("%d", &T); //T값 입력받기

    for(int i=0; i<T; i++){  //T번 실행하는 반복문
        scanf("%s", PS);  //T번 각각에 대한 문자열을 입력받습니다
        int count=0;  //count의 값을 0으로 초기화합니다

        for(int j=0; j<strlen(PS); j++){  //strlen 함수로 문자열의 길이를 재고, 그 길이만큼 반복
            if (PS[j]=='(')  
                count++;
            else if (PS[j]==')')
                count--;  //반복문이 끝나고 count의 값이 0이면 YES
            if (count<0)
                break;  //count의 값이 0이라도, 예를 들어 "))(("은 NO라고 판별해야 합니다
        }
        if (count==0)
            printf("YES\n");
        else    
            printf("NO\n"); //count 값에 따라 YES, NO를 출력
    }
    return 0;
}