#include<bits/stdc++.h>
using namespace std;
int N, A[10000], mem[10000];
int LIS(int n){
    if(mem[n] != -1){
        return mem[n];
    }
    int r = 1;
    for(int i = 0; i < n;i++){
        if(A[i] < A[n]){
            r = max(r, 1 + LIS(i));
        }
    }
    mem[n] = r;
    return r;
}
int main(){
    cin >> N;
    for(int  i = 0; i<N; i++){
        cin >> A[i];
        mem[i] = -1;
    }
    LIS(N-1);
    int ans = -1;
    for(int i = 0; i < N; i++){
        if(ans < mem[i]){
            ans = mem[i];
        }
    }
    cout << ans;
    return 0;
}