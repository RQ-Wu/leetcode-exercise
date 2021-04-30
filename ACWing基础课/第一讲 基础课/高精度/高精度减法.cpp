// 第一步：比较两者大小，确保函数中lenA >= LenB
// 第二部：补零，做减法
// 第三步：将结果中的最前面的零去除

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(string a, string b){
    if(a.size() != b.size()) return a.size() >= b.size();
    else{
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) return a[i] > b[i];
        }
    }
    return true;
}

string trimzero(string res){
    string trueRes;
    bool start = true;
    for(int i = 0; i < res.size(); i++){
        if(res[i]!='0') start = false;
        if(start == false) trueRes += res[i];
    }
    if(trueRes.size() == 0) trueRes = "0";

    return trueRes;
}

string sub(string a, string b){
    string res;

    // 补零
    for(int i = b.size(); i < a.size(); i++){
            b = "0" + b;
    }

    int c = 0;
    for (int i = a.size() - 1; i >=0; i--){
        int temp = a[i] - '0' - c - b[i] + '0';
        if (temp < 0){
            temp += 10;
            c = 1;
        }
        else{
            c = 0;
        }
        res = char(temp + '0') + res;
    }
    return res;
}

int main(){
    string a, b;
    cin >> a >> b;

    if(cmp(a, b)) cout << trimzero(sub(a, b));
    else{
        cout << "-";
        cout << trimzero(sub(a, b));
    }
}