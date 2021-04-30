#include<iostream>
#include<cstdio>

using namespace std;

int a[100005];
int n, q, target;

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    while(q--){
        scanf("%d", &target);
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if (a[mid] < target) l = mid + 1;
            else r = mid;
        }

        if (a[l] != target) printf("-1 -1\n");
        else{
            printf("%d ", l);
            int l = 0, r = n - 1;
            while(l <= r){
                int mid =l + r >> 1;
                if (a[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
            printf("%d\n", r);
        }
    }
}