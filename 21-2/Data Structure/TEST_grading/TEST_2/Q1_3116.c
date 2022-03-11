#include <stdio.h>
#include <string.h>
char *primary[] = {"(", "+-", "/*"};
int primarySet(char ch)
{
    for (int i = 0; i < 3; i++)
        if (strchr(primary[i], ch))
            return i;
}
int main()
{
    int o = 0;
    char input[100], op[100];
    gets(input);
    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
            printf("%c", input[i]);
        else if (input[i] == ')')
        {
            while (op[--o] != '(')
                printf("%c", op[o]);
            op[o] = 0;
        }
        else if (input[i] == '(')
        {
            op[o++] = input[i];
            op[o] = 0;
        }
        else
        {
        retry:
            if (op[o - 1] != '(' && o > 0)
            {
                if (primarySet(input[i]) > primarySet(op[o - 1]))
                {
                    op[o++] = input[i];
                    op[o] = 0;
                }
                else
                {
                    printf("%c", op[--o]);
                    op[o] = 0;
                    goto retry;
                }
                continue;
            }
            op[o++] = input[i];
            op[o] = 0;
        }
    }
    if (o)
        while (o--)
            printf("%c", op[o]);
    return 0;
}
