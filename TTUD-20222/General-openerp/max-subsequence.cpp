#include<iostream>
using namespace std;
int n, a[1000000], sum[1000000];
int maxSubSeq(){
    sum[0] = a[0];
    int maxValue = a[0];
    int maxSum = a[0];
    int startIndex = 0;
    int endIndex = 0;
    int tempStartIndex = 0;
    
    for(int i = 1; i<n;i++){
        if(sum[i-1] > 0){
            sum[i] = sum[i-1] + a[i];
        }else{
            if(a[i] > sum[i-1]){
                tempStartIndex = i;
                sum[i] = a[i];
            }else{
                sum[i] = sum[i-1];
            }
        }
        
        if(sum[i] > maxValue){
            maxValue = sum[i];
        }
    }
    return maxValue;
}
int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
            cin >> a[i];
    }
    cout << maxSubSeq();
    return 0;
}