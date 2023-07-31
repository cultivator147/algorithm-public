#include<bits/stdc++.h>
using namespace std;

map<string, int> numberCallsFrom, totalTimeFrom;

bool checkPhone(string pnumber){
    if(pnumber.size() != 10) return false;
    for(int i = 0; i < pnumber.size();i++){
        if(! ('0'<= pnumber[i] && pnumber[i] <= '9')) return false;
    }
    return true;
}
int hours(string time){
    return (time[0] - '0') * 10 + (time[1] - '0');
}
int minutes(string time){
    return (time[3] - '0') * 10 + (time[4] - '0');
}
int seconds(string time){
    return (time[6] - '0') * 10 + (time[7] - '0');
}
int calculateTime(string ftime, string etime){
    int start = 3600 * hours(ftime) + 60 * minutes(ftime) + seconds(ftime);
    int end = 3600 * hours(etime) + 60 * minutes(etime) + seconds(etime);
    return end - start;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int totalCalls = 0;
    int incorrectPhone = 0;
    do{
        cin >> type;
        if(type == "#") continue;
        totalCalls++;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if(!checkPhone(fnum) || !checkPhone(tnum)){
            incorrectPhone++;
        }
        int calledTime = calculateTime(ftime, etime);
        numberCallsFrom[fnum]++;
        totalTimeFrom[fnum] += calledTime;
    }while(type != "#");
    do{
        cin >> type;
        if(type == "#") continue;
        if(type == "?check_phone_number"){
            if(incorrectPhone == 0) 
                cout << 1;
            else cout << 0;
            cout << endl;
        }else if(type == "?number_calls_from"){
            string pnumber;
            cin >> pnumber;
            cout << numberCallsFrom[pnumber];
            cout << endl;
        }else if(type == "?number_total_calls"){
            cout << totalCalls;
            cout << endl;
        }else if(type == "?count_time_calls_from"){
            string pnumber;
            cin >> pnumber;
            cout << totalTimeFrom[pnumber];
            cout << endl;
        }
    }while(type != "#");
    return 0;
}