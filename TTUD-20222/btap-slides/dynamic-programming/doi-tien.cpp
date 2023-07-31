#include<bits/stdc++.h>
using namespace std;
const int INF = 999999;
int N, D[12], mark[10000];
int changeCoin(int x,int di){
    if(x < 0)return INF;
    if(x == 0)return 0;
    if(di == -1) return INF;
    if(mark[x] >= 1){
        return mark[x];
    }
    int r = min(INF, 1 + changeCoin(x-D[di], di));
    r = min(r, changeCoin(x, di-1));
    mark[x] = r;
    return r;
}
int main(){
    memset(mark, 0, sizeof(mark));
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> D[i];
        mark[D[i]] = 1;
    }
    int x;
    cin >> x;
    int r = changeCoin(x, N-1); 
    cout << r;
    return 0;
}