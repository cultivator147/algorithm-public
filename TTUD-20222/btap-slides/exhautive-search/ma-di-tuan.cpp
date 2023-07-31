#include<stack>
#include<iostream>
using namespace std;

int n;
int i, j;
int Matrix[1000][1000] = {};
typedef pair<int, int> xy;
stack<xy> indexs;
int OX[] = {1,1,-1,-1,2,2,-2,-2};
int OY[] = {2,-2,2,-2,1,-1,1,-1};
bool check(int x, int y){
    if(x > n || y > n || x <= 0 || y <= 0 || Matrix[x][y] == 1){
        return false;
    }
    return true;
}
void printMatrix(){
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<= n; j++){
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}
int temp = 0;
int solution = 0;
void BFS(int x, int y){
    if(check(x, y)){
        Matrix[x][y] = 1;
        temp++;
        if(temp == n*n){
            // printMatrix();
            solution++; 
        }else{
            for(int i = 0; i < 9; i++){
                    BFS(x + OX[i], y + OY[i]);
                }
        }
        temp--;
        Matrix[x][y] = 0;
    }
}
int main(){
    cin >> n >> i >> j;
    BFS(i, j);
    cout << solution;
    return 0;
}