#include <stdio.h>
#define Max_Size 100

int main()
{
    int case_num, size, index;
    scanf("%d", &case_num);
    for (int  i = 0; i < case_num; i++)
    {
        int count=1, queue[Max_Size]={0,}, front=0, max=0;
        scanf("%d %d", &size, &index);
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &queue[j]);
        }
        while (1)
        {
            for(int j=0; j < size; j++)
            {
                if(max<queue[j])
                    max=queue[j];
            }
            while(queue[front]!=max)
                front=(front+1)%size;
            if(front==index)
                break;
            count++;
            queue[front]=0;
            front=(front+1)%size;
            max=0;
        }
        printf("%d\n", count);
    }
    return 0;
}
