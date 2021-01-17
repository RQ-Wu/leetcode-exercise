#include<cstdio>

int main(){
    long int a[100] = {0};
    int length;
    for (length = 0; length < 100; length++){
        scanf("%ld", &a[length]);
        if (a[length] == 0)
        {
            break;
        }
    }

    for (int i = length - 1; i >=0; i--)
    {
        if (i == length - 1)
        {
            printf("%ld", a[i]);
        }
        else
        {
            printf(" %ld", a[i]);
        }
    }

    return 0;
}