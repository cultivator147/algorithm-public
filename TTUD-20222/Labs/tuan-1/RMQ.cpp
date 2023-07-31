#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> ii;
int arr[1000000];
vector<ii> vt;
int solve(ii pair){
    int min = arr[pair.first];
    for(int i = pair.first + 1; i<=pair.second;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int main(){
    int n;
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    int quantity;
    cin >> quantity;
    for(int i = 0;i<quantity;i++){
        int i1, j1;
        cin >> i1 >> j1;
        vt.push_back(ii(i1, j1));
    }
    int sum = 0;
    for(int i = 0; i< quantity;i++){
        sum += solve(vt.at(i));
    }
    cout << sum;
    return 0;
}