#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

typedef struct position{
    int x;
    int y;
    int z;
}position;

bool cmp(position a, position b){
    return a.z < b.z;
}
int main(){
    int n;
    position pos[50005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &pos[i].x, &pos[i].y, &pos[i].z);
    }
    sort(pos, pos+n, cmp);
    double dis = 0;
    for (int i = 0; i < n-1; i++)
    {
        dis += sqrt(pow(pos[i+1].x-pos[i].x, 2)+pow(pos[i+1].y-pos[i].y, 2)+pow(pos[i+1].z-pos[i].z, 2));
    }
    printf("%.3lf", dis);

    return 0;
}