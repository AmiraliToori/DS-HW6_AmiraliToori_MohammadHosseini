

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

void printPreOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int search(int arr[], int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int in[], int post[], int n) {
    int root = post[n - 1];
    Node *tNode = newNode(root);
    if (n == 1) {
        return tNode;
    }
    int iIndex = search(in, root, n);
    if (iIndex != 0) {
        tNode->left = buildTree(in, post, iIndex);
    }
    if (iIndex != n - 1) {
        tNode->right = buildTree(in + iIndex + 1, post + iIndex, n - iIndex - 1);
    }
    return tNode;
}



int main() {
    int inorder[] = {42 , 3 , 9 , 1 , 6 , 2 , 7};
    int postorder[] = {42 , 9 , 3 , 6 , 7 , 2 , 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    Node *root = buildTree(inorder, postorder, n);
    cout << "Preorder of the constructed tree : ";
    printPreOrder(root);
    return 0;
 
    
    
    
}
