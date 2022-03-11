#include <stdio.h>
#include <stdlib.h>

int result[100001]={0};

struct node{
    int y;
    struct node *next;
};

struct node *data[100001];

void push_node(int x,int y){

    struct node *p1;
    p1=malloc(sizeof(struct node));
    p1->y=y;
    p1->next=data[x];
    data[x]=p1;
    struct node *p2;
    p2=malloc(sizeof(struct node));
    p2->y=x;
    p2->next=data[y];
    data[y]=p2;
    return;
    
}

void dfs(int x){            

    for(struct node *p = data[x]; p!= NULL; p= p-> next){

        int y = p -> y;
        if(result[y] == 0){
            result[y] = x;
            dfs(y);
        }
        else 
        continue;
    }
}

int main(void){

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        push_node(x,y);
    }
    
    dfs(1);
    
    for(int i=2; i<=n; i++)
    printf("%d\n", result[i]);
    
    return 0;
}