#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int n,m,r,c;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int maxN = 999 + 100;
const int oo= 1e9 + 7;
int matrix[maxN][maxN];
int d[maxN][maxN];    //độ dài đường đi từ ô xuất phát
typedef pair<int, int> xy;
queue<xy> qe ;  //luu cac o lan can se duoc xet
int solution(){
    qe.push(xy(r, c));  d[r][c] = 0; matrix[r][c] = 1;
    while(!qe.empty()){
        //tọa độ điểm hiện tại đang xét
        xy curPoint = qe.front(); qe.pop();
        //di chuyển 4 hướng
        for(int i =0;i<4;i++){
            //tính tọa độ tiếp theo
            int nextX = curPoint.first + dx[i]; int nextY = curPoint.second + dy[i];
            //check the conditions: 
            if(nextX < 1 || nextY < 1 || nextX > m || nextY > n){
                return d[curPoint.first][curPoint.second] + 1;
            }
            if(matrix[nextX][nextY]!=1){
                d[nextX][nextY] = d[curPoint.first][curPoint.second] + 1;
                qe.push(xy(nextX, nextY));
                matrix[nextX][nextY] = 1;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m >> r >> c;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> matrix[i][j];
        }
    }
    int answer =  solution();
    cout << answer;
    return 0;
}