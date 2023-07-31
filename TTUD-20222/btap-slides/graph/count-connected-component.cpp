#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A[100001];
bool visited[100001];
void init(){
    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
}
void DFS(int u){
    vector<int> nextVertices = A[u];
    for(int i = 0; i<nextVertices.size();i++){
        int vertice = nextVertices[i];
        if(!visited[vertice]){
            visited[vertice] = true;
            DFS(vertice);
        }
    }
}
void solve(){
    init();
    int r = 0;
    for(int i = 1; i<= N; i++){
        if(!visited[i]) {
            r++;
            DFS(i);
        }
    }
    cout << r;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    solve();
    return 0;
}