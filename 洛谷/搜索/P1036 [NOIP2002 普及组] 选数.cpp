#include<cstdio>
#include<cmath>

using namespace std;

int n = 0, k = 0;
int total = 0;
int sum = 0;
int a[25];
int isChoose[25] = {0};

bool isPrime(int num){
    int s = sqrt(double(num));
    for(int i = 2; i <= s; i ++){
        if (n % i == 0) return false;
    }
    return true;
}

void chooseNum(int chooseLeft, int sum, int start){
    if(chooseLeft == 0){
        if(isPrime(sum)) total++;
    }
    else{
        for(int i = start; i < n; i++){
            if(!isChoose[i]){
                sum += a[i];
                isChoose[i] = 1;
                chooseLeft --;
                chooseNum(chooseLeft, sum, start + 1);
                sum -= a[i];
                chooseLeft ++;
                isChoose[i] = 0;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d", total);
}