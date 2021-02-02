#include<cstdio>
#include<iostream>

using namespace std;

string highAccAdd(string a, string b){
    string res;
    int lenA = a.size();
    int lenB = b.size();

    // 补0
    if(lenA < lenB){
        for(int i = lenA; i < lenB; i++){
            a = "0" + a;
        }
    }    
    else{
        for(int i = lenB; i < lenA; i++){
            b = "0" + a;
        }
    }

    // 计算
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

int main(){
    int n;
    string step[3] = {"1","2","3"};
    scanf("%d", &n);
    if(n == 0 || n == 1 || n == 2) printf("%d", n);
    else{
        for(int i = 3; i < n; i++){
            step[0] = step[1];
            step[1] = step[2];
            step[2] = highAccAdd(step[0], step[1]);
        }
        cout << step[2]
    }
}