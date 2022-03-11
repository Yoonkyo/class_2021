#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* next;
    struct node* prev;
}node;

node* HEAD;
node* TAIL;
node* cur;

void init(){
    node* a=(node*)malloc(sizeof(node));
    node* b=(node*)malloc(sizeof(node));
    a->next=b;
    a->prev=NULL;
    b->next=NULL;
    b->prev=a;
    HEAD=a, TAIL=b;
    cur=TAIL;
}
void newnode(char a){
    node* new=(node*)malloc(sizeof(node));
    new->data=a;
    new->next=cur;
    new->prev=cur->prev;
    cur->prev->next=new;
    cur->prev=new;
}
void delete(){
    node* tmp=cur->prev;
    if(tmp==HEAD) return;
    tmp->prev->next=cur;
    cur->prev=tmp->prev;
    free(tmp);
}
void left(){
    if(cur->prev->prev==NULL) return;
    cur=cur->prev;
}
void right(){
    if(cur->next==NULL) return;
    cur=cur->next;
}
void print(){
    node* head=HEAD;
    head=head->next;
    while(1){
        if(head->next==NULL) break;
        printf("%c", head->data);
        head=head->next;
        free(head->prev);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char arr[1000001]={'\0',};
        scanf("%s", arr);
        int i, len=strlen(arr);
        init();
        for(i=0; i<len; i++){
            switch(arr[i]){
                case'>':
                    right();
                    break;
                case'<':
                    left();
                    break;
                case'-':
                    delete();
                    break;
                case'!':
                    init();
                    break;
                default:
                    newnode(arr[i]);
                    break;
            }
        }
        print();
        printf("\n");
    }
    
}