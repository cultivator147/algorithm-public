#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int> vt1, vector<int> vt2){
    if(vt1.size() != vt2.size()){
        return false;
    }
    for(int i = 0;i<vt1.size();i++){
        if(vt1[i] != vt2[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int noTest;
    cin >> noTest;
    vector<int> result;
    
    for(int i = 0;i<noTest;i++){
        int noTestA, noTestB;
        cin >> noTestA >> noTestB;
        vector<int> valueSetA;
        vector<int> valueSetB;
        for(int j=0;j<noTestA;j++){
            int value;
            cin >> value;
            valueSetA.push_back(value);
        }
        for(int j = 0;j<noTestB;j++){
            int value;
            cin >> value;
            valueSetB.push_back(value);
        }
        if(check(valueSetA, valueSetB)){
            result.push_back(1);
        }else{
            result.push_back(0);
        }
    }
    for(int x: result){
        cout << x << endl;
    }
}