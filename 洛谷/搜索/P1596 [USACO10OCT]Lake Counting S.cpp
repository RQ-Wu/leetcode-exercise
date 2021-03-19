#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int n, m;
int map[105][105] = {0};
int cnt = 0;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

void dfs(int x, int y){
    map[x][y] = cnt;
    for(int i = 0; i < 8; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(map[next_x][next_y] == -1 && next_x >= 0 && next_x < n && next_y >=0 && next_y < m){
            dfs(next_x, next_y);
        } 
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++){
            if(tmp[j] == 'W') map[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == -1){
                cnt++;
                dfs(i, j);
            }
        }
    }
    printf("%d", cnt);
}