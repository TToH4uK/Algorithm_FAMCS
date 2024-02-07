#include <iostream> 
#include <fstream> 
#include <cmath> 

using namespace std;
 
int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;


    if (m > n) {
        cout << -1; 
        return 0;
    }
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int answer = 0;
    if (m == 1) {
        for (int i = 0; i < n; i++) answer += matrix[i][0];
        cout << answer;
        return 0;
    }
    int** dp = new int* [n];
    for (int i = 0; i < n; ++i) {
        dp[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = matrix[0][0];

    for (int i = 1; i < n; i++) {
        if (dp[i - 1][1] != -1) {
            dp[i][0] = fmin(dp[i - 1][0] + matrix[i][0], dp[i - 1][1] + matrix[i][0]);
        }
        else {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }

        if (dp[i - 1][m - 1] != -1) {
            dp[i][m - 1] = fmin(dp[i - 1][m - 1] + matrix[i][m - 1], dp[i - 1][m - 2] + matrix[i][m - 1]);
        }
        else if (dp[i - 1][m - 2] != -1) {
            dp[i][m - 1] = dp[i - 1][m - 2] + matrix[i][m - 1];
        }

        for (int j = 1; j < m - 1; j++) {
            if (dp[i - 1][j - 1] == -1 && dp[i - 1][j] == -1 && dp[i - 1][j + 1] == -1) {
                break;
            }
            else if (dp[i - 1][j] == -1 && dp[i - 1][j + 1] == -1) {
                dp[i][j] = dp[i - 1][j - 1] + matrix[i][j];
            }
            else  if (dp[i - 1][j + 1] == -1) {
                dp[i][j] = fmin(dp[i - 1][j - 1] + matrix[i][j], dp[i - 1][j] + matrix[i][j]);
            }
            else {
                dp[i][j] = fmin(dp[i - 1][j] + matrix[i][j], fmin(dp[i - 1][j - 1] + matrix[i][j], dp[i - 1][j + 1] + matrix[i][j]));
            }
        }
    }

    cout << dp[n - 1][m - 1];

    return 0;
}
