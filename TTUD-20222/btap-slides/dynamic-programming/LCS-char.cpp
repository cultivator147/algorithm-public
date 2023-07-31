#include<bits/stdc++.h>
using namespace std;
int N, M;
char A[10000], B[10000];
int mark[10000][10000];
void printArray(char arr[],int l){
    for(int i = 0; i < l; i++){
        cout << arr[i];
    }
}
int LCS(int n,int m){
    if(n < 0 || m < 0){
        return 0;
    }
    if(mark[n][m] != -1){
        return mark[n][m];
    }
    
    int r = 0;
    for(int j = m; j >= 0;j--){
        if(A[n] == B[j]){
            r = max(r, 1 + LCS(n-1, j-1));
        }
    }
    mark[n][m] = r;
    return r;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        if(N <= M){
            cin >> A[i];
        }else{
            cin >> B[i];
        }
    }
    for(int i = 0; i<M; i++){
        if(N <= M){
            cin >> B[i];
        }else{
            cin >> A[i];
        }
    }
    int tmp = N <= M ? N : M;
    if(tmp != N){
        M = N;
        N = tmp;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M;j++){
            mark[i][j] = -1;
        }
    }
    LCS(N-1, M-1);
    int ans = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M;j++){
            if(ans < mark[i][j]){
                ans = mark[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}