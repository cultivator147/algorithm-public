#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort(vector<int> &arr,int l,int r){
    int i = l;
    int j = r;
    int middle = l + (r-l)/2;
    int middleValue = arr[middle];
    while(i < j){
        while(arr[i] < middleValue){
            i++;
        }
        while(arr[j] > middleValue){
            j--;
        }
    
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if(i<r){
        quickSort(arr, i, r);
    }
    if(j > l){
        quickSort(arr, l, j);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> list;
    for(int i = 0;i<n;i++){
        int input;
        cin>> input;
        list.push_back(input);
    }
    quickSort(list,0,n-1);
    for(int i = 0;i<n;i++){
        cout << list[i] << " ";
    }
}