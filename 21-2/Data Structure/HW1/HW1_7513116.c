//피보나치 수
#include <stdio.h>
int F(int n)    //정수를 반환하는 함수 F를 생성
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;    //매개변수가 0, 1일때 값 지정
    return F(n - 1) + F(n - 2);    //재귀함수를 이용
}
int main()
{
    int n;
    scanf_s("%d", &n);
    printf("%d", F(n));
    return 0;
}