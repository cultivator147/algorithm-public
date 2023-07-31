#include<iostream>
using namespace std;

int n;
int k2;
int M[1000][1000] = {};
int R[1000][1000] = {};
int CR[1000], CC[1000] = {};
void printMatrix(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=n;j++){
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------" <<  endl;
}
int count = 0;
void Try(int k, int start1, int start2){
    for(int i = start1; i<= n; i++){
        for(int j = start2; j<=n; j++){
            //check dieu kien o day
            if(!CR[i] && !CC[j] && !R[i][j]){
                R[i][j] = 1;
                CR[i] = 1;
                CC[j] = 1;
                if(k == (n-k2)){
                    // printMatrix();
                    count ++;
                }else{
                    Try(k + 1, i, j);
                }
                // Khi het 1 luot thi bo dieu kien
                R[i][j] = 0;
                CC[j] = 0;
                CR[i] = 0;
            }
            
        }
        start2 = 1;
    }
}
int main(){
    cin >> n;
    cin >> k2;
    for(int i = 0; i<k2;i++){
        int inputI, inputJ;
        cin >> inputI >> inputJ;
        CC[inputJ] = 1;
        CR[inputI] = 1;
        R[inputI][inputJ] = 1;
    }
    Try(1,1,1);
    cout << count;
    return 0;
}
