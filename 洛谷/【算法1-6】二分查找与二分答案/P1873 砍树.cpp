#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    long long m, n, l = 0, r = 0;
    long long tree[1000000];

    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%lld", &tree[i]);
        r = max(r, tree[i]);
    }
    
    while(l <= r){
        long long mid = (l + r) / 2;
        long long res = 0;

        //计算根据mid砍树得到的木材
        for (int i = 0; i < n; i++) {
            long long tmp = tree[i] - mid;
            if (tmp > 0)
            {
                res += tmp;
            }
        }

        if (res >= m){
            l = mid  + 1;
        }
        else if(res < m){
            r = mid - 1;
        }
    }

    printf("%lld", r);
}