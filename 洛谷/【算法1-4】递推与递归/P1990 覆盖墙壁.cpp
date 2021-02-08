#include<cstdio>

int main(){
    int n;
    int dp[2] = {1, 2};
    int s = 1;
    scanf("%d", &n);
    for (int i = 2; i < n; i++)
    {
        int newdp = (s * 2 + dp[0] + dp[1]) % 10000;
        s += dp[0];
        s = s % 10000; 
        dp[0] = dp[1];
        dp[1] = newdp;
    }
    printf("%d", dp[n>=3?1:n-1]);
}