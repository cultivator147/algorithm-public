#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[10000], B[10000];
int mark[10000][10000];

int LCS(int n, int m)
{
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (mark[n][m] != -1)
    {
        return mark[n][m];
    }
    int r = 0;
    r = max(r, LCS(n - 1, m));
    r = max(r, LCS(n, m - 1));
    if (A[n] == B[m])
    {
        r = max(r, 1 + LCS(n - 1, m - 1));
    }
    mark[n][m] = r;
    return r;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }
    memset ( mark , -1 , sizeof ( mark ));

    LCS(N - 1, M - 1);
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ans < mark[i][j])
            {
                ans = mark[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}