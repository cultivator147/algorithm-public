#include<bits/stdc++.h>
using namespace std;
int N;

int longestDistance = -1, tempDistance = 0;
bool visited[100001]; 
vector<int> G[100001], C[100001];
int d[100001], p[100001];
void DFS(int u){
    if(G[u].size() == 0) return;
    for(int i = 0; i < G[u].size(); i++){
        int x = G[u][i];
        if(!visited[x]){
            tempDistance += C[u][i];
            visited[x] = true;
            if(longestDistance < tempDistance){
                longestDistance = tempDistance;
            }
            DFS(x);
            visited[x] = false;
            tempDistance -= C[u][i];
        }
    }
}
void init(){
    for(int i = 1; i <= N;i++){
        visited[i] = false;
    }
   
}
void solve(){
    init();
    bool found = false;
    for(int i = 1; i <= N; i++){
        if(G[i].size() == 1){
            found = true;
            DFS(i);
        }
    }
     if(!found){
        DFS(1);
    }
    cout << longestDistance;
}
void input(){
    cin >> N;
    int u,v,c;
    for(int i = 1; i < N; i++){
        cin >> u >> v >> c;
        G[u].push_back(v);
        G[v].push_back(u);
        C[u].push_back(c);
        C[v].push_back(c);
    }
}
int main(){
    input();
    solve();
    return 0;
}