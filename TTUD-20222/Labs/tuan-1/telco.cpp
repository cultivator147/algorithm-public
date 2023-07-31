#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool checkNumber(string number)
{
    if (number.length() != 10)
    {
        return false;
    }
    for (int i = 0; i < number.length(); i++)
    {
        if (!(number[i] >= '0' && number[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}
int countTime(string ftime, string etime)
{
    int startTime = 3600 * ((ftime[0] - '0') * 10 + ftime[1] - '0') +
                    60 * ((ftime[3] - '0') * 10 + ftime[4] - '0') +
                    ((ftime[6] - '0') * 10 + ftime[7] - '0');
    int endTime = 3600 * ((etime[0] - '0') * 10 + etime[1] - '0') + 60 * ((etime[3] - '0') * 10 + etime[4] - '0') +
                  ((etime[6] - '0') * 10 + etime[7] - '0');
    return endTime - startTime;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    int checkPhoneNumber = 1;
    map<string,vector< vector<string> > > calls;
    do
    {
        vector<string> call = {};
        string key = "";
        for (int i = 0; i < 6; i++)
        {
            cin >> input;
            if (i == 1)
            {
                key = input;
                if(checkNumber(key) == false){
                    checkPhoneNumber = 0;
                }
            }
            else if (i > 1)
            {
                call.push_back(input);
            }
            if (i == 5)
            {
                calls[key].push_back(call);
            }
        }
        cin >> input;
    }while (input != "#");
    map<string, vector< vector<string> > >::iterator it = calls.begin();
    // for (it; it != calls.end(); it++)
    // {
    //     cout << it->first << " ";
    //     cout << it->second[0][0] << " " << it->second[1][0] << " " << it->second[2][0] << it->second[3][0];
    //     cout << endl;
    // }
    int totalCalls = calls.size();
    do{
        cin >> input;
        if(input == "#"){
            continue;
        }
        if (input == "?check_phone_number"){
            cout << checkPhoneNumber << endl;
        } 
        else if(input == "?number_total_calls"){
            cout << totalCalls;
        }
        else if(input == "?number_calls_from"){
            string phone;
            cin >> phone;
            cout << calls[phone].size();
        }
    }while(input != "#");
}