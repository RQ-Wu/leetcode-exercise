#include<iostream>

using namespace std;

int transTime(string time){
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') *10 + (time[4] - '0');
    int second = (time[6] - '0') *10 + (time[7] - '0');
    
    return hour*24*60 + minute*60 + second;
}

int main(){
    string unlocker, locker, username,time_in,time_out;
    int max = 0;
    int min = 86400;
    int k;
    cin >> k;
    while(k--){
        cin >> username >> time_in >> time_out;
        int in = transTime(time_in);
        int out = transTime(time_out);
        if(min > in){
            min = in;
            unlocker = username;
        }
        if(max < out){
            max = out;
            locker = username;
        }
    }
    cout << unlocker << " " << locker;
}