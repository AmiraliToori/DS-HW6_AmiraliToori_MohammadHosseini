
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val) {
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int delete_greater_than(Node *root, int val) {
    if (root == NULL)
        return 0;
    if (root->data > val) {
        delete_greater_than(root->left, val);
        delete_greater_than(root->right, val);
        return 1;
    }
    else {
        int left = delete_greater_than(root->left, val);
        int right = delete_greater_than(root->right, val);
        if (left == 1)
            root->left = NULL;
        if (right == 1)
            root->right = NULL;
        return 0;
    }
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(42);
    root->left->right = newNode(589);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    inorder(root);
    cout << endl;
    delete_greater_than(root, 3);
    inorder(root);
    return 0;
}