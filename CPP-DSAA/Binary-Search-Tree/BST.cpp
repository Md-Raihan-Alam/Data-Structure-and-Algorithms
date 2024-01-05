#include<iostream>

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BinarySearchTree {
private:
    Node* root;

    Node* RInsert(Node* p, int key) {
        Node* t = nullptr;
        if (p == nullptr) {
            t = new Node;
            t->data = key;
            t->lchild = t->rchild = nullptr;
            return t;
        }
        if (key < p->data)
            p->lchild = RInsert(p->lchild, key);
        else if (key > p->data)
            p->rchild = RInsert(p->rchild, key);
        return p;
    }

    void Inorder(Node* p) {
        if (p) {
            Inorder(p->lchild);
            std::cout << p->data << " ";
            Inorder(p->rchild);
        }
    }

    Node* InPre(Node* p) {
        while (p && p->rchild != nullptr) {
            p = p->rchild;
        }
        return p;
    }

    Node* InSucc(Node* p) {
        while (p && p->lchild != nullptr) {
            p = p->lchild;
        }
        return p;
    }

    Node* Delete(Node* p, int key) {
        Node* q;
        if (p == nullptr) {
            return nullptr;
        }
        if (p->lchild == nullptr && p->rchild == nullptr) {
            if (p == root)
                root = nullptr;
            delete p;
            return nullptr;
        }
        if (key < p->data)
            p->lchild = Delete(p->lchild, key);
        else if (key > p->data)
            p->rchild = Delete(p->rchild, key);
        else {
            if (Height(p->lchild) > Height(p->rchild)) {
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            } else {
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        return p;
    }

    int Height(Node* p) {
        int x, y;
        if (p == nullptr)
            return 0;
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void Insert(int key) {
        Node* t = root;
        Node* r, *p;
        if (root == nullptr) {
            p = new Node;
            p->data = key;
            p->lchild = p->rchild = nullptr;
            root = p;
            return;
        }
        while (t != nullptr) {
            r = t;
            if (key < t->data) {
                t = t->lchild;
            } else if (key > t->data) {
                t = t->rchild;
            } else {
                return;
            }
        }
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        if (key < r->data) {
            r->lchild = p;
        } else {
            r->rchild = p;
        }
    }

    void InorderTraversal() {
        Inorder(root);
        std::cout << std::endl;
    }

    void DeleteNode(int key) {
        root = Delete(root, key);
    }

    void SearchNode(int key) {
        Node* result = Search(key);
        if (result != nullptr) {
            std::cout << "Found" << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }

    Node* Search(int key) {
        Node* t = root;
        while (t != nullptr) {
            if (key == t->data) {
                return t;
            } else if (key < t->data) {
                t = t->lchild;
            } else {
                t = t->rchild;
            }
        }
        return nullptr;
    }

    void CreateBSTFromArray(int arr[], int size) {
        for (int i = 0; i < size; ++i) {
            Insert(arr[i]);
        }
    }
};

int main() {
    BinarySearchTree bst;

    int arr[] = {10, 5, 11, 20, 8, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    bst.CreateBSTFromArray(arr, size);
    bst.InorderTraversal();

    bst.DeleteNode(20);
    bst.InorderTraversal();

    bst.DeleteNode(10);
    bst.InorderTraversal();

    bst.SearchNode(8);

    return 0;
}
