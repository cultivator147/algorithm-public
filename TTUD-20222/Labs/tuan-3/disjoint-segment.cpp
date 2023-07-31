#include<bits/stdc++.h>
using namespace std;

int N, S[1000000], P[100000], mark[1000000];
int result = -1, tempResult = 1, maxIndex = -1;

bool check(int i,int j){
    if(j > S[i] && S[j] != 0){
        return true;
    }
    return false;
}
void DS(int i){
    for(int j = S[i]+1; j <= maxIndex; j++){
        if(check(i,j)){
            tempResult++;
            if(j == maxIndex){
                if(tempResult > result) result = tempResult;
            }else{
                DS(j);
            }
            tempResult--;
        }
    }
}
void solve(){
    for(int i = 0; i < maxIndex; i++){
        if(mark[i] != 1){
            S[i] = 0;
        }
    }
    for(int i = 0; i < maxIndex;i++){
        if(mark[i]){
            DS(i);
        }
    }
    cout << result;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        if(maxIndex < a) maxIndex = a;
        mark[a] = 1;
        S[a] = b;
    }
    solve();
    return 0;
}