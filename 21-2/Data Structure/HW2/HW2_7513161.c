#include <stdio.h>
#define SIZE 100010

int N=0, K=0;
char cmd[SIZE]; // 선택한 방향(명령)
int idx[SIZE], tmp[SIZE];
struct NODE{
    int x, y; // 식물 좌표
    struct NODE *A, *B, *C, *D; //4방향 연결
}leaf[SIZE];
struct NODE *frog;
 
int compDiff(int a, int b) {
    int diff_A = leaf[a].x - leaf[a].y;
    int diff_B = leaf[b].x - leaf[b].y;
    if (diff_A == diff_B) return leaf[a].x < leaf[b].x; //우측대각선상에 있을 때는 x좌표 비교
    return diff_A < diff_B; //같지 않으면 오름차순 정렬을 위한 값 리턴
}
 
int compSum(int a, int b) {
    int sum_A = leaf[a].x + leaf[a].y;
    int sum_B = leaf[b].x + leaf[b].y;
    if (sum_A == sum_B) return leaf[a].x < leaf[b].x;
    return sum_A < sum_B;
}//위와 같다
 
void mergesort(int start, int end, int (*comp)(int, int)) {
    if (start >= end)
        return;
    int i = start, k = start, mid = (start + end) / 2, j = mid + 1;
    mergesort(start, mid, comp);
    mergesort(mid + 1, end, comp);//정렬된 값을 두 부분으로0
    while ((i <= mid) && (j <= end)) {
        if (comp(idx[i], idx[j])) tmp[k++] = idx[i++]; //idx[]는 정렬전, tmp[]는 정렬 후를 의미
        else tmp[k++] = idx[j++];
    }
    while (i <= mid) tmp[k++] = idx[i++];
    while (j <= end) tmp[k++] = idx[j++]; //남은 것들 정렬 마무리
    for (i = start; i <= end; i++)
        idx[i] = tmp[i];//정렬 완료될때까지 반복될수 있도록 다시 idx에 옮김
} //합병정렬
 
void input() {
    scanf("%d %d", &N, &K);
    scanf("%s", cmd);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &leaf[i].x, &leaf[i].y);
        leaf[i].A = leaf[i].B = leaf[i].C = leaf[i].D = NULL;
    }//입력값
}
 
void connectLeaf() {
    // 인덱스만 정렬
    for (int i = 1; i <= N; i++) {
        idx[i] = i;
    }
 
    // A, D 연결
    mergesort(1, N, compDiff);
    for (int i = 1; i < N; i++) {
        struct NODE *cur = &leaf[idx[i]];
        struct NODE* next = &leaf[idx[i + 1]];
        // 같은 대각선상인 경우
        if ((cur->x - cur->y) == (next->x - next->y)) {
            cur->A = next;
            next->D = cur;
        }
    }// 차에 따른 오름차순 정렬
 
    // B, C 연결
    mergesort(1, N, compSum);
    for (int i = 1; i < N; i++) {
        struct NODE* cur = &leaf[idx[i]];
        struct NODE* next = &leaf[idx[i + 1]];
        // 같은 대각선상인 경우
        if ((cur->x + cur->y) == (next->x + next->y)) {
            cur->B = next;
            next->C = cur;
        }
    }//합에 따른 오름차순 정렬
}
 
void delNodeLink(struct NODE* p) {
    // 실제 leaf[]를 free하지 않고 연결만 조정
    if (p->A) p->A->D = p->D;
    if (p->D) p->D->A = p->A;
    if (p->B) p->B->C = p->C;
    if (p->C) p->C->B = p->B;
}
 
void jumpFrog() {
    frog = &leaf[1];
 
    for (int i = 0; i < K; i++) {
        if (cmd[i] == 'A') {
            if (frog->A) {
                delNodeLink(frog);
                frog = frog->A;
            }
        }
        else if (cmd[i] == 'B') {
            if (frog->B) {
                delNodeLink(frog);
                frog = frog->B;
            }
        }
        else if (cmd[i] == 'C') {
            if (frog->C) {
                delNodeLink(frog);
                frog = frog->C;
            }
        }
        else if (cmd[i] == 'D') {
            if (frog->D) {
                delNodeLink(frog);
                frog = frog->D;
            }
        }
    }
    printf("%d %d\n", frog->x, frog->y);
}
 
int main() {
    input();
    connectLeaf();
    jumpFrog();
}