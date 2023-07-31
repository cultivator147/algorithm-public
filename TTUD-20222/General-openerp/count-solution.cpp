#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> X, vector<int> W, int M)
{
    int sum = 0;
    for (int i = 0; i < X.size(); i++)
    {
        int ai = W[i] * X[i];
        sum += ai;
    }
    if (sum == M){
        return true;
    }else{
        return false;
    }

}
int countSolutions(int n, vector<int>& a, int M) {
    vector<vector<int>> DP(n+1, vector<int>(M+1, 0));
    for (int j = 0; j <= M; j++) {
        DP[1][j] = (j % a[0] == 0) ? 1 : 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= j / a[i-1]; k++) {
                DP[i][j] += DP[i-1][j-k*a[i-1]];
            }
        }
    }
    return DP[n][M];
}
int main()
{
    int n;
    int M;
    cin >> n;
    cin >> M;
    vector<int> W;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        W.push_back(w);
    }
    int count = countSolutions(n, W, M);
    cout << count;
    return 0;
}