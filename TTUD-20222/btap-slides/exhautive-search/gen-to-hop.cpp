#include <iostream>
using namespace std;

int n, m;
int A[10000];
int R[10000];
int mark[10000];

void printArray()
{
    for (int i = 1; i <= m; i++) 
    {
        cout << R[i];
    }
    cout << endl;
}

void Try(int k, int start)
{
    for (int i = start; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            R[k] = A[i];
            if (k == m)
            {
                printArray();
            }
            else
            {
                mark[i] = 1;
                Try(k + 1, i);
            }
            mark[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    Try(1, 1);
}
