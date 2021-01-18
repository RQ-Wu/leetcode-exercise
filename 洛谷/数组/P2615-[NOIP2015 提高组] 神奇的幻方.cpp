#include<cstdio>

using namespace std;

typedef struct position
{
    int row;
    int column;
}position;

position getPosition(int res[][39], int n, int k){
    int i = 0, j = 0;
    position pos;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (res[i][j] == k) {
                pos.row = i;
                pos.column = j;
                break;
            }
        }
    }

    return pos;
}

int main(){
    int n;
    scanf("%d", &n);
    int res[39][39] = {0};
    res[0][n / 2] = 1;
    for (int k = 2; k <= n * n; k++) {
        position tempPos = getPosition(res, n, k - 1);
        int row = tempPos.row;
        int column = tempPos.column;
		// printf("%d %d\n", row, column);
        // 在第一行但不在最后一列
        if (row == 0 && column != n - 1)
        {
            res[n-1][column+1] = k;
        }
        // 在最后一列但是不在第一行
        else if (column == n - 1 && row != 0){
            res[row - 1][0] = k;
        }
        // 在第一行最后一列
        else if (row == 0 && column == n - 1){
            res[row + 1][column] = k;
        }
        //其它
        else
        {
            // 右上角未填数
            if (res[row - 1][column + 1] == 0)
            {
                res[row - 1][column + 1] = k;
            }
            else
            {
                res[row + 1][column] = k;
            }
            
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", res[i][j]);
        }
        if (i != n - 1)
        {
            printf("\n");
        }
    }
}