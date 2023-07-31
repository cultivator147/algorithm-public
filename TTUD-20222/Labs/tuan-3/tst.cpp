#include<bits/stdc++.h>
using namespace std;
int A[100], N;
void print(){
    for(int i = 0; i < N;i++){
        cout << A[i] << " ";
    }
}
void tst(){
    sort(A, A + N);
    int min = 10000000;
    for(int i = 0; i < N - 1; i++){
        int dist = A[i+1] - A[i];
        if(min > dist) min = dist;
    }
    cout << min;
}
int main(){
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> A[i];
    }
    tst();
    return 0;
}