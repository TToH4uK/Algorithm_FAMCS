#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	int M, N, c;
	input >> M >> c >> N;

	vector<int> hash(M, -1);


	for (int i = 0; i < N; i++) {
		int k;
		input >> k;
		int count = 0;
		int j = ((k % M) + c * count) % M;
		count += 1;
		if (hash[j] == -1) {
			hash[j] = k;
		}
		else {
			if (hash[j] == k) {
				continue;
			}
			else {
				while (hash[j] != k && hash[j] != -1) {
					j = ((k % M) + c * count) % M;
					count += 1;
				}
				if (hash[j] == -1 && j<M) {
					hash[j] = k;
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		output << hash[i] << " ";
	}
	output.close();
	input.close();
	return 0;
}
