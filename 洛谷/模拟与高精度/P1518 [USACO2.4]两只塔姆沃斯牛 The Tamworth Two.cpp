#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#include<cstdio>

using namespace std;

char map[11][11];
int cx, cy, fx, fy;
int cd = UP, fd = UP;
int num[160010] = {0};

int isBlock(int x, int y, int direction){
    if (direction == UP)
    {
        return x == 0 || map[x-1][y] == '*';
    }
    else if (direction == LEFT)
    {
        return y == 0 || map[x][y-1] == '*';
    }
    else if (direction == RIGHT)
    {
        return y == 9 || map[x][y+1] == '*';
    }
    else if (direction == DOWN)
    {
        return x == 9 || map[x+1][y] == '*';
    }
}

void move(int *x, int *y, int direction){
    if (direction == UP)
    {
        *x = *x - 1;
    }
    else if (direction == LEFT)
    {
        *y = *y - 1;
    }
    else if (direction == RIGHT)
    {
        *y = *y + 1;
    }
    else if (direction == DOWN)
    {
        *x = *x + 1;
    }
}

int main(){
    //input
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", map[i]);
        for(int j = 0; j < 10; j++)
        {
            if (map[i][j] == 'F')
            {
                fx = i;
                fy = j;
            }
            else if (map[i][j] == 'C'){
                cx = i;
                cy = j;
            }
        }
    }

    int minute = 0;
    while (1)
    {
        //printf("%d  %d  %d  %d  %d  %d\n", fd, fx, fy, cd, cx, cy);
        num[fx + fy * 10 + cx * 100 + cx *1000 + fd * 10000 + cd * 40000] = 1;
        minute++;
        int flag = 0;
        // Farmer operate
        if(isBlock(fx, fy, fd)){
            fd = (fd + 1) % 4;
        }
        else{
            move(&fx, &fy, fd);
        }
        //Cow operate
        if(isBlock(cx, cy, cd)){
            cd = (cd + 1) % 4;
        }
        else{
            move(&cx, &cy, cd);
        }
        if (fx == cx && fy == cy)
        {
            printf("%d", minute);
            break;
        }
        if (num[fx + fy * 10 + cx * 100 + cy *1000 + fd * 10000 + cd * 40000] == 1) {
            printf("0");
            break;
        }
        
    }
}