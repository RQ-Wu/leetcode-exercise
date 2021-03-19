#include<cstdio>
#include<queue>

using namespace std;
typedef struct position{
    int x;
    int y;
}position;
queue<position> q;
int horse[410][410] = {0};
int n, m, x, y;
int dx[8] = {2,-2,2,-2,-1,1,-1,1};
int dy[8] = {1,1,-1,-1,2,2,-2,-2};

void dfs(int x, int y, int step){
    if (step > 200) return;
    if((horse[x][y] == -1 || horse[x][y] > step) && x < n && x >=0 && y < m && y >=0){
        horse[x][y] = step;
        for(int i = 0; i < 8; i++){
            dfs(x+dx[i], y+dy[i], step+1);
        }
    }
    else return;
}
void bfs(){
    while(!q.empty()){
        position head = q.front();
        int step = horse[head.x][head.y];
        for(int i = 0; i < 8; i++){
            position p;
            p.x = head.x+dx[i];
            p.y = head.y+dy[i];
            if (horse[p.x][p.y] == -1 && p.x < n && p.x >=0 && p.y < m && p.y >=0){
                q.push(p);
                horse[p.x][p.y] = (step + 1);
            }
        }
        q.pop();
    }
}

int main(){
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            horse[i][j] = -1;
        }
    }
    position init;
    init.x = x - 1;
    init.y = y - 1;
    q.push(init);
    horse[init.x][init.y] = 0;
    bfs();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%-5d", horse[i][j]);
        }
        printf("\n");
    }

}