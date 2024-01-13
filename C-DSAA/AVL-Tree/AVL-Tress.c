#include<stdio.h>
#include<stdlib.h>
int MAX(int a, int b) {
    return (a > b) ? a : b;
}
struct Node 
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;
int NodeHeight(struct Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}
struct Node * LLRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
        root=pl;
    return pl;
}
struct Node * LRRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=p->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    if(root==p)
        root=plr;
    return plr;
}
struct Node * RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root == p)
        root = pr;

    return pr;
}

struct Node * RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;

    return prl;
}

struct Node* minValueNode(struct Node* node) 
{ 
    struct Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->lchild != NULL) 
        current = current->lchild; 
  
    return current; 
} 

struct Node* deleteNode(struct Node* root, int key) 
{ 
    // STEP 1: PERFORM STANDARD BST DELETE 
  
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( key < root->data ) 
        root->lchild = deleteNode(root->lchild, key); 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( key > root->data ) 
        root->rchild = deleteNode(root->rchild, key); 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->lchild == NULL) || (root->rchild == NULL) ) 
        { 
            struct Node *temp = root->lchild ? root->lchild : 
                                             root->rchild; 
  
            // No child case 
            if(temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            struct Node* temp = minValueNode(root->rchild); 
  
            // Copy the inorder successor's data to this node 
            root->data = temp->data; 
  
            // Delete the inorder successor 
            root->rchild = deleteNode(root->rchild, temp->data); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + MAX(NodeHeight(root->lchild), 
                           NodeHeight(root->rchild)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = BalanceFactor(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && BalanceFactor(root->lchild) >= 0) 
        return LLRotation(root); 
  
    // Left Right Case 
    if (balance > 1 && BalanceFactor(root->lchild) < 0) 
    { 
        root->lchild =  RRRotation(root->lchild); 
        return LLRotation(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && BalanceFactor(root->rchild) <= 0) 
        return RRRotation(root); 
  
    // Right Left Case 
    if (balance < -1 && BalanceFactor(root->rchild) > 0) 
    { 
        root->rchild = LLRotation(root->rchild); 
        return RRRotation(root); 
    } 
  
    return root; 
} 

struct Node *RInsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->height=1;
        t->lchild=NULL;
        t->rchild=NULL;
        t->data=key;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }else if(key>p->data)
    {
        p->rchild=RInsert(p->lchild,key);
    }
    p->height=NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    return p;
}
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->data); 
        preOrder(root->lchild); 
        preOrder(root->rchild); 
    } 
} 

int main() 
{ 
    struct Node *root = NULL; 
  
    /* Constructing tree given in the above figure */
    root = RInsert(root, 9); 
    root = RInsert(root, 5); 
    root = RInsert(root, 10); 
    root = RInsert(root, 0); 
    root = RInsert(root, 6); 
    root = RInsert(root, 11); 
    root = RInsert(root, -1); 
    root = RInsert(root, 1); 
    root = RInsert(root, 2); 
  
    printf("Preorder traversal of the constructed AVL"
           " tree is \n"); 
    preOrder(root); 
  
    root = deleteNode(root, 10); 
  
    printf("\nPreorder traversal after deletion of 10 \n"); 
    preOrder(root); 
  
    return 0; 
} 
