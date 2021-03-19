#include<cstdio>
#include<iostream>

using namespace std;

int n;
int map[35][35] = {0};
bool res = false;

bool dfs(int i, int j){
    if(i < 0 || i >=n || j < 0 || j >=n){
        return false;
    }
    else if(map[i][j] == 0){
        map[i][j] = 2;
        bool flag1 = dfs(i + 1, j);
        bool flag2 = dfs(i - 1, j);
        bool flag3 = dfs(i, j + 1);
        bool flag4 = dfs(i, j - 1);
        bool flag = flag1 && flag2 && flag3 && flag4;
        if(!flag){
            map[i][j] = 3;
        }
        return flag;
    }
    else return true;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map[i][j] == 0 && !res){
                res = dfs(i, j);
            }
            if(map[i][j] == 3) printf("0 ");
            else printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}