
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


// void countNodes(Node *root, int &count) {
//     if (root == NULL) return;
//     if (root->left != NULL || root->right != NULL) count++;
//     countNodes(root->left, count);
//     countNodes(root->right, count);
// }

int countNodes(Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(87);
    root->left->right = newNode(5);
    root->right->left = newNode(12);
    root->right->right = newNode(98);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(98);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
    root->left->left->left->left = newNode(16);
    root->left->left->left->right = newNode(17);

    int count = 0;
    // countNodes(root, count);
    count = countNodes(root);
    // cout << "Number of non-terminal nodes: " << count << endl;
    cout << "Number of non-terminal nodes: " << count << endl;
    return 0;
}
