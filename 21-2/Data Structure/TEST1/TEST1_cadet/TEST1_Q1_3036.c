#include <stdio.h>

int main()
{
	int n;
	
	printf("");
	
	scanf("%d",&n);      
	
	int a[n];            
	
	
	int i = 0;

	for(i=0 ; i <n ; i++)
	{
		scanf("%d", &a[i]);
	}
	int sum = 0;    

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)    
    {
        sum += a[i];    
    }

    printf("%d\n", sum);    

    return 0;
}