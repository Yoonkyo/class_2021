#include <stdio.h>
#include <stdio.h>
int paper[150][150];
int C_0 = 0, C_1 = 0;
void count(int y, int x, int n)
{
    int check = paper[y][x];
    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (check != paper[i][j])
            {   
                count(y, x, n / 2);
                count(y, x + n / 2, n / 2);
                count(y + n / 2, x, n / 2);
                count(y + n / 2, x + n / 2, n / 2);
                return;
            }
        }
    }
    if (check == 0)
        C_0++;
    else
        C_1++;
}
int main()
{
    int n;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf_s("%d", &paper[i][j]);
        }
    }
    count(0, 0, n);
    printf("%d\n%d", C_0, C_1);
    return 0;
}