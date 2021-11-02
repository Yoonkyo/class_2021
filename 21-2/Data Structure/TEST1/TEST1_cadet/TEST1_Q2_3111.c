
#include <stdio.h>
int main(){
	int value, max=0;
    int numArr[10];
	do {
		scanf("%d", &value);
		printf("%d ", value);
	} while (getc(stdin) == ' ');
 
	return 0;

    for(int i=0; i<sizeof(numArr)/sizeof(int); i++){
        if(max<numArr[i])
            max = numArr[i];
    }
    printf("%d", max);
}