#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 100005;
int a[MAXN], times[MAXN];

int main(){
    int n, res = 0;
    cin >> n;
    for(int i = 0, j = 0; i < n; i++){
        cin >> a[i];
        ++ times[a[i]];
        while(times[a[i]] > 1){
            --times[a[j++]];
        }
        res = max(res, i - j + 1);
    }
    cout << res;
}