//로또 : 빠톰펀

#include <stdio.h>
int K;  // K integers specify the number of members of set S. 
int S[14]; //입력하는 set   (6 < K < 13)
int S2[6]; //출력하는 set   (we have to select 6 numbers from set S)
void DFS(int Start,int Depth)  //DFS is "Depth First Search","깊이 우선 탐색"
                               //find all possibilities of set S2 (DFS를 이용하여 출력시켰다) 
{
    int i;
    if (Depth == 6)   //from the problem, we have to select 6 numbers from set S and put them into S2,
                      //so if number of members of S2 is equal to 6, print it
    {
        for (i = 0; i < 6; i++) 
        {
            printf("%d ", S2[i]); //print all members of set S2
        }
        printf("\n"); //make new line for every possibilities of set S2.
    }
    else  //if number of members of S2 is not equal to 6 yet, find the rest of it
    {
        for (i = Start; i < K; i++)   //from DFS(0, 0); -> Start=0=i,
                                      //and Depth=0(0 is not equal to 6 so the programe will run on "else" part until Depth=6)
                                      //repeat it until i<K(number of members of set S)
        {
            S2[Depth] = S[i]; //save the member of set S to set S2
            DFS(i + 1, Depth + 1); //back to use function DFS to find next member of set S2  (이때 사전 순으로 저장한다.)
        }
        
    }
}
 
int main()
{
    int i;
    
    while (1) //we will continue input set S and find the possible set of S2 until we input 0.
              //so we can find many test cases
    {
        scanf("%d", &K);  //The first integer on the line will be the number of K
        if (K == 0)     
            break;  //Input will be terminated by a value of zero (0) for K.
        for (i = 0; i < K; i++)
            scanf("%d", &S[i]);  //input the members of set S, until the number of members of set S is equal to K. 

        DFS(0, 0); //back to use DFS function to find all possibilities of set S2
                   //by Start=0 and Depth=0
        printf("\n"); //print 1 blank line between each test case
    }
}   

