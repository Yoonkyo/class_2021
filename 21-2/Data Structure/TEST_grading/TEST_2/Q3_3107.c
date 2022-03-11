#include <stdio.h>
int n;
int paper[2] = { 0, };
char map[129][129] = { 0, };

int check(int ltr, int ltc, int rbr, int rbc) {
	int cnt[2] = { 0, };
	for (int i = ltr; i <= rbr; i++) {
		for (int j = ltc; j <= rbc; j++) {
			cnt[map[i][j] - '0']++;
			if (cnt[0] > 0 && cnt[1] > 0)
				return 1;
		}
	}
	if (cnt[0] > 0)
		paper[0]++;
	else
		paper[1]++;
	return 0;
}

void divide(int ltr, int ltc, int rbr, int rbc) {
	int offset = (rbr - ltr + 1) / 2;
	if (offset == 1) {
		for (int i = ltr; i <= rbr; i++) {
			for (int j = ltc; j <= rbc; j++) {
				paper[map[i][j] - '0']++;
			}
		}
	}
	else {
		if (check(ltr, ltc, ltr + offset -1, ltc + offset-1))
			divide(ltr, ltc, ltr + offset -1, ltc + offset-1);
		if (check(ltr, ltc + offset, ltr + offset -1 , rbc))
			divide(ltr, ltc + offset, ltr + offset -1, rbc);
		if (check(ltr + offset, ltc, rbr, ltc + offset-1))
			divide(ltr + offset, ltc, rbr, ltc + offset-1);
		if (check(ltr + offset, ltc + offset, rbr, rbc))
			divide(ltr + offset, ltc + offset, rbr, rbc);
	}
}

int main(void) {
	int cnt[2] = { 0, };
	char trash;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &map[i][j]);
			cnt[map[i][j] - '0']++;
		}
	}
	if (cnt[0] > 0 && cnt[1] > 0) {
		divide(1, 1, n, n);
		printf("%d\n%d\n", paper[0], paper[1]);
	}
	else {
		if (cnt[0] > 0)
			paper[0] = 1;
		else
			paper[1] = 1;
		printf("%d\n%d\n", paper[0], paper[1]);
	}
	return 0;
}