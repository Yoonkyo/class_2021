#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d", &num);
    for (int k = 0; k < num; k++)
    {
        char arr[1001];
        char Q_1[1001];
        char Q_2[1001];
        int top_1 = -1;
        int top_2 = -1;
        scanf("%s", arr);
        int n = strlen(arr);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == '<')
            {
                if (top_1 != -1)
                {
                    Q_2[top_2 + 1] = Q_1[top_1];
                    top_1--;
                    top_2++;
                }
            }
            else if (arr[i] == '>')
            {
                if (top_2 != -1)
                {
                    Q_1[top_1 + 1] = Q_2[top_2];
                    top_2--;
                    top_1++;
                }
            }

            else if (arr[i] == '-')
            {
                if (top_1 != -1)
                {
                    top_1--;
                }
            }

            else if (arr[i] == '!')
            {
                top_1 = -1;
                top_2 = -1;
            }

            else
            {
                Q_1[top_1 + 1] = arr[i];
                top_1++;
            }
        }
        if (top_1 != -1)
        {
            for (int j = 0; j < top_1 + 1; j++)
            {
                printf("%c", Q_1[j]);
            }
        }

        if (top_2 != -1)
        {
            for (int j = 0; j < top_1 + 1; j++)
            {
                printf("%c", Q_2[j]);
            }
        }
        printf("\n");
    }
    return 0;
}