#include<bits/stdc++.h>
using namespace std;
int resultSize = 3, arrSize = 5;
int arr[5] = {5,3,4,2,1}, mark[5], r[3];

void print(){
    for(int i = 0; i < resultSize; i++){
        cout << r[i] << " ";
    }
    cout << endl;
}
void tst(int i,int start){
    if(i == resultSize){
        print();
        return;
    }
    for(int j = start; j < arrSize; j++){
        if(mark[j] != 1){
            mark[j] = 1;
            r[i] = arr[j];
            tst(i+1, j + 1);
            mark[j] = 0;
        }
    }
}
int main(){
    int x;
    cin >> x;
    cout << x;
    memset(mark, arrSize, 0);
    tst(0, 0);
}