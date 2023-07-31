#include<iostream>
#include<cmath>
using namespace std;
int n;
int a[10000];

int maxLeftMid(int i, int mid){
    int maxLm = a[i];
    int s = 0;
    for(int i = i; i <= mid; i++){
        s += a[i];
        maxLm = max(s, maxLm);
    }
}

int div_to_conq(int i, int j){

}
int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
     }
}