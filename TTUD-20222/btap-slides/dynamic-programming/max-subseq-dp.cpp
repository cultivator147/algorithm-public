#include<iostream>
using namespace std;
int N;
int A[10000];
int mark[10000];
int mss(int i){
    if(i == 0)return A[i];
    if(mark[i] != -1){
        return mark[i];
    }
    int MSS = max(A[i] + mss(i-1), A[i]);
    mark[i] = MSS;
    return MSS;
}
void findMax(){
    int max = -999999;
    for(int i = 0; i < N; i++){
        if(max < mark[i]){
            max = mark[i];
        }
    }
    cout << max;
}
int main(){
    cin >> N;
    int i = 0;
    for(int i = 0; i< N; i++){
        cin >> A[i];
        mark[i] = -1;
    }
    mss(N-1);
    findMax();
    return 0;
}