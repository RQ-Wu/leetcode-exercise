#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct milk{
    int price;
    int num;
}milk;

bool cmp(milk m1, milk m2){
    return m1.price < m2.price;
}

int main(){
    int n, m;
    milk milk[5050];
    int p = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &milk[i].price, &milk[i].num);
    }
    sort(milk, milk + m, cmp);
    for (int i = 0; i < m; i++)
    {
        n = n - milk[i].num;
        if (n >= 0)
        {
            p += (milk[i].price * milk[i].num);
        }
        else if(n < 0){
            p += (milk[i].price * (milk[i].num + n));
            break;
        }
    }
    printf("%d", p);
}