#include<iostream>

using namespace std;

const int MAXN = 100005;
int n, m, a[MAXN], b[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    int ap = 0, bp = 0;
    while(bp < m){
        if(b[bp] == a[ap]) ap++;
        bp++;
    }
    if(ap == n) cout << "Yes";
    else cout << "No";
}