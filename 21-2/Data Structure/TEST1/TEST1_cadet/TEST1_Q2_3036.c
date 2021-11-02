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
	int max, t;
	max = 0; 

	for (t = 0; t < n; t++)
	{
		if (a[t] > max) max = a[t]; 
	}

	printf("%d\n", max);

	return 0;
}