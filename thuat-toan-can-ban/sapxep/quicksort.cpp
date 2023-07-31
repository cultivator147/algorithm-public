#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort(int arr[], int l, int r){
    int p = arr[(l+r)/2];
    int i = l;
    int j = r;
    while(i < j){
        while(arr[i] < p){
            i++;
        }
        while(arr[j] > p){
            j--;
        }
        if(i <= j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(i < r){
        quickSort(arr, i, r);
    }
    if(l < j){
        quickSort(arr, l, j);
    }
}
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++){
        int mtp;
        cin >> mtp;
        arr[i] = mtp;
    }
    quickSort(arr, 0, n - 1);
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
}