#include<cstdio>
#include<algorithm>

using namespace std;

int use_time(int s, int t[]){
    int dp[21][1205] = {0};
    int sum = 0;
    int res = 10000;
    for(int i = 0; i < s; i++){
        sum += t[i];
    }
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if(j < t[i - 1]) dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = max(dp[i-1][j], t[i - 1] + dp[i-1][j-t[i - 1]]);
            }
        }
    }
    for (int i = 1; i <= sum; i++)
    {
        res = min(res, max(dp[s][i], sum-dp[s][i]));
    }
    return res;
}

int main(){
    int cnt[4] = {0};
    int len = 4;
    int res = 0;
    for(int i = 0; i < 4; i++){
        scanf("%d", &cnt[i]);
    }
    
    while(len--){
        int s = cnt[3-len];
        int t[21];
        for(int i = 0; i < s; i++){
            scanf("%d", &t[i]);
        }
        res += use_time(s, t);
    }
    printf("%d", res);
}