#include<iostream>
#include<string>
using namespace std;
int n;
int arr[30];

void gen(int k, string seq)
{
    if (k == n + 1)
    {
        cout << seq << endl;
        return;
    }
    else
    {
        gen(k + 1, seq + '0');
        gen(k + 1, seq + '1');
    }
}

int main(){
    cin >> n;
    gen(1, "");
}