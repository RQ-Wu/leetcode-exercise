#include<cstdio>

using namespace std;

int a[505][505] = {0};
void output(int a[][505], int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (j == 0)
            {
                printf("%d", a[i][j]);
            }
            else{
                printf(" %d", a[i][j]);
            }
        }
        if (i != n - 1)
        {
            printf("\n");
        }
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    // init the array
    int init = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = ++init;
        }
    }

    int x, y, r, z = 0;
    while (m-- > 0)
    {
        scanf("%d %d %d %d", &x, &y, &r, &z);
        int temp[2*r+1][2*r+1] = {0};
        if(z == 0){
            for (int i = 0; i < 2 * r + 1; i++){
                for(int j = 0; j < 2 * r + 1; j++){
                    temp[i][j] = a[x-1-r+(2*r-j)][y-1-r+i];
                }
            }
            for (int i = 0; i < 2 * r + 1; i++){
                for(int j = 0; j < 2 * r + 1; j++){
                    a[x-1-r+i][y-1-r+j] = temp[i][j];
                }
            }
        }
        else if(z==1){
            for (int i = 0; i < 2 * r + 1; i++){
                for(int j = 0; j < 2 * r + 1; j++){
                    temp[i][j] = a[x-1-r+j][y-r-1+(2*r-i)];
                }
            }
            for (int i = 0; i < 2 * r + 1; i++){
                for(int j = 0; j < 2 * r + 1; j++){
                    a[x-r-1+i][y-r-1+j] = temp[i][j];
                }
            }
        }
    }
	output(a, n);
    return 0;
}