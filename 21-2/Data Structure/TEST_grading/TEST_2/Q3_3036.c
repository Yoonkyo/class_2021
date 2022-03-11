#include<stdio.h>
int paper[128][128]; 
int white=0,blue=0;
void solve(int y, int x, int size)
{
    int check;
    check = paper[y][x]; 
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (check == 0 && paper[i][j] == 1) 

            {
                check = 2; 
            }
            else if (check == 1 && paper[i][j] == 0) 
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
        white++;
    else 
        blue++;
}
int main(){
    int i,size,j;
    scanf("%d",&size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%d",&paper[i][j]); 
        }

    }
    solve(0,0,size); 
    printf("%d\n",white);
    printf("%d",blue); 
    return 0;
}