#include<iostream>
#include<cstdio>

using namespace std;

double n;

double pow3(double num){
    return num*num*num;
}
int main(){
    cin >> n;
    double left = -10000.0, right = 10000.0;
    while(right - left > 1e-7){
        double mid = (right + left) / 2.0;
        double result = pow3(mid);
        if(result < n) left = mid;
        else right = mid;
    }
    printf("%6lf", right);
}