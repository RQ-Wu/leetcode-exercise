#include<iostream>

using namespace std;

int sum[100005];
int n, m, l, r, temp;

int main(){
    cin >> n >> m;
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
}