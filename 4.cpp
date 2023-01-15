
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

// int count_not_leaf(Node *root) {
//     if (root == NULL)
//         return 0;
//     if (root->left == NULL && root->right == NULL)
//         return 1;
//     else
//         return count_not_leaf(root->left) + count_not_leaf(root->right);
// }

void count_not_leaf(Node *root, int &count) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        count++;
    else {
        count_not_leaf(root->left, count);
        count_not_leaf(root->right, count);
    }
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(42);
    root->left->right = newNode(589);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // cout << "Number of leaves are " << count_not_leaf(root);
    int count = 0;
    count_not_leaf(root, count);
    cout << "Number of leaves are : >" << count;
    return 0;
}