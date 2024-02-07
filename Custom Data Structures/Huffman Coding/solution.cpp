#include <iostream>
#include <fstream>
#include <vector>
#include <queue> 

using namespace std;

int main()
{
	ifstream input("huffman.in");
	ofstream output("huffman.out");

	int n;
	long long val;

	vector<long long > sums;
	priority_queue<long long, vector<long long >, greater<long long > > huffman;

	long long  sum = 0;
	input >> n;
	for (int i = 0; i < n; i++){
		input >> val;
		huffman.push(val);
	}
	while (huffman.size() != 1){
		long long  one = huffman.top();
		huffman.pop();

		long long  two = huffman.top();
		huffman.pop();

		sums.push_back(one + two);
		huffman.push(one + two);
	}
	for (int i = 0; i < sums.size(); i++) {
		sum += sums[i];
	}
	input.close();


	output << sum;
	output.close();

	return 0;
}
