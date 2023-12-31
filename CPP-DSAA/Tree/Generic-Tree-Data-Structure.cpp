#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
class TreeNode {
public:
    T item;
    TreeNode<T>* left;
    TreeNode<T>* right;

    // Constructor
    TreeNode(T value) : item(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
public:
    // Inorder traversal
    void inorderTraversal(TreeNode<T>* root) {
        if (root == nullptr)
            return;
        inorderTraversal(root->left);
        cout << root->item << " -> ";
        inorderTraversal(root->right);
    }

    // Preorder traversal
    void preorderTraversal(TreeNode<T>* root) {
        if (root == nullptr)
            return;
        cout << root->item << " -> ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    // Postorder traversal
    void postOrderTraversal(TreeNode<T>* root) {
        if (root == nullptr)
            return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->item << " -> ";
    }

    // Create a new node
    TreeNode<T>* createNode(T value) {
        return new TreeNode<T>(value);
    }

    // Insert on the left of the node
    TreeNode<T>* insertLeft(TreeNode<T>* root, T val) {
        root->left = createNode(val);
        return root->left;
    }

    // Insert on the right of the node
    TreeNode<T>* insertRight(TreeNode<T>* root, T val) {
        root->right = createNode(val);
        return root->right;
    }

    // Depth calculation
    int depth(TreeNode<T>* node) {
        int d = 0;
        while (node != nullptr) {
            d++;
            node = node->left;
        }
        return d;
    }

    // Check if the tree is perfect
    bool isPerfect(TreeNode<T>* root, int d, int level) {
        if (root == nullptr) {
            return true;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return (d == level + 1);
        }

        if (root->left == nullptr || root->right == nullptr) {
            return false;
        }

        return isPerfect(root->left, d, level + 1) && isPerfect(root->right, d, level + 1);
    }

    // Wrapper function
    bool isPerfectTree(TreeNode<T>* root) {
        int d = depth(root);
        return isPerfect(root, d, 0);
    }

    // Count the number of nodes
    int countNumNodes(TreeNode<T>* root) {
        if (root == nullptr)
            return 0;
        return 1 + countNumNodes(root->left) + countNumNodes(root->right);
    }

    // Check if the tree is a complete binary tree
    bool checkComplete(TreeNode<T>* root, int index, int numberNodes) {
        if (root == nullptr)
            return true;

        if (index >= numberNodes)
            return false;

        return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
    }

    // Check if the tree is a full binary tree
    bool isFullBinaryTree(TreeNode<T>* root) {
        if (root == nullptr)
            return true;

        if (root->left == nullptr && root->right == nullptr)
            return true;

        if (root->left && root->right) {
            return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
        }

        return false;
    }

    // Check if the tree is height balanced
    bool checkHeightBalance(TreeNode<T>* root, int* height) {
        int leftHeight = 0, rightHeight = 0;
        int l = 0, r = 0;

        if (root == nullptr) {
            *height = 0;
            return true;
        }

        l = checkHeightBalance(root->left, &leftHeight);
        r = checkHeightBalance(root->right, &rightHeight);

        *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

        if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
            return false;
        else
            return l && r;
    }

    // Check if the tree is height balanced
    bool isHeightBalanced(TreeNode<T>* root) {
        int height = 0;
        return checkHeightBalance(root, &height);
    }
};

int main() {
    BinaryTree<int> tree;

    TreeNode<int>* root = tree.createNode(1);
    tree.insertLeft(root, 2);
    tree.insertRight(root, 3);
    tree.insertLeft(root->left, 4);
    tree.insertRight(root->left, 5);
    tree.insertLeft(root->right, 6);

    cout << "Inorder traversal" << endl;
    tree.inorderTraversal(root);

    cout << "\nPreorder traversal" << endl;
    tree.preorderTraversal(root);

    cout << "\nPostorder traversal" << endl;
    tree.postOrderTraversal(root);

    cout << "\nIs Perfect Tree: " << (tree.isPerfectTree(root) ? "Yes" : "No") << endl;
    cout << "Is Complete Binary Tree: " << (tree.checkComplete(root, 0, tree.countNumNodes(root)) ? "Yes" : "No") << endl;
    cout << "Is Full Binary Tree: " << (tree.isFullBinaryTree(root) ? "Yes" : "No") << endl;
    cout << "Is Height Balanced Tree: " << (tree.isHeightBalanced(root) ? "Yes" : "No") << endl;

    return 0;
}
