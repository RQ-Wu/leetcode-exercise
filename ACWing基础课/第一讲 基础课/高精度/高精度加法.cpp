#include<iostream>
#include<algorithm>

using namespace std;

string add(string a, string b){
    string res;
    int lenA = a.size();
    int lenB = b.size();

    // zero padding
    if(lenA > lenB){
        for(int i = lenB; i < lenA; i++){
            b = "0" + b;
        }       
    }
    else{
        for (int i = lenA; i < lenB; i++){
            a = "0" + a;
        }
    }

    int len = max(lenA, lenB);
    int c = 0;
    for(int i = len - 1; i >= 0; i--){
        int temp = a[i] - '0' + b[i] - '0' + c;
        c = temp / 10;
        temp = temp % 10;
        res = char(temp + '0') + res;
    }
    if(c!=0) res = char(c + '0') + res;

    return res;
}

int main(){
    string a, b;
    cin >> a >> b;
    cout << add(a, b);
}