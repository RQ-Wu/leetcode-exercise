#include<cstdio>

int horse[410][410] = {0};
int n, m, x, y;
int dx[8] = {2,-2,2,-2,-1,1,-1,1};
int dy[8] = {1,1,-1,-1,2,2,-2,-2};

void dfs(int x, int y, int n, int m, int step){
    if (step > 200) return;
    if((horse[x][y] == -1 || horse[x][y] > step) && x < n && x >=0 && y < m && y >=0){
        horse[x][y] = step;
        for(int i = 0; i < 8; i++){
            dfs(x+dx[i], y+dy[i], n, m, step+1);
        }
    }
    else return;
}
int main(){
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            horse[i][j] = -1;
        }
    }
    dfs(x-1, y-1, n, m, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%-5d", horse[i][j]);
        }
        printf("\n");
    }

}