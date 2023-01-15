
#include <iostream>


using namespace std;

class BST {
    struct Node {
        int data;
        Node *left;
        Node *right;
    };

    Node *root;

    Node *newNode(int val) {
        Node *temp = new Node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    void inorder(Node *root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void insert(Node *root, int val) {
        if (root->data > val) {
            if (root->left == NULL)
                root->left = newNode(val);
            else
                insert(root->left, val);
        }
        else {
            if (root->right == NULL)
                root->right = newNode(val);
            else
                insert(root->right, val);
        }
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

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        if (root == NULL)
            root = newNode(val);
        else
            insert(root, val);
    }

    void inorder() {
        inorder(root);
    }

    void delete_greater_than(int val) {
        delete_greater_than(root, val);
    }
};

int main() {
    BST tree;
    for (int i = 0; i < 50; i++) {
        int val = rand() % (50*2) + 1*2;
        tree.insert(val);
    }
    tree.inorder();
    cout << endl;
   for (int i = 0; i < 10; i++) {
        int val = rand() % (50*2) + 1*3;
        tree.delete_greater_than(val);
    }
    tree.inorder();
    return 0;
}
