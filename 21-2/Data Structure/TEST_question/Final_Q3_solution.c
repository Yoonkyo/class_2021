#include <stdio.h>
#include <stdlib.h>
 
struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};
struct Node* newNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;

    return node;
}
 
void inorder(struct Node* root){
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->key);
    inorder(root->left);
    inorder(root->right);
}
 
struct Node* constructBST(int postorder[], int start, int end){
    if(start>end){
        return NULL;
    }
    struct Node* node = newNode(postorder[end]);
    int i;
    for (i = end; i >=start; i--){
        if (postorder[i] < node->key) {
            break;
        }
    }
    node->right = constructBST(postorder, i + 1, end - 1);
    node->left = constructBST(postorder, start, i);
    return node;
}
 
int main(void){
    int postorder[10001],i=0,N;
    while(1){
        if(scanf("%d",&postorder[i])==EOF) break;
        i++;
    }
    N=i;

    struct Node* root = constructBST(postorder, 0, N - 1);
    inorder(root);
 
    return 0;
}