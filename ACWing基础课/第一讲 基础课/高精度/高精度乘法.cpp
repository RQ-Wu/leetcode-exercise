#include<iostream>
#include<vector>

using namespace std;

vector <int> mul(vector<int> &a, vector<int>b){
    vector<int> res(a.size() + b.size(), 0);

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            res[i + j] += a[i] * b[j];
        }
    }
    int t = 0;
    for(int i = 0; i < res.size(); i++){
        res[i] = res[i] + t;
        t = res[i] / 10;
        res[i] = res[i] % 10;
    }

    while(res.size() > 0 && res.back() == 0) res.pop_back();

    return res;
}

int main(){
    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for(int i = a.size() - 1; i >= 0; i--){
        A.push_back(a[i] - '0');
    }
    for(int i = b.size() - 1; i >= 0; i--){
        B.push_back(b[i] - '0');
    }

    vector<int> res = mul(A, B);

    for(int i = res.size() - 1; i >= 0; i--) cout << res[i];

    return 0;
}