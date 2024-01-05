#include<iostream>

template<typename T>
class TreeNode {
public:
    TreeNode<T>* lchild;
    T data;
    TreeNode<T>* rchild;
};

template<typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;

    TreeNode<T>* RInsert(TreeNode<T>* p, T key) {
        TreeNode<T>* t = nullptr;
        if (p == nullptr) {
            t = new TreeNode<T>;
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

    void Inorder(TreeNode<T>* p) {
        if (p) {
            Inorder(p->lchild);
            std::cout << p->data << " ";
            Inorder(p->rchild);
        }
    }

    TreeNode<T>* InPre(TreeNode<T>* p) {
        while (p && p->rchild != nullptr) {
            p = p->rchild;
        }
        return p;
    }

    TreeNode<T>* InSucc(TreeNode<T>* p) {
        while (p && p->lchild != nullptr) {
            p = p->lchild;
        }
        return p;
    }

    TreeNode<T>* Delete(TreeNode<T>* p, T key) {
        TreeNode<T>* q;
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

    int Height(TreeNode<T>* p) {
        int x, y;
        if (p == nullptr)
            return 0;
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void Insert(T key) {
        TreeNode<T>* t = root;
        TreeNode<T>* r, *p;
        if (root == nullptr) {
            p = new TreeNode<T>;
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
        p = new TreeNode<T>;
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

    void DeleteNode(T key) {
        root = Delete(root, key);
    }

    void SearchNode(T key) {
        TreeNode<T>* result = Search(key);
        if (result != nullptr) {
            std::cout << "Found" << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }

    TreeNode<T>* Search(T key) {
        TreeNode<T>* t = root;
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

    void CreateBSTFromArray(T arr[], int size) {
        for (int i = 0; i < size; ++i) {
            Insert(arr[i]);
        }
    }
};
int main() {
    BinarySearchTree<float> bst;

    float arr[] = {10.5, 5.5, 11.5, 20.5, 8.5, 30.5};
    int size = sizeof(arr) / sizeof(arr[0]);

    bst.CreateBSTFromArray(arr, size);
    bst.InorderTraversal();

    bst.DeleteNode(20.5);
    bst.InorderTraversal();

    bst.DeleteNode(10.5);
    bst.InorderTraversal();

    bst.SearchNode(8.5);

    return 0;
}

