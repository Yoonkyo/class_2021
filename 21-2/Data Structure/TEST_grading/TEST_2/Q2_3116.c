#include <stdio.h>
#define size 100
int queue[size];
int top = -1;
void push(int x)
{
    queue[++top] = x;
}
int pop()
{
    int temp = queue[0];
    for (int i = 0; i < top; i++)
    {
        queue[i] = queue[i + 1];
    }
    top--;
    return temp;
}

int main()
{
    int n;
    scanf_s("%d",&n);
    for (int i=0; i<n; i++){
        push(i+1);
    }
    while (1){
        pop();
        pop();
        push(pop());
        if (top==0){
            break;
        }
    }
    printf("%d",queue[0]);
    return 0;
}