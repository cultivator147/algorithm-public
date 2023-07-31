#include <bits/stdc++.h>

using namespace std;

long long getWays(int n, vector<int> c) {
    vector<long long> dp(n+1,0);
    dp[0] = 1;
    for(int i = 0; i < c.size(); i++){
        for(int j = c[i]; j <= n; j++){
            dp[j] += dp[j - c[i]];
        }
    }
    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    long long ways = getWays(n, c);
    cout << ways << endl;
    return 0;
}
