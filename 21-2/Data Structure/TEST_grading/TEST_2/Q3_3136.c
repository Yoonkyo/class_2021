#include <stdio.h>

int paper[129][129]={0};
int white=0, blue=0;

int count(int x_s, int x_f, int y_s, int y_f);
int main(void)
{
    int i, j, size;

    scanf("%d", &size);
    
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
            scanf(" %d", &paper[i][j]);
        
    }
    count(0, size, 0, size);
    
    printf("%d\n%d", white, blue);

    return 0;

}
int count(int x_s, int x_f, int y_s, int y_f)
{
    int i, j, check=0;

//  printf("x_s=%d  x_f=%d  y_s=%d  y_f=%d \n", x_s, x_f, y_s, y_f);


    for(i=y_s; i<y_f; i++)
    {
        for(j=x_s; j<x_f; j++)
        {
            if(paper[i][j]!=paper[y_s][x_s])
            {
                check=1;
                break;
            }
        }
        if(check==1)
            break;
    }
    
    if(check==0)
    {
        if (paper[y_s][x_s]==0)
            white++;
        else
            blue++;
        return 0;
    }
    else
    {
        count(x_s, (x_s+x_f)/2, y_s, (y_s+y_f)/2); //왼쪽 위에
        count((x_s+x_f)/2, x_f, y_s, (y_s+y_f)/2); //오른쪽 위에
        count(x_s, (x_s+x_f)/2, (y_s+y_f)/2, y_f); //왼쪽 아래
        count((x_s+x_f)/2, x_f, (y_s+y_f)/2, y_f); //오른쪽 아래
    }
}