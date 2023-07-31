#include<iostream>
using namespace std;
int N, B, A[10000], count = 0;
void ILE(int i){
    if(i == N + 1){
        if(B == 0){
            count++;
        }
        return;
    }
    for(int j = 1; j <= B; j++){
        int diff = j * A[i];
        B -= diff;
        ILE(i+1);
        B += diff;
    }
}
int main(){ 
    cin >> N >> B;
    for(int i = 1; i<=N; i++){
        cin >> A[i];
    }
    ILE(1);
    cout << count;
    return 0;
}