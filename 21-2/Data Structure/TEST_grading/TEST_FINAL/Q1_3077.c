#include <stdio.h>
#include <string.h>
int N;
int len, maxL, maxR;
char  temp[1000010], Ar[1000010];

void input();
void push(char d);

int main() {
	scanf("%d\n", &N);
	input();

	return 0; 
}

void input() {
	int i, j;
	
	for (i = 1; i <= N; ++i) {
		maxL = 1, maxR = 1000000;
		gets(temp);
		//puts(temp);
		len = strlen(temp);
		for (j = 0; j < len; ++j) {
			push(temp[j]);
		}
		for (j = 1; j < maxL; ++j) printf("%c", Ar[j]);
		for (j = maxR + 1; j <= 1000000; ++j) printf("%c", Ar[j]);
		printf("\n");
	}
}

void push(char d) {
	if (d == '<') {
		if (maxL != 1) Ar[maxR--] = Ar[--maxL];
	}
	else if (d == '>') {
		if (maxR != 1000000) Ar[maxL++] = Ar[++maxR];
	}
	else if (d == '-') {
		if (maxL != 1) maxL--;
	}
    else if (d == '!') {
        while(maxR!=1000000)
            Ar[maxL++] = Ar[++maxR];
        maxL=1;


	}
	else Ar[maxL++] = d;
}