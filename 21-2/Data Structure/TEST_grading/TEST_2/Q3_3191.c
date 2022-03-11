#include<stdio.h>
int A[2000][2000];
int number1=0,number0=0;
void solve(int y, int x, int size)
{
    int check;
    check = A[y][x]; 
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (check == 0 && A[i][j] == 1) 
            {
                check = 2;
            }
            else if (check == 1 && A[i][j] == 0) 
            {
                check = 2;
            }
            if (check == 2) 
            { 
                solve(y, x, size / 2);
                solve(y, x + size / 2, size / 2);
                solve(y + size / 2, x, size / 2);
                solve(y + size / 2, x + size / 2, size / 2);
                return;
            }
        }
    }
    if (check == 0) 
        number0++;
    else 
        number1++;
}
int main(){
    int i,size,j;
    scanf("%d",&size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%d",&A[i][j]); 
        }
        printf("\n");
    }
    solve(0,0,size); 
    printf("%d",number0);
    printf("%d",number1); 
    return 0;
}