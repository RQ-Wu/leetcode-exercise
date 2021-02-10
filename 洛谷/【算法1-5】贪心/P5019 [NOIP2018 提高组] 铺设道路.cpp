#include<cstdio>

using namespace std;
int d[100010];

void fixRoad(int left, int right){
    for(int i = left; i <= right; i++){
        d[i] --;
    }
}

int main(){
    int n;
    int times = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }
    int min = 100000;
    int minPos;
    for (int i = 0; i < n; i++){
        if (d[i] < min) {
            minPos = i;
            min = d[i];
        }
    }
    for (int i = 0; i < n; i++){
        if (i < minPos){
            if (d[i] > d[i+1]) times += d[i] - d[i+1];
        }
        else if(i > minPos){
            if (d[i] > d[i-1]) times += d[i] - d[i-1];
        }
    }
    times += min;
    printf("%d", times);
    
}