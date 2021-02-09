#include<iostream>
#include<algorithm>

using namespace std;

string cmpString(string s1, string s2){
    for (int i = 0; i < s1.size(); i++)
    {
        if(s1[i] > s2[i]) return s2;
        else if(s1[i] < s2[i]) return s1;
    }
    return s1;
    
}
string select(string s, int n){
    string res;
    if (n == 1){
        char min = '9';
        for (int i = 0; i < s.size(); i++){
            if(s[i] < min) min = s[i];
        }
        res.push_back(min);
        return res;
    }
    else if(n == s.size()) return s;
    else{
        string s1 = select(s.substr(0, s.size() - 1), n-1) + s[s.size() - 1];
        string s2 = select(s.substr(0, s.size() - 1), n);
        return cmpString(s1, s2);
    }
}
int main(){
    string s;
    string res[255][255];
    int n;
    cin >> s >> n;
    for (int i = 1; i <= s.size(); i++){
        for (int j = i; j >= 1; j--){
            if (j > s.size() - n) continue;
            else{
                if (j == i) res[i][j] = s.substr(0, i);
                else if(j == 1){
                    string tmp = s.substr(0, i);
                    char min = '9';
                    for (int k = 0; k < tmp.size(); k++){
                        if(tmp[k] < min) min = tmp[k];
                    }
                    res[i][j] = min;
                }
                else{
                    res[i][j] = cmpString(res[i-1][j], res[i-1][j-1] + s[i-1]);
                }
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < res[s.size()][s.size() - n].size(); i++)
    {
        if(res[s.size()][s.size() - n][i] != '0' || flag == 1){
            cout << res[s.size()][s.size() - n][i];
            flag = 1;
        }
    }
	if(flag == 0) cout << 0;
    
}