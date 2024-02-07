#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int s;
	cin >> s;

	vector<int> n(s + 1), m(s + 1);
	for (int i = 1; i <= s; ++i) {
		cin >> n[i] >> m[i];
	}
	int Alot = 1e9;
	vector<vector<int>> NotDP(s + 1, vector<int>(s + 1, Alot));
	for (int i = 1; i <= s; ++i) {
		NotDP[i][i] = 0;
	}

	for (int len = 2; len <= s; ++len) {
		for (int l = 1; l + len - 1 <= s; ++l) {
			int r = l + len - 1;
			for (int k = l; k < r; ++k) {
				NotDP[l][r] = min(NotDP[l][r], NotDP[l][k] + NotDP[k+1][r] + n[l] * m[r] * m[k]);
			}
		}
	}

	cout << NotDP[1][s] << endl;

	return 0;
}
