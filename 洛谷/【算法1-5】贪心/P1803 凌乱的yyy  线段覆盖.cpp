#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct game{
    int start;
    int end;
    int time;
}game;

bool cmp(game g1, game g2){
    if (g1.start == g2.start)
    {
        return g1.time < g2.time;
    }
    else return g1.start < g2.start;
}
int main(){
    int n;
    int sum = 0;
    int startTime = 0;
    game g[100005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", g[i].start, g[i].end);
        g[i].time = g[i].end - g[i].start;
    }
    sort(g, g+n, cmp);
    for(int i = 0; i < n; i++){
        if(startTime==g[i].start){
            sum++;
            startTime = g[i].end;
        }
    }
    printf("%d", sum);
}