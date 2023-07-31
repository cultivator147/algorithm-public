 #include<iostream>
 using namespace std;

int m, n;
int R[10000];
int sum[10000];
void printArray()
{
    for (int i = 1; i <= n; i++) 
    {
        cout << R[i];
    }
    cout << endl;
}

// k = 1: 1  k = 2: 1  k = 3 : 3
void Try(int k){
    int sumLeft = m - sum[k-1];
    for(int i = 1; i<=sumLeft; i++){
        if(k == n){
            R[k] = m - sum[k-1];
            printArray();
            return;
        }else{
            R[k] = i;
            sum[k] = sum[k-1] + i;
            Try(k + 1);
        }

    }
}
int main(){
    cin >> m >> n;
    Try(1);
    return 0;
}