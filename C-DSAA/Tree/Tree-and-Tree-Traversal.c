#include<stdio.h>
#include<stdlib.h>
struct Node {
    int item;
    struct Node * left;
    struct Node * right;
};

// Inorder traversal
void inorderTraversal(struct Node *root)
{
    if(root==NULL)
        return ;
    inorderTraversal(root->left);
    printf("%d ->",root->item);
    inorderTraversal(root->right);
}
// Preorder Traversal
void preorderTraversal(struct Node* root)
{
    if(root==NULL)
        return ;
    printf("%d ->",root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
// Postorder Traversal
void postOrderTraversal(struct Node* root)
{
    if(root==NULL)
        return ;
    postOrderTraversal(root->left);
    postOrderTraversal(root->left);
    printf("%d ->",root->item);
}

// Create a new node
struct Node* createNode(int value)
{
    struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->item=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
// Insert on the right of the node
struct Node* insertLeft(struct Node* root, int val)
{
    root->left=createNode(val);
    return root->left;
}
// Insert on the left of the node
struct Node* insertRight(struct Node* root, int val)
{
    root->right=createNode(val);
    return root->right;
}
int main()
{
    struct Node* root=createNode(1);
    insertLeft(root,12);
    insertRight(root,9);
    insertLeft(root->left,5);
    insertRight(root->left,6);
    printf("Inorder traversal \n");
    inorderTraversal(root);
    printf("\nPreorder traversal \n");
    preorderTraversal(root);
    printf("\nPostorder traversal \n");
    postOrderTraversal(root);
    return 0;
}