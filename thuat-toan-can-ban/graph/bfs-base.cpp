#include <iostream>
#include <queue>
#include <vector>
#include<string.h>
using namespace std;

const int MAXN = 100005; // số lượng đỉnh tối đa của đồ thị
vector<int> graph[MAXN]; // danh sách kề của đồ thị
bool visited[MAXN];      // mảng đánh dấu các đỉnh đã được thăm

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m; // nhập số lượng đỉnh và số lượng cạnh của đồ thị
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // nhập một cạnh (u, v)
        graph[u].push_back(v);
        graph[v].push_back(u); // thêm cạnh (u, v) và (v, u) vào danh sách kề
    }
    memset(visited, false, sizeof(visited)); // khởi tạo mảng visited
    bfs(1); // bắt đầu BFS từ đỉnh 1
    return 0;
}