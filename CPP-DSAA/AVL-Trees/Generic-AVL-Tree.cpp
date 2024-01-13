#include <iostream>
#include <cstdlib>

template <typename T>
class AVLTree {
private:
    template <typename U>
    struct Node {
        Node *lchild;
        U data;
        int height;
        Node *rchild;

        Node(U key) : lchild(nullptr), data(key), height(1), rchild(nullptr) {}
    };

    Node<T> *root;

    int MAX(int a, int b) {
        return (a > b) ? a : b;
    }

    int NodeHeight(Node<T> *p) {
        int hl = p && p->lchild ? p->lchild->height : 0;
        int hr = p && p->rchild ? p->rchild->height : 0;
        return hl > hr ? hl + 1 : hr + 1;
    }

    int BalanceFactor(Node<T> *p) {
        int hl = p && p->lchild ? p->lchild->height : 0;
        int hr = p && p->rchild ? p->rchild->height : 0;
        return hl - hr;
    }

    Node<T> *LLRotation(Node<T> *p) {
        Node<T> *pl = p->lchild;
        Node<T> *plr = pl->rchild;
        pl->rchild = p;
        p->lchild = plr;
        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);
        return pl;
    }

    Node<T> *LRRotation(Node<T> *p) {
        Node<T> *pl = p->lchild;
        Node<T> *plr = pl->rchild;
        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;
        plr->lchild = pl;
        plr->rchild = p;
        pl->height = NodeHeight(pl);
        p->height = NodeHeight(p);
        plr->height = NodeHeight(plr);
        return plr;
    }

    Node<T> *RRRotation(Node<T> *p) {
        Node<T> *pr = p->rchild;
        Node<T> *prl = pr->lchild;
        pr->lchild = p;
        p->rchild = prl;
        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);
        return pr;
    }

    Node<T> *RLRotation(Node<T> *p) {
        Node<T> *pr = p->rchild;
        Node<T> *prl = pr->lchild;
        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;
        prl->rchild = pr;
        prl->lchild = p;
        pr->height = NodeHeight(pr);
        p->height = NodeHeight(p);
        prl->height = NodeHeight(prl);
        return prl;
    }

    Node<T> *minValueNode(Node<T> *node) {
        Node<T> *current = node;
        while (current->lchild != nullptr)
            current = current->lchild;
        return current;
    }

    Node<T> *deleteNode(Node<T> *root, T key) {
        if (root == nullptr)
            return root;

        if (key < root->data)
            root->lchild = deleteNode(root->lchild, key);
        else if (key > root->data)
            root->rchild = deleteNode(root->rchild, key);
        else {
            if (root->lchild == nullptr || root->rchild == nullptr) {
                Node<T> *temp = root->lchild ? root->lchild : root->rchild;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node<T> *temp = minValueNode(root->rchild);
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

    Node<T> *RInsert(Node<T> *p, T key) {
        if (p == nullptr)
            return new Node<T>(key);

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

    void preOrder(Node<T> *root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preOrder(root->lchild);
            preOrder(root->rchild);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(T key) {
        root = RInsert(root, key);
    }

    void remove(T key) {
        root = deleteNode(root, key);
    }

    void printPreOrder() {
        std::cout << "Preorder traversal of the AVL tree is" << std::endl;
        preOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree<float> avlTree;

    avlTree.insert(9.5);
    avlTree.insert(5.3);
    avlTree.insert(10.7);
    avlTree.insert(0.8);
    avlTree.insert(6.2);
    avlTree.insert(11.1);
    avlTree.insert(-1.9);
    avlTree.insert(1.4);
    avlTree.insert(2.0);

    avlTree.printPreOrder();

    avlTree.remove(10.7);

    avlTree.printPreOrder();

    return 0;
}
