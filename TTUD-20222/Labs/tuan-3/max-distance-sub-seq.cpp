#include<bits/stdc++.h>
using namespace std;
int N, C, A[100001], r[100001], T[21];
int tempResult, result = -1;

int calculateDistance(){
    int min = INT_MAX;
    for(int i = 0; i < C - 1; i++){
        int dist = r[i+1] - r[i];
        if(min > dist) min = dist;
    }
    return min;
}
void MDSS(int i,int s_i){
    for(int j = s_i; j <N; j++){
        r[i] = A[j];
        if(i == C - 1){
            tempResult = calculateDistance();
            if(result < tempResult) result = tempResult;
        }else{
            MDSS(i+1,j+1);
        }
    }
}
void solve(int t){
    sort(A, A + N);
    MDSS(0,0);
    T[t] = result;
}
int main(){
    int t; cin >> t;
    for(int t_n = 0; t_n < t; t_n++){
        cin >> N >> C;
        for(int i=0;i<N;i++){
            cin >> A[i];
        }
        solve(t_n);
    }
    for(int i = 0; i < t; i++){
        cout << T[i] << endl;
    }
    return 0; 
}