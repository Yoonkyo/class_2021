#include <stdio.h>

int main()
{
    int n, a, b = 0;
    scanf_s("%d", &n);
    for (n; n > 0; n--)
    {
        scanf_s("%d", &a);
        b = b + a;
    }
    printf("%d", b);
    return 0;
}