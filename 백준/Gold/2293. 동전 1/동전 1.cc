#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    dp[0] = 1; // 동전을 사용하지 않아도 0원을 만들 수 있는 경우는 1가지입니다.

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= k; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k] << endl;

    return 0;
}
