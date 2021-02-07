#include<cstdio>
#include<cmath>

using namespace std;

void layFloor(int x, int y, int size, int addx, int addy){
    if (size == 1) return; 
    int halfx = (size + addx + addx) / 2;
    int halfy = (size + addy + addy) / 2;
    //左上角
    if (x <= halfx && y <= halfy){
        printf("%d %d 1\n", halfx+1, halfy+1);
        layFloor(x, y, size/2, addx, addy);
        layFloor(halfx, halfy + 1, size / 2, addx, addy + size / 2);
        layFloor(halfx + 1, halfy, size / 2, addx + size / 2, addy);
        layFloor(halfx + 1, halfy + 1, size / 2, 
                 addx + size / 2, addy + size / 2);
    }
    //左下角
    else if (x > halfx && y <= halfy){
        printf("%d %d 3\n", halfx, halfy + 1);
        layFloor(halfx, halfy, size / 2, addx, addy);
        layFloor(halfx, halfy + 1, size / 2, addx, addy + size / 2);
        layFloor(x, y, size / 2, addx + size / 2, addy);
        layFloor(halfx + 1, halfy + 1, size / 2, 
                 addx + size / 2, addy + size / 2);
    }
    //右下角
    else if (x > halfx && y > halfy){
        printf("%d %d 4\n", halfx, halfy);
        layFloor(halfx, halfy, size / 2, addx, addy);
        layFloor(halfx, halfy + 1, size / 2, addx, addy + size / 2);
        layFloor(halfx + 1, halfy, size / 2, addx + size / 2, addy);
        layFloor(x, y, size / 2, addy + size / 2, addy + size / 2);
    }
    // 右上角
    else if (x <= halfx && y > halfy)
    {
        printf("%d %d 2\n", halfx + 1, halfy);
        layFloor(halfx, halfy, size / 2, addx, addy);
        layFloor(x, y, size / 2, addx, addy + size / 2);
        layFloor(halfx + 1, halfy, size / 2, addx + size / 2, addy);
        layFloor(halfx + 1, halfy + 1, size / 2, 
                 addx + size / 2, addy + size / 2);
    }
}

int main(){
    int k, x, y;
    scanf("%d %d %d", &k, &x, &y);
    layFloor(x, y, pow(2, k), 0, 0);
}