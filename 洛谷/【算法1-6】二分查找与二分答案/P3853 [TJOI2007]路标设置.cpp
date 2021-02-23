#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    long long l, n, k;
    long long pos[100005];

    scanf("%lld %lld %lld", &l, &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &pos[i]);
    }

	long long left = 0, right = l;
    while(left <= right){
        long long tmp = 0;
        long long mid =  (left + right) >> 1;
        for (int i = 1; i < n; i++)
        {
            long long gap = pos[i] - pos[i - 1];
            if(gap >= mid){
                tmp += gap / mid + (gap % mid > 0);
            }
        }

        if(tmp >= k){
            left = mid +1;
        }
        else if(tmp < k){
            right = mid -1;
        }
    }
    printf("%lld", right);
}