#include<iostream>
using namespace std;
int n;
bool mark[1000] = {false};
int arr[1000] = {0};
int result[1000];
int rc = 0;
void printArray(){
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    rc++;
    cout << endl;
}
void gen(int k){
    for(int i = 0; i < n; i++){
        if(k == n){
            printArray();
            return;
        }
        if(!mark[i]){
            result[k] = arr[i];
            mark[i] = true;
            gen(k+1);
            mark[i] = false;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0 ; i<n;i++){
        cin >> arr[i];
    }
    gen(0);
    cout << rc;
    return 0;
}