#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int num;
typedef struct{
    int top;
    char s[100];
}stack;

void push(stack *s, char element){
    s->top++;
    s->s[s->top]=element;
}

char pop(stack *s){
    char temp =s->s[s->top];
    s->top--;
    return temp;
}

char peek(stack *s){
    return s->s[s->top];
}
int main(){
    stack s;
    stack operator;
    s.top=-1;
    char str[100];
    scanf("%s", str);
    for(int i=0; i<strlen(str); i++){
        char ch=str[i];
        switch(ch){
            case'+': case'-': case'*': case'/': case'(':
                push(&operator, ch);
                break;
            case')':
                while(1){
                    if(peek(&operator)!='('){
                        push(&s, pop(&operator));
                    }
                    else break;
                    
                }
            
            default:
                push(&s, ch);
                break;
                
        }
    }
    int len = strlen(str);
    while(1){
        if(peek(&s)=='(' || peek(&s)==')'){
            pop(&s);
            len-=1;
        }
        else{
        push(&s, pop(&operator));
        if(operator.top==-1) break;
        }
    }
    char arr[100];
    for(int i=0; i<len; i++){
        arr[i]=s.s[i];
    }
    printf("%s", arr);
    return 0;
}