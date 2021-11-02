#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){;
	int i, max = 0, n = 0;
	int a[10];
	char s1[1000];

	scanf("%[^\n]s", s1);
	char *ptr = strtok(s1, " ");	 //첫번째 strtok 사용.
	while (ptr != NULL)              //ptr이 NULL일때까지 (= strtok 함수가 NULL을 반환할때까지)
	{
		a[n] = atoi(ptr);	 //문자열을 int로 변환		
		ptr = strtok(NULL, " "); //자른 문자 다음부터 구분자 또 찾기
		n++;
	}

	i = 0;
	while (i<n){
		if (a[i] > max){
			max = a[i];
		}
		i++;
	}
	printf("%d", max);
}
