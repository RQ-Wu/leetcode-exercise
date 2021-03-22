#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
int power[1000];
int out[1000] = {0};

int main(){
    cin >> n;
    int num = pow(2, n);
    for(int i = 0; i < num; i++){
        cin >> power[i];
    }
    int rank = num;
    int a = -1, b = -1;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < num; i++){
            if(out[i] == 0 && a == -1) a = i;
            else if(out[i] == 0 && a != -1){
                b = i;
                int res = 0;
                if(power[a] > power[b]){
                    out[b] = 1;
                    res = b;
                }
                else {
                    out[a] = 1;
                    res = a;
                }
                a = -1;
                b = -1;
                rank --;
                if(rank == 1){
                    cout << res +1;
                    break;
                }
            }
        }
    }
}