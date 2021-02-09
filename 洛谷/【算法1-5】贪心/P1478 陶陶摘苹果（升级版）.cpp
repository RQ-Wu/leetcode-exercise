#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct apple
{
    int x;
    int y;
}apple;

bool cmpx(apple a1, apple a2){
    return a1.x < a2.x;
}

bool cmpy(apple a1, apple a2){
    return a1.y < a2.y;
}

int main(){
    int n, s, hd, ht;
    apple a[5005];
    scanf("%d %d %d %d", &n, &s, &hd, &ht);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    sort(a, a + n, cmpx);
    int canPick = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].x <= ht + hd)
        {
            canPick ++;
        }else break;
    }
    int pick = 0;
    sort(a, a+canPick, cmpy);
    for (int i = 0; i < canPick; i++)
    {
        s = s - a[i].y;
        if(s > 0) pick ++;
    }
    printf("%d", pick);

}