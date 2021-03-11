#include<cstdio>

using namespace std;

int size = 0;
int total = 0;
int a[15] = {0}, b[15] = {0}, c[30] = {0}, d[30] = {0};

void queen(int column, int size){
    if(column >= size){
        if(total < 3){
            for(int i = 0; i < size; i++) printf("%d ", a[i]+1);
            printf("\n");
        }
        total++;
    }
    else{
        for(int i = 0; i < size; i++){
            if((!b[i]) && (!c[column + i]) && (!d[size-column+i-1])){
                a[column] = i;
                b[i] = 1;
                c[column + i] = 1;
                d[size - column + i - 1] = 1;
                queen(column + 1, size);
                b[i] = 0;
                c[column + i] = 0;
                d[size - column + i - 1] = 0;
            }
        }
    }
}

int main(){
    scanf("%d", &size);
    queen(0, size);
	printf("%d", total);
}