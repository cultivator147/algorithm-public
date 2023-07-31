#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(arr, n);
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
}