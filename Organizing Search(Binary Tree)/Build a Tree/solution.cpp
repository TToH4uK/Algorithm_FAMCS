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
	int number;

	while (!fin.eof())
	{
		fin >> number;
		tree(root, number);
	}
	write(root, fout);
}
