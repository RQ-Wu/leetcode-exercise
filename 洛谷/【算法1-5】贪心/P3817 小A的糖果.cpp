#include<cstdio>

int main(){
    int n;
    long maxnum;
    int eat = 0;
    long candy[100005];

    scanf("%d %d", &n, &maxnum);
    for(int i = 0; i < n; i++){
        scanf("%ld", &candy[i]);
        if (i >= 1)
        {
            long sum = candy[i] + candy[i - 1];
            if (sum <= maxnum) continue;
            else{
                long sub = sum - maxnum;
                if (sub > candy[i]){
                    candy[i] = 0;
                    candy[i - 1] -= sub - candy[i];
                }else{
                    candy[i] -= sub;
                }
                eat += sub;
            }
        }  
    }
    printf("%d", eat);
}