#include<iostream>

using namespace std;

int n, a;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        int times = 0;
        while(a){
            times += a&1;
            a = a >> 1;
        }
        cout << times << " ";
    }
}