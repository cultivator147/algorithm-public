#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 1;
int N, L1, L2;
int A[MAX_N], S[MAX_N];
void solve(){
    deque<int> Q;
    int ans = 0;
    for(int i = 1; i <= N; i++){
        while(!Q.empty() && i - Q.front() > L2){
            Q.pop_front();
        }
        if(i - L1 >= 1){
            while(!Q.empty() && S[Q.back()] < S[i - L1]){
                Q.pop_back();
            }
            Q.push_back(i - L1);
        }
        S[i] = A[i] + (Q.empty() ? 0 : S[Q.front()]);
        ans = max(ans, S[i]);
    }
    cout << ans;
    stack<int> st;
}
int main(){
    cin >> N >> L1 >> L2;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    solve();
    return 0;
}