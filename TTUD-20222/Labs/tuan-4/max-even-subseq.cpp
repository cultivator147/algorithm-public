#include<bits/stdc++.h>
using namespace std;

int N, A[1000001], sum[1000001], maxSum = INT_MIN;
int MES(int i){
    if(sum[i] != -1){
        return sum[i];
    }
    if(i == 0){
        sum[i] = A[i];
        return A[i];
    }
    if(A[i] + MES(i-1) < 0){
        sum[i] = 0;
        return 0;
    }
    sum[i] = A[i] + MES(i-1);
    if(sum[i] > maxSum && sum[i] % 2 == 0){
        maxSum = sum[i];
    }
    return sum[i];
}
void init(){
    for(int i = 0; i < N; i++){
        sum[i] = -1;
    }
}
void solve(){
    init();
    MES(N-1);
    // int max = INT_MIN;
    // for(int i = 0; i < N; i++){
    //     if(max < sum[i] && sum[i] % 2 == 0){
    //         max = sum[i];
    //     }
    // }
    if(maxSum == INT_MIN){
        cout << "NOT_FOUND";
    }else cout << maxSum;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    solve();
    return 0;
}