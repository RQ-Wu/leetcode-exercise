#include<iostream>
#include<algorithm>

using namespace std;

string highAccAdd(string a, string b){
    string res;
    int lenA = a.size();
    int lenB = b.size();

    //补0
    if(lenA < lenB){
        for(int i = lenA; i < lenB; i++){
            a = "0" + a;
        }
    }    
    else{
        for(int i = lenB; i < lenA; i++){
            b = "0" + b;
        }
    }

    int len = max(lenA, lenB);
    int c = 0;
    int temp;
    for(int i = len - 1; i >=0; i--){
        temp = a[i] - '0' + b[i] - '0' + c;
        c = temp / 10;
        temp = temp % 10;
        res = char(temp + '0') + res;
    }
    if(c != 0) res = char(c + '0') + res;
    return res;
}