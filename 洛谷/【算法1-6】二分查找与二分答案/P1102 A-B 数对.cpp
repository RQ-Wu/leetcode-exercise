#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    long long a[100005];
    int n, res = 0;
    long long c;

    scanf("%d %lld", &n, &c);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }

    sort(a, a+n);
    for (int i = 0; i < n; i++)
    {
        int lower = lower_bound(a, a+n, a[i] - c) - a;
        int upper = upper_bound(a, a+n, a[i] - c) - a;
        res += (upper - lower);
    }

    printf("%d", res);
    
}