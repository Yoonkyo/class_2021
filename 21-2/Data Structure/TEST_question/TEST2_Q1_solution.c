#include <stdio.h> // printf 함수를 사용하기 위해
#include <string.h> //strlen 함수를 쓰기 위한 헤더파일

// 연산자 문자를 저장하는 스택의 크기
#define MAX_STACK_COUNT 16

// 스택에 문자를 추가하는 함수
void Push(char a_stack[], char *ap_count, char a_op)
{
    if (*ap_count < MAX_STACK_COUNT)
    { // 스택 초과인지 체크
        // *ap_count 위치에 문자 추가
        a_stack[*ap_count] = a_op;
        // 스택에 저장된 문자의 개수를 증가 시킨다.
        (*ap_count)++;
    }
}
// 스택에서 문자를 한 개 꺼내는 함수
char Pop(char a_stack[], char *ap_count)
{
    if (*ap_count > 0)
    {                  // 스택에 문자가 남아있는지 체크
        (*ap_count)--; // 저장된 문자의 숫자를 1줄인다.
        // *ap_count 위치의 문자 반환
        return a_stack[*ap_count];
    }

    return 0; // 스택이 비어 있는 경우!
}
// 스택에서 문자를 꺼내지 않고 참고만 하는 함수
char Peek(char a_stack[], char a_count)
{
    // 남아 있는 문자가 있다면 문자를 반환한다.
    if (a_count > 0)
        return a_stack[a_count - 1];
    return 0; // 스택이 비어 있는 경우!
}
int main()
{
    char p_exp[100];
    scanf("%s", p_exp);
    
    // 스택으로 사용할 변수와 스택에 저장된 문자의 개수를 저장할 변수
    char stack[MAX_STACK_COUNT], count = 0;

    // 문자의 길이만큼 반복
    for(int i=0; i<strlen(p_exp); i++)
    {
        // 영문자면 바로 출력한다.
        if (p_exp[i] >= 'A' && p_exp[i] <= 'Z')
            printf("%c", p_exp[i]);
        else
        {
            // 현재 문자가 '*' 또는 '/'인 경우!
            if (p_exp[i] == '*' || p_exp[i] == '/')
            {
                // 같은 등급의 우선 순위를 가진 연산자의 경우 이전 연산자를 먼저
                // 처리한다. 그리고 이제는 같은 등급의 연산자가 두 개 연속으로 들어
                // 있을수 없기 때문에 반복문으로 처리할 필요가 없다.
                if (Peek(stack, count) == '*' || Peek(stack, count) == '/')
                {
                    printf("%c", Pop(stack, &count));
                }
            }
            else
            {
                // 우선 순위가 낮은 +, -가 나오면 스택에 있는 모든 문자를 다 꺼내야 한다.
                // 왜냐하면 등급 높은 연산자는 무조건 꺼내야하고 같은 등급도
                // 먼저 나온것부터 처리해야하기 때문이다.
                while (count)
                    printf("%c", Pop(stack, &count));
            }
            Push(stack, &count, p_exp[i]); // 현재 연산자를 추가한다.
        }
    }
    // 스택에 문자가 남아 있다면 모두 꺼내서 출력한다.
    while (count)
        printf("%c", Pop(stack, &count));
    printf("\n"); // 줄바꿈을 한다.
    return 0;
}