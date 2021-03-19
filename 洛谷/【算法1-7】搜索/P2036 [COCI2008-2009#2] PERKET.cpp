#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n = 0;
int res = 0x7fffffff;
int suan[15], ku[15];
int suan_mul = 1, ku_sum = 0;
int choose[15] = {0};

void f(int start){
    for (int i = start; i < n; i++)
    {
        if(!choose[i]){
            choose[i] = 1;
            suan_mul *= suan[i];
            ku_sum += ku[i];
            res = min(res, abs(suan_mul - ku_sum));
            f(i+1);
            suan_mul /= suan[i];
            ku_sum -= ku[i];
            choose[i] = 0;
        }
    }
    
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &suan[i], &ku[i]);
    }
    f(0);
    printf("%d", res);

}