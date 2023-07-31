#include<iostream>
#include<string>
using namespace std;
int n;
int arr[30];

// void printArray(int arr[]){
//     for(int i = 0;i<n;i++){
//         cout << arr[i];
//     }
//     cout << endl;
// }

// void quayLui(int index){
//     for(int j = 0; j <= 1;j++){
//         arr[index] = j;
//         if(index == (n-1)){
//             printArray(arr);
//         }else{
//             quayLui(index + 1);
//         }
//     }
// }

void gen(int k, string seq)
{
    if (k == n + 1)
    {
        cout << seq << endl;
        return;
    }
    if (seq.length() > 0 && seq[seq.length() - 1] == '1')
    {
        gen(k + 1, seq + '0');
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