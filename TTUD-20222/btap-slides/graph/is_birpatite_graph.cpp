#include<bits/stdc++.h>
using namespace std;
int N,M, d[100001];
vector<int> G[100001];
int level[100001];

int BFS(int u){
    queue<int> Q;
    Q.push(u);
    level[u] = 0;
    while(!Q.empty()){
        int v = Q.back(); Q.pop();
        for(int i = 0; i < G[v].size(); i++){
            int x = G[v][u];
            if(level[x] > -1){
                if(level[x] % 2 == level[v] % 2){
                    return 0;
                }
            }else{
                level[x] = level[v] + 1;
                Q.push(x);
            }
        }
    }
    return 1;
}
void init(){
    for(int i = 1; i <= N; i++){
        level[i] = -1;
    }
}
void solve(){
    init();
    int ans = 1;
    for(int v= 1; v <= N; v++) if(d[v]== -1){
        if(!BFS(v)){
            ans = 0; break;
        }
    }   
    cout << ans ;
}

void input(){
    cin >> N >> M;
    int u, v;
    for(int i = 1; i<=M; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
int main(){
    input();
    solve();
    return 0;
}