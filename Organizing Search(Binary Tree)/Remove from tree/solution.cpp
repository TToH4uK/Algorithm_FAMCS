#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	Node(int newValue = 0) : ToRight(0), ToLeft(0), value(newValue) {};
	Node* ToRight;
	Node* ToLeft;
	int value;
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
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	Node* root = NULL;
	int a;
	int value;

	fin >> value;

	while (!fin.eof())
	{
		fin >> a;
		tree(root, a);
	}

	root = deleteNode(root, value);

	write(root, fout);
}
