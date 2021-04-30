#include<iostream>

using namespace std;

int n, m, temp, temp_front = 0, l, r, c;
int a[100005] = {0};

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        a[i] = temp - temp_front;
        temp_front = temp;
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r >> c;
        a[l] += c;
        a[r + 1] -= c;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        cout << sum << " ";
    }
}