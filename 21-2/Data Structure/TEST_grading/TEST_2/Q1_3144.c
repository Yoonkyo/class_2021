#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char arr[201],stack[201];
    int top=-1;
    scanf("%s",arr);
    for(int i=0;i<strlen(arr);i++){
        if(isalpha(arr[i]))
            printf("%c",arr[i]);
        else{
            switch(arr[i]){
                case'(':
                    stack[++top]=arr[i];
                    break;
                case'*':
                case'/':
                    while(top!=-1&&(stack[top]=='*'||stack[top]=='/')){
                        printf("%c",stack[top--]);
                    }
                    stack[++top]=arr[i];
                    break;
                case'+':
                case'-':
                    while(top!=-1&&(stack[top]!='(')){
                        printf("%c",stack[top--]);
                    }
                    stack[++top]=arr[i];
                    break;
                case')':
                    while(top!=-1&&stack[top]!='('){
                        printf("%c",stack[top--]);
                    }
                    top--;
                    break;
                    
            }
        }
    }
    while(top!=-1){
        printf("%c",stack[top--]);
    }
    return 0;
}