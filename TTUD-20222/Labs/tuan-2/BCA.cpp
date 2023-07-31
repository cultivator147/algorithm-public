#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> teachers;

int M, N, minLoad = 999999;
vector<vector<int>> courses;
int conflics[31][31];

int maxLoad()
{
    int max = -1;
    for (vector<int> t_c : teachers)
    {
        int sz = t_c.size();
        if (max < sz)
            max = sz;
    }
    return max;
}
bool checkCourse(int a, int b)
{
    if (conflics[a][b] == 1)
    {
        return false;
    }
    return true;
}

bool check(int t_i, int c)
{
    vector<int> teacher = teachers[t_i];
    for (int c_e : teacher)
    {
        if (!checkCourse(c_e, c))
        {
            return false;
        }
    }
    return true;
}
void BCA(int c_i)
{
    vector<int> course = courses[c_i];
    for (int i = 0; i < course.size(); i++)
    {
        int t_i = course[i];
        if (check(t_i, c_i))
        {
            teachers[t_i].push_back(c_i);
            if (c_i == N)
            {
                int tempMinLoad = maxLoad();
                if (tempMinLoad < minLoad)
                    minLoad = tempMinLoad;
            }
            else
            {
                BCA(c_i + 1);
            }
            teachers[t_i].pop_back();
        }
    }
}
void solve()
{
    for (int i = 0; i <= M; i++)
    {
        vector<int> teacher = {};
        teachers.push_back(teacher);
    }
    BCA(1);
    cout << minLoad;
}
int main()
{
    cin >> M >> N;
    int k;
    for (int i = 0; i <= N; i++)
    {
        vector<int> course;
        courses.push_back(course);
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> k;
        int c_n;
        for (int j = 1; j <= k; j++)
        {
            cin >> c_n;
            courses.at(c_n).push_back(i);
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        conflics[a][b] = 1;
    }
    // M = 4, N = 4;
    // for(int i = 0; i <= N; i++){
    //     vector<int> a;
    //     a.push_back(i);
    //     a.push_back(i);
    //     courses.push_back(a);
    // }
    solve();
    return 0;
}