#include<bits/stdc++.h>
using namespace std;

const string UNDEFINED = "0000000";
typedef pair<string, string> cc;
map<int, int> peopleBornAt;
map<string, cc> ancestors;
map<string, bool> alives;
int convertDate(string date){
	int year = atoi(date.substr(0,4).c_str());
	int month = atoi(date.substr(5,2).c_str());
	int day = atoi(date.substr(8,2).c_str());
	return 864*365*year + 864*30*month + 864*day;
}
int mostAliveAncestor(string code){
    string fcode = ancestors[code].first;
    string mcode = ancestors[code].second;
    if(fcode == UNDEFINED && mcode == UNDEFINED){
        return 1;
    }else if(fcode == UNDEFINED){
        return 1 + mostAliveAncestor(mcode);
    }else if(mcode == UNDEFINED){
        return 1 + mostAliveAncestor(fcode);
    }else{
        return 1 + max(mostAliveAncestor(fcode), mostAliveAncestor(mcode));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string code, type;
    int numberOfPeople = 0;

    do{
        cin >> code;
        if(code == "*") continue;
        string dob, fcode, mcode, isAlive, rcode;
        cin >> dob >> fcode >> mcode >> isAlive >> rcode;

        numberOfPeople++;
        alives[code] = isAlive == "Y" ? true : false;
        int idob = convertDate(dob);
        peopleBornAt[idob]++;
        ancestors[code] = cc(fcode, mcode);
    }while(code != "*");
    do{
        cin >> type;
        if(type == "***") continue;
        if(type == "NUMBER_PEOPLE"){
            cout << numberOfPeople << endl;
        }else if(type == "NUMBER_PEOPLE_BORN_AT"){
            string idob; cin >> idob;
            cout << peopleBornAt[convertDate(idob)] << endl;
        }else if(type == "MOST_ALIVE_ANCESTOR"){
            string icode; cin >> icode;
            cout << mostAliveAncestor(icode) - 1 << endl;
        }else if(type == "NUMBER_PEOPLE_BORN_BETWEEN"){
            string fdate, tdate; cin >> fdate >> tdate;
            int cnt = 0;
            for(pair<int, int> p : peopleBornAt){
                if(p.first >= convertDate(fdate) && p.first <= convertDate(tdate))cnt++;
            }
            cout << cnt << endl;
        }else if(type == "MAX_UNRELATED_PEOPLE"){

        }
    }while(type != "***");
    return 0;
}