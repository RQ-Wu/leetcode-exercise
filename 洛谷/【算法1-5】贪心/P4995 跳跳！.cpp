#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    long long res = 0;
    int n;
    int h[310];
    int nowHeight = 0;
    int max[310] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    sort(h, h + n);
    for (int i = 0; i < n; i++)
    {
        int tmp = i / 2;
        if(i % 2){
            res += (h[tmp] - nowHeight) * (h[tmp] - nowHeight);
            nowHeight = h[tmp];
        }else{
            res += (h[n - 1 - tmp] - nowHeight) * (h[n -1 - tmp] - nowHeight);
            nowHeight = h[n - 1- tmp];
        }
    }
    cout << res;
}