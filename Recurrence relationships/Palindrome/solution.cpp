#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    string s;
    cin >> s;
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());


    vector<vector<int>> DP(n + 1, vector<int>(n + 1, 0));


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }


    int len = DP[n][n];

  
    string palindrome = "";
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            palindrome += s[i - 1];
            i--;
            j--;
        }
        else if (DP[i - 1][j] >= DP[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(palindrome.begin(), palindrome.end());

    cout << len << endl;
    cout << palindrome << endl;

    return 0;
}
