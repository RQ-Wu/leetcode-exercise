#include<cstdio>

int n, m, t, sx, sy, fx, fy;
int map[10][10] = {0};
int res = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y){
    if(x == fx && y == fy){
        res ++;
        return ;
    }
    else{
        for(int i = 0; i < 4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(map[next_x][next_y] != -1 && next_y > 0 && next_y <= n &&next_x > 0 && next_x <= m){
                dfs(next_x, next_y);
            }
        }
        return ;
    }
}

int main(){
    scanf("%d %d %d", &n, &m ,&t);
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
    for (int i = 0; i < t; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y] = -1;
    }
    dfs(sx, sy);
    printf("%d", res);
    
}