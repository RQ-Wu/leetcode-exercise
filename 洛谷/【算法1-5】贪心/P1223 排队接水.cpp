#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct IDAndTime
{
    int ID;
    long time;
}IDAndTime;

bool cmp(IDAndTime it1, IDAndTime it2){
    return it1.time < it2.time;
}

int main(){
    IDAndTime it[1010];
    int n;
    float wait = 0, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &it[i].time);
        it[i].ID = (i + 1);
    }
    sort(it, it+n, cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", it[i].ID);
        if (i < n - 1)
        {
            wait += it[i].time;
            sum += wait;
        }
    }
    printf("\n%f", sum / n);
    
}