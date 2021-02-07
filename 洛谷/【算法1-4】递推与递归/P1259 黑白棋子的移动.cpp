#include<cstdio>
#include<iostream>

using namespace std;

int chess[210] = {0};
char out[3] = {'o', '*', '-'};

void moveChess(int length, int n){
    if (n == 4)
    {
        printf("oooo****--");
        for (int i = 10; i < length; i++) printf("%c", out[chess[i]]);
        printf("\n");
        printf("ooo--***o*");
        for (int i = 10; i < length; i++) printf("%c", out[chess[i]]);
        printf("\n");
        printf("ooo*o**--*");
        for (int i = 10; i < length; i++) printf("%c", out[chess[i]]);
        printf("\n");
        printf("o--*o**oo*");
        for (int i = 10; i < length; i++) printf("%c", out[chess[i]]);
        printf("\n");
        printf("o*o*o*--o*");
        for (int i = 10; i < length; i++) printf("%c", out[chess[i]]);
        printf("\n");
        printf("--o*o*o*o*");
        for (int i = 10; i < length; i++) printf("%c", out[chess[i]]);
        printf("\n");
        return;
    }
    
    for (int i = 0; i < length; i++){
        printf("%c", out[chess[i]]);
    }
    printf("\n");
    chess[n-1] = chess[n] = 2;
    chess[2*n] = 0;
    chess[2*n+1] = 1;
    for (int i = 0; i < length; i++){
        printf("%c", out[chess[i]]);
    }
    printf("\n");
    chess[n-1] = chess[n] = 1;
    chess[2*n-1] = chess[2*n-2] = 2;

    moveChess(length, n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = n; i < 2*n; i++)
    {
        chess[i] = 1;
    }
    chess[2*n] = 2;
    chess[2*n+1] = 2;

    moveChess(2*n+2, n);
}