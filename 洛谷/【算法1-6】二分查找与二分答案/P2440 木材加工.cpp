#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int n;
    long long k, l = 1, r = 1;
    long long tree[100005];

    scanf("%d %lld", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%lld", &tree[i]);
        r = max(tree[i], r);
    }

    while (l <= r)
    {
        long long res = 0;
        long long mid = (l + r) >> 1;
        for (int i = 0; i < n; i++)
        {
            res += (tree[i] / mid);
        }

        if (res >= k)
        {
            l = mid + 1;
        }
        else if(res < k){
            r = mid - 1;
        }
    }

    printf("%lld", r);
}