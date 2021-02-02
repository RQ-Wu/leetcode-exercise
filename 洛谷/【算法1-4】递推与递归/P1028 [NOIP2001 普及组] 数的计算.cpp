#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    long long dp[1005] = {0};
    int n;
    dp[1] = 1;

    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int half = i / 2;
        for(int j = 1; j <= half; j++){
            dp[i] += dp[j];
        }
        dp[i]++;
    }

    printf("%lld", dp[n]);
    
}