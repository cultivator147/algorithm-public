#include<iostream>

using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i< n;i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    for(int i = n-1;i>0;i--){
        bool swapped = true;
        for(int j = 0;j<i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = false;
            }
        } 
        if(swapped){
            break;
        }
    }
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}