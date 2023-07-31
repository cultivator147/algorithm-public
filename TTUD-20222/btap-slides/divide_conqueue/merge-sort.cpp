#include<iostream>
using namespace std;

int n;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize){
    int i =0,j=0,k=0;
    while(i < leftSize && j < rightSize){
        if(left[i] > right[j]){
            arr[k++] = right[j++];
        }else{
            arr[k++] = left[i++];
        }
    }
    while(i < leftSize){
        arr[k++] = left[i++];
    }
     while(j < rightSize){
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size){
    //basecase
    if(size == 1) return;
    int middle = size/2;
    int left[middle], right[size-middle];
    for(int i = 0; i<middle;i++){
        left[i] = arr[i];
    }
    for(int i = 0; i< size - middle;i++){
        right[i] = arr[middle+i];
    }
    mergeSort(left, middle);
    mergeSort(right, size-middle);
    merge(arr, left, middle, right, size-middle);
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int arr[1000];
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, n);
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}