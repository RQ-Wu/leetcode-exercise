#include<cstdio>

using namespace std;

int main(){
    int m,n,hx,hy;
    int solution[21][21]={0};
    int hourse[21][21] = {0};
    int hourseDis[2][9]={{0,1,2,2,1,-1,-2,-2,-1},{0,-2,-1,1,2,2,1,-1,-2}};
    scanf("%d %d %d %d", &m, &n, &hx, &hy);
    for(int i = 0; i < 9; i++){
        if(hx+hourseDis[0][i] <= m && hy+hourseDis[1][i] <= n){
            hourse[hx+hourseDis[0][i]][hy+hourseDis[1][i]] = 1;
        }
    }


    for(int i = 0; i < m+1; i++){
        for(int j = 0; j < n+1; j++){
            if(hourse[i][j] == 1) solution[i][j] = 0;
            else if(i==0 || j==0) solution[i][j] = 1;
            else solution[i][j] = solution[i-1][j] + solution[i][j-1];
        }
    }

    printf("%d", solution[m][n]);
}