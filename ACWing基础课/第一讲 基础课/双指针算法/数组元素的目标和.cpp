#include<iostream>

using namespace std;

const int MAXN = 100005;
int n, m, x;
int a[MAXN], b[MAXN];

int main(){
    cin >> n >> m >> x;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    int ap = 0, bp = m - 1;
    while(ap < n && bp >= 0){
        if(a[ap] + b[bp] > x) bp--;
        else if(a[ap] + b[bp] < x) ap++;
        else{
            cout << ap << " " << bp << endl;
            ap++;
        }
    }
}