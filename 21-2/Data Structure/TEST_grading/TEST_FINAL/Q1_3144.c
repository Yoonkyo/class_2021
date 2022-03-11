#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    char ch;
    struct node* next;
    struct node* prev;
}node;
node* HEAD;
node* TAIL;
node* cur;

void init(){
    node *a=(node*)malloc(sizeof(node));
    node *b=(node*)malloc(sizeof(node));
    a->next=b;
    a->prev=NULL;
    b->prev=a;
    b->next=NULL;
    HEAD=a,TAIL=b;
    cur=TAIL;
}
void insertnode(char ch){
    node* p=(node*)malloc(sizeof(node));
    p->ch=ch;

    p->next=cur;
    p->prev=cur->prev;
    cur->prev->next=p;
    cur->prev=p;
}
void delete(){
    node* del=cur->prev;
    if(del==HEAD) return;
    del->prev->next=cur;
    cur->prev=del->prev;
    free(del);
}
void curleft(){
    if(cur->prev->prev==NULL) return;
    cur=cur->prev;
}
void curright(){
    if(cur->next==NULL) return;
    cur=cur->next;
}
void print(){
    node* head=HEAD;
    head=head->next;
    while(1){
        if(head->next==NULL) break;
        printf("%c",head->ch);
        head=head->next;
        free(head->prev);
    }
}
int main(void){
    int T;
    scanf("%d",&T);
    while(T--){
        char S[1000001]={'\0',};
        scanf("%s",S);
        int i,len=strlen(S);
        init();
        for(i=0;i<len;i++){
            switch(S[i]){
                case'<':
                    curleft();
                    break;
                case'>':
                    curright();
                    break;
                case'-':
                    delete();
                    break;
                case'!':
                    init();
                    break;
                default:
                    insertnode(S[i]);
                    break;
            }
        }
        print();
        printf("\n");
    }

}