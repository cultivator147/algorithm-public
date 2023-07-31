#include<iostream>
#include<stack>
using namespace std;

int n;
int Matrix[1000][1000] = {};
typedef pair<int, int> xy;
stack<xy> indexs;
int OX[] = {1,1,-1,-1,2,2,-2,-2};
int OY[] = {2,-2,2,-2,1,-1,1,-1};
int solutions = 0;
int temp = 0;
bool check(int x, int y){
    if(x > n || y > n || x <= 0 || y <= 0 || Matrix[x][y] == 1){
        return false;
    }
    return true;
}

void BFS(int x, int y){
    for(int i = 0; i<8;i++){
        int nextX = x + OX[i];
        int nextY = y + OY[i];
        if(check(nextX, nextY)){
            cout << nextX << " " << nextY << endl;
            indexs.push(xy(nextX, nextY));
        };
    }
    while(!indexs.empty()){
        temp++;
        xy xyNext = indexs.top();
        indexs.pop();
        Matrix[xyNext.first][xyNext.second] = 1;
        if(temp == n*n){
            solutions++;
        }else{
            BFS(xyNext.first, xyNext.second);
        }
        temp--;
        Matrix[xyNext.first][xyNext.second] = 0;
    }
}
int main(){
    // n = 3;
    // int i = 1, j = 1;
    int i,j;
    cin >> n >> i >> j;
    Matrix[i][j] = 1;
    BFS(i, j);
    cout << endl << "solutions: " <<  solutions;
    return 0;
}