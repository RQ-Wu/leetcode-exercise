#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> div(vector<int> &a, int &b){
    vector<int> res;
    int c = 0;
    for(int i = 0; i < a.size(); i++){
        c = c * 10 + a[i];
        res.push_back(c / b);
        c = c % b;
    }
    reverse(res.begin(), res.end());
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    res.push_back(c);

    return res; 
}

int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = 0; i < a.size(); i++) A.push_back(a[i] - '0');
    vector<int> res = div(A, b);
    int len = res.size();
    for(int i = len - 2; i >= 0; i--) cout << res[i];
    cout << endl;
    cout << res[len - 1];
    
}