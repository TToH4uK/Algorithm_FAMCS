#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node {
    Node(int newValue = 0) : ToRight(0), ToLeft(0), value(newValue) {};
    Node* ToRight;
    Node* ToLeft;
    int value;
    int height;
};

void tree(Node*& root, int newValue) {
    if (!root)
        root = new Node(newValue);

    else if (newValue > root->value)
        if (!root->ToRight)
            root->ToRight = new Node(newValue);
        else
            tree(root->ToRight, newValue);

    else if (newValue < root->value)
        if (!root->ToLeft)
            root->ToLeft = new Node(newValue);
        else
            tree(root->ToLeft, newValue);
}

Node* min(Node* root) {
    while (root->ToLeft)
    {
        root = root->ToLeft;
    }
    return root;
}

int getHeight(Node* root) {
    if (root == NULL) {
        return -1;
    }
    return root->height;
}

void post_order(Node* root) {
    if (root != NULL) {
        post_order(root->ToLeft);
        post_order(root->ToRight);
        root->height = max(getHeight(root->ToLeft), getHeight(root->ToRight)) + 1;
    }
}

vector <int> arr;

void in_order(Node* root) {
    if (root != NULL) {
        in_order(root->ToLeft);
        if (getHeight(root->ToLeft) == getHeight(root->ToRight)){
            arr.push_back(root->value);
        }
        in_order(root->ToRight);
    }
    return;
}

Node* deleteNode(Node* root, int value) {
    if (!root) {
        return NULL;
    }
    if (value < root->value) {
        root->ToLeft = deleteNode(root->ToLeft, value);
    }
    else if (value > root->value) {
        root->ToRight = deleteNode(root->ToRight, value);
    }
    else if (root->ToLeft && root->ToRight) {
        root->value = min(root->ToRight)->value;
        root->ToRight = deleteNode(root->ToRight, min(root->ToRight)->value);
    }
    else if (root->ToLeft) {
        root = root->ToLeft;
    }
    else if (root->ToRight) {
        root = root->ToRight;
    }
    else if (!root->ToLeft && !root->ToRight) {
        root = NULL;
    }
    return root;
}


void write(Node* root, ofstream& fout) {
    if (!root) return;
    fout << root->value << endl;

    write(root->ToLeft, fout);
    write(root->ToRight, fout);
}

int main() {
    ifstream fin("tst.in");
    ofstream fout("tst.out");

    Node* root = NULL;
    int a;

    while (!fin.eof())
    {
        fin >> a;
        tree(root, a);
    }
    post_order(root);
    in_order(root);
    if (arr.size() % 2 != 0) {
        int x = arr[arr.size() / 2];
        root = deleteNode(root, x);
    }

    write(root, fout);
    return 0;
}
