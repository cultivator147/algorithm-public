#include <bits/stdc++.h>

using namespace std;
int B[10001];
int mark[10001];
int N;
int res = 0;
int solve(int i){
    if(i==2){
        res += 1;
    }
    for(int j = 1; j < B[i];j++){
        res += j + solve(i+1);
    }
}
int calculate(){
    return B[1] - B[0];
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> B[j];
            cout << solve(N-1);
        }
    }

}