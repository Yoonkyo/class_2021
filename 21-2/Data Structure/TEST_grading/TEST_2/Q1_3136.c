#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct Stack{ //???? ?????? ????? ???? ???? 
    int top;
    char s[MAX_SIZE];
}Stack;

void push(Stack *s, char elem){
    s->top++;
    s->s[s->top] = elem;
}

char pop(Stack *s){
    char temp = s->s[s->top];
    s->top--;
    return temp;
}
int is_empty(Stack *s){
    if (s->top != -1)
        return 0;
    return 1;
}

char peek(Stack *s){
    return s->s[s->top];
}

int Operator_grade(char s){ // ???????? ?��?????? ????????? ???
    switch(s){
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
        default:
            return -1;
    }
}

void postfix(char *str){
    int i=0;
    Stack s;
    s.top = -1;
    for(i=0; i<strlen(str); i++){
        if(Operator_grade(str[i]) == -1){ //???????? ??? ???
            printf("%c", str[i]);
        }
        else if(str[i]=='('){
            push(&s, str[i]);
        }
        else if(str[i]==')'){
            while(peek(&s) != '('){
                printf("%c", pop(&s));
            }
            pop(&s);
        }
        else if (Operator_grade(str[i]) >=1 ){
            // ?????? ??????? ??? && ???? top?? ?��?????? ?? ????? pop
            while(!is_empty(&s) && isOperator(str[i]) <= isOperator(peek(&s))){
                printf("%c", pop(&s));
            }
            push(&s, str[i]);
        }
    }
    while(!is_empty(&s)){  //strlen?? ???? ????? ?????? ??????? ?????????? ???
        printf("%c", pop(&s));
    }
}

int main(void){
    char str[100];
    int i=0;
    scanf("%s", str);
    postfix(str);
}