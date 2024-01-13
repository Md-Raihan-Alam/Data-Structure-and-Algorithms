#include <iostream>

using namespace std;

class Node {
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;

    Node(int key) : lchild(nullptr), data(key), height(1), rchild(nullptr) {}
};

int MAX(int a, int b) {
    return (a > b) ? a : b;
}

int NodeHeight(Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(Node *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

Node *LLRotation(Node *p) {
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    return pl;
}

Node *LRRotation(Node *p) {
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    return plr;
}

Node *RRRotation(Node *p) {
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    return pr;
}

Node *RLRotation(Node *p) {
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
    return prl;
}

Node *minValueNode(Node *node) {
    Node *current = node;
    while (current->lchild != nullptr)
        current = current->lchild;
    return current;
}

Node *deleteNode(Node *root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->lchild = deleteNode(root->lchild, key);
    else if (key > root->data)
        root->rchild = deleteNode(root->rchild, key);
    else {
        if (root->lchild == nullptr || root->rchild == nullptr) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node *temp = minValueNode(root->rchild);
            root->data = temp->data;
            root->rchild = deleteNode(root->rchild, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + MAX(NodeHeight(root->lchild), NodeHeight(root->rchild));

    int balance = BalanceFactor(root);

    if (balance > 1 && BalanceFactor(root->lchild) >= 0)
        return LLRotation(root);

    if (balance > 1 && BalanceFactor(root->lchild) < 0) {
        root->lchild = RRRotation(root->lchild);
        return LLRotation(root);
    }

    if (balance < -1 && BalanceFactor(root->rchild) <= 0)
        return RRRotation(root);

    if (balance < -1 && BalanceFactor(root->rchild) > 0) {
        root->rchild = LLRotation(root->rchild);
        return RRRotation(root);
    }

    return root;
}

Node *RInsert(Node *p, int key) {
    if (p == nullptr)
        return new Node(key);

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

int main() {
    Node *root = nullptr;

    root = RInsert(root, 9);
    root = RInsert(root, 5);
    root = RInsert(root, 10);
    root = RInsert(root, 0);
    root = RInsert(root, 6);
    root = RInsert(root, 11);
    root = RInsert(root, -1);
    root = RInsert(root, 1);
    root = RInsert(root, 2);

    cout << "Preorder traversal of the constructed AVL tree is" << endl;
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after deletion of 10" << endl;
    preOrder(root);

    return 0;
}
