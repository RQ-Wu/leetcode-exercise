#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct coin{
    int m;
    int v;
    double avg;
}coin;

bool cmp (coin c1, coin c2){
    return c1.avg > c2.avg;
}
int main(){
    int n, t;
    double p;
    coin c[110];
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++){
        scanf("%d %d", &c[i].m, &c[i].v);
        c[i].avg = double(c[i].m) / double(c[i].v); 
    }
    for (int i = 0; i < n; i++){
        if (t > c[i].m)
        {
            t -= c[i].m;
            p += c[i].v;
        }
        else{
            p += c[i].avg * t;
            break;
        }
    }
    printf("%.2lf", p);
}