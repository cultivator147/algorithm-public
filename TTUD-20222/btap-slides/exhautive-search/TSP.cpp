#include<iostream>
#include<stack>
using namespace std;

int currentCost[100];
int minCost = 999999;
bool visited[100]= {0};
int count = 0;
stack<int> verticles;
int n;
int distances[100][100] = {{0,0,0,0,0},{0,0,1,1,9},{0,1,0,9,3},{0,1,9,0,2},{0,9,3,2,0}};
void Try(int k){
    if(currentCost[k] < minCost){
        //update status variables
        if(count == (n-1)){
            verticles.push(1);
        }else{
            for (int i = 2; i <= n; i++)
            {
                if (!visited[i])
                {
                    verticles.push(i);
                }
            }
        }
        
        while(!verticles.empty()){
            int verticle = verticles.top();
            verticles.pop();
            if(!visited[verticle]){
                visited[verticle] = true;
                count++;
                currentCost[verticle] = currentCost[k] + distances[k][verticle];
                if(count == (n) && visited[1]){
                    if(minCost > currentCost[verticle]){
                        minCost = currentCost[verticle];
                    }
                }else{
                    Try(verticle);
                }   
            }
            if(verticle != k){
                currentCost[verticle] = 0;
                visited[verticle] = false;
            }
            count--;
        
    }
}
int main(){
    // cin >> n;
    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=n;j++){
    //         cin >> distances[i][j];
    //     }
    // }
    n = 4;
    for(int i = 1; i<=n ;i++){
        visited[i] = false;
    }
    Try(1);
    cout << minCost;
    return 0;
}
