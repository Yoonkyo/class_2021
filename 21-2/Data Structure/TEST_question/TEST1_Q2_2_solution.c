
#include <stdio.h>
int main(){
	int value, n=0, max=0;
	int numArr[10];
	do {
		scanf("%d", &value);
		numArr[n] = value;
		n++;
	} while (getc(stdin) == ' ');

	for(int i=0; i<n; i++){
		if (max<numArr[i]) max = numArr[i];
	}
	printf("%d", max);
}
