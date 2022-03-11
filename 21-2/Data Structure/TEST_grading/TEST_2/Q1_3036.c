#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_STACK_SIZE 100
 
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;
 
void init(StackType *s) {
    s->top = -1;
}
 
int is_empty(StackType *s) {
    return (s->top == -1);
}
 
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}
 
StackType *s;
 
void push(StackType *s, element item) {
    if (is_full(s)) {
        printf("full \n");
        return;
    }
    else    s->stack[++(s->top)] = item;
 
}
 
element pop(StackType *s) {
    if (is_empty(s)) {
        printf("blank \n");
        exit(1);
    }
    else   return s->stack[(s->top)--];
 
}
 
 
element peek(StackType *s) {
    if (is_empty(s)) {
        printf("blank \n");
        exit(1);
    }
    else    return s->stack[s->top];
 
}
 
int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}
 

void infix_to_postfix(char exp[], char cexp[]) {
    int i = 0;
    int j = 0;
    char ch, ch2, top_op;
    int len = (int)strlen(exp);
 
    StackType s;
    init(&s);
 
    for (i = 0; i < len; i++) {
        ch = exp[i];
        ch2 = exp[i + 1]; 
        switch (ch) {
            
        case '+': case '-': case '*': case '/':
            
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                cexp[j++] = pop(&s);
                cexp[j++] = ' ';
            }
            push(&s, ch);
            break;
 
            
        case '(':           
            push(&s, ch);
            break;
        case ')':           
            top_op = pop(&s);
 
            while (top_op != '(') {          
                cexp[j++] = top_op;
                cexp[j++] = ' ';
 
                top_op = pop(&s);
 
 
            }
            break;
 
 
 
            
        default:
            cexp[j++] = ch; 
            if (ch2 != '+' && ch2 != '-' && ch2 != '*' && ch2 != '/' && ch2 != ' ' && ch2 != '\0' &&
                ch2 != '(' && ch2 != ')')
            {
                cexp[j++] = ch2; 
                i++; 
            }
            cexp[j++] = ' ';
 
            break;
        }
    }
 
    while (!is_empty(&s)) {
        cexp[j++] = pop(&s);
        cexp[j] = 0;
 
    }
}
 
void main() {
 
    int result = 0;
 
    char a[100];
    char b[100];
    
 
    scanf("%s", a);
    infix_to_postfix(a, b);
    printf("%s", b);
 
 
}