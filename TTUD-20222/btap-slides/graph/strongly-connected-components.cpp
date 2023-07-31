#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> G[100001], RG[100001];
int x[100001], idx;
int ncc;
char color[100001];

void init(){
    for(int i = 1; i <= N; i++){
        color[i] = 'W';
    }
}

void dfsG(int s){
    color[s] = 'G';
    for(int i = 0; i < G[s].size(); i++){
        int v = G[s][i];
        if(color[v] == 'W'){
            dfsG(v);
        }
    }
    color[s] = 'B';
    idx++;
    x[idx] = s;
}
void dfsG(){
    init();
    idx = 0;
    for(int v = 1; v <= N; v++){
        if(color[v] == 'W'){
            dfsG(v);
        }
    }
    
}
void dfsRG(int s){
    color[s] = 'G';
    for(int j = 0; j < RG[s].size(); j++){
        int v = RG[s][j];
        if(color[v] == 'W'){
            dfsRG(v);
        }
    }
    color[s] = 'B';
}
void dfsRG(){
    init();
    ncc = 0;
    for(int i = N; i >= 1; i--){
        int v = x[i];
        if(color[v] == 'W'){
            ncc++;
            dfsRG(v);
        }
    }
}
void solve(){
    dfsG();
    dfsRG();
    cout << ncc;
}
void input(){
    cin >> N >> M;
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        G[u].push_back(v);
        RG[v].push_back(u);
    }
}

int main(){
    input();
    solve();
    return 0;
}