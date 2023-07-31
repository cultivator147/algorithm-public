#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n;
int bMark[10000] = {0};
int A[10000]= {0};
void printArray(){
    for(int i = 1; i<=n;i++){
        cout << A[i];
    }
    cout << endl;
}
void Try(int k){
    for(int i = 1; i<=n; i++){
        if(bMark[i] == 0){
            A[k] = i;
            bMark[i] = 1;
            if(k == n){
                printArray();
            }else{
                Try(k+1);
            }
            bMark[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    Try(1);
    
}