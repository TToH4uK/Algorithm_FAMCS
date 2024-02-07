#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> factorials(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        factorials[i] = (long long)factorials[i - 1] * i % MOD;
    }

    vector<int> inv_factorials(N + 1, 1);
    for (int i = 2; i <= N; i++) {
        inv_factorials[i] = (long long)(MOD - MOD / i) * inv_factorials[MOD % i] % MOD;
    }
    for (int i = 2; i <= N; i++) {
        inv_factorials[i] = (long long)inv_factorials[i - 1] * inv_factorials[i] % MOD;
    }

    int answer = (long long)factorials[N] * inv_factorials[K] % MOD * inv_factorials[N - K] % MOD;

    cout << answer << endl;

    return 0;
}
