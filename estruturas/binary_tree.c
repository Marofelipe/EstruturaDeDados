#include<stdio.h>
#include<stdlib.h>
#define Item int
#define key(node) (node->dado)

typedef struct No {
    Item dado;
    struct no *left, *right;  
}no;

no* init();
no* compare(no* root, no* node);
no* search(no* root, Item dado);
void insert(no* root, Item dado);
no* remove(no* root, Item dado);

void main(){ 
    no* root = init();
};

no* init() {
    no *root = malloc(sizeof(no));
    root->left = NULL;
    root->right = NULL;
    root->dado = NULL;
    return root;
}
no* compare(no* root, no* node){
    return key(root) >= key(node)? node: root;
}

no* search(no* root, Item dado) {
    if(root == NULL) return NULL;
    if(root->dado == dado) return root;
    no* left = search(root->left, dado);
    return left == NULL? search(root->right, dado): left;
    
}
void insert(no* root, Item dado) {
    
}
no* remove(no* root, Item dado) {
    return root; 
}