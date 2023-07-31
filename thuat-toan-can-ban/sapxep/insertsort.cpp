#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void insertionSort(int a[], int n){
	for(int i = 1; i<n; i++){
        int index = i;
        while((a[index] < a[index-1]) && index > 0){
            swap(a[index],a[index-1]);
            index--;
        }
    }
} 
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
