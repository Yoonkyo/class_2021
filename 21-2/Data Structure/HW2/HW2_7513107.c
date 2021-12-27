#include <stdio.h>
int front, check[1024], tree[1024], L[11] = {0,1,3,7,15,31,63,127,255,511,1023};
int K;

void Tree(int layer){
    if (layer > K) return;
    if (layer == K - 1){
        tree[L[layer]] = check[front++];
        L[layer] = L[layer] + 1;
        return;
    }
    Tree(layer + 1);

    tree[L[layer]] = check[front++];
    L[layer] = L[layer] + 1;

    Tree(layer + 1);

    return;
}

int main(){
    scanf("%d", &K);

    for (int i = 0; i < L[K]; i++)
        scanf("%d", &check[i]);
    
    Tree(0);

    int t = 0, n = 1;
    for (int i = 0; i < K; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", tree[t]);
            t++;
        }
        n *= 2;
        printf("\n");
    }
    return 0;
}