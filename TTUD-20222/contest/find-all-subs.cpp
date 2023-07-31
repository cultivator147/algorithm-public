#include<bits/stdc++.h>
using namespace std;
int N, A[1000];
void generateSubsets(const vector<int>& nums, vector<int>& subset, int index) {
    // In tập con hiện tại
    cout << "{ ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << "}" << endl;

    // Quay lui để sinh các tập con tiếp theo
    for (int i = index; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        generateSubsets(nums, subset, i + 1);
        subset.pop_back();
    }
}
void solve(){
    for(int i = 1; i <= N;i++){
        cout << A[i];
    }
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    solve();
    return 0;
}