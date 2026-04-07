#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[1005][1005];
long long nums[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    
    nums[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    nums[n + 1] = 1;
    
    for (int len = 3; len <= n + 2; ++len) {
        for (int i = 0; i <= n + 2 - len; ++i) {
            int j = i + len - 1;
            long long max_val = 0;
            long long mult = nums[i] * nums[j];
            long long* dpi = dp[i];
            for (int k = i + 1; k < j; ++k) {
                long long val = dpi[k] + dp[k][j] + mult * nums[k];
                if (val > max_val) {
                    max_val = val;
                }
            }
            dp[i][j] = max_val;
        }
    }
    
    cout << dp[0][n + 1] << "\n";
    return 0;
}
