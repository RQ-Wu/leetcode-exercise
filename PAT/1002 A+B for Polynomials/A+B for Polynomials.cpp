#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    int k1 = 0;
    int k2 = 0;
    double b;
    vector<double> a(1001, 0);
    int loc = 0;
    int length = 0;
    
    cin >> k1;
    for(int i = 0; i < k1; i++){
        cin >> loc;
        cin >> a[loc];
    }
    cin >> k2;
    for(int i = 0; i < k2; i++){
        cin >> loc >> b;
        a[loc] = a[loc] + b;
    }
    for(int i = 0; i < 1001; i++){
        if(a[i] != 0) length ++;
    }
    cout << length;
    for(int i = 1000; i >= 0; i--){
        if(a[i] != 0){
            printf(" %d %.1lf",i,a[i]);
        }
    }
    return 0;
}