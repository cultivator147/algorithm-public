#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int x){
    int l = 0;
    int r = n - 1;
    int middle;
    while(l < r){
        middle = (l+r)/2;
        if(arr[middle] < x){
            l = middle + 1;
        }else{
            r = middle;
        }
    }
    if(arr[l] == x){
        return l;
    }
    return -1;
}
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        int mtp;
        cin >> mtp;
        arr[i] = mtp;
    }
    int x;
    cin >> x;
    int index = binarySearch(arr, n, x);
    cout << index;
}