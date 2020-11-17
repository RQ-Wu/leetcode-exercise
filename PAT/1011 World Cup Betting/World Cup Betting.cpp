#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    double bet[3][3] = {0};
    double profit = 1;
    int max[3] = {0};
    char result[3] = {'W','T','L'};
    for(int i = 0; i < 3; i++){
        int temp = 0;
        for(int j = 0; j < 3; j++){
            cin >>bet[i][j];
        }
        for(int j = 0; j < 3; j++){
            if(bet[i][j] > temp){
                temp = bet[i][j];
                max[i] = j;
            }
        }
        cout << result[max[i]] << " ";
        profit *= bet[i][max[i]];
    }
    profit = (profit * 0.65 - 1) * 2;
    printf("%.2lf", profit);
}