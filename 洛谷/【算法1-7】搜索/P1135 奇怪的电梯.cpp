#include<cstdio>
#include<queue>

using namespace std;

int n, a, b;
int num[205] = {0};
int step[205] = {0};
int flag[2] = {1, -1};
queue<int> q;

void bfs(){
    while(!q.empty()){
        int head = q.front();
        for (int i = 0; i < 2; i++)
        {
            int floor = head + flag[i] * num[head];
            if (floor >= 0 && floor < n && step[floor] == -1){
                q.push(floor);
                step[floor] = step[head] + 1;
                if (floor == b - 1) return;
            }
        }
        q.pop();
    }
}

int main(){
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        step[i] = -1;
    }
    step[a - 1] = 0;
    q.push(a - 1);
    bfs();
    printf("%d", step[b - 1]);
}